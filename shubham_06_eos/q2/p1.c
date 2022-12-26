#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<unistd.h>
#include<string.h>

#define MAX 50

struct my_msg{

    long int msg_type;
    char some_text[MAX];
};

int main()
{
    int running=1;
    char buff[MAX];
    struct my_msg some_data;
    int msgid;
    msgid=msgget((key_t)1234,0666|IPC_CREAT);
    if(msgid==-1)
    {
        printf("Queue is not created errror\n");
    }
    else
    {
        printf("\nEnter a some text:-");
        fgets(buff,20,stdin);
        some_data.msg_type=1;
        strcpy(some_data.some_text,buff);
        if(msgsnd(msgid,(void*)&some_data,MAX,0)==-1)
        {
            printf("MSG SEND Error\n");
        }
        if(strncmp(buff,"end",3)==0)
        {
            running=0;
        }
    }
}
