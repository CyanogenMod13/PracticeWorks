#include "util.h"
#include <stdio.h>
#include <stdlib.h>

float inline randomf(float start, float end)
{
	return start + (rand() / (float) RAND_MAX) * (end - start);
}

void print_array(float* arr, int n)
{
	for (int i = 0; i < n; i++)
		printf("%f ", arr[i]);
}

void print_array(float** arr, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%f ", arr[i][j]);
		printf("\n");
	}
}

float** create_matrix(int n, int m)
{
	float** matrix = new float* [n];
	for (int i = 0; i < n; i++)
		matrix[i] = new float[m];
	return matrix;
}

void delete_matrix(float** arr, int n, int m)
{
	for (int i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;
}

float** create_random_matrix(int n, int m)
{
	float** matrix = create_matrix(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			matrix[i][j] = randomf(-10, 10);
	return matrix;
}

float** minor(float** arr, int n, int i, int j)
{
	int rank = n - 1;
	float** m = create_matrix(rank, rank);
	int m_i = 0;
	int m_j = 0;
	for (int arr_i = 0; arr_i < n; arr_i++)
	{
		if (arr_i == i) continue;
		for (int arr_j = 0; arr_j < n; arr_j++)
		{
			if (arr_j == j) continue;
			m[m_i][m_j] = arr[arr_i][arr_j];
			m_j++;
		}
		m_i++;
		m_j = 0;
	}
	return m;
}

float determanite(float** arr, int n)
{
	if (n == 1) return arr[0][0];
	float sum = 0;
	for (int j = 0; j < n; j++)
	{
		float** m = minor(arr, n, 0, j);
		sum += determanite(m, n - 1) * ((j & 1) == 0 ? 1 : -1) * arr[0][j];
		delete_matrix(m, n - 1, n - 1);
	}
	return sum;
}