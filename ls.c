
#include <stdio.h> 
#include <dirent.h> 

#include <string.h>
#include <unistd.h>
#include <stdlib.h>



void dFlag(char *s){

    printf("%s\n",s);



}



int main(int argc, char* args[]) 
{ 



   

    FILE *p=fopen("/home/harman/Desktop/direc.txt","r");

    char buff[100];

    fscanf(p, "%[^\n]", buff);

    chdir(buff);

    fclose(p);

    







    int flag=0;
    if(argc>1){
        if(args[1][1]=='a'){
            flag=1;
        }
        else{
            dFlag(args[2]);
            return 0;
        }
    }




    struct dirent *reader;
    DIR *directory = opendir("./"); 
  
    if (directory==NULL){
        printf("Error opening the directory.EXITING."); 
        exit(0);
    } 


    //if(flag==0){
    //int c=0;
    if(flag==0){
    while ((reader=readdir(directory))!= NULL) {

            // c++;
            // if(c==1 || c==3){
            //     continue;
            // }

            char *name=reader->d_name;

            if(name[0]=='.') {continue;}

            printf("%s  ", reader->d_name); 
            
    }
}
   // }
    else{
        while ((reader=readdir(directory))!= NULL) {

            

    
            printf("%s  ", reader->d_name); 
            
    }

   }
  
    closedir(directory);     
    return 0; 
} 
