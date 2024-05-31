#include <stdio.h>
#include <stdlib.h>

void string_circular (char str[], char dir, int n)
{
    int i, resto, size = 0;
    char aux;

    for(i = 0; str[i] != '\0'; i++)
    {
        size++;
        if(str[i] == ' ')
        {
            str[i] = '\0';
            size = i;
        }
    }

    resto = n % size;
    
    if (dir == 'd')
    {
        while(resto!=0)
        {
            aux = str[size-1];
            for(i = (size-1); i > 0; i--)
            {
                str[i] = str[i-1];
            }
            str[0] = aux;
            resto--;
        }
    }

    if (dir == 'e')
    {
        resto = size - resto;
        while(resto!=0)
        {
            aux = str[size-1];
            for(i = (size-1); i > 0; i--)
            {
                str[i] = str[i-1];
            }
            str[0] = aux;
            resto--;
        }
    }
}

int main() 
{
    char s1[20], dir, continuar;
    int i, deslocamento;

    do
    {
        printf("String: ");
        scanf("%s", s1);

        fflush(stdin);

        do 
        {
            printf("Direcao ('d' ou 'e'): ");
            scanf(" %c", &dir);
            
            if (dir != 'd' && dir != 'e')
            {
                printf("Direcao invalida!\n");
            }
            fflush(stdin);
        } while (dir != 'd' && dir != 'e');

        do 
        {
            printf("Deslocamentos (> 0): ");
            scanf("%d", &deslocamento);

            if(deslocamento < 0)
            {
                printf("Deslocamento invalido!\n");
            }
            fflush(stdin);
        } while (deslocamento <= 0);

        string_circular(s1, dir, deslocamento);

        printf("String final: %s", s1);
        fflush(stdin);

        do 
        {
            printf("\nContinuar ('s' ou 'n')?");
            scanf(" %c", &continuar);
            
            if(continuar != 's' && continuar != 'n')
            {
                printf("Opcao invalida!\n");
            }
            
            fflush(stdin);
        } while (continuar != 's' && continuar != 'n');
        
        fflush(stdin);

    } while (continuar == 's');

    printf("\n* fim *\n");

    return 0;

}