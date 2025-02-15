#ifndef _SERVER
#define _SERVER

#include "defines.h"
#include <netinet/in.h>
#include <pthread.h>
#include <unistd.h> 

typedef struct server server; 

struct server {
  int fd;
  int port;
  int status;
  struct sockaddr_in addr;
};

int main(int argc, char **argv);

#endif
