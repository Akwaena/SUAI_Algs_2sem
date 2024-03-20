#include "stdio.h"

int main ()
{
    float s, a, n, eps;
    int sign;
    printf("eps=");
    scanf ("%f", &eps);
    s=0;
    sign=1;
    n=1;
    a= (n+2)/(n*(n+1));
    while (a>eps)
    {
        printf("(%f)/(%f*%f)\n", n+2, n, n+1);
        s= s+sign*a;
        sign= -sign;
        n= n+1;
        a= (n+2)/(n*(n+1));
    }
    printf ("s=%f", s);
    return 0;
}