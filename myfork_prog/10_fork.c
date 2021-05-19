#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
		int i,fd,cnt=1;
		pid_t pid;
		char *c="hello world!\n";
		char *s="how r u all?\n";

		pid=fork();
		if(pid==0)
		{
				fd=open("./file1.txt",O_CREAT | O_APPEND | O_RDWR,0644);
				for(i=0;i<10;i++)
				{
						write(fd,c,strlen(c));
						sleep(1);
				}
		}
		else
		{
				fd=open("./file1.txt",O_CREAT | O_APPEND | O_RDWR,0644);
				for(i=0;i<10;i++)
				{
						write(fd,s,strlen(s));
						sleep(1);
				}

		}
		close(fd);
		return 0;
}






