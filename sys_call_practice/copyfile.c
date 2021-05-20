#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
		int f1,f2,cnt;
		char ch[1204];
		if(argc < 3)
		{
				perror("Invalid arguments");
				_exit(1);
		} 
		f1 = open(argv[1],O_RDWR);
		if(f1 < 0)
		{
				perror("cannot open source file");
				_exit(2);
		}
		f2 = open(argv[2],O_CREAT | O_APPEND |O_RDWR,0644);
		if(f2 < 0)
		{
				perror("cannot open destination file");
				_exit(3);
		}
		while((cnt = read(f1,&ch,512))>0)
				{
					write(f2,&ch,cnt);
				}

		close(f1);
		close(f2);
		return 0;
}

