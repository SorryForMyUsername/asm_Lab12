#include "stdio.h"
#include "conio.h"

int main()
{
    double a = 1.1;
    __asm {
        fld1
        fldz
        fld a
        fcom st(1)
        fstsw ax
        sahf
        jb l1

        fadd st(0), st(2)
        jmp p1
    l1:
        fabs
    p1:
        fstp a
    }
    printf("\t a==> %g\n",a);
    _getch();
    return 0;
}
