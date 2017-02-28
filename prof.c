#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <semaphoresyscall.h>

int main(int argc, char **argv)
{
	int i=1, noOfStudents = atoi(argv[1]);
	sem_init(1,0);
	sleep(5);
	while( i <= noOfStudents)
	{
		sem_up(1);
		sleep(3);
		printf("prof: answer question\n");
		sleep(1);
		i++;
	}
	return 0;
}
