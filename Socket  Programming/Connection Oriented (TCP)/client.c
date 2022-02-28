#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>


int main(){
	char *ip = "127.0.0.1";
	int port = 1234;
	
	int sock;
	
	struct sockaddr_in addr;
	socklen_t addr_size;
	char buffer[1000];
	
	sock = socket(AF_INET,SOCK_STREAM,0);
	
	if(sock < 0){
		perror("Socket error/Socket creation failed!!\n");
		exit(0);
	}
	printf("TCP server Socket Created Sucessfully\n");
	
	memset(&addr,'\0',sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = port;
	addr.sin_addr.s_addr = inet_addr(ip);
	
	connect(sock,(struct sockaddr*)&addr,sizeof(addr));
	printf("Connected to Server Sucessfully!!\n");
	
	bzero(buffer,1000);
	strcpy(buffer,"Hi Server");
	printf("Client msg :: %s\n",buffer);
	send(sock,buffer,strlen(buffer),0);
	
	bzero(buffer,1000);
	recv(sock,buffer,sizeof(buffer),0);
	printf("Server msg :: %s\n",buffer);
	
	close(sock);
	printf("Disconnected from the server!!!\n");
	
	return 0;
	
}
