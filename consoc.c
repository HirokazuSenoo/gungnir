#include <gungnir.h>

int consock(const char *addr,const char *portnum){
  struct sockaddr_in server;
  int sock;
  long port;
  port = strtol(portnum,NULL,0);
  sock = socket(AF_INET,SOCK_STREAM,0);

  server.sin_family = AF_INET;
  server.sin_port = htons(port);
  inet_pton(AF_INET,addr,&server.sin_addr.s_addr);

  connect(sock,(struct sockaddr *)&server,sizeof(server));
  return sock;
}
