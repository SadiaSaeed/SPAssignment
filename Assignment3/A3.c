#include <stdio.h> 
#include <string.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <errno.h> 
#include <netdb.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 

void main() {
 
 //Question1
    char IPc[16];

    fgets(IPc, 16, stdin);
    struct in_addr ip; 
    ip.s_addr = inet_addr(IPc); //inet_addr returns an unsigned integer when you enter the IP address

    printf("4-byte unsigned integer: %u \n", ip.s_addr);

    char *IP;
    IP = inet_ntoa(ip);//returns the IP address coresponding to the unsigned integer

    printf("IP address: %s \n", IP);



//Question#2

char hostbuffer[256];
char *IPbuffer;
struct hostent *host_entry;

int hostname;

hostname = gethostname(hostbuffer, sizeof(hostbuffer)); //extracts your computer's host name and save it into hostbuffer

if (hostname == -1)
{
    perror("Hostname: ");
    exit(-1);
}

host_entry = gethostbyname(hostbuffer);//it stores host IP, Network address and subnet mask 

if (host_entry == NULL)
{
    perror("Host_Entry: ");
    exit(-1);
}

IPbuffer = inet_ntoa(*((struct in_addr*)
                        host_entry->h_addr_list[0]));

printf("Hostname: %s\n", hostbuffer);
printf("Host IP: %s\n", IPbuffer);





}