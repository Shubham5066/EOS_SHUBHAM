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
    char buff[20];
    struct my_msg some_data;
    int msgid;
    int i=0;
    int count=0;
    long  int msg_to_rec=0;
    msgid=msgget((key_t)1234,0666|IPC_CREAT);
    if(msgid==-1)
    {
        printf("Queue is not created errror\n");
    }
    else
    {
        
        msgrcv(msgid,(void *)&some_data,MAX,msg_to_rec,0);
        printf("\nRecieved :-%s\n",some_data.some_text);
        strcpy(buff,some_data.some_text);
        printf("\nBUff=%s\n",buff);
        while(buff[i]!='\0')
        {
            if(buff[i]=='s')
            {
                count++;
                
            }
              printf("\ncount=%d",count);
        }
        printf("Recieved:-%s\n total s=%d\n",some_data.some_text,count);
        if(strncmp(some_data.some_text,"end",3)==0)
        {
            running=0;
        }
        msgctl(msgid,IPC_RMID,0);
    }
}
