#include "stdio.h"
#include "conio.h"

int main()
{
	double arr[] = { 11.1445, 3.00124, 2.5235 };

	int count = 0;

	__asm {
		mov esi, 0
		mov ecx, 0

		fild count
		fld1
		fld st(0)
		fadd st(1), st(0)
		fadd st(1), st(0)

		fld arr[esi*8]
		fcomi st(0), st(1)
		jbe second
		  fcomi st(0), st(2)
		  jae second
		    fxch st(3)
			fadd st(0), st(1)
			inc ecx
			fxch st(3)
	second:
		fstp st(0)
		inc esi
		
		fld arr[esi*8]
		fcomi st(0), st(1)
		jbe third
		  fcomi st(0), st(2)
		  jae third
		    fxch st(3)
		    fadd st(0), st(1)
			fld arr[esi*8]
			fstp arr[ecx*8]
			inc ecx
		    fxch st(3)
	third:
		fstp st(0)
		inc esi

		fld arr[esi * 8]
		fcomi st(0), st(1)
		jbe asmEnd
		  fcomi st(0), st(2)
		  jae asmEnd
		    fxch st(3)
		    fadd st(0), st(1)
		    fld arr[esi * 8]
		    fstp arr[ecx * 8]
		    inc ecx
		    fxch st(3)

	asmEnd:
		fxch st(3)
		fistp count
	}

	for (int i = 0; i < count; i++) {
		printf("\n %lf", arr[i]);
	}

	return 0;
}