#include <stdio.h>
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 
  
// Function designed for chat between client and server. 
void func(int sockfd) 
{ 
    char buff[MAX]; 
    int n; 
    // infinite loop for chat 
    for (;;) { 
        bzero(buff, MAX); 
  
        // read the message from client and copy it in buffer 
        read(sockfd, buff, sizeof(buff)); 
        // print buffer which contains the client contents 
        printf("From client: %s\t To client : ", buff); 
        bzero(buff, MAX); 
        n = 0; 
        // copy server message in the buffer 
        while ((buff[n++] = getchar()) != '\n') 
            ; 
  
        // and send that buffer to client 
        write(sockfd, buff, sizeof(buff)); 
  
        // if msg contains "exit" then server exit and chat ended.

        int len = strlen(buff);

        buff[len-1] = '\0';
        if (strcmp(buff, "exit") == 0) { 
            printf("Server Exit...\n"); 
            break; 
        } 
    } 
} 
  
// Driver function 
int main() 
{ 
    int sockfd, connfd, len; 
    struct sockaddr_in servaddr, cli; //Created two objects of sockaddr_in
  
    // socket create and verification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); //sock_stream is used for real time communication, AF_INET??, 0 is used for default protocol 
    if (sockfd == -1) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 
    bzero(&servaddr, sizeof(servaddr)); //function to initialize the object servaddr
  
    // assign IP, PORT 
    servaddr.sin_family = AF_INET; //storing the host id
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); //assigns the address
    servaddr.sin_port = htons(PORT); //specifies the port to connect to
  
    // Binding newly created socket to given IP and verification 
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { //binds a socket to an address, in this case the address of the current host and port number on which the server will run.
        printf("socket bind failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully binded..\n"); 
  
    // Now server is ready to listen and verification 
    if ((listen(sockfd, 5)) != 0) { //it allows the process to listen on the socket for connections. At max 5 connection request can be catered by the server at a time. 
        printf("Listen failed...\n"); 
        exit(0); 
    } 
    else
        printf("Server listening..\n"); 
    len = sizeof(cli); 
  
    // Accept the data packet from client and verification 
    connfd = accept(sockfd, (SA*)&cli, &len); 
    if (connfd < 0) { 
        printf("server accept failed...\n"); 
        exit(0); 
    } 
    else{
        printf("Awaiting Authentication... \n");
        char auth[100];
        bzero(auth, sizeof(auth)); 
        read(connfd, auth, sizeof(auth));
        auth[strlen(auth)-1] ='\0'; 
        
        if(strcmp(auth,"12345")==0){
            printf("server accept the client...\n");
            write(connfd,"Success", sizeof("Success"));
            func(connfd);
        }
        else
        {
            printf("Authentication Unsuccesful \n");
        }
        
    }  
    // After chatting close the socket 
    close(sockfd); 
}