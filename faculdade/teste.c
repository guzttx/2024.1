#include <stdio.h>
#include <stdlib.h>

    int main() 
{
    char c1, c2;
    char s1[20];
    int cont = 0, i;

    printf("Digite uma palavra: \n");
    fgets(s1, sizeof(s1), stdin);

    printf("Digite um caracter: \n");
    fflush(stdin);
    //scanf(" %c", &c1);
    c1 = getchar();

    printf("Digite outro caracter: \n");
    fflush(stdin);
    //scanf(" %c", &c2);
    c2 = getchar();

    for (i = 0;i < sizeof(s1); i++)
    {
        if (s1[i] == c1)
        {
            s1[i] = c2;
            //cont++;
        }
    }

    //printf("%d\n", cont);

    puts(s1);

    return 0;
} 
