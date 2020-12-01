#include <sys/types.h>
#include<sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include<fcntl.h>


/* HELP FUNCTIONS AHEAD      



*/

void helpExit(){

	printf("%s\n","exit: exit [n]");
	printf("%s\n","     Exit the shell.");

	printf("%s\n", "     Exits the shell with a status of N.  If N is omitted, the exit status is that of the last command executed.");
  


    return;




}






















void getCurrDir(){

	char dir[2000];
	
	getcwd(dir,sizeof(dir));

	if(dir==NULL){
		perror("Cannot get the current directory.");
		return;
	}

	printf("%s",dir);

	return;




}

void writeTo(){



	FILE *p=fopen("/home/harman/Desktop/direc.txt","w");

	if(p==NULL){
		perror("Error in opening the file.");
		return;
	}

	char dir[2000];
	
	getcwd(dir,sizeof(dir));

	fputs(dir,p);

	fclose(p);
	return;


}



void changeDir(char *f){

	chdir(f);

	writeTo();

	return;
}








void echo(char *s,int flag){

	if(flag==0){
	printf("%s\n",s);
	return; }

	else if(flag==2){

		while(*s!='\0'){

			if(*s=='\\'){
				printf("%s\n","");
				s++;
				s++;
				continue;

			}
			printf("%c",*s);
			s++;
		}
		printf("%s\n","");
		return;
	}

	else{
		printf("%s",s);
	}

}






void endShell(){
	exit(0);
}







void add_data(int n,char *s){

	

	FILE *p=fopen("/home/harman/Desktop/text.txt","a");
	if(p==NULL){
		perror("Error in opening the file. EXITING");
		exit(1);
	}


	
	fprintf(p,"%d %s\n",n,s);
	
	fclose(p);

	return;



}


void printHistory(){

	char buff[1024];

	FILE *p=fopen("/home/harman/Desktop/text.txt","r");

	if(p==NULL){
		perror("File can't be opened.");
		return;
	}

	while(fgets(buff,1024,p)){

		printf("%s",buff);
	}

	fclose(p);

	return;





}

void changeCounter(int c){

	chdir("Assignment_1.2");

	FILE *p=fopen("/home/harman/Desktop/counter.txt","w");

	if(p==NULL){
		perror("Error in opening the file.");
		return;
	}

	char buff[100];

	sprintf(buff,"%d",c);

	fputs(buff,p);

	fclose(p);
	return;



}

void historyRem(){

	FILE *p=fopen("/home/harman/Desktop/text.txt","w");

	if(p==NULL){
		perror("Error in opening the file. EXITING");
		return;
	}

	fclose(p);

	changeCounter(0);

	return;
}

void historyN(int c,int n){

	

	char buff[1024];

	FILE *p=fopen("/home/harman/Desktop/text.txt","r");

	if(p==NULL){
		perror("Error in opening the file. EXITING");
		return;
	}

	int counter=0;

	while(fgets(buff,1024,p)){

		counter++;

		

		if(counter>(c-n)){

			printf("%s",buff);

		}
	}

	fclose(p);

	return;




}


















void internalC(char *args[]){

	pid_t pid=fork();
	if(pid<0){
		perror("Child can't be cloned.");
		return;
	}

	if(pid==0){

		int t=execvp(args[0],args);
		if(t==-1){
			perror("Error occured with the process.");

		}
		exit(0);




	}
	if(pid>0){
		wait(NULL);
		return;
	}


}

int getCounter(){

	chdir("Assignment_1.2");

	FILE *p=fopen("/home/harman/Desktop/counter.txt","r");

	char buff[100];

	fscanf(p, "%[^\n]", buff);

	int n=atoi(buff);

	fclose(p);

	return n;


}

// void changeCounter(int c){

// 	FILE *p=fopen("counter.txt","w");

// 	char buff[100];

// 	sprintf(buff,"%d",c);

// 	fputs(buff,p);

// 	fclose(p);
// 	return;



// }

