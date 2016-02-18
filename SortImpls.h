#pragma once

#include <array>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

void BubbleSort(vector <int> &arr, int start, int end);
void InsertSort(vector <int> &arr, int start, int end);
void MergeSort(vector <int> &arr, int start, int end);
void IterativeMergeSort(vector <int> &arr, int start, int end);
void QuickSort(vector <int> &arr, int start, int end);
void Merge(vector <int> &arr, int first, int mid, int last);
void partition(vector<int> &a, int first, int last, int &pivotIndex);

int mini(const int a, const int b);

void PrinArray(const vector<int> &array, string name);

void IterativeMerge(vector<int> &arr, vector<int>&temp, int first, int mid, int last);

void choosePivot(vector<int> &a, int first, int last);


void Swap(int &val1, int &val2);

void BubbleSort(vector <int> &arr, int start, int end)
{
	bool sorted = false;
	int pass = 1;
	int size = end + 1;
	while (!sorted && (pass < size))
	{
		sorted = true;
		for (int index = 0; index < size - pass; index++)
		{
			if (arr[index] > arr[index + 1])
			{
				Swap(arr[index], arr[index + 1]);
				sorted = false;
			}
		}
		pass++;
	}
}

void Swap(int &val1, int &val2)
{
	int temp = val1;
	val1 = val2;
	val2 = temp;
}

void InsertSort(vector<int> &arr, int start, int end)
{
	for (int place = 1; place < end + 1; place++)
	{
		int temp = arr[place];
		int i = place;
		while ((i > 0) && (arr[i - 1] > temp))
		{
			arr[i] = arr[i - 1];
			i--;
		}
		arr[i] = temp;
	}
}

void MergeSort(vector <int> &arr, int first, int last)
{
	if (first < last)
	{
		int mid = first + (last - first) / 2;
		MergeSort(arr, first, mid);
		MergeSort(arr, mid + 1, last);
		Merge(arr, first, mid, last);
	}
}

void Merge(vector <int> &arr, int first, int mid, int last)
{
	vector<int> temp(arr.size());

	int first1 = first;
	int last1 = mid;
	int first2 = mid + 1;
	int last2 = last;

	int index = first1;
	while ((first1 <= last1) && (first2 <= last2))
	{
		if (arr[first1] <= arr[first2])
		{
			temp[index] = arr[first1];
			first1++;
		}
		else
		{
			temp[index] = arr[first2];
			first2++;
		}
		index++;
	}

	while (first1 <= last1)
	{
		temp[index] = arr[first1];
		first1++;
		index++;
	}
	while (first2 <= last2)
	{
		temp[index] = arr[first2];
		first2++;
		index++;
	}
	for (index = first; index <= last; index++)
	{
		arr[index] = temp[index];
	}
}

void QuickSort(vector <int> &arr, int first, int last)
{		int pIndex;

		if (first < last)
		{
		partition(arr, first, last, pIndex);
		QuickSort(arr, first, pIndex - 1);
		QuickSort(arr, pIndex + 1, last);
		}/*
	if (last - first < 4)
	{
		InsertSort(arr, first, last);
		return;
	}
	else
	{
		int mid = (first + last) / 2;

		if (arr[first] > arr[mid])
		{
			Swap(arr[first], arr[mid]);
		}
		if (arr[mid] > arr[last])
		{
			Swap(arr[mid], arr[last]);
		}
		if (arr[first] > arr[mid])
		{
			Swap(arr[first], arr[mid]);
		}

		int pivot = arr[mid];
		Swap(arr[mid], arr[last - 1]);

		int left = first + 1;
		int right = last - 2;
		bool done = false;
		while (!done)
		{

			while ((arr[left] < pivot))
			{
				left++;
			}
			while (arr[right] > pivot)
			{
				right--;
			}
			if (left < right)
			{
				Swap(arr[right], arr[left]);
				right--;
				left++;
			}
			else
			{
				done = true;
			}
		}
		Swap(arr[left], arr[last - 1]);
		QuickSort(arr, first, left - 1);
		QuickSort(arr, left + 1, last);
	}*/
}


void partition(vector<int> &a, int first, int last, int &pIndex)
{
	choosePivot(a, first, last);
	int pivot = a[first];
	int last1 = first;
	int firstUK = first + 1;
	for (; firstUK <= last; ++firstUK)
	{
		if (a[firstUK] < pivot)
		{
			++last1;
			Swap(a[firstUK], a[last1]);
		}
	}
	Swap(a[first], a[last1]);
	pIndex = last1;
}
void choosePivot(vector<int> &a, int first, int last)
{
	int middle = (first + last) / 2;
	Swap(a[first], a[middle]);
}

void IterativeMergeSort(vector <int> &arr, int start, int end)
{
	vector<int> temp(arr.size());
	int left, right, mid, size, arraySize;

	bool check = false;
	for (size = 1; size < arr.size(); size = 2 * size)
	{
		if (check == false)
		{
			for (int i = 0; i < arr.size() - size; i += 2 * size)
			{
				left = i;
				mid = i + size - 1;
				right = mini((i + size + size - 1), arr.size() - 1);
				IterativeMerge(arr, temp, left, mid, right);
			}
			check = true;
		}
		else
		{
			for (int i = 0; i < arr.size() - size; i += 2 * size)
			{
				left = i;
				mid = i + size - 1;
				right = mini((i + size + size - 1), arr.size() - 1);
				IterativeMerge(temp, arr, left, mid, right);
			}
			check = false;
		}
	}
}


void IterativeMerge(vector<int> &arr, vector<int>&temp, int first, int mid, int last)
{
	int first1 = first;
	int last1 = mid;
	int first2 = mid + 1;
	int last2 = last;

	int index = first1;
	while ((first1 <= last1) && (first2 <= last2))
	{
		if (arr[first1] <= arr[first2])
		{
			temp[index] = arr[first1];
			first1++;
		}
		else
		{
			temp[index] = arr[first2];
			first2++;
		}
		index++;
	}

	while (first1 <= last1)
	{
		temp[index] = arr[first1];
		first1++;
		index++;
	}
	while (first2 <= last2)
	{
		temp[index] = arr[first2];
		first2++;
		index++;
	}
}

int mini(const int a, const int b)
{
	if (a <= b)
	{
		return a;
	}
	else
	{
		return b;
	}
}