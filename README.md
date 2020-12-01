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


SAMPLE TEST CASE:


harman@ubuntu:~/Desktop/Assignment_1.2$ make
gcc cat.c -o cat
gcc date.c -o date
gcc ls.c -o ls
gcc mkdir.c -o mkdir
gcc rm.c -o rm
gcc linux.c -o linux
./linux
harman@ubuntu: $ /home/harman/Desktop/Assignment_1.2 >>>  cd hola
harman@ubuntu: $ /home/harman/Desktop/Assignment_1.2/hola >>>  cd ..
harman@ubuntu: $ /home/harman/Desktop/Assignment_1.2 >>>  cd --help
cd: cd [dir]
    Change the shell working directory.
    
    Change the current directory to DIR.  The default DIR is the value of the
    HOME shell variable.
    
    The variable CDPATH defines the search path for the directory containing
    DIR.  Alternative directory names in CDPATH are separated by a colon (:).
    A null directory name is the same as the current directory.  If DIR begins
    with a slash (/), then CDPATH is not used.
    
    If the directory is not found, and the shell option `cdable_vars' is set,
    the word is assumed to be  a variable name.  If that variable has a value,
    its value is used for DIR.
    
    Options:
      ..  moves to the previous directory

      --help shows help regarding the command
    
    
    Exit Status:
    Returns 0 if the directory is changed; non-zero otherwise.
harman@ubuntu: $ /home/harman/Desktop/Assignment_1.2 >>>  pwd
/home/harman/Desktop/Assignment_1.2
harman@ubuntu: $ /home/harman/Desktop/Assignment_1.2 >>>  pwd --help
pwd: pwd [-L]
    Print the name of the current working directory.
    
    Options:
      -L	print the value of $PWD if it names the current working
    		directory
     
    By default, `pwd' behaves as if `-L' were specified.
    
    Exit Status:
    Returns 0 unless an invalid option is given or the current directory
    cannot be read.
harman@ubuntu: $ /home/harman/Desktop/Assignment_1.2 >>>  pwd -L
/home/harman/Desktop/Assignment_1.2
harman@ubuntu: $ /home/harman/Desktop/Assignment_1.2 >>>  echo harman
harman 
harman@ubuntu: $ /home/harman/Desktop/Assignment_1.2 >>>  echo -n harman     
harman harman@ubuntu: $ /home/harman/Desktop/Assignment_1.2 >>>  echo -e harman\n singh
harman
 singh 
harman@ubuntu: $ /home/harman/Desktop/Assignment_1.2 >>>  history
1 exit
2 ls
3 ls -a
4 ls -b
5 history
6 history 2
7 exit
8 history
9 history 3
10 exit
11 pwd
12 pwd -L
13 exit
14 pwd
15 pwd -L
16 ls
17 ls -a
18 ls -b hola
19 exit
20 echo harman
21 echo -n harman singh
22 echo -e harman singh
23 echo -e harman\n \nsingh
24 exit
25 echo lala lala lala
26 pwd
27 pwd -L
28 exit
29 pwd
30 pwd -L
31 pwd --help
32 exit
33 cd hola
34 pwd
35 cd /home/harman/Desktop/Assignment_1.2
36 cd hola
37 cd hola
38 cd hola
39 cd hola
40 cd hola
41 cd ..
42 exi
43 exit
44 exit
45 cd ..
46 cd ..
47 cd ..
48 cd ..
49 cd ..
50 cd ..
51 cd ..
52 cd ..
53 cd hola
54 cd ..
55 cd ..
56 cd ..
57 cd ..
58 cd Assignment-1.2
59 cd ..
60 exit
61 cd ..
62 cd ..
63 cd ..
64 cd Assignment_1.2
65 cd Assignment-1.2
66 cd hola
67 cd ..
68 cd Assignment_1.2
69 ls
70 cd hola
71 cd hola
72 cd ..
73 ls
74 exit
75 cd hola
76 cd hola
77 cd hola
78 cd ..
79 cd Assignment_1.2
80 echo haha
81 exit
81 cd hola
83 ls
84 ls -a
85 exit
86 exit
87 exit
88 cd hola
90 cd --help
91 pwd
92 pwd --help
93 pwd -L
94 echo harman
95 echo -n harman
96 echo -e harman\n singh
97 history
harman@ubuntu: $ /home/harman/Desktop/Assignment_1.2 >>>  history 4
95 echo -n harman
96 echo -e harman\n singh
97 history
98 history 4
harman@ubuntu: $ /home/harman/Desktop/Assignment_1.2 >>>  history -c
harman@ubuntu: $ /home/harman/Desktop/Assignment_1.2 >>>  history
1 history
harman@ubuntu: $ /home/harman/Desktop/Assignment_1.2 >>>  ls
test3.c  linux  a.out  ls.c  cat  mkdir  ls  rm  cd_help.txt  cat.c  mkdir.c  read.txt  lol  holaa  date  remove.txt  text.txt  test  holaaa  test.c  Makefile  rm.c  counter.txt  linux.c  date.c  pwd_help.txt  hola  
harman@ubuntu: $ /home/harman/Desktop/Assignment_1.2 >>>  ls -a
..  test3.c  linux  a.out  ls.c  cat  mkdir  ls  rm  .  cd_help.txt  cat.c  mkdir.c  read.txt  lol  holaa  date  remove.txt  text.txt  test  holaaa  test.c  Makefile  .hello.txt  rm.c  counter.txt  linux.c  date.c  pwd_help.txt  hola  
harman@ubuntu: $ /home/harman/Desktop/Assignment_1.2 >>>  ls -d hola
hola

