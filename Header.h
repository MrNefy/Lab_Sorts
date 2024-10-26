#pragma once
#include <iostream>
#include <time.h>

using namespace std;
#define st_len 60000

void selection_sort(int arr[], int len);
void insertion_sort(int arr[], int len);
void bubble_sort(int arr[], int len);
void marge_sort(int arr[], int begin, int end);

void shell_sort(int arr[], int len);
void shell_hibbard(int arr[], int len);
void shell_pratt(int arr[], int len);

void quick_sort(int arr[], int begin, int end);
void heap_sort(int arr[], int n = st_len);



void printArray(int arr[], int max);