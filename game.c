#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int AImove(int M, int b, int* array) {
	if (b * 2 >= M) return M;
	if (array[M - 1] != 0) return array[M - 1];
	else return 1;
}

void main() {
	int M, a = 1, b = 1, c = 2, i, j;
	int* array;
	srand(time(0));
	printf("Enter a number of matches: \n");
	scanf("%d", &M);
	array = malloc(sizeof(int)*M);
	array[0] = 1;
	array[1] = 2;
	for(i = 2; i < M; ++i){
		if(i == 3 * c ) c++;
		for(j = 1; j < c; ++j){
			if((array[i - j] == 0)){
				array[i] = j;
				break;
			}
			else if(array[i - j] > j * 2 ){
				array[i] = j;
				break;
			}
			else array[i] = 0;
		}
	}
	do {
		do {
			system("cls");
			if (a > b * 2) printf("\nEnter a value less than 'MaxDecrement'! ");
			else if (a <= 0) printf("\nYou can't enter a value less than 0!");
			else if (a > M) printf("\nYou can't enter a value over than matches number!");
			printf("\nMatches: %d\tMaxDec: %d\nDecrement: ", M, b * 2);
			scanf("%d", &a);
		} while (a > b * 2 || a <= 0 || a > M);
		b = a;
		M -= a;
		if (M == 0) printf("\nYou won!");
		else {
			a = AImove(M, b, array);
			b = a;
			M -= a;
			if (M == 0) printf("\nAI won!");
		}
		sleep(1000);
	} while (M != 0);
	free(array);
}