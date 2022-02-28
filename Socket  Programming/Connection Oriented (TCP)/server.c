#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>


int main(){
	char *ip = "127.0.0.1";
	int port = 1234;
	
	int server_sock, client_sock;
	
	struct sockaddr_in server_addr, client_addr;
	socklen_t addr_size;
	char buffer[1000];
	
	server_sock = socket(AF_INET,SOCK_STREAM,0);
	
	if(server_sock < 0){
		perror("Socket error/Socket creation failed!!\n");
		exit(0);
	}
	printf("TCP server Socket Created Sucessfully\n");
	
	memset(&server_addr,'\0',sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = port;
	server_addr.sin_addr.s_addr = inet_addr(ip);
	
	int temp;
	temp = bind(server_sock,(struct sockaddr*)&server_addr,sizeof(server_addr));
	
	if(temp < 0){
		perror("Bind failed/Error\n");
		exit(0);
	}
	
	printf("Bind to the port number :: %d\n",port);
	
	listen(server_sock,5);
	
	printf("Listening.....\n");
	
	while(1){
	
		addr_size = sizeof(client_addr);
		client_sock = accept(server_sock,(struct sockaddr*)&client_addr,&addr_size);
		printf("Client Connected \n");
		
		bzero(buffer,1000);
		recv(client_sock,buffer,sizeof(buffer),0);
		printf("Client :: %s\n",buffer);
		bzero(buffer,1000);
		strcpy(buffer,"Hello Client");
		send(client_sock,buffer,strlen(buffer),0);
		printf("Sent Reply/Acknowledgement to Client\n");
		close(client_sock);
		printf("Client Disconnected\n");
		
	}
	
	return 0;
	
	
}
