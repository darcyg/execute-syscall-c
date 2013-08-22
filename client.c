/*
	Simple udp client
	Silver Moon (m00n.silv3r@gmail.com)
*/
#include<stdio.h>	//printf
#include<string.h> //memset
#include<stdlib.h> //exit(0);
#include<arpa/inet.h>
#include<sys/socket.h>

#define PORT 25588

int main(void)
{
	struct sockaddr_in si_other;
	int s, i, slen=sizeof(si_other);
	char * message;

	s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	memset((char *) &si_other, 0, sizeof(si_other));
	si_other.sin_family = AF_INET;
	si_other.sin_port = htons(PORT);
	
	inet_aton("127.0.0.1" , &si_other.sin_addr);

	message = "savvas";
		
	sendto(s, message, strlen(message)+1 , 0 , 
	       (struct sockaddr *) &si_other, slen);
	return 0;
}
