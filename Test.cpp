#include "Header.h"
#include <fstream>

void arr_copy(int arr[], int copy[]) {
	for (int i = 0; i < st_len; i++)
	{
		arr[i] = copy[i];
	}
}

int main() {
	static int arr[st_len]{};
	static int copy[st_len]{};
	srand(time(0));
	for (int i = 0; i < st_len; i++)
	{
		arr[i] = rand();
		copy[i] = arr[i];
		//cout << arr[i] << ' ';
	}
	ofstream txt("results_time.txt", ios::app);
	for (int step = 0; step < 50001; step += 10000)
	{
		txt << '\t' << st_len - step << '\n';
		for (int i = 1; i <= 4; i++) {
			clock_t tStart = clock();
			switch (i) {
			case 1: selection_sort(arr, st_len - step); break;	//сортировка выбором
			case 2: insertion_sort(arr, st_len - step); break;	//сортировка вставками
			case 3: bubble_sort(arr, st_len - step); break;		//сортировка пузырьком
			case 4: marge_sort(arr, 0, st_len - step - 1);		//сортировка слиянием
			}
			txt << (double)(clock() - tStart) / CLOCKS_PER_SEC << '\n';
			printf("\nTime taken: %.3fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
			cout << i << '\n';
			//printArray(arr, st_len - step);
			arr_copy(arr, copy);
		}
		//сортировка Шелла (последовательность Шелла, Хиббарда, Пратта)
		for (int i = 1; i <= 3; i++) {
			clock_t tStart = clock();
			switch (i) {
			case 1: shell_sort(arr, st_len - step); break;		//послед. Шелла
			case 2: shell_hibbard(arr, st_len - step); break;	//послед. Хиббарда
			case 3: shell_pratt(arr, st_len - step);			//послед. Пратта
			}
			txt << (double)(clock() - tStart) / CLOCKS_PER_SEC << '\n';
			printf("\nTime taken: %.3fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
			cout << i << " + 4 (shell)\n";
			//printArray(arr, st_len - step);
			arr_copy(arr, copy);
		}
		for (int i = 1; i <= 2; i++) {
			clock_t tStart = clock();
			switch (i) {
				// быстрая сортировка
			case 1: quick_sort(arr, 0, st_len - step - 1); break;
				// пирамидальная сортировка
			case 2: heap_sort(arr, st_len - step);
			}
			txt << (double)(clock() - tStart) / CLOCKS_PER_SEC << '\n';
			printf("\nTime taken: %.3fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);//\n\n\n\n
			cout << i << " + 7\n";
			//printArray(arr, st_len - step);
			arr_copy(arr, copy);
		}
		cout << "\n\n\n\n\n";
	}
	txt.close();
	return 0;
}

void printArray(int arr[], int max)
{
	for (int i = 0; i < max; ++i)
		cout << arr[i] << ' ';
	cout << "\n";
}