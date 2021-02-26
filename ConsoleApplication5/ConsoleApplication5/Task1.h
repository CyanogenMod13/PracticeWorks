#ifndef _Task1_
#define _Task1_

#include <iostream>
#include "Utility.h"

void task1()
{
	unsigned long N, M;

	std::cout << "Enter N: ";
	std::cin >> N;
	std::cout << "Enter M: ";
	std::cin >> M;

	long** matrix = new long* [N];
	for (int i = 0; i < N; i++)
	{
		matrix[i] = new long[M];
		for (int j = 0; j < M; j++)
			matrix[i][j] = random(0, 10);
		bubble_sort(matrix[i], M, i & 1);
	}

	print(matrix, N, M);

	if (N != M)
	{
		std::cout << "1. Square matrix" << std::endl;
		long count = labs(M - N);
		long** tmp = new long* [M];
		if (M > N)
		{
			for (int i = 0; i < N; i++)
				tmp[i] = matrix[i];
			for (int i = N; i < M; i++)
			{
				tmp[i] = new long[M];
				for (int j = 0; j < M; j++)
					tmp[i][j] = random(0, 10);
				bubble_sort(tmp[i], M, i & 1);
			}
		}
		else if (M < N)
		{
			for (int i = 0; i < M; i++)
				tmp[i] = matrix[i];
			for (int i = M; i < N; i++)
				delete[] matrix[i];
		}
		delete[] matrix;
		matrix = tmp;
		print(matrix, M, M);
	}

	std::cout << "2. " << std::endl;
	long min = matrix[0][M - 1];
	for (int i = 1; i < M; i++)
	{
		min = min(min, matrix[i][])
	}
}

#endif // !Task1