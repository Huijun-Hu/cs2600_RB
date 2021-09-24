#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* 
Restaurant Bill
@ author : Huijun Hu
 - computes the tax and tip on a restaurant bill for a patron. 
 - accept the tax and tip both in percentages as input. 
 - Display the meal cost, tax amount, tip amount, and total bill. 
 - The meal cost should be randomly selected.
*/
 
int main(){

	/* variables declaration */
	float taxP = -1, tipP = -1;
	int mealNum;
	time_t t;
	float tax, tip, total;

	/* input for taxP and tipP and check for negativity*/
	do{
		printf("Please enter tax (percentage): ");
		scanf("%f", &taxP);
	} while (taxP < 0);
	do{
		printf("Please enter tip (percentage): ");
		scanf("%f", &tipP);
	} while (tipP < 0);
	
   
	printf("\nA meal is selecting for you...");

	/* initialize random number generator */
	srand((unsigned)time(&t));
	mealNum = rand() % 4;

	char mealName[4][20] = {"Salad", "Soup", "Sandwich", "Pizza"};
	float mealPrice[] = {9.95, 4.55, 13.25, 22.35};

	/* calculation */
	tax = mealPrice[mealNum] * taxP;
	tip = mealPrice[mealNum] * tipP;
	total = mealPrice[mealNum] + tax + tip;

	/* output */
	printf("\nYour selected meal is %s and it costs $%f.", mealName[mealNum], mealPrice[mealNum]);
	printf("\nTax amount: $%f\nTip amount: $%f\nTotal bill: $%f\n\n", tax, tip, total);

	return 0;
 } /* end main */