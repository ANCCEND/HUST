#include <stdio.h>

int main(void)
{
    float speed = 2, x = 0, s;
    scanf("%f", &s);
    int i = 0;
    while (x < s)
    {
        x += speed;
        speed *= 0.98;
        i++;
    }
    printf("%d", i);

    return 0;
}