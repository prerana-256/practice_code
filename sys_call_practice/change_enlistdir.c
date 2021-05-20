#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc,char *argv[])
{
		struct dirent *de;
		struct stat st;
		DIR *dp;
		int err;
		char str[512];
		if(argc != 2)
		{
				fprintf(stderr,"Invalid arguments.\nSyntax :%s <dirpath>\n",argv[0]);
				_exit(1);
		}

		dp = opendir(argv[1]);
		if(dp==NULL)
		{
				perror("failed to open dir");
				_exit(2);
		}

		err = chdir(argv[1]);
		if(err<0)
		{
				perror("failed to change dir");
				_exit(3);
		}

		printf("changed to dir: %s \n",getcwd(str,512));

		while((de=readdir(dp))!=NULL)
		{
				printf("%lu\t%lu\t%s\n",de->d_ino,st.st_size,de->d_name);
		}
		closedir(dp);
		return 0;

}

