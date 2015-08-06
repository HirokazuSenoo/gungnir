#include <gungnir.h>

int main(int argc,char *argv[]){
  int soc;
  char buf[1024],*ptr;
  socklen_t len;
  soc = wsock(argv[1]);
  char rbuf[NI_MAXHOST],sbuf[NI_MAXSERV];
  char tbuf[2048];
  struct sockaddr_storage from;
  int acc;
  for(;;){
    len = (socklen_t)sizeof(from);
    if((acc = accept(soc,(struct sockaddr *)&from,&len)) < 0){
      printf("accept error\n");
      exit(1);
    }else{
      socklen_t len = 0;
      getnameinfo((struct sockaddr *)&from,len,rbuf,sizeof(rbuf),sbuf,sizeof(sbuf),NI_NUMERICHOST | NI_NUMERICSERV);
      for(;;){
	if(!(strcmp("quit\n",tbuf)))break;
       	memset(&tbuf,0,sizeof(rbuf));
	
	recv(acc,tbuf,sizeof(tbuf),0);
	send(acc,tbuf,sizeof(tbuf),0);
	//fgets(tbuf,1024,stdin);
	printf("%s\n",tbuf);
	
      }
    }
  }
}
