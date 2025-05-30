#include "stdio.h"
#include "conio.h"

int main() 
{
	double x, y, z, max;
	printf("x: ");
	scanf_s("%lf", &x);
	printf("y: ");
	scanf_s("%lf", &y);
	printf("z: ");
	scanf_s("%lf", &z);

	__asm {
		fld x
		fld y
		fld z

		fcom st(1)
		fstsw ax
		sahf
		ja XorZ
		  fxch st(1)
		  fcom st(2)
		  fstsw ax
		  sahf
		  jb Zmax
		    fstp max
			jmp asmEnd
	XorZ:
		fcom st(2)
		fstsw ax
		sahf
		jb Zmax
		  fstp max
		  jmp asmEnd
	Zmax:
		fxch st(2)
		fstp max
	asmEnd:
	}

	printf("\nmax = %lf", max);

	return 0;
}