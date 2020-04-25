#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#define MAX 80
#define PORT 8080
#define SA struct sockaddr

struct directory
{
    char dname[1000];
    char access[10];
    int filescount;
    int dircount;

    struct directory *next; //to point it to the next object of directory
};

struct filelist
{
    char fname[1000];
    int fsize;
    char access[10];

    struct filelist *next;
};

void func(int sockfd)
{
    char buff[MAX];
    int n;
    for (;;)
    {                              //infinite loop
        bzero(buff, sizeof(buff)); // initializing buff to 0
        printf("Enter the string : ");
        n = 0;
        while ((buff[n++] = getchar()) != '\n') //Until enter is pressed, store whatever is being typed in the buffer
            ;
        write(sockfd, buff, sizeof(buff)); //to send whatver is in the buffer to server
        bzero(buff, sizeof(buff));         //intialize buffer to 0
		while (1)
		{
			read(sockfd, buff, sizeof(buff));  //receive the message from server and store it in buffer
			buff[strlen(buff)-1]='\0';
			if (strcmp(buff,"End") == 0)
			{
				break;
			}
			else{
				printf("%s \n", buff);
			}
		}
    }
}

int main()
{
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;

    // socket create and varification
    sockfd = socket(AF_INET, SOCK_STREAM, 0); //these paramteres must be same as of the server in order of successful connection with the server.
    if (sockfd == -1)
    {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr)); //intializing servaddr

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    // connect the client socket to server socket
    if (connect(sockfd, (SA *)&servaddr, sizeof(servaddr)) != 0)
    {
        printf("connection with the server failed...\n");
        exit(0);
    }
    else
        printf("connected to the server..\n");

    char password[100];
    int n =0;
    printf("Enter a password: ");
    while ((password[n++] = getchar()) != '\n'); //Until enter is pressed, store whatever is being typed in the buffer
        
    write(sockfd, password, sizeof(password)); //to send whatver is in the buffer to server
    bzero(password, sizeof(password));         //intialize buffer to 0
    int m = read(sockfd, password, sizeof(password));
    
    if(strcmp(password,"Success") == 0){
        printf("Successful \n");
        func(sockfd);
    }
    else{
        printf("Wrong Password");
    }

    close(sockfd);
}