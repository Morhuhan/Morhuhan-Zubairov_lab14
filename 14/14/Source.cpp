#include <stdio.h>
#include <math.h>

#define N 16 

int check_number(int check[], int size_check) {

	double power = 0;
	int sum = 0;

	for (int i = size_check - 1; i > -1; i--) {
		sum = sum + pow(2, power) * check[i];
		power++;
	}

	return sum;
}

void writing(int number10, int number2[], int size_number2) {

	int remains = 3;
	int i = size_number2 - 1;

	do {
		remains = number10 % 2;
		number2[i] = remains;
		i--;
		number10 = number10 / 2;
	} while (number10 > 0);
}

void search(int number2[], int size_number2, int check[], int size_check) {

	int step = 2;
	int buffer = 0;

	for (int i = 0; i < (size_number2 - 1); i++) {

		for (int i = 0; i < step; i++) {
			check[size_number2 - i] = number2[size_number2 - i];
		}

		if (buffer == check_number(check, size_check)) continue;

		else {
			printf("%d \n", check_number(check, size_check));
		}
	}

}



int main() {

	int number2[N] = { 0 };
	int size_number2 = N;

	int number10 = 0;

	int check[N] = { 0 };
	int size_check = N;

	scanf_s("%d", &number10);

	writing(number10, number2, size_number2);

	for(int i = 0; i < N; i++){
		printf("%d ", number2[i]);
	}

	search(number2, size_number2, check, size_check);
}
