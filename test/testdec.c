/*

    This file is part of libdvbcsa.

    libdvbcsa is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    libdvbcsa is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with libdvbcsa; if not, write to the Free Software Foundation,
    Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

*/

#include <stdio.h>

#include <dvbcsa/dvbcsa.h>
#include "dvbcsa_pv.h"

#ifdef HAVE_ASSERT_H
#include <assert.h>
#endif

struct                  test_s
{
  const uint8_t         key[256];
  const uint8_t         in[256];
  const uint8_t         out[256];
};

static const struct test_s      csa_tests[2] =
  {
    /* test 1 */
    {
      /* control words */
      {0x07, 0xe0, 0x1b, 0x02, 0xc9, 0xe0, 0x45, 0xee},

      {0xde, 0xcf, 0x0a, 0x0d, 0xb2, 0xd7, 0xc4, 0x40, 0xde, 0x5d, 0x63, 0x18, 0x5a, 0x98, 0x17, 0xaa,
       0xc9, 0xbc, 0x27, 0xc6, 0xcb, 0x49, 0x40, 0x48, 0xfd, 0x20, 0xb7, 0x05, 0x5b, 0x27, 0xcb, 0xeb,
       0x9a, 0xf0, 0xac, 0x45, 0x6d, 0x56, 0xf4, 0x7b, 0x6f, 0xa0, 0x57, 0xf3, 0x9b, 0xf7, 0xa2, 0xc7,
       0xd4, 0x68, 0x24, 0x00, 0x2f, 0x28, 0x13, 0x96, 0x94, 0xa8, 0x7c, 0xf4, 0x6f, 0x07, 0x2a, 0x0e,
       0xe8, 0xa1, 0xeb, 0xc7, 0x80, 0xac, 0x1f, 0x79, 0xbf, 0x5d, 0xb6, 0x10, 0x7c, 0x2e, 0x52, 0xe9,
       0x34, 0x2c, 0xa8, 0x39, 0x01, 0x73, 0x04, 0x24, 0xa8, 0x1e, 0xdb, 0x5b, 0xcb, 0x24, 0xf6, 0x31,
       0xab, 0x02, 0x6b, 0xf9, 0xf6, 0xf7, 0xe9, 0x52, 0xad, 0xcf, 0x62, 0x0f, 0x42, 0xf6, 0x66, 0x5d,
       0xc0, 0x86, 0xf2, 0x7b, 0x40, 0x20, 0xa9, 0xbd, 0x1f, 0xfd, 0x16, 0xad, 0x2e, 0x75, 0xa6, 0xa0,
       0x85, 0xf3, 0x9c, 0x31, 0x20, 0x4e, 0xfb, 0x95, 0x61, 0x78, 0xce, 0x10, 0xc1, 0x48, 0x5f, 0xd3,
       0x61, 0x05, 0x12, 0xf4, 0xe2, 0x04, 0xae, 0xe0, 0x86, 0x01, 0x56, 0x55, 0xb1, 0x0f, 0xa6, 0x33,
       0x95, 0x20, 0x92, 0xf0, 0xbe, 0x39, 0x31, 0xe1, 0x2a, 0xf7, 0x93, 0xb4, 0xf7, 0xe4, 0xf1, 0x85,
       0xae, 0x50, 0xf1, 0x63, 0xd4, 0x5d, 0x9c, 0x6c},

      {0xaf, 0xbe, 0xfb, 0xef, 0xbe, 0xfb, 0xef, 0xbe, 0xfb, 0xef, 0xbe, 0xfb, 0xe6, 0xb5, 0xad, 0x7c,
       0xf9, 0xf3, 0xe5, 0xb1, 0x6c, 0x7c, 0xf9, 0xf3, 0xe6, 0xb5, 0xad, 0x6b, 0x5f, 0x3e, 0x7c, 0xf9,
       0x6c, 0x5b, 0x1f, 0x3e, 0x7c, 0xf9, 0xad, 0x6b, 0x5a, 0xd7, 0xcf, 0x9f, 0x3e, 0x5b, 0x16, 0xc7,
       0xcf, 0x9f, 0x3e, 0x6b, 0x5a, 0xd6, 0xb5, 0xf3, 0xe7, 0xcf, 0x96, 0xc5, 0xb1, 0xf3, 0xe7, 0xcf,
       0x9a, 0xd6, 0xb5, 0xad, 0x7c, 0xf9, 0xf3, 0xe5, 0xb1, 0x6c, 0x7c, 0xf9, 0xf3, 0xe6, 0xb5, 0xad,
       0x6b, 0x5f, 0x3e, 0x7c, 0xf9, 0x6c, 0x5b, 0x1f, 0x3e, 0x7c, 0xf9, 0xad, 0x6b, 0x5a, 0xd7, 0xcf,
       0x9f, 0x3e, 0x5b, 0x16, 0xc7, 0xcf, 0x9f, 0x3e, 0x6b, 0x5a, 0xd6, 0xb5, 0xf3, 0xe7, 0xcf, 0x96,
       0xc5, 0xb1, 0xf3, 0xe7, 0xcf, 0x9a, 0xd6, 0xb5, 0xad, 0x7c, 0xf9, 0xf3, 0xe5, 0xb1, 0x6c, 0x7c,
       0xf9, 0xf3, 0xe6, 0xb5, 0xad, 0x6b, 0x5f, 0x3e, 0x7c, 0xf9, 0x6c, 0x5b, 0x1f, 0x3e, 0x7c, 0xf9,
       0xad, 0x6b, 0x5a, 0xd7, 0xcf, 0x9f, 0x3e, 0x5b, 0x16, 0xc7, 0xcf, 0x9f, 0x3e, 0x6b, 0x5a, 0xd6,
       0xb5, 0xf3, 0xe7, 0xcf, 0x96, 0xc5, 0xb1, 0xf3, 0xe7, 0xcf, 0x9a, 0xd0, 0x00, 0x00, 0x00, 0x00,
       0xff, 0xfc, 0x44, 0x00, 0x66, 0xb1, 0x11, 0x11}
    },

    /* test 2 */
    {
      {0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00},

      {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
       0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
       0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
       0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
       0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f,
       0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5a, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f,
       0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f,
       0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7a, 0x7b, 0x7c, 0x7d, 0x7e, 0x7f,
       0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
       0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
       0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf,
       0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7},

      {0x2d, 0x0a, 0x47, 0x20, 0x18, 0x11, 0x9c, 0x8a, 0xd1, 0x2a, 0x65, 0x6b, 0x89, 0xe4, 0x35, 0x2b,
       0xc2, 0xb5, 0x90, 0x61, 0xd1, 0x7e, 0x02, 0xe1, 0x3f, 0x46, 0x70, 0xcf, 0x77, 0x91, 0x2f, 0x22,
       0x93, 0xc1, 0x6c, 0xfe, 0x49, 0xad, 0x7c, 0xc2, 0xaf, 0x86, 0x1b, 0xa3, 0x29, 0xbe, 0xaa, 0x64,
       0xf0, 0x22, 0xb9, 0x5e, 0x98, 0xaa, 0x60, 0xef, 0xdf, 0xd6, 0x44, 0x77, 0xe6, 0xbf, 0xbb, 0x94,
       0xb2, 0x0a, 0x63, 0x0e, 0x5c, 0xf2, 0xac, 0xb4, 0x49, 0xcc, 0x9e, 0x4f, 0x94, 0x4c, 0x30, 0x12,
       0xe8, 0x55, 0xc2, 0x44, 0xa4, 0x52, 0xcb, 0x61, 0x81, 0xc9, 0xb6, 0xa6, 0x6b, 0xef, 0xaf, 0xa6,
       0x71, 0x1d, 0x7b, 0x58, 0x2f, 0xfa, 0xd1, 0x0c, 0x07, 0x9d, 0x1f, 0x35, 0x87, 0xbe, 0x02, 0x9f,
       0x20, 0xc6, 0x60, 0x8f, 0x1c, 0x30, 0x0f, 0x96, 0xd0, 0x71, 0xd6, 0x51, 0x10, 0xdf, 0x5b, 0xf6,
       0x44, 0x2f, 0x80, 0x28, 0xb7, 0xec, 0x23, 0x59, 0x4b, 0x94, 0x0b, 0x9a, 0x74, 0xa1, 0x1f, 0xf7,
       0x9e, 0x76, 0xb4, 0xdf, 0xbb, 0x3c, 0x8c, 0x88, 0x97, 0x22, 0x56, 0x73, 0x16, 0x05, 0xac, 0xf9,
       0x4f, 0x77, 0x9d, 0x38, 0xa0, 0x6b, 0x05, 0xd2, 0xe6, 0x15, 0x01, 0xb1, 0x5c, 0xc9, 0x62, 0xa9,
       0x9b, 0x1a, 0x6a, 0x1a, 0xcf, 0xe6, 0xa8, 0xba}
    }
  };

