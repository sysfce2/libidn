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
  if (!(const void *) idn_free)
    fail ("idn_free");
  if (!(const void *) idna_strerror)
    fail ("idna_strerror");
  if (!(const void *) idna_to_ascii_4i)
    fail ("idna_to_ascii_4i");
  if (!(const void *) idna_to_ascii_4z)
    fail ("idna_to_ascii_4z");
  if (!(const void *) idna_to_ascii_8z)
    fail ("idna_to_ascii_8z");
  if (!(const void *) idna_to_ascii_lz)
    fail ("idna_to_ascii_lz");
  if (!(const void *) idna_to_unicode_44i)
    fail ("idna_to_unicode_44i");
  if (!(const void *) idna_to_unicode_4z4z)
    fail ("idna_to_unicode_4z4z");
  if (!(const void *) idna_to_unicode_8z4z)
    fail ("idna_to_unicode_8z4z");
  if (!(const void *) idna_to_unicode_8z8z)
    fail ("idna_to_unicode_8z8z");
  if (!(const void *) idna_to_unicode_8zlz)
    fail ("idna_to_unicode_8zlz");
  if (!(const void *) idna_to_unicode_lzlz)
    fail ("idna_to_unicode_lzlz");
  if (!(const void *) pr29_4)
    fail ("pr29_4");
  if (!(const void *) pr29_4z)
    fail ("pr29_4z");
  if (!(const void *) pr29_8z)
    fail ("pr29_8z");
  if (!(const void *) pr29_strerror)
    fail ("pr29_strerror");
  if (!(const void *) punycode_decode)
    fail ("punycode_decode");
  if (!(const void *) punycode_encode)
    fail ("punycode_encode");
  if (!(const void *) punycode_strerror)
    fail ("punycode_strerror");
  if (!(const void *) stringprep)
    fail ("stringprep");
  if (!(const void *) stringprep_4i)
    fail ("stringprep_4i");
  if (!(const void *) stringprep_4zi)
    fail ("stringprep_4zi");
  if (!(const void *) stringprep_check_version)
    fail ("stringprep_check_version");
  if (!(const void *) stringprep_convert)
    fail ("stringprep_convert");
  if (!(const void *) stringprep_iscsi)
    fail ("stringprep_iscsi");
  if (!(const void *) stringprep_iscsi_prohibit)
    fail ("stringprep_iscsi_prohibit");
  if (!(const void *) stringprep_kerberos5)
    fail ("stringprep_kerberos5");
  if (!(const void *) stringprep_locale_charset)
    fail ("stringprep_locale_charset");
  if (!(const void *) stringprep_locale_to_utf8)
    fail ("stringprep_locale_to_utf8");
  if (!(const void *) stringprep_nameprep)
    fail ("stringprep_nameprep");
  if (!(const void *) stringprep_plain)
    fail ("stringprep_plain");
  if (!(const void *) stringprep_profile)
    fail ("stringprep_profile");
  if (!(const void *) stringprep_profiles)
    fail ("stringprep_profiles");
  if (!(const void *) stringprep_rfc3454_A_1)
    fail ("stringprep_rfc3454_A_1");
  if (!(const void *) stringprep_rfc3454_B_1)
    fail ("stringprep_rfc3454_B_1");
  if (!(const void *) stringprep_rfc3454_B_2)
    fail ("stringprep_rfc3454_B_2");
  if (!(const void *) stringprep_rfc3454_B_3)
    fail ("stringprep_rfc3454_B_3");
  if (!(const void *) stringprep_rfc3454_C_1_1)
    fail ("stringprep_rfc3454_C_1_1");
  if (!(const void *) stringprep_rfc3454_C_1_2)
    fail ("stringprep_rfc3454_C_1_2");
  if (!(const void *) stringprep_rfc3454_C_2_1)
    fail ("stringprep_rfc3454_C_2_1");
  if (!(const void *) stringprep_rfc3454_C_2_2)
    fail ("stringprep_rfc3454_C_2_2");
  if (!(const void *) stringprep_rfc3454_C_3)
    fail ("stringprep_rfc3454_C_3");
  if (!(const void *) stringprep_rfc3454_C_4)
    fail ("stringprep_rfc3454_C_4");
  if (!(const void *) stringprep_rfc3454_C_5)
    fail ("stringprep_rfc3454_C_5");
  if (!(const void *) stringprep_rfc3454_C_6)
    fail ("stringprep_rfc3454_C_6");
  if (!(const void *) stringprep_rfc3454_C_7)
    fail ("stringprep_rfc3454_C_7");
  if (!(const void *) stringprep_rfc3454_C_8)
    fail ("stringprep_rfc3454_C_8");
  if (!(const void *) stringprep_rfc3454_C_9)
    fail ("stringprep_rfc3454_C_9");
  if (!(const void *) stringprep_rfc3454_D_1)
    fail ("stringprep_rfc3454_D_1");
  if (!(const void *) stringprep_rfc3454_D_2)
    fail ("stringprep_rfc3454_D_2");
  if (!(const void *) stringprep_saslprep)
    fail ("stringprep_saslprep");
  if (!(const void *) stringprep_saslprep_space_map)
    fail ("stringprep_saslprep_space_map");
  if (!(const void *) stringprep_strerror)
    fail ("stringprep_strerror");
  if (!(const void *) stringprep_trace)
    fail ("stringprep_trace");
  if (!(const void *) stringprep_ucs4_nfkc_normalize)
    fail ("stringprep_ucs4_nfkc_normalize");
  if (!(const void *) stringprep_ucs4_to_utf8)
    fail ("stringprep_ucs4_to_utf8");
  if (!(const void *) stringprep_unichar_to_utf8)
    fail ("stringprep_unichar_to_utf8");
  if (!(const void *) stringprep_utf8_nfkc_normalize)
    fail ("stringprep_utf8_nfkc_normalize");
  if (!(const void *) stringprep_utf8_to_locale)
    fail ("stringprep_utf8_to_locale");
  if (!(const void *) stringprep_utf8_to_ucs4)
    fail ("stringprep_utf8_to_ucs4");
  if (!(const void *) stringprep_utf8_to_unichar)
    fail ("stringprep_utf8_to_unichar");
  if (!(const void *) stringprep_xmpp_nodeprep)
    fail ("stringprep_xmpp_nodeprep");
  if (!(const void *) stringprep_xmpp_nodeprep_prohibit)
    fail ("stringprep_xmpp_nodeprep_prohibit");
  if (!(const void *) stringprep_xmpp_resourceprep)
    fail ("stringprep_xmpp_resourceprep");

#ifdef WITH_TLD
  if (!(const void *) tld_check_4)
    fail ("tld_check_4");
  if (!(const void *) tld_check_4t)
    fail ("tld_check_4t");
  if (!(const void *) tld_check_4tz)
    fail ("tld_check_4tz");
  if (!(const void *) tld_check_4z)
    fail ("tld_check_4z");
  if (!(const void *) tld_check_8z)
    fail ("tld_check_8z");
  if (!(const void *) tld_check_lz)
    fail ("tld_check_lz");
  if (!(const void *) tld_default_table)
    fail ("tld_default_table");
  if (!(const void *) tld_get_4)
    fail ("tld_get_4");
  if (!(const void *) tld_get_4z)
    fail ("tld_get_4z");
  if (!(const void *) tld_get_table)
    fail ("tld_get_table");
  if (!(const void *) tld_get_z)
    fail ("tld_get_z");
  if (!(const void *) tld_strerror)
    fail ("tld_strerror");
#endif
}
