#include  <unistd.h>
#include  <stdio.h>
#include  <sys/types.h>

#define   MAX_COUNT  200

void  ChildProcess(void);                
void  ParentProcess(void);            

void  main(void)
{
		pid_t pid;

		pid = fork();
		if (pid == 0) 
				ChildProcess();
		else 
				ParentProcess();
}

void  ChildProcess(void)
{
		int   i;

		for (i = 1; i <= MAX_COUNT; i++)
				printf("   This line is from child, value = %d\n", i);
		printf("   *** Child process is done ***\n");
}

void  ParentProcess(void)
{
		int   i;

		for (i = 1; i <= MAX_COUNT; i++)
				printf("This line is from parent, value = %d\n", i);
		printf("*** Parent is done ***\n");
}
