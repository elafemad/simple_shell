#include "shell.h"
/**
 * free_str - free allocated space of an array.
 * @a: the array to free
 */
void free_str(char **a)
{
	int i;

	if (!a)
		return;
	for (i = 0; a[i]; i++)
	{
		free(a[i]);
		a[i] = NULL;
	}
	free(a), a = NULL;
}
