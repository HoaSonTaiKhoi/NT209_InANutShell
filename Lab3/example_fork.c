/*######################################
# University of Information Technology #
# IT007 Operating System #
# <Võ Nhật Hoàng>, <22520481> #
# File: example_fork.c #
######################################*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	pid_t pid;
	pid=fork();

	if(pid==0)
		printf("Child Process, pid=%d\n",pid);
	else
		printf("Parent Process, pid=%d\n",pid);
exit(0);
}
