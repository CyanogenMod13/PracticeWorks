#ifndef _UTIL_
#define _UTIL_

float randomf(float start, float end);

void print_array(float* arr, int n);

void print_array(float** arr, int n, int m);

float** create_matrix(int n, int m);

float** create_random_matrix(int n, int m);

float** minor(float** arr, int n, int i, int j);

float determanite(float** arr, int n);

#endif