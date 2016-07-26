#include "complex.h"

void ditfft1(struct complex *input, struct complex *output, int size, int stride);


void ditfft(struct complex *input, struct complex *output, int size, int stride)
{
	if(size == 1)
	{
		complex_copy(input,output);
	}
}
