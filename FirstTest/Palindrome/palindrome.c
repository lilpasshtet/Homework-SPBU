#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(const char buffer[100])
{
	if (buffer == NULL)
	{
		return false;
	}

	int lenString = strlen(buffer);

	for (int i = 0; i < lenString / 2; i++)
	{
		if (buffer[i] != buffer[lenString - i - 1])
		{
			return false;
		}
	}

	return true;
}

bool testCorrectCase()
{
	return isPalindrome("арозаупаланалапуазора");
}

bool testNullCase()
{
	isPalindrome(NULL);
	return true;
}

bool testUncorrectCase()
{
	return isPalindrome("€люблю€зыкпрограммировани€си");
}

int main()
{
	if (!testCorrectCase() || !testNullCase() || testUncorrectCase())
	{
		printf("ERROR!");
		return 1;
	}

	printf("Enter string:\n");
	char buffer[100] = "";
	scanf("%[^\n]", buffer);

	if (isPalindrome(buffer))
	{
		printf("This is a palindrome!");
	}
	else
	{
		printf("This is not a palindrome!");
	}

	return 0;
}