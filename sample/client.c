#include <gungnir.h>

int main(int argc,char *argv[]){
  
  char rbuf[1024],sbuf[1024];
  int n;
  int soc;
  soc = consock(argv[1],argv[2]);
 
  for(;;){
    // memset(rbuf,0,sizeof(rbuf));
    // memset(sbuf,0,sizeof(rbuf));
    fgets(sbuf,1024,stdin);
    send(soc,sbuf,sizeof(sbuf),0);
    recv(soc,rbuf,sizeof(rbuf),0);
    printf("%s\n",rbuf);
    
  }
  close(soc);
  
  
  return 0;
}
