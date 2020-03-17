#include <stdio.h>
#include <stdbool.h>
#include <string.h>



bool isValid (char * s) {
	int i = 0, len = strlen (s), j = 0;

	if (len == 0) {
		return true;
	}

	char lifo[len / 2 + 1];
	// if we reach the len/2 + 1 in the lifo then for sure its false
	// because one or more parenthesis won't be closed so false
	while (s[i] != '\0' && j <= len) {
		if (s[i] == '(') {
			lifo[j] = '(';
			j++;
		}
		else if (s[i] == '[') {
			lifo[j] = '[';
			j++;
		}
		else if (s[i] == '{') {
			lifo[j] = '{';
			j++;
		}
		else if (s[i] == ')' && j) {
			if (lifo[--j] != '(')
				return false;
		}
		else if (s[i] == ']' && j) {
			if (lifo[--j] != '[')
				return false;
		}
		else if (s[i] == '}' && j) {
			if (lifo[--j] != '{')
				return false;
		}
		else {
			return false;
		}
		i++;
	}
	
	return (j) ? false : true;
}


int main(int argc, char const *argv[])
{
	char s[20];

	while (1)
	{
		scanf ("%s", s);
		if (isValid (s))
			printf ("True\n");
		else
			printf ("False\n");
	}
	
	return 0;
}
