#include <stdio.h>
#include <unistd.h>

int main()
{
		int i;
		pid_t pid;

		pid=fork();
		if(pid==0)
		{
				for(i=0;i<10;i++)
				{
						printf("CHILD:%d\n",i);
						sleep(1);
				}
		}
		else
		{

				for(i=0; i>-10; i--)
				{

						printf("PARENT:%d\n",i);
						sleep(1);
				}
		}
}

