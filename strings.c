#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	for (i = 0; s[i] != '\0'; i++)
	{
		/* No need for additional code inside the loop.*/
	}
	return (i);
}
/**
 * _strcmp - performs lexicogarphic comparison of two strings.
 * @s1: the first string
 * @s2: the second string
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	int result = 0;

	for (; *s1 && *s2; s1++, s2++)
	{
		if (*s1 != *s2)
		{
			result = (*s1 - *s2);
			break;
		}
	}

	if (!result)
		return (result);
	else if (result < 0)
		return (-1);
	else
		return (1);
}

/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	for (; *needle; needle++, haystack++)
	{
		if (*needle != *haystack)
		{
			return (NULL);
		}
	}
	return ((char *)haystack);
}
/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	for (; *dest; dest++)
	{
		/* Continue to the end of 'dest'.*/
	}

	for (; *src; src++, dest++)
	{
		*dest = *src;
	}

	*dest = *src;
	return (ret);
}

