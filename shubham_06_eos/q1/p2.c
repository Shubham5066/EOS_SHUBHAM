#include<stdio.h>
#include <sys/stat.h>

#include<sys/types.h>
#include<unistd.h>
#include <fcntl.h>
int main(void )
{
    int fd=0;
    unsigned char buff[128];
    int count;
    int i;
    fd=open("/usr/include/stdio.h",O_RDONLY);
    read(fd,buff,128);
    printf("Reciever=%s",buff);
    close(fd);
    while(buff[i]!='\0')
    {
        if(buff[i]==0)
        {
            coun++;
        }
        printf("\ncount=%d",count);
    }

    return 0;
}
