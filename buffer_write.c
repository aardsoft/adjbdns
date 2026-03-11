#include <unistd.h>
#include "buffer.h"

int buffer_unixwrite(int fd,void *buf,unsigned int len)
{
  return write(fd,buf,len);
}
