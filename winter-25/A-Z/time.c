#include <stdio.h>
#include <string.h>
void flip(char *, char *, char *);

int main(void)
{
    char s[101], flip1[101], flip2[101];
    scanf("%s", s);
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {
        flip1[i] = s[i];
        flip2[i] = s[i];
    }
    flip1[i] = '\0';
    flip2[i] = '\0';
    flip(s, flip1, flip2);

    return 0;
}

void flip(char s[], char flip1[], char flip2[])
{
    int flag = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        for (int j = i + 1; s[j] != '\0'; j++)
        {
            char *x = flag ? flip1 : flip2;
            int m = i, n = j;
            for(int i=0;s[i]!='\0';i++){
                x[i]=s[i];
            }
            while (n >= m)
            {
                x[n] = s[m];
                x[m] = s[n];
                n--, m++;
            }
            if (strcmp(flip1, flip2) <= 0)
                flag = 0;
            else
                flag = 1;
        }
    }
    char *x = strcmp(flip1, flip2) <= 0 ? flip1 : flip2;
    printf("%s", x);
}