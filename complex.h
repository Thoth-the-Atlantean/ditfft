#include <math.h>

/*********************
*    Definitions     *
*********************/

#define PI 3.141592653

/******************************************************************************
  The data type complex models a complex number, which contains a real and
  imaginary component. This data type will be used to store complex values
  used in the Fast Fourier Transform (FFT).
******************************************************************************/
struct complex
{
	double real;
	double imaginary;
};

/************************
  Function Declarations
*************************/

void           print_complex(struct complex *obj);
void 	       complex_copy(struct complex *in, struct complex *out);
struct complex generate_complex(double real, double imaginary);
struct complex complex_exp(double argument);
struct complex complex_multiplication(struct complex *x, struct complex *y);
struct complex complex_addition(struct complex *x, struct complex *y);
double magnitude(struct complex *x);

void print_complex(struct complex *obj)
{
	printf("%f%s%fi\n",obj->real,(obj->imaginary>=0?"+":""),obj->imaginary);
}

void complex_copy(struct complex *in, struct complex *out)
{
	out->real = in->real;
	out->imaginary = in->imaginary;
}

struct complex generate_complex(double real, double imaginary)
{
	struct complex a;
	a.real = real;
	a.imaginary = imaginary;

	return a;
}

/*******************************************************************************
  Creates a complex number [type: struct complex]  with real and imaginary
  components corresponding to the expression e^(xi) = cos(x) + isin(x). 
  Argument is a double in units of radians.
*******************************************************************************/

struct complex complex_exp(double argument)
{
	struct complex a;

	a.real 		= cos(argument);
	a.imaginary 	= sin(argument);

	return a;
}

/******************************************************************************
  Performs complex multiplication (distribution) using values stored in 
  complex structures which are accessed via pointers. The returned value
  has type struct complex and can be saved.
******************************************************************************/ 

struct complex complex_multiplication(struct complex *x, struct complex *y)
{
	struct complex output;

	output.real = ( x->real * y->real ) - (x->imaginary * y->imaginary);
	output.imaginary = (x->real * y->imaginary) + (x->imaginary * y->real);

	return output;
}



/*****************************************************************************
  Adds real components and imaginary components of the structures the pointers
  x and y point to. Returns a struct with type complex.
*****************************************************************************/
struct complex complex_addition(struct complex *x, struct complex *y)
{
	struct complex output;

	output.real = (x->real + y->real);
	output.imaginary = (x->imaginary + y->imaginary);
	return output;
}

double magnitude(struct complex *x)
{
	return sqrt(pow(x->real,2)+pow(x->imaginary,2));
}
