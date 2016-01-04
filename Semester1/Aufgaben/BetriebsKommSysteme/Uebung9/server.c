#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <ctype.h>

int	process(int connfd);
typedef struct Jungle
{
	char *first,*second;
}Jingle;

Jingle	possibleAnswers[] = 
{
	{"jingle bells,jingle bells,","jingle all the way!"},
	{"stopp",0}
};

int main(int argv, char **argc)
{
	int sockfd, connfd;
	struct sockaddr_in serv_addr;
	int pid = 0;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (sockfd < 0) 
	{
		perror("ERROR opening socket");
		exit(1);
	}

    memset(&serv_addr, 0,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(10000);

	if (bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) 
	{
		perror("ERROR on binding");
		exit(1);
	}

	listen(sockfd,20);


	while(1)
	{
		connfd = accept(sockfd, (struct sockaddr*)NULL, NULL);

		pid = fork();

		if(pid == 0) 
		{
			process(connfd);
			break;
		}
	}
	
	return 0;
}
int	process(int connfd)
{
	int i;
	char buffer[1024];
	printf("Oeffne Socket %i\n",connfd);

    memset(buffer, 0,sizeof(buffer));

	for(i = 0;i < sizeof(possibleAnswers)/sizeof(Jingle);i++)
	{
		strcat(buffer,possibleAnswers[i].first);
		strcat(buffer,"\n");
	}
	int len = write(connfd,buffer,strlen(buffer) + 1);
	while(1)
	{
		int len = read(connfd,buffer,1024);
		if(len == 0 || len == -1) break;

		for(int i = 0; i < len; i++) buffer[i] = tolower(buffer[i]);
		
		if(strcmp("stopp",buffer) == 0) break;
		for(i = 0;i < sizeof(possibleAnswers)/sizeof(Jingle);i++)
		{
			if(strcmp(buffer,possibleAnswers[i].first) == 0)
			{
				printf("%s %s\n",buffer,possibleAnswers[i].second);
				write(connfd,possibleAnswers[i].second,strlen(possibleAnswers[i].second) + 1);
				break;
			}
		}
	}
	
	printf("Schliesse Socket %i\n",connfd);
	close(connfd);
	return 0;
}
