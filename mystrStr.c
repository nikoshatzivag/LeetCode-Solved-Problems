#include <stdio.h>
#include <string.h>

int strStr (char * haystack, char * needle) {
	int i, j = 0, len1 = strlen(haystack), len2 = strlen(needle);

	// printf ("len1 = %d, len2 = %d\n", len1, len2);

	if (len2 == 0)
		return 0;

	if (len1 < len2)
		return -1;

	for (i = 0; i < len1 - len2 + 1; i++, j = 0) {
		while (haystack[i + j] == needle[j]) {
			if (j == len2 - 1) {
				return i;
			}
			j++;
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	char haystack[20], needle[20];

	while (1)
	{
		scanf ("%s", haystack);
		scanf ("%s", needle);

		printf ("StrStr returned: %d\n", strStr (haystack, needle));
	}
	
	return 0;
}
