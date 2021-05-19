#include<stdio.h>
#include<unistd.h>

//zombie process program

int main()
{
		int i;
		pid_t pid;
		pid=fork();
		if(pid==0)
		{
				for(i=0;i<20;i+=2)
				{
						printf("Child:%d\n",i);
						sleep(1);
				}
		}
		else
		{
				for(i=1;i<20;i++)
				{
						printf("Parent:%d\n",i);
						sleep(1);
				}
		}
		return 0;
}
