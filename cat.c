#include <sys/types.h>
#include<sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include<fcntl.h>

int main(int argc, char* argv[]){


	FILE *pp=fopen("/home/harman/Desktop/direc.txt","r");

    char bufff[100];

    fscanf(pp, "%[^\n]", bufff);

    chdir(bufff);

    fclose(pp);


	char s[100];
	if(argc==2){
		strcpy(s,argv[1]);
	}
	else{
		strcpy(s,argv[2]);
	}

	FILE *p=fopen(s,"r");

	if(p==NULL){
		perror("Error opening the file.EXITING");
		exit(1);
	}

	char buff[1000000];

	int c1=0;

	int c2=0;

	int flag=0;

	if(argc>2){
		if(argv[1][1]=='n'){
			flag=1;
		}
		else{
			flag=2;
		}
	}


	
	while(fgets(buff,1000000,p)){

		c1++;
		if(flag==1 ){ //for -n flag to number lines
			printf("   %d ",c1);
		}

		if(flag==2 && strcmp(buff,"\n")!=0){  //for -b flag to number only non blank lines
			c2++;
			printf("   %d ",c2);
			
		}
		printf("%s",buff);
	}



	return 0;




}
