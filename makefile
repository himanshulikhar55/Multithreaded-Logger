logger: logger.c test_logger.c
	gcc -o logger logger.c test_logger.c -pthread