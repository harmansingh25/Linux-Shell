#include <sys/types.h>
#include<sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include<fcntl.h>
#include<time.h>



int main(int argc, char *args[]){



	FILE *pp=fopen("/home/harman/Desktop/direc.txt","r");

    char bufff[100];

    fscanf(pp, "%[^\n]", bufff);

    chdir(bufff);

    fclose(pp);


	int flag=0;

	char s[100];
	if(argc==2){
		strcpy(s,args[1]);
	}
	else{
		strcpy(s,args[2]);
	}

    if(argc>2){
        if(args[1][1]=='i'){
            flag=1;
        }
        else{
            flag=2;
        }
    }



	if(flag==1){ ////for -i flag to prompt

		char ans[100];
		char *t=s;
		printf("%s%s%s%s%s","rm: remove regular empty file ","'",t,"'","? ");
		scanf("%s",ans);

		if(strcmp(ans,"y")==0){

			
			int ans=remove(s);
			if(flag!=2 && ans!=0){ ///for normal cases , i.e. not -f flag

				printf("%s%s%s%s\n","rm: cannot remove ","'",s,"' : No such file or directory");

			}

		}

		
		return 0;

	}



	int ans=remove(s);
	if(flag!=2 && ans!=0){ ///for normal cases , i.e. not -f flag

		printf("%s%s%s%s\n","rm: cannot remove ","'",s,"' : No such file or directory or the given file is a directory");

	}
	return 0;


}
