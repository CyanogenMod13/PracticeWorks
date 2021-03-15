#include <stdio.h>
#include "util.h"

int main()
{
	float** a = create_random_matrix(5, 5);
	print_array(a, 5, 5);
	printf("%f ", determanite(a, 5));
}