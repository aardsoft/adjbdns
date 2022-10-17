#include <stdlib.h>
#include <limits.h>
#include <sys/stat.h>
#include <string.h>
#include "auto_inst_home.h"
#include "auto_service_home.h"

extern void h(const char* home,int uid,int gid,int mode);
extern void d(const char* home,const char* subdir,int uid,int gid,int mode);
extern void c(const char* home,const char* subdir,const char* file,int uid,int gid,int mode);

void rd(const char* dir)
{
  struct stat st;
  char tmp[PATH_MAX];
  strncpy(tmp, dir, strlen(dir));
  char* p=NULL;
  for (p=tmp+1; *p; p++)
    if (*p == '/'){
      *p=0;
      if (stat(tmp, &st))
        d("/",tmp+1,-1,-1,02755);
      *p='/';
    }
  d("/", dir+1,-1,-1,02755);
}

void hier()
{
  char* destdir=getenv("DESTDIR");

  if (destdir){
    rd(auto_inst_home);
    rd(auto_service_home);
    d(destdir,"etc",-1,-1,02755);
    c(destdir,"etc","dnsroots.global",-1,-1,0644);
  } else
    c("/","etc","dnsroots.global",-1,-1,0644);

  d(auto_service_home,"system",-1,-1,02755);
  c(auto_service_home,"system","tinydns.service",-1,-1,0644);
  c(auto_service_home,"system","tinydns6.service",-1,-1,0644);

  h(auto_inst_home,-1,-1,02755);
  d(auto_inst_home,"bin",-1,-1,02755);
  d(auto_inst_home,"sbin",-1,-1,02755);

  c(auto_inst_home,"bin","dnscache-conf",-1,-1,0755);
  c(auto_inst_home,"bin","tinydns-conf",-1,-1,0755);
  c(auto_inst_home,"bin","walldns-conf",-1,-1,0755);
  c(auto_inst_home,"bin","rbldns-conf",-1,-1,0755);
  c(auto_inst_home,"bin","pickdns-conf",-1,-1,0755);
  c(auto_inst_home,"bin","axfrdns-conf",-1,-1,0755);

  c(auto_inst_home,"bin","dnscache",-1,-1,0755);
  c(auto_inst_home,"bin","tinydns",-1,-1,0755);
  c(auto_inst_home,"bin","walldns",-1,-1,0755);
  c(auto_inst_home,"bin","rbldns",-1,-1,0755);
  c(auto_inst_home,"bin","pickdns",-1,-1,0755);
  c(auto_inst_home,"bin","axfrdns",-1,-1,0755);

  c(auto_inst_home,"bin","tinydns-get",-1,-1,0755);
  c(auto_inst_home,"bin","tinydns-data",-1,-1,0755);
  c(auto_inst_home,"bin","tinydns-edit",-1,-1,0755);
  c(auto_inst_home,"bin","rbldns-data",-1,-1,0755);
  c(auto_inst_home,"bin","pickdns-data",-1,-1,0755);
  c(auto_inst_home,"bin","axfr-get",-1,-1,0755);

  c(auto_inst_home,"bin","dnsip",-1,-1,0755);
  c(auto_inst_home,"bin","dnsip6",-1,-1,0755);
  c(auto_inst_home,"bin","dnsipq",-1,-1,0755);
  c(auto_inst_home,"bin","dnsip6q",-1,-1,0755);
  c(auto_inst_home,"bin","dnsname",-1,-1,0755);
  c(auto_inst_home,"bin","dnstxt",-1,-1,0755);
  c(auto_inst_home,"bin","dnsmx",-1,-1,0755);
  c(auto_inst_home,"bin","dnsfilter",-1,-1,0755);
  c(auto_inst_home,"bin","random-ip",-1,-1,0755);
  c(auto_inst_home,"bin","dnsqr",-1,-1,0755);
  c(auto_inst_home,"bin","dnsq",-1,-1,0755);
  c(auto_inst_home,"bin","dnstrace",-1,-1,0755);
  c(auto_inst_home,"bin","dnstracesort",-1,-1,0755);

  c(auto_inst_home,"sbin","djbdns-chroot.suid",-1,-1,0755);
  c(auto_inst_home,"sbin","djbdns-chroot.login",-1,-1,0755);

  c(auto_inst_home,"sbin","tinydns-sign",-1,-1,0755);
}
