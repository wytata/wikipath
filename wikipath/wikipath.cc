#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string>
#include <openssl/ssl.h>

#define MAX_RESPONSE_SIZE 32768

using std::string;

int main (int argc, char *argv[]) {
	int sock = socket(AF_INET , SOCK_STREAM, IPPROTO_TCP);
	if (sock == -1) {
		printf("INVALID SOCKET\n");
		exit(1);
	}

	struct sockaddr_in serverAddr;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(443);
	struct hostent* server = gethostbyname("en.wikipedia.org");
	if (server == NULL) {
		printf("Failed to get server information for en.wikipedia.org");
		exit(1);
	} else {
		memcpy((char*)&serverAddr.sin_addr.s_addr, server->h_addr, server->h_length);
	}

	if (connect(sock, (struct sockaddr*)&serverAddr, sizeof(struct sockaddr_in)) == -1) {
		printf("error on connect");
		exit(1);
	}

	SSL_CTX* sslCtx = SSL_CTX_new(TLS_client_method());
	SSL* ssl =  SSL_new(sslCtx);
	SSL_set_fd(ssl, sock);
	SSL_connect(ssl);
	
	printf("%s\n", inet_ntoa(serverAddr.sin_addr));
	string request = "GET /wiki/Engineering HTTP/1.0\r\nUser-agent: wikipath/1.0\r\nHost: en.wikipedia.org\r\nConnection: close\r\n\r\n";

	SSL_write(ssl, request.c_str(), request.size());
	char response[MAX_RESPONSE_SIZE];
	memset(response, 0, MAX_RESPONSE_SIZE);
	SSL_read(ssl, &response, MAX_RESPONSE_SIZE-1);
	//send(sock, request.c_str(), request.size(), 0);
	printf("%s\n", response);

	//printf("Hello world\n");	
	return 0;
}
