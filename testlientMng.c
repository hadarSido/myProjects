#include <stdio.h> 
#include <string.h>
#include <errno.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h> 
#include <sys/time.h>
#include "clientMng.h"/*client Manager functions decleration*/
#define CLIENT_PORT 1025
#define IP_ADDRESS ("192.168.1.246")

typedef struct Window
{
    int m_firstWindow;
    int m_secendWindow;
}Window;

static void Test1_ClientMngInsertChatPid(void);
int main()
{
    
    Test1_ClientMngInsertChatPid();
   
    
    return 0;
}

static void Test1_ClientMngInsertChatPid(void)
{
	int result;
    Client *ptrClientMng;
    Window* pid;
    pid-> m_firstWindow = 4;
    pid-> m_secendWindow= 5;
    ptrClientMng = ClientManagerCreate(CLIENT_PORT, IP_ADDRESS);
    result = InsertChatPid(ptrClientMng, "g1", pid);
	if(result == MANAGER_SUCCESS)
	{
		printf("%-50s %s", "Test1_ClientMngInsertChatPid","**PASS**\n");
	}
	else
	{
		printf("%-40s %s","Test1_ClientMngInsertChatPid","**FAIL**\n");
	}
	ClientManagerDestroy(&ptrClientMng);
	printf("\n");
}