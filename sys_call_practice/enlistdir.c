#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>         
#include <sys/stat.h>        
#include <fcntl.h> 

int main(int argc,char *argv[])
{
		struct dirent *de;
		DIR *dp;
		if(argc != 2)
		{
				perror("invalid arguments.");
				_exit(1);
		}

		dp = opendir(argv[1]);
		if(dp==NULL)
		{
				perror("failed to open directory");
				_exit(2);
		}

		while((de=readdir(dp))!= NULL)
		{
				printf("%lu\t%s\n",de->d_ino,de->d_name);

		}

		closedir(dp);

		return 0;

}

