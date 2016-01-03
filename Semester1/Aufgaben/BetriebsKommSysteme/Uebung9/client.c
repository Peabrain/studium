#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argv, char **argc)
{
    int sockfd = 0;
    char buffer[1024];
    struct sockaddr_in serv_addr; 

	printf("Client\n");
	printf("======\n");
	if(argv == 2)
	{
	}
	
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Error : Could not create socket \n");
        return 1;
    } 

    memset(buffer, 0, sizeof(buffer)); 
    memset(&serv_addr, 0, sizeof(serv_addr)); 

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(10000); 

    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printf("\n inet_pton error occured\n");
        return 1;
    } 

    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
       printf("\n Error : Connect Failed \n");
       return 1;
    } 

	printf("Moegliche Eingaben:\n");
	int len = read(sockfd,buffer,1024);
	printf("%s",buffer);


	while(1)
	{
		printf("Eingabe Bitte: ");fgets(buffer,1024,stdin);
		buffer[strlen(buffer)-1] = 0;
		int len = write(sockfd,buffer,strlen(buffer) + 1);
		if(len == 0 || len == -1) break;
		if(strcmp("stopp",buffer) == 0) break;
		read(sockfd,buffer,1024);
		printf("%s\n",buffer);
	}
	close(sockfd);

	return 0;
}
