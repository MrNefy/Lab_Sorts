#include "Header.h"
#include <vector>

//1 selection_sort
//Сортировка выбором
void selection_sort(int arr[], int len) {
	for (int current = 0; current < len-1; current++)
	{
		int min = current;
		for (int i = current + 1; i < len; i++)
		{
			if (arr[i] < arr[min])
			{
				min = i;
			}
		}
		swap(arr[current], arr[min]);
	}
}

//2 insertion_sort
//Сортировка вставками
void insertion_sort(int arr[], int len) {
	for (int cur = 1; cur < len; cur++) {
		if (arr[cur - 1] > arr[cur]) {
			int temp = arr[cur];
			int i = cur;
			while (i > 0 && arr[i - 1] > temp)
			{
				arr[i--] = arr[i - 1];
			}
			arr[i] = temp;
		}
	}
}

//3 bubble_sort
//сортировка пузырьком
void bubble_sort(int arr[], int len) {
	for (int cur = len; cur > 1; cur--)
	{
		for (int i = 1; i < cur; i++)
		{
			if (arr[i - 1] > arr[i])
				swap(arr[i - 1], arr[i]);
		}
	}
}

//4 merge_sort
//сортировка слиянием
void marge_sort2(int arr[], int begin, int end, int* temp_arr) {
	if (end - begin > 0) {//последний элемент - первый последний элемент
		int mid = begin + (end - begin) / 2;
		marge_sort2(arr, begin, mid, temp_arr);//left array
		marge_sort2(arr, mid + 1, end, temp_arr);//right array
		int left = begin;
		int right = mid + 1;
		int i = 0;
		while (left <= mid && right <= end)
		{
			if (arr[left] <= arr[right])
			{
				temp_arr[i++] = arr[left++];
			}
			else
			{
				temp_arr[i++] = arr[right++];
			}
		}
		while (right <= end)
		{
			temp_arr[i++] = arr[right++];
		}
		while (left <= mid)
		{
			temp_arr[i++] = arr[left++];
		}
		for (i = 0; i <= end - begin; i++)
		{
			arr[begin + i] = temp_arr[i];
		}
	}
}

void marge_sort(int arr[], int begin, int end) {
	static int* temp_arr;
	temp_arr = new int[end+1];
	marge_sort2(arr, begin, end, temp_arr);
	delete[] temp_arr;
}