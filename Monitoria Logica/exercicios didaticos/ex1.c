//Crie um algoritmo que preenche produtos (nomes) e preços em vetores. 
//O usuário pode definir previamente quantos produtos irá adicionar.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fill_array(int tamanho, char produtos[tamanho][30], float *precos){
    for(int i = 0; i < tamanho; i++){
        printf("Digite o nome do produto %d: ", i+1);
        fflush(stdin);
        fgets(produtos[i], 30, stdin);
        printf("Digite o preco do produto %d: ", i+1);
        scanf("%f", &precos[i]);
    }
}

void fix_name(char *name){
    int len = strlen(name);
    if(name[len-1] == '\n'){
        name[len-1] = '\0';
    }
}

int main(){
    int tamanho;
    printf("Digite quantos produtos deseja adicionar: ");
    scanf("%d", &tamanho);
    char produtos[tamanho][30];
    float precos[tamanho];
    fill_array(tamanho, produtos, precos);
    for(int i = 0; i < tamanho; i++){
        fix_name(produtos[i]);
    }
    for(int i = 0; i < tamanho; i++){
        printf("Produto %d: %s, Preco: %.2f\n", i+1, produtos[i], precos[i]);
    }
    return 0;
}
