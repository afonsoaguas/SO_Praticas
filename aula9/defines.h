#ifndef __DEFINES_H__
#define __DEFINES_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <unistd.h>

#define exit_on_error(s,m) if (s<0) { perror(m); exit(1);}

#define IPC_KEY 0x0a99114
#define MSG_TYP 33

#endif