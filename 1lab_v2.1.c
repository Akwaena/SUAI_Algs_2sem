#include <stdio.h>

int main()
{
    float v1, v2, t;
    float t1, s;

    printf("v1=");
    if (scanf("%f", &v1) != 1 || v1 <= 0)
    {
        printf("Error");
        return -1;
    }

    printf("v2=");
    if (scanf("%f", &v2) != 1 || v2 >= v1 || v2 <= 0)
    {
        printf("Error");
        return -1;
    }

    printf("%d", v2 >= v1);

    printf("t=");
    if (scanf("%f", &t) != 1 || t < 0)
    {
        printf("Error");
        return -1;
    }

    t1 = t / 3600;
    s = v1 * t1 + ((v2 - v1) * t1) / 2;

    printf("distance=%.2f km\n", s);

    return 0;
}