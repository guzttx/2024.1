#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct municipio 
{ 
    char* nome; 
    int populacao; 
    int** dados;  
}; 
typedef struct municipio Municipio; 

int** matrix_alloc(int days)
{
    int i;
    int **matrix;
    matrix = (int **)malloc(days * sizeof(int *));
    if(matrix == NULL)
    {
        printf("Erro na alocacao de memoria\n");
        exit(1);
    }
    for(i = 0; i < days; i++)
    {
        matrix[i] = (int *)malloc(3 * sizeof(int));
        if(matrix[i] == NULL)
        {
            printf("Erro na alocacao de memoria\n");
            exit(1);
        }
    }
    return matrix;
}

char* name_alloc(int size)
{
    char *name;
    name = (char *)malloc(size * sizeof(char));
    if(name == NULL)
    {
        printf("Erro na alocacao de memoria\n");
        exit(1);
    }
    return name;
}

Municipio* array_alloc(int size, Municipio *array, int rows)
{
    int i, j;
    int char_size = 50;
    array = (Municipio *)malloc(size * sizeof(Municipio));
    if(array == NULL)
    {
        printf("Erro na alocacao de memoria\n");
        exit(1);
    }

    for(i = 0; i < size; i++)
    {
        array[i].nome = name_alloc(char_size);
        array[i].populacao = 0;
        array[i].dados = matrix_alloc(rows);
    }

    return array;
}

void citynew_confirmed(Municipio *array, int size, int days, int index)
{
    int newcases = 0;
    newcases = newcases + array[index].dados[days-1][1];
    printf("Numero de novos casos confirmados: %d\n", newcases);
}

void citynew_deaths(Municipio *array, int size, int days, int index)
{
    int recentdeaths = 0;
    recentdeaths = recentdeaths + array[index].dados[days-1][2];
    printf("Numero de novos obitos confirmados: %d\n", recentdeaths);
}

void city_totalcases(Municipio *array, int size, int days, int index)
{
    int i, j;
    int totalcases = 0;
    for(i = 0; i < days; i++)
    {
        totalcases = totalcases + array[index].dados[i][1];
    }
    printf("Numero total de casos confirmados do municipio: %d\n", totalcases);
}

void city_totaldeaths(Municipio *array, int size, int days, int index)
{
    int i, j;
    int totaldeaths = 0;
    for(i = 0; i < days; i++)
    {
        totaldeaths = totaldeaths + array[index].dados[i][2];
    }
    printf("Numero total de obitos do municipio: %d\n", totaldeaths);
}

void city_hundredthousandcases(Municipio *array, int size, int days, int index)
{
    int i;
    float total = 0;
    for(i = 0; i < days; i++)
    {
        total = total + array[index].dados[i][1];
    }
    float casesperhundredthousand;
    casesperhundredthousand = (total/(float)array[index].populacao) * 100000;
    printf("Numero de casos confirmados por 100 mil habitantes: %.2f\n", casesperhundredthousand);
}

void city_hundredthousanddeaths(Municipio *array, int size, int days, int index)
{
    int i;
    float total = 0;
    for(i = 0; i < days; i++)
    {
        total = total + array[index].dados[i][2];
    }
    float hundredthousanddeaths = 0;
    hundredthousanddeaths = (total/(float)array[index].populacao) * 100000;
    printf("Numero de obitos por 100 mil habitantes: %.2f\n", hundredthousanddeaths);
}

void print_epidemiologicdata(Municipio *array, int size, int days, int index)
{
    citynew_confirmed(array, size, days, index);
    citynew_deaths(array, size, days, index);
    city_totalcases(array, size, days, index);
    city_totaldeaths(array, size, days, index);
    city_hundredthousandcases(array, size, days, index);
    city_hundredthousanddeaths(array, size, days, index);
}

void total_deaths(Municipio *array, int size, int days)
{
    int i, j;
    int deaths = 0;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < days; j++)
        {
            deaths = deaths + array[i].dados[j][2];
        }
    }
    printf("%d\n", deaths);
}

void total_confirmed(Municipio *array, int size, int days)
{
    int i, j;
    int total = 0;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < days; j++)
        {
            total = total + array[i].dados[j][1];
        }
    }
    printf("%d\n", total);
}

void print_matrix(Municipio *array, int days, int index)
{
    int i;
    printf("Dia:\tConfirmados:\tObitos:\n");
    for(i = 0; i < days; i++)
    {
        printf("%d\t", array[index].dados[i][0]);
        printf("%d\t \t", array[index].dados[i][1]);
        printf("%d\n", array[index].dados[i][2]);
    }
    printf("\n");
}

void print_array(Municipio *array, int size, int days)
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("\nNome: %s\n", array[i].nome);
        printf("Populacao: %d\n", array[i].populacao);
        print_epidemiologicdata(array, size, days, i);
    }
    printf("\n");
}

