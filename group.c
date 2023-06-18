#include <arpa/inet.h>
#include <string.h> /*strings*/
#include <stdlib.h>
#include "group.h"

struct Group
{
    char        m_groupName[GROUP_NAME_SIZE]; /*the key for the Q*/
    char        m_groupPort[PORT_SIZE];/*4-5 let can be deffine*/
    char        m_groupIP[IP_SIZE];
    int         m_GroupUserscounter; /*active users in thr group at the moment(1 - in the creation)*/ 
    int         m_magicNum;
};

Group* GroupCreate (char* _groupName, char* _port/*same to all*/, char* _addressIP)
{
    Group* newGroup;
    if (NULL == _groupName || NULL == _port || 0 == _addressIP)
    {
        return NULL;
    }
    if (NULL == (newGroup =(Group*)malloc(sizeof(Group))))
    {
        return NULL;
    }
    strcpy(newGroup-> m_groupName, _groupName);
    strcpy(newGroup-> m_groupPort, _port);
    strcpy(newGroup-> m_groupIP, _addressIP);
    newGroup-> m_GroupUserscounter = 1;
    newGroup-> m_magicNum = MAGIC_NUM;
    return newGroup;
}
/*********************************************************/
void GroupDestroy(void* _group)
{
    Group* curGroup = (Group*)_group;
    if (NULL == curGroup || MAGIC_NUM != curGroup -> m_magicNum) 
	{
	    return;
	}

    curGroup->m_magicNum = 0;
    free(curGroup);
}
/*********************************************************/
GroupResultCode IncreasNumOfGroupUsers(Group* _group)
{
    if (NULL == _group )
    {
        return GROUP_FAIL;
    }
    _group-> m_GroupUserscounter += 1;
    return GROUP_SUCCESS;
}
/*********************************************************/
GroupResultCode GroupGetIPAddress(Group* _group, char* _addressIP)
{
   if (NULL == _group || NULL == _addressIP)
    {
        return GROUP_FAIL;
    }
   strcpy(_addressIP, _group-> m_groupIP);
    _addressIP[strlen(_group-> m_groupIP)] = '\0';
   return GROUP_SUCCESS;
}
/*********************************************************/
GroupResultCode GroupGetPort(Group* _group, char* _port)
{
   if (NULL == _group || NULL == _port)
    {
        return GROUP_FAIL;
    }
   strcpy(_port, _group-> m_groupPort);
   _port[strlen(_group-> m_groupPort)] = '\0';
   return GROUP_SUCCESS;
}

GroupResultCode DecreasNumOfGroupUsers(Group* _group)
{
    if (NULL == _group)
    {
        return GROUP_NOT_INITIALIZED;
    }
    if (_group-> m_GroupUserscounter == 0)
    {
        return GROUP_IS_EMPTY;
    }
    if (_group-> m_GroupUserscounter == 1)
    {
        _group-> m_GroupUserscounter = 0;
        return GROUP_IS_EMPTY;
    }   
    _group-> m_GroupUserscounter -= 1;
    return GROUP_SUCCESS;
}
/*********************************************************/
int GroupGetNumOfUsers(Group* _group)
{
   return _group-> m_GroupUserscounter;
}
/*********************************************************/
GroupResultCode GroupGetGroupName(Group* _group, char* _groupName)
{
    if (NULL == _group || NULL == _groupName)
    {
        return GROUP_FAIL;
    }
   strcpy(_groupName, _group-> m_groupName);
   _groupName[strlen(_group-> m_groupName)] = '\0';
   return GROUP_SUCCESS;
}