#include "Header.h"

//6 quick sort
//������� ����������
void quick_sort(int arr[], int low, int high) {
	if (high - low > 0)
	{
		int point = low + abs(rand()) % (high - low + 1);//��������� �������� �������
		int l = low;
		int r = high;
		while (1)
		{
			if (arr[point] > arr[l])
				l++;
			else
			{
				swap(arr[l], arr[point]);
				point = l;
				break;
			}
		}
		int side = 1;
		while (r != l)
		{
			if (side)
			{
				if (arr[point] <= arr[r])//9. � 10 ��������
					r--;
				else
				{
					swap(arr[r], arr[point]);
					point = r;
					l++;
					side = 0;
				}
			}
			else
			{
				if (arr[l] < arr[point])
					l++;
				else
				{
					swap(arr[l], arr[point]);
					point = l;
					r--;
					side = 1;
				}
			}
		}
		quick_sort(arr, low, point - 1);
		quick_sort(arr, point + 1, high);
	}
}