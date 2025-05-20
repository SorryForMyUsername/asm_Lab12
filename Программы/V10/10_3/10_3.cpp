#include "stdio.h"
#include "conio.h"

int main()
{
	double x, y;
	printf("x: ");
	scanf_s("%lf", &x);

	__asm {
		fldz
		fld x
		fcomi st(0), st(1)
		jae XisPositive
		  fcos
		  fmul st(0), st(0)
		  fmul st(0), st(0)
		  jmp asmEnd
	XisPositive:
		fld1
		fld1
		fadd st(0), st(1)
		fdivp st(1), st(0)
		fxch st(1)
		fcomi st(0), st(1)
		ja XgreaterThen05 
		  f2xm1
		  fld1
		  fld1
		  fadd st(0), st(1)
		  fadd st(1), st(0)
		  fmulp st(1), st(0)
		  fsubp st(1), st(0)
		  jmp asmEnd
	XgreaterThen05:
		fld1
		fld st(1)
		fmul st(0), st(0)
		fadd st(0), st(1)
		fxch st(1)
		fsubp st(2), st(0)
		fmul st(0), st(1)
	asmEnd:
		fstp y
	}

	printf("\nf(x) = %lf", y);

	return 0;
}