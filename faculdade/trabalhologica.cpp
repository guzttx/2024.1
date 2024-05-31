#include <iostream>
#include <string>
using namespace std;

int main ()
{
    // declaracao de variaveis
    char player1[99];
    char player2[99];
    string deck[] = {" r1", "r1", "r2", "r2", "r3", "r3", "r4", "r5", "r6", "r7", "J", "Q", "K", "A", // roxas    (14)
                    "1",  "1", "3", "3", "4","4", "5", "5", "7", "C", "J", "Q", "K", "A",            // pretas   (14)
                    "1",  "1", "2", "2", "3", "4", "5", "J", "Q", "K", "A",             // vermelhas (11)
                    "2", "2", "2", "4", "4", "5","5","5", "J", "Q", "K", "A",           // amarelas (12)
                    "Joker", "Joker", "Joker",};                                 //                  jokers       (3)
                                                                    //                  total: 54
    int card_id[54];                                                            
    string color[54];
    string handP1[7];
    string handP2[7];
    int i, j, opcao;
    int k;

     // Coloca uma cor para cada variavel
    fill_n(color, 14, "purple");
    fill_n(color + 14, 14, "black");
    fill_n(color + 28, 11, "red");
    fill_n(color + 29, 12, "yellow");
    color[51] = "purple";
    color[52] = "red";
    color[53] = "yellow";

     // Coloca um ID para o vetor
    for (i = 0; i <= 54; i++)
    {
        card_id[i] = i;
    }


    // inicializacao
    cout << ("_____________________________________________________\n\n");
    cout <<("  Bem-vindo(a) ao card game! \n");
    
    cout <<("\nComo voce se chama player 1? \n");
    cin >> player1;

    cout <<("\nComo voce se chama player 2? \n");
    cin >> player2;

    cout <<("\nOtimo, ") << player1 << " e " << player2 << (". Vamos comecar");

    cout <<("\n\n");
    cout <<("Eis o baralho com cartas e cores:\n\n");

    for (i = 0; i <= 54; i++) 
    {
        cout << card_id[i] << ": ";
        cout << deck[i];
        cout << ": " << color[i] + "\n";
	}
    cout << "\n\n";

    system("pause");

    cout << ("Vou embaralhar e distribuir as cartas\n\n");

    return 0;
}