#include <unistd.h>
#include <stdlib.h>

int main (int argc, char **argv) {
  char **arg, **ptr;
  arg = malloc ((argc + 4) * sizeof *arg);
  if (!arg) exit (1);
  ptr = arg;
  *ptr++ = "/usr/sbin/djbdns-chroot.suid";
  *ptr++ = "/etc/tinydns";
  *ptr++ = "/bin/sh";
  while (*(++argv)) *ptr++ = *argv;
  return execvp (*arg, arg);
}
