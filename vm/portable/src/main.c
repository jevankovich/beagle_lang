#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#include <elf.h>

int main(int argc, char **argv) {
	if (argc != 2) return 1;
	int file = open(argv[1], O_RDONLY);

	struct stat stats;
	if (fstat(file, &stats)) return 2;

	char *data = mmap(NULL, stats.st_size, PROT_READ, MAP_SHARED, file, 0);

	printf("%.1000s", data);

	return 0;
}
