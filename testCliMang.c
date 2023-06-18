#include <stdio.h> /*printf, NULL*/
#include <string.h>
#include <errno.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <arpa/inet.h>
#include "clientNet.h"/*client functions decleration*/
#include "clientMng.h"/*client Manager functions decleration*/
#define CLIENT_PORT 1025
#define IP_ADDRESS ("192.168.1.246")


int main(void)
{
    ClientManager* ptrClientManager;
    ptrClientManager = ClientManagerCreate(CLIENT_PORT, IP_ADDRESS);
    ClientManagerDestroy(&ptrClientManager);

    printf("Create Client Manager!\n");
    return 0;
}

