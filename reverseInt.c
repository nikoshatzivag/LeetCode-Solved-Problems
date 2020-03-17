#include <stdio.h>
#include <math.h>

int reverse (int x) {
	int digitx = 0;
	long temp = (int) x, sum = 0;

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
	// to avoid overflow
	if (sum < -(pow(2.0, 31.0)) || sum > (pow(2.0, 31.0)) - 1)
		return 0;
	
	return (int) sum;

	// ######### 2nd SOLUTION #######
	// long temp = 0;
	
	// while (x)
	// {
	// 	temp = temp * 10 + x % 10;
	// 	x /= 10;
	// }

	// if (temp < -(pow(2.0, 31.0)) || temp > (pow(2.0, 31.0)) - 1)
	// 	return 0;
	
	// return (int)temp;
}

int main(int argc, char const *argv[])
{
	int x;
	while (1) {
		scanf ("%d", &x);
		printf ("Reversed: %d\n", reverse (x));
	}
	return 0;
}
