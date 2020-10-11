#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>

int main(int argc, char* argv[]) {
	int tcp_socket = socket(AF_INET, SOCK_STREAM, 0);
	printf("%i\n", tcp_socket);
	return 0;
}