#define TS_SIZE         184     /* stream size generation */

static void
hexdump         (const char     *str,
                 const void     *data,
                 unsigned int   len)
{
  const uint8_t *p = (const uint8_t *)data;
  unsigned int  i;

  printf("- %s -\n", str);
  for (i = 0; i < len; i++)
    printf("0x%02x,%c", p[i], (i+1)%16 ? ' ' : '\n');
  puts("");
}

int
main            (void)
{
  struct dvbcsa_key_s   *key = dvbcsa_key_alloc();
  unsigned int          i;
  uint8_t               data[256];

#ifdef HAVE_ASSERT_H
  assert(key != NULL);
#endif

  puts("* CSA decryption *");

  for (i = 0; i < sizeof(csa_tests) / sizeof(struct test_s); i++)
    {
      printf(" test %u\n", i + 1);

      dvbcsa_key_set(csa_tests[i].key, key);

      memcpy(data, csa_tests[i].in, TS_SIZE);
      dvbcsa_decrypt(key, data, TS_SIZE);

      if (memcmp(data, csa_tests[i].out, TS_SIZE))
        {
          puts("\nTest failed\n");
          hexdump("control words", csa_tests[i].key, sizeof(dvbcsa_cw_t));
          hexdump("input data", csa_tests[i].out, TS_SIZE);
          hexdump("expected stream", csa_tests[i].in, TS_SIZE);
          hexdump("output stream", data, TS_SIZE);
          return (1);
        }
    }

  dvbcsa_key_free(key);

  puts("* Done *");

  return (0);
}

