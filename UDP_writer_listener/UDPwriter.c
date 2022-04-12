/*

STEP 1: Create UDP socket
        - How to create a socket? Use socket()?
STEP 2: Send message to server/listener
STEP 3: Wait (loop) until server responds
STEP 4: Process reply
STEP 5: Close socket descriptor and exit

*/

/* 
All of the structs we call to are inside one of these header files,
we're just setting variables when we do "struct <struct> var 1, var 2;"   
*/ 
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <errno.h>

#if defined(_WIN32)
#define GETSOCKETERRNO() (WSAGetLastError())
#else
#define GETSOCKETERRNO() (errno)
#endif

int main()
{
    char message[2000], server_message[2000];     // Does these have to be pointers?
    int message_size = sizeof(message);
    int reply_size = sizeof(server_message);
    unsigned int flags=0;

    //Create socket
    // int my_socket = socket(things.ai_family, things.ai_socktype, things.ai_protocol);
    printf("Creating socket...\n");
    int my_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    printf("Status: %s\n", strerror(errno));

    //Initialize server address
    printf("Initializing server address...\n");
    struct sockaddr_in ina_client;   //ina = internet address
    ina_client.sin_family = AF_INET;  //Use IPv4
    ina_client.sin_port = htons(2000);  //Port number (it's gotta be in network order, hence htons()!)
    ina_client.sin_addr.s_addr = inet_addr("127.0.0.1");  //Sets address...apparently this is an old way?
    // ina_client.sin_addr.s_addr = inet_pton(AF_INET, "127.0.0.1", &(ina.sin_addr));
    if (ina_client.sin_addr.s_addr < 0) {
        printf("Error setting address!");
    }
    else if (ina_client.sin_addr.s_addr == 0) {
        printf("Address is messed up!");
    }
    int sockaddr_size = sizeof(ina_client);

    memset(&ina_client.sin_zero, 0, sizeof(ina_client.sin_zero));

    printf("Status: %s\n", strerror(errno));

    //Write message
    printf("Enter a phrase to be sent: ");
    fgets(message, sizeof(message), stdin);
    
    /*
    sendto(<socket file descriptor>, <pointer to message>, <length of message in bytes>,
            <flags=0 I guess?>, <pointer to struct sockaddr (server address)>,
            <size of sockaddr struct?>)
    */
    if (sendto(my_socket, message, strlen(message), flags, (struct sockaddr*)&ina_client,
        sockaddr_size) < 0) {
            printf("Failed to send\n");
            printf("The last error message is: %s\n", strerror(errno));
            return -1;
        }


    //Receive reply from server
    /*
    recvfrom(<socket file descriptor>, <pointer to server reply>, <length of message in
              bytes>, <flags=0 again?>, <server address again>, <size of sockaddr struct?>)
    */
    if (recvfrom(my_socket, server_message, reply_size, flags, (struct sockaddr*)&ina_client, 
        &sockaddr_size) < 0) {
            printf("Error when receiving reply\n");
            printf("The last error message is: %s\n", strerror(errno));
            return -1;
              }

    //What's the response from the server?
    printf("Server response is: %s", server_message);

    //Close socket
    close(my_socket);

    return 0;
}