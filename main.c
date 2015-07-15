/* Main program where things should work. Must implement all the functions I did :| */

#include "stdio.h"
#include "stdlib.h"
#include "array_int.h"

int main(int argc, char const *argv[])
{
	struct DynIntArray * a;
	int erro;
	int x, i;
	int index;
	int element;
	int option;
	char choice;

	a = Array_new(&erro);
	
	for (i = 0; i < 5; i++)
	{
		Array_insertLast(a, i+2, &erro);
	}
	printf("Tamanho do array: %d\n", Array_size(a,&erro));
	printf("Espaço total do array: %d\n", Array_capacity(a,&erro));
	
	do
	{

		printf("Choose one of the operations to test the functions on this array: \n");
		printf("Press 1 to get an index from an element of this array.\n");
		printf("Press 2 to get a element from an index of this array.\n");
		printf("Press 3 to remove the last element of this array.\n");
		printf("Press 4 to remove any element you want of this array.\n");
		printf("Press 5 to insert an element on the first index of this array\n");
		printf("Press 6 to insert an element o the last index of this array\n");
		printf("Press 7 to set an element on any index of this array.\n");
		printf("Press -1 to quit this program test.\n");
		scanf("%d", &option);

		if (option == 1)
		{
			printf("Type the element you want to check the index:\n");
			scanf("%d", &element);
			x = Array_getIndexFor(a, element, &erro);
			if (!erro)
			{
				printf("The element %d is on index %d\n",element, x);
			}
			else
			{
				printf("[ERROR ON PROGRAM COMPLAIN ON THE DEVELOPER.]\n");
			}
		}
		else if (option == 2)
		{
			printf("Type the index you want to check the element:\n");
			scanf("%d", &index);
			x = Array_getAtIndex(a, index, &erro);
			if (!erro)
			{
				printf("The index %d guards the element %d\n", index, x);
			}
			else if (erro == 2)
			{
				printf("The index is invalid \n");
			}
			else
			{
				printf("[ERROR ON PROGRAM COMPLAIN ON THE DEVELOPER]\n");
			}
		}
		else if (option == 3)
		{
			x = Array_removeLast(a, &erro);
			if (!erro)
			{
				printf("The element you removed was %d\n", x);
			}
			else if (erro == 3)
			{
				printf("This array you are working is empty\n");
			}
			else
			{
				printf("[ERROR ON PROGRAM COMPLAIN ON THE DEVELOPER]\n");
			}
		}
			
	} while (option != -1);
	
	return 0;
}

