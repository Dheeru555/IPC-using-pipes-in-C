# IPC-using-pipes-in-C
Description:
------------
If a valid command has been entered, the interpreter should fork to create a new process, and the child process will execute the command. This program will support running multiple shell commands at the same time using pipe.

/*Devineni, Sai Dheeraj --- devinenis7463@uhcl.edu ----- ID:1595002-------*/

Compilation Of The Program :
---------------------------
First should give 'gcc' space 'filename' and then enter

Example
-------
gcc DevineniParser.c 

Execution Of The Program :
------------------------
1)Need to give command ./a.out and then enter.
2)After that it will ask to enter the commands, so please enter the commands u want to execute with spaces only in between commands, otherwise it will not work.
3)After completion it will ask to quit--->press 'q' or else press any other character to continue.

Example
-------
./a.out

Dheeraj--->Enter the commands:ls -l | grep smp | wc (Have spaces in between)

Enter q to quit or enter any other letter to continue ('q' to quit or else other key to continue)
