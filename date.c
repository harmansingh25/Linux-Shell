#include <sys/types.h>
#include<sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include<fcntl.h>
#include<time.h>


int main(int argc, char* args[]){


	FILE *p=fopen("/home/harman/Desktop/direc.txt","r");

    char buff[100];

    fscanf(p, "%[^\n]", buff);

    chdir(buff);

    fclose(p);



	int flag=0;
    if(argc>1){
        if(args[1][1]=='d'){
            flag=1;
        }
        else{
            flag=2;
        }
    }

	if(flag==2){  ///for printing only date in yyyy-mm-dd format (ISO)

		time_t t;
		time(&t);
		struct tm *date=localtime(&t);

		int day=date->tm_mday;  int mon=date->tm_mon+1;  int year=date->tm_year+1900;
		printf("%d-%02d-%02d\n",year,mon,day);

		return 0;

	}


	char timeh[100];
	strcpy(timeh,args[2]);  ///for -d flag

	//int flag=1;


	time_t curT;

	time(&curT);


	char *token;

	token=strtok(ctime(&curT)," ");

	int c=0;

	while(token!=NULL){
		c++;
		if(c==5){
			printf("%s ","IST");
			continue;
		}

		if(flag==1 && c==4){
			printf("%s ",timeh);
			token=strtok(NULL," ");
			continue;
		}
		printf("%s ",token);
		token=strtok(NULL," ");

	}

	

	return 0;
}
