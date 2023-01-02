#include <sys/types.h>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

#define ARRAYS_NUM 100
#define ARRAY_SIZE 10000

void fill_array(int * arr)
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		arr[i] = rand() % 100 + 1;
	}
}

void print_array(const int * arr)
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		printf("%d\n", arr[i]);
	}
}

void bubble_sort_array(int * arr)
{
	int tmp;

	for (int i = 1; i < ARRAY_SIZE; i++)
	{
		for (int j = 1; j < ARRAY_SIZE; j++)
		{
			if (arr[j] > arr[j-1])
			{
				tmp      = arr[j];
				arr[j]   = arr[j-1];
				arr[j-1] = tmp;
			}
		}
	}
}

void save_arr_in_file(const int * arr, int arr_num)
{
	FILE * f;
	char path[16];

	snprintf(path, sizeof(path), "%d.arr", arr_num);

	f = fopen(path, "w");
	if (f == NULL)
	{
		perror("fopen failed");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		fprintf(f, "%d\n", arr[i]);
	}

	fclose(f);
}

int main(int argc, char const *argv[])
{
	int arrays[ARRAYS_NUM][ARRAY_SIZE];

	for (int i = 0; i < ARRAYS_NUM; i++)
	{
		fill_array(arrays[i]);
	}

	for (int i = 0; i < ARRAYS_NUM; i++)
	{
		pid_t ret = fork();
		if (ret < 0)
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
		}
		if (ret == 0) //child
		{
			bubble_sort_array(arrays[i]);
			save_arr_in_file(arrays[i], i);
			exit(EXIT_SUCCESS);
		}
	}

	for (int i = 0; i < ARRAYS_NUM; i++)
	{
		wait(NULL);
	}

	exit(EXIT_SUCCESS);
}

/*
int main(int argc, char const *argv[])
{
	int arrays[ARRAYS_NUM][ARRAY_SIZE];

	for (int i = 0; i < ARRAYS_NUM; i++)
	{
		fill_array(arrays[i]);
	}

	for (int i = 0; i < ARRAYS_NUM; i++)
	{
		bubble_sort_array(arrays[i]);
		save_arr_in_file(arrays[i], i);
	}

	exit(EXIT_SUCCESS);
}
*/
