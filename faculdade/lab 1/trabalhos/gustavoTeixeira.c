
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

int digitoVerificacao(int matricula)                            //       funcao que define o digito de de verificacao
{
    int soma, dv, d1, d2, d3, d4, d5;

    d1 = matricula / 10000;
    d2 = (matricula % 10000) / 1000;                                        /* separa os digitos da matricula em variaveis (preparacao para o passo a) */
    d3 = (matricula % 1000) / 100;
    d4 = (matricula % 100) / 10;
    d5 = matricula % 10;

    soma = (d1 * 9) + (d2 * 8) + (d3 * 7) + (d4 * 6) + (d5 * 5);            /*execucao passo a + passo b(mult dos numeros da matricula e realizacao da soma dos valores encontrados)*/

    soma = soma * 10;                                                       /*execucao passo c(multiplicacao da soma por 10)*/

    dv = soma % 11;                                                         /*execucao passo d(resto da divisao da soma por 11)*/
    if(dv >= 10)
    {
        dv = dv % 10;
    }

    return dv;
}

float mgerala(float aprovadascont, float mediaAprovadas)            //      funcao para calculo da mga
{
    float mga;

    mga = mediaAprovadas / aprovadascont;                           

    return mga;
}

float paproveitamentoa(float aprovadascont, float disciplinas)          //       funcao para calculo do paa
{
    int paa;

    paa = (aprovadascont * 100) / disciplinas;                        

    return paa;
}

float mtotald(float mtda, float mtdr)
{
    float mtd;

    mtd = mtda - mtdr;

    return mtd;
}

int main()
{
    int matricula, dv;

    printf("Digite os 5 ultimos digitos da matricula: ");
    scanf("%d", &matricula);
    
    dv = digitoVerificacao(matricula);
    
    printf("Matricula: %d-%d\n", matricula, dv);

    int cargaHoraria, aprovadascont = 0, reprovadascont = 0;
    int mediaAprovadas = 0, mediaReprovadas = 0, aprovadasSemNota = 0, reprovadasSemNota = 0;
    int dif, cod, disciplinas = 0;
    float mtda = 0, mtdr = 0;
    float nota, m1 = 0, m2 = 0, m3 = 0, m4 = 0;                                 

    do
    {
        printf("Digite o codigo de aprovado ou reprovado(1 - aprovado, 0 - reprovado, ou digite qualquer numero negativo para ir para o menu)\n");
        printf("Digite o codigo: ");
        scanf("%d", &dif);

        if (dif > 1)
        {
            printf("Valor invalido!\n");
        }    
        
        else if(dif == 1)
        {
            printf("Aprovado com nota ou sem nota? (1 = com, 0 = sem)\n");
            scanf("%d", &cod);

            if(cod == 1)                                                           
            {
                printf ("Digite o valor da nota: ");
                scanf ("%f", &nota);

                printf ("Digite o valor da carga horaria: ");                                     //      leitura de variaveis para calculo das medias
                scanf ("%d", &cargaHoraria);

                if((nota >= 5 && nota <= 10) && cargaHoraria > 0)
                {
                    mediaAprovadas = mediaAprovadas + nota;
                    disciplinas++;
                    aprovadascont++;
                    mtda = mtda + (nota * (float)cargaHoraria);                                 //  mtda =  variavel positiva no calculo do mtd
                    m1 = m1 + (nota * (float)cargaHoraria);                                  //     definindo m1 como o somatorio do produto das medias finais pela carga horaria
                }

                else
                {
                    printf("Valor invalido!\n");
                }
            }
            else if(cod == 0)
            {
                printf ("Digite o valor da nota: ");
                scanf ("%f", &nota);

                printf ("Digite o valor da carga horaria: ");                                     //      leitura de variaveis para calculo das medias
                scanf ("%d", &cargaHoraria);

                if((nota >= 5 && nota <=10) && cargaHoraria > 0)
                {
                    disciplinas++;
                    aprovadasSemNota++;
                    aprovadascont++;
                    m2 = m2 + (nota*(float)cargaHoraria);
                }
                else
                {
                    printf("Valor invalido!\n");
                }
            }
            
            else
            {
                printf("Valor invalido!\n");
            }
        }
        
        else if(dif == 0)
        {
            printf("Reprovado com nota ou sem? (1 = com, 0 = sem)\n");
            scanf("%d", &cod);

            if(cod==1)
            {
                printf("Digite o valor da nota:\n");
                scanf("%f", &nota);

                printf("Digite o valor da carga horaria:\n");
                scanf("%d", &cargaHoraria); 

                if((nota >= 0 && nota < 5) && cargaHoraria > 0)
                {
                    disciplinas++;
                    mediaReprovadas = mediaReprovadas + nota;
                    reprovadascont++;
                    mtdr = mtdr + (nota * (float)cargaHoraria);                 //                 mtdr = variavel negativa no calculo do MTD
                    m3 = m3 + ((5-nota)*(float)cargaHoraria);
                }
                else
                {
                    printf("Valor invalido!\n");
                }
            }
            else if(cod==0)
            {
                printf("Digite o valor da carga horaria:\n");
                scanf("%d", &cargaHoraria);
                disciplinas++;                                                 //            como foi reprovado sem contar a nota, leva-se em conta apenas a carga horaria
                reprovadasSemNota++;
                m4= m4 + (5*(float)cargaHoraria);
            }
            else
            {
                printf("Valor invalido!\n");
            }       
        }    
    
        else
        {
            printf("Indo para o menu!\n");
        }
    
    } while (dif >= 0);

    m2 = (m2/aprovadasSemNota);                        //  definindo m2 como produto da media das medias das notas, pela carga horaria das mesmas

    int aprovadastotal = aprovadascont + aprovadasSemNota;
    int reprovadastotal = reprovadascont + reprovadasSemNota;

    float mga, ida, mtd, paa;

    mga = mgerala(aprovadascont, mediaAprovadas);
    paa = paproveitamentoa(aprovadascont, disciplinas);
    mtd = mtotald(mtda, mtdr);
    ida = m1+m2-m3-m4;                                              //          ida = m1 + m2 - m3 - m4      


    bool sair = true;                          //              definicao de variavel utilizada na repeticao do menu
    int opcao;

    do 
    {
        printf("Menu de opcoes!\n");
        printf("1 - Media Geral Acumulada\n");                                              //          loop de abertura do menu para o usuario, enquanto a variavel sair for verdadeira
        printf("2 - Indice de Desempenho Academico\n");
        printf("3 - Media Total de Disciplinas\n");
        printf("4 - Percentual de Aproveitamento do Aluno\n");
        printf("5 - Sair\n");
        scanf ("%d", &opcao);

        switch(opcao)
        {
            case 1:

                printf("MGA: %.2f\n", mga);
                break;

            case 2:
                printf("IDA: %.2f\n", ida);
                break;
                                                                        //        switch case de outputs desejados pelo usuario

            case 3:
                printf("MTD: %.2f\n", mtd);
                break;
            
            case 4:
                printf("PAA: %.2f%%\n", paa);
                if(paa == 100)
                {
                    printf("Parabens, sem reprovacoes!\n");
                }
                break;
            
            case 5:
                sair = false;                                                //              define a variavel sair como falsa, encerrando o loop e o programa
                printf("Saindo do programa!\n");    
                break;

            default:    
                printf("Valor invalido!\n");
                break;
        }

    } while (sair == true);
    
    return 0;
}