void** fill_matrix(int **matrix, int days)
{
    int i, j;
    for(i = 0; i < days; i++)
    {
        matrix[i][0] = i+1;
    }
    for(i = 0, j = 1; i < days; i++)
    {
        printf("Digite o numero de casos confirmados no dia %d: ", i+1);
        scanf("%d", &matrix[i][j]);
        j++;
        printf("Digite o numero de mortes no dia %d: ", i+1);
        scanf("%d", &matrix[i][j]);
        j = 1;
    }
}

void* fill_array(Municipio *array, int size, int days)
{
    int i, j;
    for(i = 0; i < size; i++)
    {
        printf("Digite o nome do municipio %d: ", i+1);
        fflush(stdin);
        fgets(array[i].nome, 50, stdin);
        for(j = 0; j < 50; j++)
        {
            if(array[i].nome[j] == '\n')
            {
                array[i].nome[j] = '\0';
            }
        }
        printf("Digite a populacao de %s: ", array[i].nome);
        scanf("%d", &array[i].populacao);
        fill_matrix(array[i].dados, days);
        printf("\n");
    }
}

void free_memory(Municipio *array, int size, int days)
{
    int i, j;
    for(i = 0; i < size; i++)
    {
        free(array[i].nome);
        for(j = 0; j < days; j++)
        {
            free(array[i].dados[j]);
        }
        free(array[i].dados);
    }
    free(array);
}

void print_search(Municipio *array, int size, int days)
{
    int i, j, found = 0;
    char searchitem[50];

    printf("Digite o nome do municipio que deseja buscar: ");
    fflush(stdin);
    fgets(searchitem, 50, stdin);
    for(i = 0; i < 50; i++)
    {
        if(searchitem[i] == '\n')
        {
            searchitem[i] = '\0';
        }
    }
    for(i = 0; i < size; i++)
    {
        if(strcmp(searchitem, array[i].nome) == 0)
        {
            printf("Municipio encontrado:\n");
            printf("Nome: %s\n", array[i].nome);
            printf("Populacao: %d\n", array[i].populacao);
            print_matrix(array, days, i);
            found = 1;
        }
    }
    if(found == 0)
    {
        printf("Municipio nao encontrado\n");
    }
}

void greater_incidence(Municipio *array, int size, int days)
{
    int i, j;
    int total = 0;
    int greater = 0;
    char *city;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < days; j++)
        {
            total = total + array[i].dados[j][1];
        }
        if(total > greater)
        {
            greater = total;
            city = array[i].nome;
        }
    }
    printf("%s\n", city);
}

void lower_mortality(Municipio *array, int size, int days)
{
    int i, j;
    int total = 0;
    int lower = 1000000000;
    char *city;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < days; j++)
        {
            total = total + array[i].dados[j][2];
        }
        if(total < lower)
        {
            lower = total;
            city = array[i].nome;
        }
    }
    printf("%s\n", city);
}

void cont_nonewdeaths(Municipio *array, int size, int days)
{
    int i;
    int cont = 0;
    for(i = 0; i < size; i++)
    {
        if(array[i].dados[days-1][2] == 0)
        {
            cont++;
        }
    }
    printf("%d\n", cont);
}

void print_reports(Municipio *array, int size, int days)
{
    printf("\nO municipio de maior incidencia eh: ");
    greater_incidence(array, size, days);

    printf("O municipio de menor mortalidade eh: ");
    lower_mortality(array, size, days);

    printf("O total de confirmados geral eh: ");
    total_confirmed(array, size, days);

    printf("O total de obitos eh: ");
    total_deaths(array, size, days);

    printf("A quantidade de municipios sem novos obitos eh: ");
    cont_nonewdeaths(array, size, days);
}

int main()
{
    int array_size;
    int optionmenu;
    int days;
    int i;

    printf("Digite o numero de municipios: ");
    scanf("%d", &array_size);

    printf("Digite o numero de dias monitorados: ");
    scanf("%d", &days);

    Municipio *cities_array;

    cities_array = array_alloc(array_size, cities_array, days);
    fill_array(cities_array, array_size, days);

    while(1)
    {
        printf("\nMenu de opcoes:\n");
        printf("1 - Buscar municipio\n");
        printf("2 - Mostrar lista de municipios e dados epidemiologicos gerais\n");
        printf("3 - Mostrar relatorios diversos:\n");
        printf("4 - Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &optionmenu);

        switch(optionmenu)
        {
            case 1:
                print_search(cities_array, array_size, days);
                break;
            case 2:
                print_array(cities_array, array_size, days);
                break;
            case 3:
                print_reports(cities_array, array_size, days);
                break;
            case 4:
                printf("Saindo do programa\n");
                free_memory(cities_array, array_size, days);
                exit(1);
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
    }

    return 0;
}

