#pragma once
#include <iostream>
int partition(int arr[], int start, int end)
{
	int pivot = arr[end];
	int pindex = start;
	for (size_t i = start; i < end; i++)
	{
		if (arr[i] <= pivot)
		{
			std::swap(arr[i], arr[pindex]);
				pindex++;
		}
	}
	std::swap(arr[pindex], arr[end]);
	return pindex;
}
void quicksort(int arr[], int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int pivot = partition(arr, start, end);


	quicksort(arr, start, pivot - 1);
	quicksort(arr, pivot + 1, end);

}
