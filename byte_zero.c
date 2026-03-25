#include "byte.h"

void byte_zero(void *s, unsigned int n)
{
  char *s_char = s;
  for (;;) {
    if (!n) break; *s_char++ = 0; --n;
    if (!n) break; *s_char++ = 0; --n;
    if (!n) break; *s_char++ = 0; --n;
    if (!n) break; *s_char++ = 0; --n;
  }
}
