#include <unistd.h>
#include "buffer.h"

int buffer_unixread(int fd,void *buf,unsigned int len)
{
  return read(fd,buf,len);
}
