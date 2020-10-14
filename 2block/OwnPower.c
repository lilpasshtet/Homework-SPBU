#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

float stupidPower(double basis, int power)
{
	int firstIterPower = basis;
	if (power < 0)
	{
		for (int i = 1; i < abs(power); i++)
		{
			basis = basis * firstIterPower;
		}
		return 1 / basis;
	}
	if (power == 0)
	{
		return 1;
	}
	else
	{
		for (int i = 1; i < power; i++)
		{
			basis = basis * firstIterPower;
		}
		return basis;
	}
}

float ownPower(int basis, int power)
{
	if (power < 0) 
	{
		return 1 / ownPower(basis, abs(power));
	}
	else if (power == 0)
	{
		return 1;
	}
	else if (power % 2 == 0)
	{
		int temp = ownPower(basis, power / 2);
		return temp * temp;
	}
	else
	{
		return ownPower(basis, power - 1) * basis;
	}
}

bool testCorrectCase() 
{
	return ownPower(2, 4) == stupidPower(2, 4) && stupidPower(2, 4) == 16;
}

bool testFloatCase() 
{
	return ownPower(2, -1) == stupidPower(2, -1) && stupidPower(2, -1) == 0.5;
}

bool testIncorrectCase() 
{
	return ownPower(NULL, -1);
	return true;
}

int main()
{
	if (!testCorrectCase() || !testFloatCase() || !testIncorrectCase())
	{
		printf("ERROR");
		return 1;
	}
	printf("Enter the basis and power\n");
	int basis = 0;
	int power = 0;
	scanf("%d%d", &basis, &power);

	printf("Smart power is %lf\n", ownPower(basis, power));

	printf("Stupid power is %lf\n", stupidPower(basis, power));

	return 0;
}