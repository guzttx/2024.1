/*1. Implemente  uma  função  que  indique  se  um  ponto  (x,y)  está  localizado  dentro  ou  fora  de  um 
retângulo.  O  retângulo  é  definido  por  seus  vértices  inferior  esquerdo  (x0,y0)  e  superior  direito 
(x1,y1). A função deve ter como valor de retorno 1, se o ponto estiver dentro do retângulo, e 0 caso 
contrário, obedecendo ao protótipo:  int dentro_ret (int x0, int y0, int x1, int y1, int x, int y)*/

#include <stdio.h>
#include <stdlib.h>

int dentro_retangulo(int xo, int yo, int x, int y, int px, int py)
{
    if(px >= xo && px <= x && py >= yo && py <= y)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int ponto_x, ponto_y;
    int retangulo_xo, retangulo_yo, retangulo_x, retangulo_y;
    int check_dentro;

    printf("Digite a coordenada x inferior esquerda do retangulo:\n");
    scanf("%d", &retangulo_xo);
    printf("Digite a coordenada y inferior esquerda do retangulo:\n");
    scanf("%d", &retangulo_yo);

    printf("Digite a coordenada x superior direita do retangulo:\n");
    scanf("%d", &retangulo_x);
    printf("Digite a coordenada y superior direita do retangulo:\n");
    scanf("%d", &retangulo_y);

    printf("Digite a coordenada x do ponto:\n");
    scanf("%d", &ponto_x);
    printf("Digite a coordenada y do ponto:\n");
    scanf("%d", &ponto_y);

    check_dentro = dentro_retangulo(retangulo_xo, retangulo_yo, retangulo_x, retangulo_y, ponto_x, ponto_y);

    if (check_dentro == 1)
    {
        printf("\nO ponto %d, %d esta dentro do retangulo.(%d)", ponto_x, ponto_y, check_dentro); 
    }
    else
    {
        printf("\nO ponto %d, %d esta fora do retangulo.(%d)", ponto_x, ponto_y, check_dentro);
    }


    return 0;
}