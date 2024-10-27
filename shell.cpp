#include "Header.h"

//5 shell_sort
//сортировка Шелла (последовательность Шелла, Хиббарда, Пратта)
int set_d(int d, int num)
{
	int n = 1;
	switch (num)
	{
	case 1:
		return d / 2;
	case 2:
		while (n << 1 < d + 1) n <<= 1;
		return n - 1;
	case 3:
		if (d > 1) {
			while (pow(2, n) * pow(3, n) <= d >> 1) n++;
			return (int)pow(2, n - 1) * pow(3, n - 1);
		}
		return 0;
	}
}

void lets_shell(int arr[], int len, int d, int num) {
	if (d > 0)
	{
		for (int l = d; l < len; l += d) {
			int tmp = arr[l];
			int r = l;
			while (tmp < arr[r - d] && r - d >= 0)
			{
				arr[r] = arr[r - d];
				r -= d;
			}
			arr[r] = tmp;
		}
		lets_shell(arr, len, set_d(d, num), num);
	}
}

void shell_sort(int arr[], int len) { lets_shell(arr, len, set_d(len, 1), 1); }
void shell_hibbard(int arr[], int len) { lets_shell(arr, len, set_d(len, 2), 2); }
void shell_pratt(int arr[], int len) { lets_shell(arr, len, set_d(len, 3), 3); }