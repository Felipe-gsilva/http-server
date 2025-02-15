#include "server.h"

#define PORT 3100
#define MAX_CONNS 10

void *test_thread(void *vargp) {
  sleep(10);
  printf("Printing from Thread \n");
  printf("status: %d\n", *(int *)vargp);

  return NULL;
}

int connection_pool(int *status) {
  pthread_t thread_id;
  printf("Before Thread\n");
  pthread_create(&thread_id, NULL, test_thread, status);
  pthread_join(thread_id, NULL);
  printf("After Thread\n");
  exit(0);
}

int main(int argc, char **argv) {
  server s;

  if ((s.fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    puts("socket failed");
    exit(EXIT_FAILURE);
  }

  s.addr.sin_addr.s_addr = INADDR_ANY;
  s.addr.sin_port = htons(PORT);
  s.addr.sin_family = AF_INET;

  if ((s.port = bind(s.fd, (struct sockaddr *)&s.addr, sizeof(s.addr))) < 0) {
    puts("failed to bind socket on port");
    exit(EXIT_FAILURE);
  }

  if ((s.status = (listen(s.fd, MAX_CONNS))) < 0) {
    puts("failted to listen to conns");
    exit(EXIT_FAILURE);
  }

  while (1) {
    connection_pool(&s.status);
  }
  return 0;
}
