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
	int taxP = -1, tipP = -1;
	int mealNum;
	time_t t;
	double tax, tip, total;

	/* input for taxP and tipP and check for negativity*/
	do{
		printf("Please enter tax (%%): ");
		scanf("%d", &taxP);
	} while (taxP < 0);
	do{
		printf("Please enter tip (%%): ");
		scanf("%d", &tipP);
	} while (tipP < 0);
	
   
	printf("\nA meal is selecting for you...");

	/* initialize random number generator */
	srand((unsigned)time(&t));
	mealNum = rand() % 4;

	char mealName[4][20] = {"Salad", "Soup", "Sandwich", "Pizza"};
	double mealPrice[] = {9.95, 4.55, 13.25, 22.35};

	/* calculation */
	tax = mealPrice[mealNum] * (taxP/100.00);
	tip = mealPrice[mealNum] * (tipP/100.00);
	total = mealPrice[mealNum] + tax + tip;

	/* output */
	printf("\nYour selected meal is %s and it costs $%.2f.", mealName[mealNum], mealPrice[mealNum]);
	printf("\nTax amount: $%.4f\nTip amount: $%.4f\nTotal bill: $%.4f\n\n", tax, tip, total);

	return 0;
 } /* end main */