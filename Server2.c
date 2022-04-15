#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<stdlib.h>

int main(){
int sockfd,retval,n;
socklen_t clilen;
struct sockaddr_in cliaddr,servaddr;
char buf[10000];
sockfd=socket(AF_INET,SOCK_DGRAM,0);
if(sockfd<0){
perror("sock:");
exit(1);
}

bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(8000);

retval=bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
if(retval<0){
perror("bind: ");
exit(2);
}
//listen(listfd,5);
printf("Socket Bound to Port 8000 is:-\n");
clilen=sizeof(struct sockaddr_in);
while(1){
printf("Before recv from is:-\n");
n=recvfrom(sockfd,buf,10000,0,(struct sockaddr *)&cliaddr,&clilen);
printf("Client Connected is\n");
printf("received bytes = %d\n",n);
buf[n]='\0';
printf("Msg from The Client is = %s\n",buf);

}



return 0;
}
