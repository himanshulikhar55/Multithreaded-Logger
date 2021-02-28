The folder has 5 files:
a) logger.h
b) logger.c
c) test_logger.c
d) makefile
e) readme.md
----------------------------------------------------------------------------------------------------------------------------------------------

The description of files is as follows:

a) logger.h: 	  This file contains the function & variable declarations.

b) logger.c: 	  This file contains the implementation of the functions declared in logger.h.

c) test_logger.c: This file is made to test the logger module.

d) makefile: 	  Compiles the code.

e) readme.md: 	  Describes the contents of the zip file.
----------------------------------------------------------------------------------------------------------------------------------------------

How does the code work?

The main file calls the make_log() function. This function calls the main logging function and then opens the log file, locks it, makes the log and releases the lock.
----------------------------------------------------------------------------------------------------------------------------------------------

Features Not Implemented

The program currently does not implement rotation. The log file will keep on increasing in size.
----------------------------------------------------------------------------------------------------------------------------------------------
