#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
    int fd,cnt;
    char ch[128];
    fd=open("./encrypt.c",O_CREAT | O_APPEND | O_RDWR);
    if(fd<0)
    {
        perror("failed to open src file");
        _exit(1);
    }
    cnt=read(fd,&ch,128);
    while((cnt=read(fd,&ch,128))>0)
    {
        write(STDOUT_FILENO,&ch,cnt);
    }

    close(fd);

    return 0;
}