void pwd_help(){

	char buff[1024];

	FILE *p=fopen("pwd_help.txt","r");

	while(fgets(buff,1024,p)){

		printf("%s",buff);
	}

	fclose(p);

	return;


}
void cd_help(){

	char buff[1024];

	FILE *p=fopen("cd_help.txt","r");

	while(fgets(buff,1024,p)){

		printf("%s",buff);
	}

	fclose(p);

	return;


}




void tokenise(char *s){

	

	int counter=getCounter();

	

	add_data(++counter,s);

	

	changeCounter(counter);

	


	char *args[1000];
	char *token;

	//printf("%s\n",s);

	//char copy[100];

	token=strtok(s," ");
	//strcpy(copy,token);

	if(strcmp(token,"cat")==0){
		args[0]="./cat";
		token=strtok(NULL," ");

		for(int i=1;i<100;i++){
		if(token==NULL){
			args[i]=NULL;
			break;
		}
		args[i]=token;
		token=strtok(NULL," ");

	}
		internalC(args);
		return;
	}

	if(strcmp(token,"ls")==0){
		args[0]="./ls";
		token=strtok(NULL," ");

		for(int i=1;i<100;i++){
		if(token==NULL){
			args[i]=NULL;
			break;
		}
		args[i]=token;
		token=strtok(NULL," ");

	}
		internalC(args);
		printf("%s\n","");
		return;

	}
	if(strcmp(token,"date")==0){
		args[0]="./date";
		token=strtok(NULL," ");

		for(int i=1;i<100;i++){
		if(token==NULL){
			args[i]=NULL;
			break;
		}
		args[i]=token;
		token=strtok(NULL," ");

	}
		internalC(args);
		return;
	}

	if(strcmp(token,"rm")==0){
		args[0]="./rm";
		token=strtok(NULL," ");
		

		for(int i=1;i<100;i++){
		if(token==NULL){
			args[i]=NULL;
			break;
		}
		args[i]=token;
		token=strtok(NULL," ");

	}
		internalC(args);
		return;
	}

	if(strcmp(token,"mkdir")==0){
		args[0]="./mkdir";
		token=strtok(NULL," ");


		for(int i=1;i<100;i++){
		if(token==NULL){
			args[i]=NULL;
			break;
		}
		args[i]=token;
		token=strtok(NULL," ");

	}
		internalC(args);
		return;
	}

	if(strcmp(token,"exit")==0){
		token=strtok(NULL," ");
		if(token==NULL){
			endShell();
			return;
		}
		else if(token[0]=='-'){
			helpExit();
			return;
		}
		else{
			endShell();
			return;
		}
	}

	if(strcmp(token,"echo")==0){
		
		token=strtok(NULL," ");
		
		if(strcmp(token,"-n")==0){
			

			token=strtok(NULL," ");

			while(token!=NULL){

			printf("%s ",token);
			token=strtok(NULL," ");
			}
			

			// char g[]="";
			

			// char h[1000];
			

			// while(token!=NULL){
			// 	strcpy(h,token);
				
			// 	strcat(g,h);
				
			// 	strcat(g," ");
			// 	token=strtok(NULL," ");
			// }
	
			// echo(g,1);
			return;


		}
		if(strcmp(token,"-e")==0){

			token=strtok(NULL," ");

			char g[1000]="";

			while(token!=NULL){

				strcat(g,token);
				strcat(g," ");

			
			token=strtok(NULL," ");
			}

			echo(g,2);
			
			return;


		}
		else{
			

			char g[1000]="";

			while(token!=NULL){

				strcat(g,token);
				strcat(g," ");

			
			token=strtok(NULL," ");
			}

			echo(g,0);
			return;

		}


	}
	if(strcmp(token,"history")==0){

		token=strtok(NULL," ");

		if(token==NULL){
			printHistory();
			return;
		}

		else if(strcmp(token,"-c")==0){
			historyRem();
			return;
		}
		else {

			

			int n=atoi(token);
			//printf("%d\n",counter);
			historyN(counter,n);
			return ;

		}


	}
	if(strcmp(token,"pwd")==0){
		token=strtok(NULL," ");
		if(token==NULL){
			FILE *pp=fopen("/home/harman/Desktop/direc.txt","r");

    	char bufff[100];

    	fscanf(pp, "%[^\n]", bufff);

    	chdir(bufff);

    	fclose(pp);

		printf("%s\n",bufff);
			return;
		}
		else if(token[1]=='L'){
			FILE *pp=fopen("/home/harman/Desktop/direc.txt","r");

    	char bufff[100];

    	fscanf(pp, "%[^\n]", bufff);

    	chdir(bufff);

    	fclose(pp);

		printf("%s\n",bufff);
			return;
		}
		else{
			pwd_help();
			return;

		}
	}

	if(strcmp(token,"cd")==0){

		//printf("%s\n",token);

		token=strtok(NULL," ");

		if(token[0]=='-'){
			cd_help();
			return;
		}

		char g[100]="";

		strcpy(g,token);

		

		changeDir(g);

		return;
	}

	else{

		printf("%s\n","Enter a valid command");
	}

}

