#include <stdio.h>


int searchInsert(int* nums, int numsSize, int target){
	int low = 0, uper = numsSize, i;
	
	while (low <= uper) {
		i = (low + uper) / 2;
		if (nums[i] == target) {
			return i;
		}
		else if (nums[i] > target) {
			uper = i - 1;
		}
		else {
			low = i + 1;
			i++;
		}
	}
	return i;
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
		printf ("What are you looking for: ");
		scanf ("%d", &input);
		printf ("Search insert returned: %d\n", searchInsert (table, i - 1, input));
		i = 0;
	}
	
	return 0;
}
