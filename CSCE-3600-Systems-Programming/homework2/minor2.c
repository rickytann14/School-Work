#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]){
	int i;
	int ssize, wsize, j;
	int count = 0;
	/*char instring[] = argv[2];*/
	char temp[254];
	FILE *ofp, *ifp;

	i = j = count;
	if(argc != 3){
		printf("\nThe Program has encounterd an error!");
		printf("\nUsage: ./a.out filename [word]");
		exit(1); 
	}

	ifp = fopen(argv[1], "r");
	ofp = fopen(argv[2], "w");
	
	printf("Size of argv[2] is %d\n", sizeof(argv[2]));
	/*Look for number of times word occuers*/			
	while(fgets(temp, 254, ifp) != NULL){
	
	/*printf("\n%c", temp[6]);*/
	ssize = sizeof(temp);
	wsize = sizeof(argv[2]);
		if(temp[i] == argv[2][0]){
		/*First letter of the word found*/
			for(j = 0; j<= wsize-1; j++){
				if(temp[i+j] != argv[2][j]){
					/*Mismatch*/
					while(isspace(temp[i]) == 0 && ispunct(temp[i]) == 0 && temp[i] != '\0'){
						i++;
					}
				}
			}
			if(j == wsize-1){
				if(isspace(temp[i+j]||ispunct(temp[i+j])||temp[i+j] == '\0')){
					count++;
					i += j ;
				}
			}
		}
		printf("%s", temp);
		/*puts(temp);*/
	}
	printf("\n%c", temp[6]);
	printf("\nTotal Number Occurrences of \"%s\" in File: %d\n", argv[2], count);
	fclose(ifp);
	fclose(ofp);
	return 0;
}
