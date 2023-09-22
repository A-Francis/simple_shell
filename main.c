#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */

int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int fd = 2;

	asm("mov %1, %0\n\t"
	    "add $3, %0"
	    : "=r" (fd)
	    : "r" (fd));

	fd = (ac == 2) ? open(av[1], O_RDONLY) : fd;

	if (fd == -1)
	{	int errno_value = errno;
		int exit_status = (errno_value == EACCES) ? 126 :
		((errno_value == ENOENT) ? 127 : EXIT_FAILURE);

		if (errno_value == ENOENT)
		{
			_eputs(av[0]);
			_eputs(": 0: Can't open ");
			_eputs(av[1]);
			_eputchar('\n');
			_eputchar(BUF_FLUSH);
		}

		exit(exit_status);
	}

	info->readfd = fd;
	populate_env_list(info);
	read_history(info);
	hsh(info, av);

	return (EXIT_SUCCESS);
}

