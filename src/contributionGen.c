#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>

int main() {

    FILE *filePointer;
    int numberOfCommits = 0;

    filePointer = fopen("../assets/file.txt", "w");

    if(filePointer == NULL){
      printf("Error!");   
      exit(1);             
   }else {
        printf("Enter the number of commits: ");
        scanf("%d", &numberOfCommits);

        for(int i=0; i<numberOfCommits; i++) {
            int randomNumber = rand();
            char randomCommit[25] = "generated random Commit";
            char space[2] = "\n";
            fputs(randomCommit, filePointer);
            fputs(space, filePointer);

            system("git add ../assets/file.txt");
            
            char commitMessage[50] = "git commit -m \" randomCommit \" ";
            system(commitMessage);
        }
   }

   fclose(filePointer);
   system("git push origin master");

    return 0;
}