#include "server.h"

#define PORT 3100
#define MAX_CONNS 10

int main(int argc, char **argv) {
  int server_fd;
  struct sockaddr_in addr;

  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    puts("socket failed");
    exit(EXIT_FAILURE);
  }

  addr.sin_addr.s_addr = INADDR_ANY;
  addr.sin_port = htons(PORT);
  addr.sin_family = AF_INET;

  int s_port;
  if ((s_port = bind(server_fd, (struct sockaddr *)&addr, sizeof(addr))) < 0) {
    puts("failed to bind socket on port");
    exit(EXIT_FAILURE);
  }

  int s_status;
  if ((s_status = (listen(server_fd, MAX_CONNS))) < 0) {
    puts("failted to listen to conns");
    exit(EXIT_FAILURE);
  }

  // while (1) { }
  // use pthread for handling multiple clients
  return 0;
}
