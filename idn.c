/* idn.c	Command line interface to the library
 * Copyright (C) 2003  Simon Josefsson
 *
 * This file is part of GNU Libidn.
 *
 * GNU Libidn is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * GNU Libidn is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Libidn; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#include <stdio.h>
#include <unistd.h>

#include <stringprep.h>
#include <punycode.h>
#include <idna.h>

#include "idn_cmd.h"

#define GREETING "Copyright 2002, 2003 Simon Josefsson\n"\
	"GNU Libidn comes with NO WARRANTY, to the extent permitted by law.\n"\
	"You may redistribute copies of GNU Libidn under the terms of\n"\
	"the GNU Lesser General Public License.  For more information\n"\
	"about these matters, see the file named COPYING.LIB.\n"\

int
main (int argc, char *argv[])
{
  struct gengetopt_args_info args_info;
  char readbuf[BUFSIZ];
  char *p, *r;
  unsigned long *q;
  int rc;

  if (cmdline_parser(argc, argv, &args_info) != 0)
    return 1;

  if ((args_info.stringprep_given ? 1 : 0) +
      (args_info.punycode_encode_given ? 1 : 0) +
      (args_info.punycode_decode_given ? 1 : 0) +
      (args_info.idna_to_ascii_given ? 1 : 0) +
      (args_info.idna_to_unicode_given ? 1 : 0) != 1)
    {
      fprintf(stderr, "%s: One of -s, -e, -d, -a or -u must be specified.\n",
	      argv[0]);
      cmdline_parser_print_help();
      return 1;
    }

  if (!args_info.quiet_given)
      fprintf(stderr, "%s %s\n" GREETING, PACKAGE, VERSION);

  if (args_info.debug_given)
    fprintf(stderr, "system locale uses charset `%s'.\n",
	    stringprep_locale_charset());

  do
    {
      if (fgets(readbuf, BUFSIZ, stdin) == NULL)
	{
	  sprintf(readbuf, "%s: fgets() failed: ", argv[0]);
	  if (!feof(stdin))
	    perror(readbuf);
	  return 1;
	}

      if (readbuf[strlen(readbuf)-1] == '\n')
	readbuf[strlen(readbuf)-1] = '\0';

      if (args_info.stringprep_given)
	{
	  p = stringprep_locale_to_utf8 (readbuf);
	  if (!p)
	    {
	      fprintf(stderr, "%s: could not convert from %s to UTF-8.\n",
		      argv[0], stringprep_locale_charset());
	      return 1;
	    }

	  if (args_info.debug_given)
	    {
	      size_t i;
	      for (i = 0; p[i]; i++)
		fprintf(stderr, "input[%d] = U+%04x\n", i, p[i] & 0xFFFF);
	    }

	  rc = stringprep_profile (p, &r,
				   args_info.profile_given ?
				   args_info.profile_arg :
				   "Nameprep", 0);
	  free(p);
	  if (rc != STRINGPREP_OK)
	    {
	      fprintf(stderr,
		      "%s: stringprep_profile() failed with error %d.\n",
		      argv[0], rc);
	      return 1;
	    }

	  if (args_info.debug_given)
	    {
	      size_t i;
	      for (i = 0; r[i]; i++)
		fprintf(stderr, "output[%d] = U+%04x\n", i, r[i] & 0xFFFF);
	    }

	  p = stringprep_utf8_to_locale (r);
	  if (!p)
	    {
	      fprintf(stderr, "%s: could not convert from UTF-8 to %s.\n",
		      argv[0], stringprep_locale_charset());
	      return 1;
	    }

	  fprintf(stdout, "%s\n", p);

	  free(p);
	}

      if (args_info.punycode_encode_given)
	{
	  size_t len, len2;

	  p = stringprep_locale_to_utf8 (readbuf);
	  if (!p)
	    {
	      fprintf(stderr, "%s: could not convert from %s to UTF-8.\n",
		      argv[0], stringprep_locale_charset());
	      return 1;
	    }

	  q = stringprep_utf8_to_ucs4 (p, -1, &len);
	  free(p);
	  if (!q)
	    {
	      fprintf(stderr, "%s: could not convert from UTF-8 to UCS-4.\n",
		      argv[0]);
	      return 1;
	    }

	  if (args_info.debug_given)
	    {
	      size_t i;
	      for (i = 0; i < len; i++)
		fprintf(stderr, "input[%d] = U+%04x\n", i, q[i] & 0xFFFF);
	    }

	  len2 = BUFSIZ;
	  rc = punycode_encode (len, q, NULL, &len2, readbuf);
	  if (rc != PUNYCODE_SUCCESS)
	    {
	      fprintf(stderr, "%s: punycode_encode() failed with error %d.\n",
		      argv[0], rc);
	      return 1;
	    }

	  readbuf[len2] = '\0';

	  p = stringprep_utf8_to_locale (readbuf);
	  if (!p)
	    {
	      fprintf(stderr, "%s: could not convert from UTF-8 to %s.\n",
		      argv[0], stringprep_locale_charset());
	      return 1;
	    }

	  fprintf(stdout, "%s\n", p);

	  free(p);
	}

      if (args_info.punycode_decode_given)
	{
	  size_t len, len2;

	  len = BUFSIZ;
	  q = (unsigned long*) malloc(len * sizeof(q[0]));
	  if (!q)
	    {
	      sprintf(readbuf, "%s: malloc() failed: ", argv[0]);
	      perror(readbuf);
	      return 1;

	    }
	  rc = punycode_decode (strlen(readbuf), readbuf, &len, q, NULL);
	  if (rc != PUNYCODE_SUCCESS)
	    {
	      free(q);
	      fprintf(stderr, "%s: punycode_decode() failed with error %d.\n",
		      argv[0], rc);
	      return 1;
	    }

	  if (args_info.debug_given)
	    {
	      size_t i;
	      for (i = 0; i < len; i++)
		fprintf(stderr, "output[%d] = U+%04x\n", i, q[i] & 0xFFFF);
	    }

	  q[len] = 0;
	  p = stringprep_ucs4_to_utf8 (q, -1, NULL, NULL);
	  if (!p)
	    {
	      free(q);
	      fprintf(stderr, "%s: could not convert from UCS-4 to UTF-8.\n",
		      argv[0]);
	      return 1;
	    }

	  r = stringprep_utf8_to_locale (p);
	  free(p);
	  if (!r)
	    {
	      fprintf(stderr, "%s: could not convert from UTF-8 to %s.\n",
		      argv[0], stringprep_locale_charset());
	      return 1;
	    }

	  fprintf(stdout, "%s\n", r);

	  free(r);
	}

      if (args_info.idna_to_ascii_given)
	{
	  p = stringprep_locale_to_utf8 (readbuf);
	  if (!p)
	    {
	      fprintf(stderr, "%s: could not convert from %s to UTF-8.\n",
		      argv[0], stringprep_locale_charset());
	      return 1;
	    }

	  q = stringprep_utf8_to_ucs4 (p, -1, NULL);
	  if (!q)
	    {
	      free(p);
	      fprintf(stderr, "%s: could not convert from UCS-4 to UTF-8.\n",
		      argv[0]);
	      return 1;
	    }
	  if (args_info.debug_given)
	    {
	      size_t i;
	      for (i = 0; q[i]; i++)
		fprintf(stderr, "input[%d] = U+%04x\n", i, q[i] & 0xFFFF);
	    }

	  rc = idna_to_ascii_from_ucs4 (q, &r,
					args_info.allow_unassigned_given,
					args_info.usestd3asciirules_given);
	  free(q);
	  if (rc != IDNA_SUCCESS)
	    {
	      fprintf(stderr, "%s: idna_to_ascii_from_locale() failed "
		      "with error %d.\n", argv[0], rc);
	      return 1;
	    }
	  fprintf(stdout, "%s\n", r);

	  free(r);
	}

      if (args_info.idna_to_unicode_given)
	{
	  p = stringprep_locale_to_utf8 (readbuf);
	  if (!p)
	    {
	      fprintf(stderr, "%s: could not convert from %s to UTF-8.\n",
		      argv[0], stringprep_locale_charset());
	      return 1;
	    }

	  q = stringprep_utf8_to_ucs4 (p, -1, NULL);
	  if (!q)
	    {
	      free(p);
	      fprintf(stderr, "%s: could not convert from UCS-4 to UTF-8.\n",
		      argv[0]);
	      return 1;
	    }
	  if (args_info.debug_given)
	    {
	      size_t i;
	      for (i = 0; q[i]; i++)
		fprintf(stderr, "input[%d] = U+%04x\n", i, q[i] & 0xFFFF);
	    }
	  free(q);

	  rc = idna_to_unicode_ucs4_from_utf8
	    (p, &q, args_info.allow_unassigned_given,
	     args_info.usestd3asciirules_given);
	  free(p);
	  if (rc != IDNA_SUCCESS)
	    {
	      fprintf(stderr, "%s: idna_to_unicode_locale_from_locale() "
		      "failed with error %d.\n", argv[0], rc);
	      return 1;
	    }

	  if (args_info.debug_given)
	    {
	      size_t i;
	      for (i = 0; q[i]; i++)
		fprintf(stderr, "output[%d] = U+%04x\n", i, q[i] & 0xFFFF);
	    }

	  p = stringprep_ucs4_to_utf8 (q, -1, NULL, NULL);
	  if (!p)
	    {
	      free(q);
	      fprintf(stderr, "%s: could not convert from UCS-4 to UTF-8.\n",
		      argv[0]);
	      return 1;
	    }

	  fprintf(stdout, "%s\n", p);

	  free(p);
	}

    }
  while (!feof(stdin) && !ferror(stdin));

  return 0;
}
