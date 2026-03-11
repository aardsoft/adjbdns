#ifndef BYTE_H
#define BYTE_H

extern unsigned int byte_chr(char *,unsigned int,char);
extern unsigned int byte_rchr(char *,unsigned int,char);
extern void byte_copy(char *,unsigned int,char *);
extern void byte_copyr(char *,int,char *);
extern int byte_diff(char *,unsigned int,char *);
extern void byte_zero(char *,unsigned int);

#define byte_equal(s,n,t) (!byte_diff((s),(n),(t)))

#endif
