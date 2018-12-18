#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_MAX_LEN 100
#define DATA_MAX_LEN 500
#define NUM_OF_NUMS  4

int main(void) {
	FILE *file;
	int i;
	float nums[NUM_OF_NUMS];
	char c = '\0', name[NAME_MAX_LEN], buffer[DATA_MAX_LEN];

	if((file = fopen("input.txt", "r")) == NULL) {
		printf("File open failed.\n");
		return 1;
	}

	while(1) {
		if (fgets(name, NAME_MAX_LEN, file) == NULL)
			break;

		if (fgets(buffer, DATA_MAX_LEN, file) == NULL)
			break;

		for (i = 0; i < NUM_OF_NUMS; ++i) {
			if (sscanf(buffer, "%f %f %f %f", &nums[0], &nums[1], &nums[2], &nums[3], &nums[4]) == EOF) {
				printf("File malformed; %d numbers expected for %s.\n", NUM_OF_NUMS, name);
				fclose(file);
				return 1;
			}
		}

		printf("Name is: %s", name);
		for (i = 0; i < NUM_OF_NUMS; ++i)
			printf("Number %d is: %.2f\n", i, nums[i]);
		printf("\n");
	}

	fclose(file);

	return 0;
}