harman@ubuntu: $ /home/harman/Desktop/Assignment_1.2 >>>  cat read.txt
Hello my name is Harman Singh.
I live in New Delhi.



I am 19 years old.
harman@ubuntu: $ /home/harman/Desktop/Assignment_1.2 >>>  cat -n read.txt
   1 Hello my name is Harman Singh.
   2 I live in New Delhi.
   3 
   4 
   5 
   6 I am 19 years old.
harman@ubuntu: $ /home/harman/Desktop/Assignment_1.2 >>>  cat -b read.txt
   1 Hello my name is Harman Singh.
   2 I live in New Delhi.



   3 I am 19 years old.
harman@ubuntu: $ /home/harman/Desktop/Assignment_1.2 >>>  date
Wed Sep 30 22:33:54 IST 2020
 harman@ubuntu: $ /home/harman/Desktop/Assignment_1.2 >>>  date -d 12:00:00
Wed Sep 30 12:00:00 IST 2020
 harman@ubuntu: $ /home/harman/Desktop/Assignment_1.2 >>>  date -I
2020-09-30

harman@ubuntu: $ /home/harman/Desktop/Assignment_1.2 >>>  rm remove.txt
harman@ubuntu: $ /home/harman/Desktop/Assignment_1.2 >>>  ls
test3.c  linux  a.out  ls.c  cat  mkdir  ls  rm  cd_help.txt  cat.c  mkdir.c  read.txt  lol  holaa  date  text.txt  test  holaaa  test.c  Makefile  rm.c  counter.txt  linux.c  date.c  pwd_help.txt  hola  
harman@ubuntu: $ /home/harman/Desktop/Assignment_1.2 >>>  rm -i holaa
rm: remove regular empty file 'holaa'? y
harman@ubuntu: $ /home/harman/Desktop/Assignment_1.2 >>>  rm -f thisisnotthere
harman@ubuntu: $ /home/harman/Desktop/Assignment_1.2 >>>  mkdir hello
harman@ubuntu: $ /home/harman/Desktop/Assignment_1.2 >>>  mkdir -v OS
mkdir: created directory 'OS'
harman@ubuntu: $ /home/harman/Desktop/Assignment_1.2 >>>  mkdir -p hola
harman@ubuntu: $ /home/harman/Desktop/Assignment_1.2 >>>  mkdir -p newf/newff/newfff
harman@ubuntu: $ /home/harman/Desktop/Assignment_1.2 >>>  exit 5


