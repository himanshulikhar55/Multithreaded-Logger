#include "logger.h"
int main(){
	//Just to generate random log_level
	srand(time(NULL));
	char level[3][6] = {"DEBUG", "INFO", "ERROR"};
	int index = (rand() % 3);
	char *log_level = level[index];
	// printf("%d\n", index);
	//User process just needs to give this and log_level
	char *message = "TESTING!";
	int thread_id = gettid();
	make_log(log_level, thread_id, message);
	return 0;
}
