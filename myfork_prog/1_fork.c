#include<stdio.h>
#include<unistd.h>

//fork() creates copies of process as parent and child

int main()
{
		pid_t pid;
		printf("processing!\n");
		pid=fork();
		printf("fork() returned: %d\n",pid);
		printf("end!\n");
		return 0;
}
