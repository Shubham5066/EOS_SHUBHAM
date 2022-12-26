#include<stdio.h>
#include <sys/stat.h>

#include<sys/types.h>
#include<unistd.h>
#include <fcntl.h>
int main(void)
{
    int fd=0;
    fd=open("/usr/include/stdio.h",O_WRONLY);
    write(fd,"HELLO SHUBHA\n",12);
    close(fd);
    return 0;


}
