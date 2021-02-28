#include <time.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
FILE * fp;
void insert_log(char *timestamp, char *log_level, char const *filename, char const *function_name, int thread_id, char *message);
void open_file(char *filename, int file_id);
void call_make_log(char *log_level, int thread_id, char *message, char const *function_name, char const *filename);
void init_mut(char *filename, int file_id);
#define make_log(log_level, thread_id, message) call_make_log(log_level, thread_id, message,__FUNCTION__, __FILE__)