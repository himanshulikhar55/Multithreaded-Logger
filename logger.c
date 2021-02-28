#include "logger.h"
void call_make_log(char *log_level, int thread_id, char *message, char const *function_name, char const *filename){
	time_t rawtime;
	struct tm * timeinfo;
	time (&rawtime);
	timeinfo = localtime (&rawtime);
	char *timestamp = asctime(timeinfo);
	timestamp[strcspn(timestamp, "\n")] = '\0';
	insert_log(timestamp, log_level, filename, function_name, thread_id, message);
}
void init_mut(char *filename, int file_id){
	key_t key = ftok(filename,file_id); 
  
		// shmget returns an identifier in shmid
		int shmid = shmget(key,sizeof(pthread_mutex_t),0666|IPC_CREAT);

		// shmat to attach to shared memory 
		pthread_mutex_t *lock_ptr = (pthread_mutex_t*) shmat(shmid,0,0);
		pthread_mutexattr_t attrmutex;

		/* Initialise attribute to mutex. */
		pthread_mutexattr_init(&attrmutex);
		pthread_mutexattr_setpshared(&attrmutex, PTHREAD_PROCESS_SHARED);
		/* Initialise mutex. */
		pthread_mutex_init(lock_ptr, &attrmutex);
		shmdt(lock_ptr);
}
void open_file(char *filename, int file_id){
	
	int len = 4096 + strlen(filename);
	char cwd[len];
	
	if(getcwd(cwd, sizeof(cwd)) == NULL)
		perror("getcwd() error");
	
	strcat(cwd,filename);
	if(access( cwd, F_OK ) == 0)
		fp = fopen(cwd,"a");
	else{
		fp = fopen(cwd,"w");
		init_mut(filename, file_id);
	}
}
void insert_log(char *timestamp, char *log_level, char const *filename, char const *function_name, int thread_id, char *message){
   	open_file("/platform9.log", 65);
	if (fp){
		// printf("FIRST\n");
		key_t key = ftok("platform9.log", 65);
		// shmget returns an identifier in shmid
		int shmid = shmget(key,sizeof(pthread_mutex_t),0666|IPC_CREAT);

		// shmat to attach to shared memory
		pthread_mutex_t *lock_ptr = (pthread_mutex_t*) shmat(shmid,0,0);
		// printf("SECOND\n");

		pthread_mutex_lock(lock_ptr);
		// printf("HERE!\n");

		fprintf(fp, "%s %s %s %s %d %s\n", timestamp, log_level, filename, function_name, thread_id, message);
		fclose(fp);
		printf("Your message has been logged into the log file!\n");

		pthread_mutex_unlock(lock_ptr);
		//detach from shared memory
		shmdt(lock_ptr);
	}
	else
		printf("Unable to open file\n");
}
