#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <semaphoresyscall.h>

void askQuestion(int studentNbr)
{
	sem_down(1);
	printf("student %d: ask question\n", studentNbr);
	sleep(4);
	printf("student %d: leave room\n", studentNbr);
}

int main(int argc, char **argv)
{
	pid_t pids[100];
	int i;
	int n = atoi(argv[1]);;

	
	for (i = 1; i <= n; ++i) {
	  if ((pids[i] = fork()) < 0) {
		perror("fork");
		abort();
	  } else if (pids[i] == 0) {
		sleep(2);
		askQuestion(i);
		exit(0);
	  }
	}

	
	int status;
	pid_t pid;
	while (n > 0) {
	  pid = wait(&status);
	 // printf("Child with PID %ld exited with status 0x%x.\n", (long)pid, status);
	  --n;  // TODO(pts): Remove pid from the pids array.
	}
	sem_release(1);
}