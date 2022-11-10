#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
            char randomCommit[] = "generated random Commit" + i;
            fputs(randomCommit, filePointer);

            system("git add ../assets/file.txt");
            system("git commit -m \"%s\"", randomCommit);
        }
   }

   fclose(filePointer);
   system("git push origin main");

    return 0;
}