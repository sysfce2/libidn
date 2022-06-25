/* tst_symbols.c --- Test if all exported symbols are available.
 * Copyright (C) 2010-2022 Simon Josefsson
 *
 * This file is part of GNU Libidn.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <stringprep.h>
#include <idna.h>
#include <punycode.h>
#include <idn-free.h>
#include <pr29.h>
#ifdef WITH_TLD
# include <tld.h>
#endif

#include "utils.h"

void
doit (void)
{
  const void *p;

  p = (const void *) idn_free;
  p = (const void *) idn_free;
  p = (const void *) idna_strerror;
  p = (const void *) idna_to_ascii_4i;
  p = (const void *) idna_to_ascii_4z;
  p = (const void *) idna_to_ascii_8z;
  p = (const void *) idna_to_ascii_lz;
  p = (const void *) idna_to_unicode_44i;
  p = (const void *) idna_to_unicode_4z4z;
  p = (const void *) idna_to_unicode_8z4z;
  p = (const void *) idna_to_unicode_8z8z;
  p = (const void *) idna_to_unicode_8zlz;
  p = (const void *) idna_to_unicode_lzlz;
  p = (const void *) pr29_4;
  p = (const void *) pr29_4z;
  p = (const void *) pr29_8z;
  p = (const void *) pr29_strerror;
  p = (const void *) punycode_decode;
  p = (const void *) punycode_encode;
  p = (const void *) punycode_strerror;
  p = (const void *) stringprep;
  p = (const void *) stringprep_4i;
  p = (const void *) stringprep_4zi;
  p = (const void *) stringprep_check_version;
  p = (const void *) stringprep_convert;
  p = (const void *) stringprep_iscsi;
  p = (const void *) stringprep_iscsi_prohibit;
  p = (const void *) stringprep_kerberos5;
  p = (const void *) stringprep_locale_charset;
  p = (const void *) stringprep_locale_to_utf8;
  p = (const void *) stringprep_nameprep;
  p = (const void *) stringprep_plain;
  p = (const void *) stringprep_profile;
  p = (const void *) stringprep_profiles;
  p = (const void *) stringprep_rfc3454_A_1;
  p = (const void *) stringprep_rfc3454_B_1;
  p = (const void *) stringprep_rfc3454_B_2;
  p = (const void *) stringprep_rfc3454_B_3;
  p = (const void *) stringprep_rfc3454_C_1_1;
  p = (const void *) stringprep_rfc3454_C_1_2;
  p = (const void *) stringprep_rfc3454_C_2_1;
  p = (const void *) stringprep_rfc3454_C_2_2;
  p = (const void *) stringprep_rfc3454_C_3;
  p = (const void *) stringprep_rfc3454_C_4;
  p = (const void *) stringprep_rfc3454_C_5;
  p = (const void *) stringprep_rfc3454_C_6;
  p = (const void *) stringprep_rfc3454_C_7;
  p = (const void *) stringprep_rfc3454_C_8;
  p = (const void *) stringprep_rfc3454_C_9;
  p = (const void *) stringprep_rfc3454_D_1;
  p = (const void *) stringprep_rfc3454_D_2;
  p = (const void *) stringprep_saslprep;
  p = (const void *) stringprep_saslprep_space_map;
  p = (const void *) stringprep_strerror;
  p = (const void *) stringprep_trace;
  p = (const void *) stringprep_ucs4_nfkc_normalize;
  p = (const void *) stringprep_ucs4_to_utf8;
  p = (const void *) stringprep_unichar_to_utf8;
  p = (const void *) stringprep_utf8_nfkc_normalize;
  p = (const void *) stringprep_utf8_to_locale;
  p = (const void *) stringprep_utf8_to_ucs4;
  p = (const void *) stringprep_utf8_to_unichar;
  p = (const void *) stringprep_xmpp_nodeprep;
  p = (const void *) stringprep_xmpp_nodeprep_prohibit;
  p = (const void *) stringprep_xmpp_resourceprep;

#ifdef WITH_TLD
  p = (const void *) tld_check_4;
  p = (const void *) tld_check_4t;
  p = (const void *) tld_check_4tz;
  p = (const void *) tld_check_4z;
  p = (const void *) tld_check_8z;
  p = (const void *) tld_check_lz;
  p = (const void *) tld_default_table;
  p = (const void *) tld_get_4;
  p = (const void *) tld_get_4z;
  p = (const void *) tld_get_table;
  p = (const void *) tld_get_z;
  p = (const void *) tld_strerror;
#endif

  if (p == NULL)
    fail ("no symbols");
}
