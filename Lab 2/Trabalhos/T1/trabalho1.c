#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct 
{
    int code;
    char name[80];
    float weight;
    int height;
    float imc;
    char zone[15];
} Pessoa;

void fill_array(Pessoa *person, int size)
{
    int i,j;
    for(i=0; i<size; i++) 
    {
        printf("\nDigite o nome da pessoa %d: ", i+1);
        fflush(stdin);
        fgets(person[i].name, 80, stdin);
        for(j=0; j<80; j++)
        {
            if(person[i].name[j] == '\n')
            {
                person[i].name[j] = '\0';
            }
        }

        printf("\nDigite o codigo da pessoa %d: ", i+1);
        scanf("%d", &person[i].code);
        
        printf("\nDigite o peso da pessoa  %d: ", i+1);
        scanf("%f", &person[i].weight);
        
        printf("\nDigite a altura da pessoa %d: ", i+1);
        scanf("%d", &person[i].height);

        person[i].imc = person[i].weight / pow((float)person[i].height / 100, 2);

        if (person[i].imc < 18.5)
        {
            strcpy(person[i].zone, "Magreza");
        }
        else if (person[i].imc > 18.5 && person[i].imc < 24.9)
        {
            strcpy(person[i].zone, "Normal");
        }
        else if(person[i].imc > 24.9 && person[i].imc < 30)
        {
            strcpy(person[i].zone, "Sobrepeso");
        }
        else
        {
            strcpy(person[i].zone, "Obesidade");
        }
    }
}

void clear_array(Pessoa *person, int size)
    {
        int i;
        for(i=0; i<size; i++) 
        {
            person[i].code = 0;
            strcpy(person[i].name, "NULL");
            person[i].weight = 0.0;
        }
    }

void print_overweightname(Pessoa *person, int size)
{
    int i, op = 0;
    for (i=0; i<size; i++)
    {
        if(person[i].imc > 24.9 && person[i].imc < 30)
        {
            fputs(person[i].name, stdout);
            printf(" ");
        }
    }
}

float average_weight(Pessoa *person, int size)
{
    int i;
    float soma=0;

    for(i=0;i<size;i++)
    {
        soma += person[i].weight; 
    }

    soma = soma/size;

    return soma;
}

void print_obesitycode(Pessoa *person, int size)
{
    int i;   

    printf("O codigo das pessoas com obesidade eh: ");

    for (i=0;i<size;i++)
    {        
        if(person[i].imc > 30)
        {
            printf("%d ", person[i].code);
        }
    }
}

void print_array(Pessoa *person, int size)
    {
        int i;
        for(i=0; i<size; i++) 
        {
            printf("\nO nome da pessoa %d eh: ", i+1);
            fputs(person[i].name, stdout);
            printf("\nO codigo da pessoa %d eh: %d ", i+1, person[i].code);
            printf("\nO peso da pessoa %d eh: %.2f ", i+1, person[i].weight);
            printf("\nA altura da pessoa %d eh: %d ", i+1, person[i].height);
            printf("\nO IMC da pessoa %d eh: %.2f ", i+1, person[i].imc);
            printf("\nA faixa da pessoa %d eh: %s \n", i+1, person[i].zone);
        }
        printf("\n");
    }

void overaverageweight_number(Pessoa *person, int size, float media)
{
    int i, cont = 0;
    for(i=0; i<size; i++)
    {
        if(person[i].weight > media)
        {
            cont++;
        }
    }

    printf("O numero de pessoas acima do peso medio eh: %d\n", cont);
}

void notnormal_number(Pessoa *person, int size)
{
    int i, cont = 0;

    for(i=0; i<size; i++)
    {
        if(person[i].imc < 18.5 || person[i].imc > 24.9)
        {
            cont++;
        }
    }

    printf("O numero de pessoas que nao estao na faixa de peso normal eh: %d\n", cont);
}

void normal_underaveragename(Pessoa *person, int size, float media)
{
    int i;

    printf("O(s) nome(s) da(s) pessoa(s) que estao na faixa normal de peso e pesam menos que o valor medio dos pesos eh(sao):\n");

    for(i=0; i<size; i++)
    {
        if ( person[i].imc < 24.9 && person[i].imc > 18.5 && person[i].weight < media)
        {
            fputs(person[i].name, stdout);
            printf(" ");
        }
    }
}

void greater_imc(Pessoa *person, int size)
{
    float greater = 0; 
    int i;
    int cont = 0;
    for(i=0;i<size;i++)
    {
        if(person[i].imc > greater)
        {
            greater = person[i].imc;
        }
    }
    
    printf("O(s) nome(s) da(s) pessoa(s) com o maior IMC eh(sao):\n");
    
    for(i=0;i<size;i++)
    {
        if(person[i].imc == greater)
        {
            fputs(person[i].name, stdout);
        }
    }

    printf("\n");
}

void lower_imc(Pessoa *person, int size)
{
    float lower = 1000; 
    int i;
    int cont = 0;
    for(i=0;i<size;i++)
    {
        if(person[i].imc < lower)
        {
            lower = person[i].imc;
        }
    }

    printf("O(s) nome(s) da(s) pessoa(s) com o menor IMC eh(sao):\n");

    for(i=0;i<size;i++)
    {
        if(person[i].imc == lower)
        {
            fputs(person[i].name, stdout);
        }
    }
    printf("\n");
}

int main()
{
    int array_size;
    int i;

    printf("\nDigite o numero de pessoas a serem cadastradas: ");
    scanf("%d", &array_size);

    Pessoa person[array_size];

    clear_array(person, array_size);
    
    fill_array(person, array_size);

    int option;
    int sair = 0;
    float media;
    media = average_weight(person, array_size);

    do
    {
        printf("\n\nSelecione uma opcao:\n");
        printf("1 - Imprimir as informacoes de todos os cadastrados\n");
        printf("2 - Imprimir o nome das pessoas com sobrepeso\n");
        printf("3 - Imprimir o codigo das pessoas com obesidade\n");
        printf("4 - O valor medio dos pesos\n");
        printf("5 - A quantidade de pessoas com peso acima da media\n");
        printf("6 - A quantidade de pessoas que nao estao na faixa normal de peso\n");
        printf("7 - O nome das pessoas que estao na faixa normal de peso e pesam menos que o valor medio dos pesos\n");
        printf("8 - O nome da(s) pessoa(s) que obteve(obtiveram) o maior IMC\n");
        printf("9 - O codigo da(s) pessoa(s) que obteve(obtiveram) o menor IMC\n");
        printf("0 - Sair\n");

        scanf("%d", &option);

        switch (option)
        {
        case 1:
            print_array(person, array_size);
            break;
        
        case 2:
            print_overweightname(person, array_size);
            break;
        
        case 3:
            print_obesitycode(person, array_size);
            break;
        
        case 4:
            printf("\nO valor medio dos %d pesos eh %.2f", array_size, media);
            break;
        
        case 5:
            overaverageweight_number(person, array_size, media);
            break;
        
        case 6:
            notnormal_number(person, array_size);
            break;
        
        case 7:
            normal_underaveragename(person, array_size, media);
            break;
        
        case 8:
            greater_imc(person, array_size);
            break;
        
        case 9:
            lower_imc(person, array_size);
            break;
        
        default:
            sair = 1;
            printf("Saindo...");
            break;
        }

    } while (sair != 1);

    return 0;
}