# Linux-Shell


The shell program handles all the internal commands whereas for the external commands, separate programs have been written.


Commands that can be taken by the system:

1)cd -which changes the directory

	- .. is used to go to the previous directory
	- --help to show help regarding the execution

2)pwd -which shows the present working directory

		-P prints the value pf $PWD if it names the current working directory (default pwd behaves like this)
		--help to get help regarding the execution

3)exit -which exites the process
	
	   -[n]	exits the process with exit status n
	   --help to get help regarding the execution

4)echo -prints the line written after it

		-n [string] ignores the end line character
		-e [string] evaluates \n and moves to a new line. 

5)history - prints the history list for all the sessions
		-c clears the history list
		-[n] prints the last n commands

6)ls - lists all the files and folders in the directory

	-a prints hidden files also(starting with . or ..)
	-d [name] prints only the name of the directory	

7)cat - reads a file and prints the contents

	  -n numbers the output lines
	  -b numbers only non empty lines

8)date - prints the current system time and date

		-d [string] prints string instead of the current time
		- I prints the date in ISO format

9)rm [file]- removes the file from the directory

	-i [file] prompts the user before deleting the file
	-f [file] no error message is printed even if file is not present in the directory

10)mkdir [file] - make a new file or directory
			
			-v [file] prints the message that file has been created
			-p doesnt show error if file already exists or makes parent directories for children



ASSUMPTIONS

-> There is an external file(counter.txt) for deciding the line number in each session of the process. The history file(text.txt) is also there which contains the history of all the sessions. Both these files will be present on the desktop.

->direc.txt is stored on the desktop to save the current working directory.

->The readable file to show the execution of the cat command (read.txt) is also present on the desktop.
-> remove.text is included in the submission to show rm command and hola folder is included to show cd command.
-> Text files for commands with --help flag are also included (except for exit).

Error Handling: (Only errors essential to personalised shell are handled.)

- In pwd command, error is handled when current directory cant be accessed and NULL is returned.
-In history command, if there is a problem opening the history list, error is reported. This error is also checked in changCounter(), getCounter() and other functions which require file handling.
-In the ls command, if the directory is null(which can't be found), error is reported.
-In the cat command, if the file can't be read, error is reported.
-In the rm command, errors are handled when the file does not exist in the directory or if a directory itself is being removed if -f flag is not set
-In the mkdir command, errors are handled when the parent directory doesn't exist and when the file already exists in the directory.
Overall, error is handled in the internalC function where if the pid returned is less than 0, the child couldnt be cloned. If the execvp system call returns -1; error is reported that the process couldn't get executed. wait system call is used when pid>0 where the parent waits for the child to terminate the process. In the tokenise() function, error is handled when none of the commands entered are valid according to this personalised shell.


