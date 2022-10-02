#include <stdio.h>
#include <limits.h>
int main()
{
	unsigned int apples;
	unsigned int students;
	unsigned int price = 2; // 2 dollars per apple
	printf("\nUInt max:  %u\n\n", UINT_MAX); // for quick reference on the cl
	printf("Quantity of students: ");
	scanf("%d", &students);
	printf("Quantity of apples per student: ");
	scanf("%d", &apples);

	// get total apples
	if(__builtin_mul_overflow(apples, students, &apples)){
		printf("\nthere was an error calculating the total number of apples needed: Aborting!\n");
		return 0;
	}
	// get total price
	if (__builtin_mul_overflow(price, students, &price)){
		printf("\nthere was an error calculating the Price: Aborting!\n");
		return 0;
	}

	// print result
	printf("The price for %d apples is $%d\n", apples, price);
	return 0;
}


//Chris Glanzer 