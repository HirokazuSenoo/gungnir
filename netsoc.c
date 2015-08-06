#include <gungnir.h>
/*********************************************
ポート番号を引数に取りbindされたソケットを返す
acceptは行わない
返り値でエラーが検出された場合exitでプロセスを落とすので注意
*********************************************/
int wsock(const char *portnum){

  char rbuf[NI_MAXHOST],sbuf[NI_MAXSERV];
  struct addrinfo hints, *res0;
  int soc,opt;
  socklen_t opt_len;

  memset(&hints,0,sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  if((getaddrinfo(NULL,portnum,&hints,&res0)) != 0){
      printf("アドレスを解決できません\n");
    }
  if((getnameinfo(res0->ai_addr,res0->ai_addrlen,rbuf,sizeof(rbuf),sbuf,sizeof(sbuf),NI_NUMERICHOST | NI_NUMERICSERV)) != 0){
    printf("名前解決に失敗しました\n");
    exit(1);
  }

  if((soc = socket(res0->ai_family,res0->ai_socktype,res0->ai_protocol)) < 0){
    printf("ソケットの作成に失敗\n");
    exit(1);
  }

  opt = 1;
  opt_len = sizeof(opt);
  if((setsockopt(soc,SOL_SOCKET,SO_REUSEADDR,&opt,opt_len)) < 0){
    printf("ソケット作成に失敗しました\n");
    close(soc);
    freeaddrinfo(res0);
    exit(1);
  }
  if((bind(soc,res0->ai_addr,res0->ai_addrlen))<0){
    printf("bind error\n");
    close(soc);
    freeaddrinfo(res0);
    exit(1);
  }
  if(listen(soc,SOMAXCONN) < 0){
    printf("listen error\n");
    close(soc);
    freeaddrinfo(res0);
    exit(1);
  }
  freeaddrinfo(res0);
  return soc;
}
