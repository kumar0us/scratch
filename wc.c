#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv)
{
    FILE *fp = NULL;
    char *fname = NULL;
    int word_count = 0;
    char buf[64*1024] = {0,};

    if (argc != 2)
    {
	printf ("Usage: %s <text-file-name>\n", argv[0]);
	return 1;
    }

    fname = argv[1];
    fp = fopen (fname, "r");
    if (fp == NULL)
    {
	printf ("Failed to open file %s for reading. err = %d(%s)\n",
		fname, errno, strerror(errno));
	goto out;
    }

    while (fscanf(fp, "%s", buf) == 1)
    {
	word_count++;
    }

    printf ("word: %d\n", word_count);

out:
    if (fp)
    {
	fclose (fp);
    }
}
