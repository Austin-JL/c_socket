#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	char *ip = argv[1];
	int port = atoi(argv[2]);
	char *client_name = argv[3];
	int sock = 0, valread;
	struct sockaddr_in serv_addr;
	char *hello = " : Hello from client";
	char *msg =strcat(client_name, hello);
	char buffer[1024] = {0};
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);

	// Convert IPv4 and IPv6 addresses from text to binary form
	if (inet_pton(AF_INET, ip, &serv_addr.sin_addr) <= 0)
	{
		printf("\nInvalid address/ Address not supported \n");
		return -1;
	}

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}
	for (;;)
	{
		send(sock, msg, strlen(msg), 0);
		printf("Hello message sent\n");
		valread = read(sock, buffer, 1024);
		printf("%s\n", buffer);
		sleep(1);
	}
	return 0;
}
