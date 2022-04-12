/*

STEP 1: Create UDP socket
        - How to create a socket? Use socket()?
STEP 2: Bind socket to server address
        - How do we get the server address?
STEP 3: Wait (loop) until client's datagram packet arrives
STEP 4: Process datagram packet and send reply to client

*/


#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <errno.h>

#define GETSOCKETERRNO() (errno)

int main()
{
    char message[2000];

    //Create socket:
    int my_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    //Initialize server address (loopback)
    struct sockaddr_in ina_listener, ina_client;
    ina_listener.sin_family = AF_INET;
    ina_listener.sin_port = htons(2000);
    ina_listener.sin_addr.s_addr = inet_addr("127.0.0.1");
    int flags=0;
    int ina_listener_size = sizeof(ina_listener);
    int ina_client_size = sizeof(ina_client);

    //Bind to port and IP
    bind(my_socket, (struct sockaddr*)&ina_listener, sizeof(ina_listener));

    printf("Status: %s\n", strerror(errno));

    printf("Listening...\n");

    printf("Status: %s\n", strerror(errno));
    //Revieve any incoming messages
    if (recvfrom(my_socket, message, sizeof(message), flags, (struct sockaddr*)&ina_client, 
                  &ina_client_size) < 0) {
        printf("Failed to recieve message\n");
        return -1;
                  }

    printf("Client says: %s", message);

    char reply[2000] = "Message recieved";

    //Send reply
    if (sendto(my_socket, reply, strlen(reply), flags, (struct sockaddr*)&ina_client,
        ina_client_size) < 0) {
            printf("Failed to send reply\n");
            printf("The last error message is: %s\n", strerror(errno));
            return -1;
        }

    //Close socket
    close(my_socket);
}
