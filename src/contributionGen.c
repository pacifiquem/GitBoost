#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include<time.h>

int main() {

    FILE *filePointer;
    int numberOfCommits = 0;

    filePointer = fopen("./assets/file.txt", "w");

    if(filePointer == NULL){
      printf("Error!");   
      exit(1);             
   }else {
        printf("Enter the number of commits: ");
        scanf("%d", &numberOfCommits);

        for(int i=0; i<numberOfCommits; i++) {
        	
    		time_t seconds;
    		seconds = time(NULL);
    		
    		char randomWord[50];
            int randomWordLength = rand() % 1000 + 1;
    		sprintf(randomWord, "%ld", seconds+randomWordLength+i);
    		
            char space[2] = "\n";
            fprintf(filePointer, randomWord);
            fprintf(filePointer, space);

            system("git add .");
            system("git commit -m \" randomCommit \"");
            printf("pushed !");
        }
   }

   fclose(filePointer);
   system("git push origin master");

    return 0;
}