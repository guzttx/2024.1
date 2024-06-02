/*Implemente um sistema em C para controle de locação de veículos a clientes. O sistema deve atender aos 
seguintes requisitos: 
 Deve ser possível cadastrar veículos: incluir veículos e listar todos os veículos.  
o Sobre cada veículo, guardar: placa, marca, modelo, ano de fabricação, quilometragem atual, valor da 
diária, e uma flag “disponibilidade” que informa se o veículo está disponível para locação (um veículo está 
disponível para locação se ele não está locado no dia atual).  
 Deve ser possível cadastrar clientes: incluir clientes e listar todos os clientes. 
o Sobre cada cliente, guardar: CNH, nome e telefone.  
 Deve ser possível realizar a locação de veículos por clientes: locar veículo (retirar), devolver veículo e listar todas 
as locações. 
o Sobre cada locação, guardar: cliente, veículo, dia da retirada, dia da devolução e valor total pago.  
Restrições: 
1) Um veículo só pode ser locado se estiver disponível na data solicitada. 
2) A quilometragem atual do veículo deve ser solicitada pelo programa e atualizada pelo usuário sempre que o veículo 
for devolvido. 
3) A  flag “disponibilidade” deve  ser  atualizada  automaticamente  pelo  programa  sempre  que  o  veículo  for  locado 
(indisponível) e devolvido (disponível).  
4) O  valor  total  pago  deve  ser  calculado  automaticamente  pelo  programa,  com  base  no  valor  da  diária  e  nos  dias 
locados. 
5) Uma locação só pode ser feita por um cliente já cadastrado e um veículo já cadastrado; 
6) Não pode haver duplicidade de informações sobre clientes e veículos. Por exemplo, uma locação não 
armazena /replica  os  dados  de  clientes  e  veículos,  mas  guarda  apenas  ponteiros  que  apontam  para  os  respectivos 
cliente e veículo já previamente cadastrados.  
Faça  um  menu  de  opções  que  permita  ao  usuário  realizar  as  operações  descritas  acima  e  gerar  os  seguintes 
relatórios: 
R1) Listar todas as locações ativas (clientes ainda não devolveram os carros) em uma certa data (a data é informada pelo 
usuário); 
R2) Listar todas as locações já realizadas por um cliente (a CNH do cliente é informada pelo usuário); 
R3)  Listar  o  faturamento  da  locadora  por  mês  (mês  é  informado  pelo  usuário).  Por  faturamento,  entenda  o  total 
arrecadado em locações. 
R4) Listar a placa dos 3 veículos mais rodados (quilometragem mais alta). 
R5) Listar a placa e o modelo de todos os veículos disponíveis (não estão locados). /
Sugere-se que o menu principal seja estruturado conforme abaixo: 
1. incluir veículos 
2. listar veículos 
3. incluir clientes 
4. listar clientes 
5. realizar locação 
6. devolver veículo 
7. listar locações 
9. relatórios (podem abrir um submenu com os 5 relatórios ou listar os 5 relatórios no menu principal) 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carro.h"
#include "cliente.h"
#include "locacao.h"

int main()
{   
    Veiculos *lista_veiculos;
    lista_veiculos = (Veiculos*)malloc(sizeof(Veiculos));
    
    int opcao;
    do
    {
        printf("1. incluir veículos\n");
        printf("2. listar veículos\n");
        printf("3. incluir clientes\n");
        printf("4. listar clientes\n");
        printf("5. realizar locação\n");
        printf("6. devolver veículo\n");
        printf("7. listar locações\n");
        printf("8. relatórios\n");
        printf("0. sair\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            add_carro(lista_veiculos);
            break;
        case 2:
            print_listaveiculos(lista_veiculos);
            break;
        case 3:
           // incluirCliente();
            break;
        case 4:
            //listarClientes();
            break;
        case 5:
            //realizarLocacao();
            break;
        case 6:
            //devolverVeiculo();
            break;
        case 7:
            //listarLocacoes();
            break;
        case 8:
            //relatorios();
            break;
        case 0:
            break;
        default:
            printf("Opção inválida\n");
            break;
        }
    } while (opcao != 0);
}