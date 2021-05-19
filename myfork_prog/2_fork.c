#include<stdio.h>
#include<unistd.h>

/*distinguish between child and parent process*/

int main()
{
		pid_t pid;
		printf("processing!\n");
		pid=fork();
		if(pid==0)
		{
				printf("1st CHILD\n");
				sleep(1);
		}
		else if(pid>0)
		{
				pid=fork();
				if(pid==0)
				{
						printf("2nd CHILD\n");
						sleep(1);
				}

				else if(pid>0)

				{
						pid=fork();

						if(pid==0)
						{
								printf("3rd CHILD\n");
								sleep(1);
						}
				}
		}
		printf("PARENT\n");
		sleep(1);
		printf("end!\n");
		sleep(1);



		return 0;

}



