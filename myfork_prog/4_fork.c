#include<stdio.h>
#include<unistd.h>

//orphan process program

int main()
{
		pid_t pid;
		int i;

		pid=fork();

		if(pid==0)
		{
				for(i=0;i<20;i++)
				{
						printf("child:%d\n",i);
						sleep(1);
				}
		}
		else
		{
				for(i=1;i<20;i+=2)
				{
						printf("parent:%d\n",i);
						sleep(1);
				}
		}
		return 0;
}

