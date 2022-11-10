#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include<time.h>

int main() {

    FILE *filePointer;
    FILE *reserverdFilePointer;
    int numberOfCommits = 0;

    filePointer = fopen("./assets/file.txt", "w");

    if(filePointer == NULL){
      printf("Error!");   
      exit(1);             
   }else {
   	
   	    fclose(filePointer);
        printf("Enter the number of commits: ");
        scanf("%d", &numberOfCommits);

        for(int i=0; i<numberOfCommits; i++) {
        	
        	reserverdFilePointer = fopen("./assets/file.txt", "w");
        	
    		time_t seconds;
    		seconds = time(NULL);
    		
    		char randomWord[50];
            int randomWordLength = rand() % 1000 + 1;
    		sprintf(randomWord, "%ld", seconds+randomWordLength+i);
    		
            char space[2] = "\n";
            fputs(randomWord, filePointer);
            fputs(space, filePointer);
            fputs("changed !", filePointer);
            fputs(space, filePointer);

            fclose(reserverdFilePointer);

            system("git add .");
            system("git commit -m \" randomCommit \"");
            
        }
   }
   
   system("git push origin master");

    return 0;
}