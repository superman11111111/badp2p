#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/time.h>
#include <stdlib.h>
#include <memory.h>
#include <ifaddrs.h>
#include <net/if.h>
#include <stdarg.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <netdb.h>

/*
 * Orienting at https://github.com/bschmaltz/c-p2p-chat/blob/master/peer.c
 *
 * */


int sock;
struct sockaddr_in self_addr;
struct sockaddr_in peer_addr;
pthread_mutex_t stdout_lock;


void * read_input(void *ptr);

int main(int argc, char* argv[]) {

	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock < 0) {
		fprintf(stderr, "%s\n", "error - error creating socket.");
		abort();
	}
	self_addr.sin_family = AF_INET;
	self_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	self_addr.sin_port = 8888;
	
	peer_addr.sin_family = AF_INET;
	inet_aton("127.0.0.1", &peer_addr.sin_addr);
	peer_addr.sin_port = 8888;

	if (bind(sock, (struct sockaddr *)&self_addr, sizeof(self_addr))) {
		fprintf(stderr, "%s\n", "error - binding.");
		abort();
	}

	
	/* receive */
	pthread_t th;
	pthread_create(&th, NULL, read_input, NULL);
	pthread_detach(th);

	printf("workey?\n");
	pthread_exit(NULL);

}

void error(char msg[]) {
	pthread_mutex_lock(&stdout_lock);
	fprintf(stderr, "%s\n", msg); 
	pthread_mutex_unlock(&stdout_lock);
}


void * read_input(void *ptr) {
	char lbuf[256];
	char *p; 
	while (1) {
		memset(lbuf, 0, sizeof(lbuf));
		p = fgets(lbuf, sizeof(lbuf), stdin);
		lbuf[strlen(lbuf)-1] = '\0';
		switch (lbuf[0]) {
			case 'a':
				printf("lol\n");
				break;
			default:
				error("error - request type unknown");
				break;
		}
	}
}


