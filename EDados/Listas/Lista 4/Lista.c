/*1. Implemente  uma  função  que  altere  uma  lista,  de  forma  que  os  valores  positivos  fiquem  negativos  e  os 
negativos fiquem positivos. Esta função deve ter o protótipo: 
Lista* lst_altera (Lista* l); 
Para testar esta função, use/implemente as funções de:  - criação de lista - inserção na lista - impressão da lista  

2. Implemente uma função que insira elementos sempre ao final da lista. Esta função deve ter o protótipo: 
Lista* lst_insere (Lista* l, int i); 
Para testar esta função, use/implemente as funções de:  - criação de lista - impressão da lista - busca último da lista 

3. Implemente  uma  função  que  calcule  a  média  aritmética  dos  valores  armazenados.  Esta  função  deve  ter  o 
protótipo: 
Lista* lst_calculaMedia (Lista* l); 
Para testar esta função, use/implemente as funções de:  - criação de lista - inserção na lista - impressão da lista 

4. Implemente  uma  função  que  remova  o  elemento  anterior  a  um  elemento  de  valor  v.  Esta  função  deve  ter  o 
protótipo: 
Lista* lst_retira_ant (Lista* l, int v) 
Para testar esta função, use/implemente as funções de:  - criação de lista - inserção na lista - impressão da lista */


#include <stdio.h>
#include <stdlib.h>

struct lista 
{ 
    int info; 
    struct lista* prox; 
}; 
typedef struct lista Lista;

Lista* cria_lista()
{
    return NULL;
}

Lista* insert_list(Lista* lista, int numero)
{
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = numero;
    novo->prox = lista;
    return novo;
}

void imprime_lista(Lista* lista)
{
    Lista* pointer;
    for (pointer = lista; pointer != NULL; pointer = pointer -> prox)
    {
        printf("%d", pointer->info);
        if(pointer -> prox != NULL)
        {
            printf(", ");
        }   
        else
        {
            printf("\n");
        }
    }
}

Lista* lst_altera(Lista* list)
{
    Lista *pointer;

    for (pointer = list; pointer != NULL; pointer = pointer->prox)
    {
        pointer->info = pointer->info * -1;
    }
    
    return list;

}

Lista* insere_final(Lista* list, int valor)
{
    Lista *node;
    node = (Lista*)malloc(sizeof(Lista));

    node->info = valor;
    node->prox = NULL;

    Lista *aux;

    if(list == NULL)
    {
        list = node;
    }
    else
    {
        for(aux = list; aux->prox != NULL; aux = aux->prox);
        aux->prox = node;
    }

    return list;
}

float media_lista(Lista* list)
{
    float soma = 0;
    int cont = 0;
    Lista *aux;

    for(aux = list; aux != NULL; aux = aux->prox)
    {
        soma = (float)aux->info + soma;
        cont++;
    }

    soma = soma/(float)cont;
    
    return soma;
}

Lista *remove_anterior(Lista* list, int v)
{
    Lista *aux, *ant;

    if(list == NULL)
    {
        return list;
    }

    if(list->info == v)
    {
        return list;
    }

    for(aux = list; aux -> info != v; aux = aux->prox)
    {
        if(aux->info == v)
        {
            printf("Valor encontrado: %d\n", aux->info);
        }
    }

    return list;
}

int main()
{
    Lista *list = cria_lista();
    list = insert_list(list, 1);
    list = insert_list(list, 2);
    list = insert_list(list, 3);
    list = insert_list(list, 4);
    list = insert_list(list, 5);
    list = insert_list(list, 6);
    list = insert_list(list, 7);
    list = insert_list(list, 8);
    list = insert_list(list, 9);
    list = insert_list(list, 10);

    imprime_lista(list);

    list = lst_altera(list);

    imprime_lista(list);

    list = insere_final(list, 465);

    imprime_lista(list);

    float media = media_lista(list);

    printf("Media: %.2f\n", media);

    list = remove_anterior(list, 465);

    imprime_lista(list);

    return 0;
}