/*Trabalho 2 Introducao a Ciencia da Informacao - Gustavo Teixeira - Leonardo Balk*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nota
{
    char ST[3];
    int estrutura;
    int tipo_nota;
    char BG[3];
    int numero_nota;
    int data_nota;
};
typedef struct nota note;

struct emissao
{
    char nome[50];
    char rua[30];
    int numero;
    char bairro[30];
    char cidade[30];
    char estado_sigla[3];
    char telefone[15];
    char cpf_cnpj[15];
};
typedef struct emissao emission;

struct itens
{
    int quantidade;
    char nome[50];
    float valor_unitario;
    float valor_total;
};
typedef struct itens item;

struct CTT
{
    char CTT[3];
    int numeroItens;
    float valorTotalNota;
};
typedef struct CTT CTT;

void clearNewLine(char *string)
{
    int len = strlen(string);
    if (string[len - 1] == '\n')
    {
        string[len - 1] = '\0';
    }
}

int numeroItens(item *itens, int n)
{
    int soma = 0;
    for (int i = 0; i < n; i++)
    {
        soma = soma + itens[i].quantidade;
    }
    return soma;
}

int valorTotalnota(item *itens, int n)
{
    float soma = 0;
    for (int i = 0; i < n; i++)
    {
        soma = soma + (itens[i].valor_unitario * itens[i].quantidade);
    }
    return soma;
}

void fill_nota(note *nota)
{
    int opcao;
    strcpy(nota->ST, "ST");
    nota->estrutura = 850;
    printf("Digite o tipo de nota (1 para Venda ou 0 para Compra): ");
    scanf("%d", &opcao);
    if (opcao == 1)
    {
        nota->tipo_nota = 5400;
    }
    else
    {
        nota->tipo_nota = 5700;
    }
    strcpy(nota->BG, "BG");
    printf("Digite o numero da nota: ");
    scanf("%d", &nota->numero_nota);
    printf("Digite a data da nota: ");
    scanf("%d", &nota->data_nota);
}

void fill_n1(emission *n1)
{
    strcpy(n1->nome, "EMPRESA SYSTEMPA");
    strcpy(n1->rua, "RUA VENANCIO AIRES");
    n1->numero = 1233;
    strcpy(n1->bairro, "CENTRO");
    strcpy(n1->cidade, "SANTA MARIA");
    strcpy(n1->estado_sigla, "RS");
    strcpy(n1->telefone, "5533334444");
    strcpy(n1->cpf_cnpj, "001010100-0001");
}

void fill_n2(emission *n2)
{
    printf("Digite o nome de N2: ");
    fflush(stdin);
    fgets(n2->nome, 50, stdin);
    clearNewLine(n2->nome);
    
    printf("Digite a rua do N2: ");
    fflush(stdin);
    fgets(n2->rua, 30, stdin);
    clearNewLine(n2->rua);

    printf("Digite o numero da rua do N2: ");
    scanf("%d", &n2->numero);

    printf("Digite o bairro do N2: ");
    fflush(stdin);
    fgets(n2->bairro, 30, stdin);
    clearNewLine(n2->bairro);

    printf("Digite a cidade do N2: ");
    fflush(stdin);
    fgets(n2->cidade, 30, stdin);
    clearNewLine(n2->cidade);

    printf("Digite a sigla do estado do N2: ");
    fflush(stdin);
    fgets(n2->estado_sigla, 3, stdin);
    clearNewLine(n2->estado_sigla);

    printf("Digite o telefone do N2: ");
    fflush(stdin);
    fgets(n2->telefone, 15, stdin);
    clearNewLine(n2->telefone);

    printf("Digite o CPF/CNPJ do N2: ");
    fflush(stdin);
    fgets(n2->cpf_cnpj, 15, stdin);
    clearNewLine(n2->cpf_cnpj);
}

void print_nota(note *nota, emission *n1, emission *n2)
{
    printf("%s*%d*%d\n", nota->ST, nota->estrutura, nota->tipo_nota);
    printf("%s*%d*%d\n", nota->BG, nota->numero_nota, nota->data_nota);
    printf("N1*%s*%s %d. BAIRRO %s*%s - %s*%s*%s\n", n1->nome, n1->rua, n1->numero, n1->bairro, n1->cidade, n1->estado_sigla, n1->telefone, n1->cpf_cnpj);
    printf("N2*%s*%s %d. BAIRRO %s*%s - %s*%s*%s\n", n2->nome, n2->rua, n2->numero, n2->bairro, n2->cidade, n2->estado_sigla, n2->telefone, n2->cpf_cnpj);
}

void fill_itens(item *itens, int numero_produtos)
{
    for (int i = 0; i < numero_produtos; i++)
    {
        printf("Digite o nome do item %d: ", i + 1);
        fflush(stdin);
        fgets(itens[i].nome, 50, stdin);
        clearNewLine(itens[i].nome);
        printf("Digite a quantidade do item %d: ", i + 1);
        scanf("%d", &itens[i].quantidade);
        printf("Digite o valor unitario do item %d: ", i + 1);
        scanf("%f", &itens[i].valor_unitario);
        itens[i].valor_total = itens[i].quantidade * itens[i].valor_unitario;    
    }
}

void print_itens(item *itens, int numero_produtos)
{
    for (int i = 0; i < numero_produtos; i++)
    {
        printf("PO%d*%d*%s*%.2f*%.2f\n", i + 1, itens[i].quantidade, itens[i].nome, itens[i].valor_unitario, itens[i].valor_total);
    }
}

void fill_ctt(CTT *ctt, item *itens, int numero_produtos)
{
    strcpy(ctt->CTT, "CTT");
    ctt->numeroItens = numeroItens(itens, numero_produtos);
    ctt->valorTotalNota = valorTotalnota(itens, numero_produtos);
}

void print_ctt(CTT *ctt)
{
    printf("%s*%d*%.2f\n", ctt->CTT, ctt->numeroItens, ctt->valorTotalNota);
}

int main()
{
    int numero_produtos;

    note nota;
    fill_nota(&nota);

    emission n1;
    emission n2;

    fill_n1(&n1);
    fill_n2(&n2);

    printf("Digite o numero de produtos a serem inseridos: ");
    scanf("%d", &numero_produtos);

    item itens[numero_produtos];
    fill_itens(itens, numero_produtos);\

    CTT ctt;
    fill_ctt(&ctt, itens, numero_produtos);

    printf("\n\n");
    print_nota(&nota, &n1, &n1);
    print_itens(itens, numero_produtos);
    print_ctt(&ctt);
    printf("SE*%d\n", nota.numero_nota);

    return 0;
}