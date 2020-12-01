
#include <sys/stat.h>


#include <string.h>
#include <sys/types.h>
#include<sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include<fcntl.h>
#include<time.h>


int main(int argc, char* args[]){

	FILE *pp=fopen("/home/harman/Desktop/direc.txt","r");

    char bufff[100];

    fscanf(pp, "%[^\n]", bufff);

    chdir(bufff);

    fclose(pp);

	//int flag=2;


	char s[100];
	if(argc==2){
		strcpy(s,args[1]);
	}
	else{
		strcpy(s,args[2]);
	}

	int flag=0;
    if(argc>2){
        if(args[1][1]=='v'){
            flag=1;
        }
        else{
            flag=2;
        }
    }



	int res=mkdir(s,0777);

	

	if(res!=0  && flag!=2){ //flag 2 for -p flag

		printf("%s%s%s%s","mkdir: cannot create directory ","'",s,"': Either File exists or No such file or directory");
	}

	if(res!=0 && flag==2){   ///for -p flag (make parent directories or not throw an error in case of existing)

		char t[10000];

		strcpy(t,s);

		char *token;

		token=strtok(t,"/");

		

		

		char string[100]="";
		int c=0;

		while(token!=NULL){
			c++;

			if(c!=1)
			strcat(string,"/");

			strcat(string,token);
			
			int lol=mkdir(string,0777);
			token=strtok(NULL,"/");

		}
	}







	if(flag==1){ ///for -v flag

		printf("%s%s%s%s\n","mkdir: created directory ","'",s,"'");

	}

	return 0;


}
