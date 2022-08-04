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
	// переставить элементы по оси
	int pivot = partition(arr, start, end);

	// повторяем подмассив, содержащий элементы, меньшие опорной точки
	quicksort(arr, start, pivot - 1);

	// повторяем подмассив, содержащий элементы, превышающие точку опоры
	quicksort(arr, pivot + 1, end);

}