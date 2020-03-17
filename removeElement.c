#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
	int i, remove = 0, newLen = numsSize;

	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] == val)
		{
			remove += 1;
			newLen--;
			continue;
		}
		nums[i - remove] = nums[i];
	}
	return newLen;
}