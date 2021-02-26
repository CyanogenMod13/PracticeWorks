#ifndef _Utility_
#define _Utility_

#include <iostream>
#include <cmath>

inline long random(long start, long end)
{
	return start + (rand() + 1) % (end - start + 1);
}

inline long min(long a, long b)
{
	return a > b ? b : a;
}

inline void print(long** arr, long N, long M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

inline void print(long* arr, long N)
{
	for (int i = 0; i < N; i++)
	{
		std::cout << arr[i] << " ";
	}
}

inline void swap(long& a, long& b)
{
	long c = b;
	b = a;
	a = c;
}

void bubble_sort(long* arr, long size, bool oder = 0)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			if (i == j) continue;
			if (arr[i] < arr[j] && oder || arr[i] > arr[j] && !oder)
			{
				swap(arr[i], arr[j]);
				continue;
			}
		}
}

#endif // !_Utility_
