#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int reverse (int x) {
	int digitx = 0, temp = x, sum = 0;

	// if (x < -(pow(2.0, 31.0)) || x > (pow(2.0, 31.0)) - 1)
	// 	return 0;

	while (temp)
	{
		digitx++;
		temp /= 10;
	}

	for (int i = 0; i < digitx; i++, x = x / 10) {
		temp = x % 10;
		for (int j = i + 1; j < digitx; j++, temp = temp * 10);
		sum += temp;
	}
	
	return sum;
}

bool isPalindrome(int x) {
	if (x < 0 || x > (pow(2.0, 31.0)) - 1)
		return false;

	int temp = x;
	short digitx = 0, i;

	while (temp)
	{
		digitx++;
		temp /= 10;
	}

	short lifo[digitx / 2 + 1];

	if (digitx % 2) {
		for (i = 0; i < digitx / 2; i++, x /= 10) {
			lifo[i] = x % 10;
		}
		x /= 10;
		for (i -= 1; i >= 0; i--, x /= 10) {
			if (lifo[i] != x % 10)
				return false;
		}
	}
	else {
		for (i = 0; i < digitx / 2; i++, x /= 10) {
			lifo[i] = x % 10;
		}
		for (i -= 1; i >= 0; i--, x /= 10) {
			if (lifo[i] != x % 10)
				return false;
		}
	}

	return true;
}


int main(int argc, char const *argv[])
{
	int x;
	while (1) {
		scanf ("%d", &x);
		if (isPalindrome (x))
			printf ("True\n");
		else
			printf ("False\n");
	}
	return 0;
}