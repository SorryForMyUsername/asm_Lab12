#include "stdio.h"
#include "conio.h"

int main()
{
    double x = 1, y = 6, z = 1, min, f;
    __asm {
        fld z
        fld y
        fld x
        fadd st(0), st(1)
        fld1
        fadd st(0), st(0)
        fdiv st(3), st(0)
        fxch st(3)
        fadd st(0), st(1)
        fld z
        fld x
        fmul st(0), st(4)
        fmul st(0), st(1)

        fcom st(2)
        fstsw ax
        sahf
        ja p1
        fst min
        jmp p3
    p1:
        fxch st(2)
        fst min
    p3:
        fld1
        fld min
        fmul st(0), st(0)
        fadd st(0), st(1)
        fstp f
    }
    printf("\t min==> %g\n", f);
    _getch();
    return 0;
}
