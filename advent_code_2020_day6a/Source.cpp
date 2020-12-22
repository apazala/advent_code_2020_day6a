#include <stdio.h>
#include <string.h>

int main() {
	char line[32];
	char present[26] = { 0 };

	FILE *fin = fopen("input.txt", "r");
	if (!fin) {
		fprintf(stderr, "Unable to open input file\n");
		return 1;
	}

	int count = 0;
	while (fgets(line, sizeof(line), fin)) {
		if (line[0] == '\n') {
			memset(present, 0, sizeof(present));
		}
		else {
			for (char *p = line; *p >= 'a'; p++) {
				int i = (*p) - 'a';
				if (!present[i]) {
					present[i] = 1;
					count++;
				}
			}
		}
	}

	printf("%d\n", count);

	fclose(fin);
	return 0;
}