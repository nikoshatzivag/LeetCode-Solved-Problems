#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
	int less = nums[0];
	short i, newLen = numsSize, remove = 0;

	for (i = 1; i < numsSize; i++)
	{
		// less = nums[i];
		while (less == nums[i] && i < numsSize)
		{
			remove++;
			newLen--;
			i++;
		}
		nums[i - remove] = nums[i];
		less = nums[i];
	}
	return newLen;
}


int main(int argc, char const *argv[])
{
	int table[10], input, i = 0;
	while (1)
	{
		while (1)
		{
			printf ("Give number: ");
			scanf ("%d", &input);
			if (input != -10) {
				table[i] = input;
				i++;
			}
			else {
				break;
			}
		}
		printf ("[");
		i = removeDuplicates (table, i);
		for (; i > 0; i--)
			printf ("%d ", table[i]);
		printf ("]\n");
		// printf ("Remove Duplicates returned: %d\n", removeDuplicates (table, i));

		i = 0;
	}
	
	return 0;
}