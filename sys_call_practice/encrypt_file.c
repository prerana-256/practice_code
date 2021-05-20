#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{
		int fd_src,fd_dest,cnt;
		char ch;
		if(argc<3)
		{
				perror("Invalid arguments");
				_exit(1);
		}
		fd_src=open(argv[1],O_RDWR);
		if(fd_src<0)
		{
				perror("cannot open source file");
				_exit(2);
		}
		fd_dest=open(argv[2],O_CREAT | O_TRUNC | O_RDWR, 0644);
		if(fd_dest<0)
		{
				perror("cannot open destination file");
				_exit(3);
		}
		while((cnt=read(fd_src,&ch,1))>0)
		{
				ch=ch+1;
				
				write(fd_dest,&ch,cnt);

		}
		close(fd_src);
		close(fd_dest);
		return 0;
}

