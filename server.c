/*
	Simple udp server
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
	struct sockaddr_in si_me, si_other;
	
	int s, i, slen = sizeof(si_other) , recv_len;
	char buf[512];
	
	//create a UDP socket
	s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	
	// zero out the structure
	memset((char *) &si_me, 0, sizeof(si_me));
	
	si_me.sin_family = AF_INET;
	si_me.sin_port = htons(PORT);
	si_me.sin_addr.s_addr = htonl(INADDR_ANY);
	
	//bind socket to port
	bind(s , (struct sockaddr*)&si_me, sizeof(si_me));
	
  recvfrom(s, buf, 512, 0, 
                (struct sockaddr *) &si_other, &slen);

	return 0;
}
