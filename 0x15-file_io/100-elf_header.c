#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_addr - prints address
 * @ptr: magic pointer
 * Return: none
 */
void print_addr(char *ptr)
{
	int j;
	int bgn;
	char syst;

	printf("  Entry point address:               0x");

	syst = ptr[4] + '0';
	if (syst == '1')
	{
		bgn = 26;
		printf("80");
		for (j = bgn; j >= 22; j--)
		{
			if (ptr[j] > 0)
				printf("%x", ptr[j]);
			else if (ptr[j] < 0)
				printf("%x", 256 + ptr[j]);
		}
		if (ptr[7] == 6)
			printf("00");
	}

	if (syst == '2')
	{
		bgn = 26;
		for (j = bgn; j > 23; j--)
		{
			if (ptr[j] >= 0)
				printf("%02x", ptr[j]);

			else if (ptr[j] < 0)
				printf("%02x", 256 + ptr[j]);

		}
	}
	printf("\n");
}
/**
 * print_type - prints the type
 * @ptr: magic pointer.
 * Return: none
 */
void print_type(char *ptr)
{
	char type = ptr[16];

	if (ptr[5] == 1)
		type = ptr[16];
	else
		type = ptr[17];

	printf("  Type:                              ");
	if (type == 0)
		printf("NONE (No file type)\n");
	else if (type == 1)
		printf("REL (Relocatable file)\n");
	else if (type == 2)
		printf("EXEC (Executable file)\n");
	else if (type == 3)
		printf("DYN (Shared object file)\n");
	else if (type == 4)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", type);
}

/**
 * print_osabi - prints osabi
 * @ptr: magic pointer.
 * Return: none
 */
void print_osabi(char *ptr)
{
	char osabi = ptr[7];

	printf("  OS/ABI:                            ");
	if (osabi == 0)
		printf("UNIX - System V\n");
	else if (osabi == 2)
		printf("UNIX - NetBSD\n");
	else if (osabi == 6)
		printf("UNIX - Solaris\n");
	else
		printf("<unknown: %x>\n", osabi);

	printf("  ABI Version:                       %d\n", ptr[8]);
}


/**
 * print_version - prints version
 * @ptr: magic pointer.
 * Return: none
 */
void print_version(char *ptr)
{
	int version = ptr[6];

	printf("  Version:                           %d", version);

	if (version == EV_CURRENT)
		printf(" (current)");

	printf("\n");
}
/**
 * print_data - prints data
 * @ptr: magic pointer
 * Return: none
 */
void print_data(char *ptr)
{
	char data = ptr[5];

	printf("  Data:                              2's complement");
	if (data == 1)
		printf(", little endian\n");

	if (data == 2)
		printf(", big endian\n");
}
/**
 * print_magic - prints magic info.
 * @ptr: magic pointer.
 * Return: none
 */
void print_magic(char *ptr)
{
	int bytes;

	printf("  Magic:  ");

	for (bytes = 0; bytes < 16; bytes++)
		printf(" %02x", ptr[bytes]);

	printf("\n");

}

/**
 * check_sys - check the version system.
 * @ptr: magic pointer.
 * Return: no return.
 */
void check_sys(char *ptr)
{
	char syst = ptr[4] + '0';

	if (syst == '0')
		exit(98);

	printf("ELF Header:\n");
	print_magic(ptr);

	if (syst == '1')
		printf("  Class:                             ELF32\n");

	if (syst == '2')
		printf("  Class:                             ELF64\n");

	print_data(ptr);
	print_version(ptr);
	print_osabi(ptr);
	print_type(ptr);
	print_addr(ptr);
}

/**
 * check_elf - checks for an elf file.
 * @ptr: magic pointer.
 * Return: 1 if elf else 0
 */
int check_elf(char *ptr)
{
	int addr = (int)ptr[0];
	char E = ptr[1];
	char L = ptr[2];
	char F = ptr[3];

	if (addr == 127 && E == 'E' && L == 'L' && F == 'F')
		return (1);

	return (0);
}

/**
 * main - check the code for Holberton School students.
 * @argc: argument count.
 * @argv: arguments vector.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int fd, my_read;
	char ptr[27];

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);

	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "Err: file can not be open\n");
		exit(98);
	}

	lseek(fd, 0, SEEK_SET);
	my_read = read(fd, ptr, 27);

	if (my_read == -1)
	{
		dprintf(STDERR_FILENO, "Err: The file can not be read\n");
		exit(98);
	}

	if (!check_elf(ptr))
	{
		dprintf(STDERR_FILENO, "Err: It is not an ELF\n");
		exit(98);
	}

	check_sys(ptr);
	close(fd);

	return (0);
}
