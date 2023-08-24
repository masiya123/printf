#include "main.h"
/**
 * puns - Unsigned decimal integer function
 *
 * @arg: arg
 * Return: length
 */
int puns(va_list arg)
{
	unsigned int num, a = 0, div;

	num = va_arg(arg, int);

	if (num == 0)
	{
		putchar('0');
		a = 1;
	}
	if (num > 0)
	{
		for (div = 1; (num / div) > 9; div *= 10)
			;
		while (div != 0)
		{
			putchar((num / div) + '0');
			num %= div;
			div /= 10;
			a++;
		}
	}
	return (a);
}

/**
 * poct - Unsigned octal function
 *
 * @arg: arg
 * Return: length
 */
int poct(va_list arg)
{

	unsigned int num, a = 0, i = 0;
	int tab[100];

	num = va_arg(arg, int);
	if (num < 9)
	{
		putchar(num + '0');
		a = 1;
	}
	else if (num >= 9)
	{
		while (num > 0)
		{
			tab[i] = num % 8;
			num /= 8;
			i++;
		}
	}
	while (i--)
	{
		putchar(tab[i] + '0');
		a++;
	}
	return (a);
}

/**
 * phex - Unsigned hexadecimal integer function
 * @arg: arg
 * Return: length
 */
int phex(va_list arg)
{
	unsigned int n = va_arg(arg, unsigned int);
	unsigned int a[1024];
	int i = 0, t = 0;
	char p;

	if (n < 1)
	{
		write(1, "0", 1);
		return (1);
	}
	for (i = 0; n > 0; i++, t++)
	{
		a[t] = n % 16;
		n = n / 16;
		if (a[t] > 10)
			a[i] = a[t] + 39;
		else
			a[i] = a[t];
	}
	for (i = t - 1; i >= 0; i--)
	{
		p = a[i] + '0';
		putchar(p);
	}
	return (t);
}

/**
 * pHEX - program that unsigned hexadecimal integer (uppercase)
 * @arg: arg
 * Return: length
 */
int pHEX(va_list arg)
{

	unsigned int n = va_arg(arg, unsigned int);
	int a[1024], i = 0, t = 0;
	char p;

	if (n < 1)
	{
		putchar('0');
		return (1);
	}
	for (i = 0; n > 0; i++)
	{
		a[t] = n % 16;
		n = n / 16;
		if (a[i] > 10)
			a[i] = a[t] + 7;
		else
		{
			a[i] = a[t];
		}
		t++;
	}
	for (i = t - 1; i >= 0; i--)
	{
		p = a[i] + '0';
		putchar(p);
	}
	return (t);
}

/**
 * pSTR - return an str function
 * @arg: var to write
 * Return: string
 */
int pSTR(va_list arg)
{
	int i = 0, b;
	char *s = va_arg(arg, char *);

	if (s == NULL)
		s = "(null)";
	while (s[i] != '\0')
	{
		b = s[i];
		if (b == 92 && s[i + 1] == 'n')
		{
			putchar('x');
			putchar('0');
			putchar('A');
			i++;
		}
		else
		{
		putchar(s[i]);
		i++;
	}
	}
	return (i);
}
