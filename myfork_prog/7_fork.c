#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

//using exit() check status of zombie process

int main()
{
		int i,status;
		pid_t pid;
		pid=fork();
		if(pid==0)
		{
				for(i=0;i<10;i+=2)
				{
						printf("Child:%d\n",i);
						sleep(1);
				}
				_exit(1);
		}
		else
		{
				for(i=1;i<20;i++)
				{
						printf("Parent:%d\n",i);
						sleep(1);
						if(i==6)
						{
								wait(&status);
								printf("Child exit status:%d\n",WEXITSTATUS(status));
						}
				}
		}
		return 0;
}