int main(){

	char s[100000];
	
	

	

	while(21){

		printf("%s","harman@ubuntu: $ ");

		FILE *pp=fopen("/home/harman/Desktop/direc.txt","r");

    	char bufff[100];

    	fscanf(pp, "%[^\n]", bufff);

    	chdir(bufff);

    	fclose(pp);

		printf("%s",bufff);
		printf("%s"," >>>  ");

		scanf("%[^\n]%*c",s);

		//printf("%s\n",s);

		tokenise(s);

		

		// if(strcmp(s,"pwd")==0){
		// 	add_data(++counter,s);
		// 	getCurrDir();
		// 	printf("%s\n","");

		// }

		// if(strcmp(s,"cd")==0){
		// 	char g[100];
		// 	scanf("%s",g);

		// 	char msg[100];
		// 	snprintf(msg,sizeof msg,"%s%s%s",s," ",g);
		// 	add_data(++counter,msg);
		// 	changeDir(g);

		// }
		// if(strcmp(s,"echo")==0){

		// 	char g[100];

		// 	scanf("%[^\n]%*c",g);

		// 	char msg[100];
		// 	snprintf(msg,sizeof msg,"%s%s",s,g);
		// 	add_data(++counter,msg);

		// 	echo(g,0);


		// }

		// if(strcmp(s,"history")==0){

		// 	add_data(++counter,s);

		// 	printHistory();
		// 	printf("%s\n","");
		// }

		// if(strcmp(s,"exit")==0){
		// 	add_data(++counter,s);
		// 	endShell();
		// }

		// if(strcmp(s,"cat")==0){
		// 	char g[100];
		// 	scanf("%s",g);
		// 	char msg[100];
		// 	snprintf(msg,sizeof msg,"%s%s%s",s," ",g);
		// 	add_data(++counter,msg);
		// 	char *args[]={"./cat",g,NULL};
		// 	internalC(args);


		// }
		// if(strcmp(s,"date")==0){

		// 	add_data(++counter,s);
		// 	char *args[]={"./date",NULL};
		// 	internalC(args);

		// }

		// if(strcmp(s,"ls")==0){

		// 	add_data(++counter,s);
		// 	char *args[]={"./ls",NULL};
		// 	internalC(args);
		// 	printf("%s\n","");
		// }

		// if(strcmp(s,"rm")==0){

		// 	char g[100];
		// 	scanf("%s",g);
		// 	char *args[]={"./rm",g,NULL};
		// 	char msg[100];
		// 	snprintf(msg,sizeof msg,"%s%s%s",s," ",g);
		// 	add_data(++counter,msg);
		// 	internalC(args);


		// }

		// if(strcmp(s,"mkdir")==0){
		// 	char g[100];
		// 	scanf("%s",g);
		// 	char *args[]={"./mkdir",g,NULL};
		// 	char msg[100];
		// 	snprintf(msg,sizeof msg,"%s%s%s",s," ",g);
		// 	add_data(++counter,msg);
		// 	internalC(args);


		// }


	}


	return 0;
	






}
