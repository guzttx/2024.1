#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void print_hand(string hand[], int size, int id[])
{
    for (int i = 0; i < size; i++)
    {
        cout << id[i] << ": ";
        cout << hand[i] << "; ";
    }
    cout << "\n\n";
}

void print_table(string table[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << table[i] << ", ";
        if (i == 19)
        {
            cout << "\n";
        }
    }
    cout << "\n\n";
}

void print_deck(string deck[], int size, int id[])
{
    for (int i = 0; i < size; i++)
    {
        cout << id[i] << ": ";
        cout << deck[i] << ", ";
        cout << "\n";
    }
    cout << "\n\n";
}

void sort_deck(string deck[], int size)
{
    while(deck[0] == "xx")
    {
        for (int i = 0; i < size; i++)
        {
            if (deck[i] == "xx")
            {
                deck[i] = deck[i+1];
                deck[i+1] = "xx";
            }
        }
    }
}

void sort_hand(string hand[])
{
    int cont = 0, i;
    string aux;
    for (i = 0; i < 7; i++)
    {
        if (hand[i] == "xx")
        {
            cont++;
        }
    }
    
    if(cont != 0)
    {
        for (i = 1; i < 7; i++)
        {
            if (hand[i-1] == "xx" && hand[i] != "xx")
            {   
                aux = hand[i];
                hand[i] = hand[i-1];
                hand[i-1] = aux;
            }
        }
    }
}

void sort_table(string table[])
{
    int cont = 0, i;
    string aux;
    for (i = 0; i < 40; i++)
    {
        if (table[i] == "xx")
        {
            cont++;
        }
    }
    
    if(cont != 0)
    {
        for (i = 1; i < 40; i++)
        {
            if (table[i-1] != "xx" && table[i] == "xx")
            {   
                aux = table[i];
                table[i] = table[i-1];
                table[i-1] = aux;
            }
        }
    }
}

void card_play(string player, string hand[], string table[], int sizehand, int sizetable, int card, int id[7])
{
    cout << player << ", escolha uma carta para colocar na mesa:\n\n";

    print_hand(hand, 7, id);
    
    cin >> card;

    while (card <= 0 || card > 7 || hand[card - 1] == "xx")
    {
        cout << "Carta invalida, escolha outra:\n\n";
        cin >> card;
    }

    table[0] = hand[card - 1];
    hand[card - 1] = "xx";

    cout << "Carta colocada na mesa:\n\n";
}

void buy_cards(string hand[], string table[], string deck[])
{
    int contRed = 0;
    int contMissingCards = 0;
    int cartasCompraveis;
    int i, j;

    for (i = 0; i < 7; i++)
    {
        if (hand[i] == "xx")
        {
            contMissingCards++;
        }
    }

    for (i = 0; i < 40; i++)
    {
        if (table[i][0] == 'r')
        {
            contRed++;
        }
    }

    cout << "Voce tem " << contRed << " cartas vermelhas na mesa\n";
    cout << "Voce tem " << contMissingCards << " cartas faltando na mao\n";

    if (contRed == 0)
    {
        cartasCompraveis = 1;
    }

    else
    {
        cartasCompraveis = contRed;
    }

    if (cartasCompraveis >= contMissingCards)
    {
        cartasCompraveis = contMissingCards;
    }
    
    cout << "Voce pode comprar " << cartasCompraveis << " cartas\n";
    
    j = 0;

        for (i = 6; i >= 0, cartasCompraveis != 0; i--)
        {
            if(hand[i] == "xx")
            {
                hand[i] = deck[j];
                deck[j] = "xx";
                j++;
                cartasCompraveis--;
            }
        }
        cartasCompraveis--;
    cout << "Voce comprou " << j << " cartas\n\n";
}

int check_gameover(string deck[])
{
    int cont = 0, i;
    for (i = 0; i < 54; i++)
    {
        if (deck[i] == "xx")
        {
            cont++;
        }
    }
    if (cont == 0)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

int check_conditiondeal(int option, string hand[])
{
    int cont = 0;
    if (option == 1)
    {
        for (int i = 0; i < 7; i++)
        {
            if (hand[i] != "xx")
            {
                cont++;
            }
        }
        if (cont == 7)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    if (option == 2)
    {
        for (int i = 0; i < 7; i++)
        {
            if (hand[i] == "xx")
            {
                cont++;
            }
        }
        if (cont == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}

int check_forcebuy(string hand[])
{
    int cont = 0, i;

    for(i = 0; i < 7; i++)
    {
        if (hand[i] == "xx")
        {
            cont++;
        }
    }

    if (cont == 7)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main ()
{
    // declaracao de variaveis
    char player1[99];
    char player2[99];
    string deck[] = {"r1", "r1", "r2", "r2", "r3", "r3", "r4", "r5", "r6", "r7", "J", "Q", "K", "A", // roxas    (14)
                    "1",  "1", "3", "3", "4","4", "5", "5", "7", "C", "J", "Q", "K", "A",            // pretas   (14)
                    "1",  "1", "2", "2", "3", "4", "5", "J", "Q", "K", "A",             // vermelhas (11)
                    "2", "2", "2", "4", "4", "5","5","5", "J", "Q", "K", "A",           // amarelas (12)
                    "T", "T", "T"};                                 //                  jokers(tricksters para nao confundir com o J dos valetes)      (3)
                                                                    //                  total: 54
    int card_id[54];
    int hand_id[7];                                                            
    string color[54];
    string handP1[7];
    string handP2[7];
    string tableP1[40];
    string tableP2[40];
    string auxdeck[54];                                         //                          variavel para armazenar cartas e cores concatenadas

    int i, j, k;
    int gameover = 0, option, condicao;
    int forcebuy = 0;
    int scoreP1 = 0, scoreP2 = 0;
    int cardselect;
    int sizedeck = 54;                                          //                      tamanho do baralho + 1   
    int sizehand = 7;
    int sizetable = 40;
    
    
    for (i = 0; i < 7; i++)                                     //                                      zerando as maos
    {
        handP1[i] = "xx";
        handP2[i] = "xx";
    }

    for(i = 0; i < 40; i++)                                     //                                      zerando as cartas da mesa
    {
        tableP1[i] = "xx";
        tableP2[i] = "xx";
    }

     // Coloca uma cor para cada variavel
    fill_n(color, 14, "purple");
    fill_n(color + 14, 14, "black");
    fill_n(color + 28, 11, "red");
    fill_n(color + 39, 12, "yellow");
    color[51] = "purple";
    color[52] = "red";
    color[53] = "yellow";

    // Coloca um ID para o vetor
    for (i = 0; i < 54; i++)
    {
        card_id[i] = i + 1;
    }

    for (i = 0; i < 7; i++)
    {
        hand_id[i] = i + 1;
    }

    // inicializacao
    cout << ("_____________________________________________________\n\n");
    cout << ("  Bem-vindo(a) ao card game! \n");
    cout << ("\nComo voce se chama player 1? \n");
    cin >> player1;                                                                     //                      definicao dos jogadores
    cout << ("\nComo voce se chama player 2? \n");
    cin >> player2;
    cout << ("\nOtimo, ") << player1 << " e " << player2 << (". Vamos comecar");

    cout << ("\n\n");
    cout << ("Eis o baralho com cartas e cores:\n\n");

    for (i = 0; i < sizedeck; i++) 
    {
        auxdeck[i] = color[i] + " " + deck[i];                              //                "concatenando cartas em numero e cor em uma variavel auxiliar"
	}
    
    print_deck(auxdeck, sizedeck, card_id);

    cout << ("Vou embaralhar e distribuir as cartas\n\n");
    unsigned seed = time(0);
    srand(seed);
    for (i = 0; i < 54; i++)
    {
        int j = i + rand() % (54 - i);                            //  embaralhando as cartas utilizando seed do tempo do sistema para nao gerar jogos iguais
        swap(deck[i], deck[j]);
        swap(color[i], color[j]);
        swap(auxdeck[i], auxdeck[j]);
    }

    cout << ("Cartas embaralhadas...\n\n");
    //print_deck(auxdeck, sizedeck, card_id);                       //              remover comentario para ver as cartas embaralhadas

    cout << "Distribuindo as cartas...\n\n";

    j = 0;
    k = 7;
    for (i=0; i < 7; i++, k++, j++)
    {
        handP1[j] = auxdeck[i];                   //            distribuicao das cartas
        handP2[j] = auxdeck[k];
        auxdeck[i] = "xx";
        auxdeck[k] = "xx";
    }
    sort_deck(auxdeck, sizedeck);

    cout << "Cartas distribuidas...\n\n";
    cout << "Vamos comecar o jogo!\n";
    cout << player1 << " comeca:\n";

    card_play(player1, handP1, tableP1, sizehand, sizetable, cardselect, hand_id);
    sort_table(tableP1);
    print_table(tableP1, sizetable);
    cout << "\n\n\n\n\n\n\n";

    cout << player2 << ", sua vez:\n";
    card_play(player2, handP2, tableP2, sizehand, sizetable, cardselect, hand_id);
    sort_table(tableP2);
    print_table(tableP2, sizetable);
    cout << "\n\n\n\n\n\n\n";

    sort_hand(handP1);
    sort_hand(handP2);

    while(gameover != 1)
    {
        cout << player1 << ", sua vez:\n";
        print_table(tableP1, sizetable);
        print_hand(handP1, sizehand, hand_id);
        cout << "Comprar cartas?\n 1 - sim\n 2 - nao\n";
        cin >> option;

        while (option != 1 && option != 2)
        {
            cout << "Opcao invalida, escolha outra:\n\n";
            cin >> option;
        }
        
        if(option == 2)
        {
            forcebuy = check_forcebuy(handP1);
        }
        
        condicao = check_conditiondeal(option, handP1);
        
        if (forcebuy == 1)
        {
            cout << "Voce precisa comprar cartas\n";
            buy_cards(handP1, tableP1, auxdeck);
        }
        
        forcebuy = 0;

        if (option == 1)
        {
            if (condicao == 0)
            {
                cout << "Voce nao pode puxar carta do baralho, cardplay forcado:\n\n";
                card_play(player1, handP1, tableP1, sizehand, sizetable, cardselect, hand_id);
            }
            else
            {
                buy_cards(handP1, tableP1, auxdeck);
                sort_deck(auxdeck, sizedeck);
                sort_hand(handP1);
                print_hand(handP1, sizehand, hand_id);
            }
        }
        
        card_play(player1, handP1, tableP1, sizehand, sizetable, cardselect, hand_id);
        sort_hand(handP1);
        sort_table(tableP1);
        print_table(tableP1, sizetable);
        cout << "\n\n\n\n\n\n\n";

        cout << player2 << ", sua vez:\n";
        print_table(tableP2, sizetable);
        print_hand(handP2, sizehand, hand_id);
        cout << "Comprar cartas?\n 1 - sim\n 2 - nao\n";
        cin >> option;

        while (option != 1 && option != 2)
        {
            cout << "Opcao invalida, escolha outra:\n\n";
            cin >> option;
        }

        condicao = check_conditiondeal(option, handP2);
        forcebuy = check_forcebuy(handP2);

        if (forcebuy == 1)
        {
            cout << "Voce precisa comprar cartas\n";
            buy_cards(handP2, tableP2, auxdeck);
        }

        forcebuy = 0;

        if (option == 1)
        {
            if (condicao == 0)
            {
                cout << "Voce nao pode puxar carta do baralho, cardplay forcado:\n\n";
                card_play(player2, handP2, tableP2, sizehand, sizetable, cardselect, hand_id);
            }
            else
            {
                buy_cards(handP2, tableP2, auxdeck);
                sort_deck(auxdeck, sizedeck);
                sort_hand(handP2);
                print_hand(handP2, sizehand, hand_id);
            }
        }

        card_play(player2, handP2, tableP2, sizehand, sizetable, cardselect, hand_id);
        sort_hand(handP2);
        sort_table(tableP2);
        print_table(tableP2, sizetable);
        cout << "\n\n\n\n\n\n\n";

        gameover = check_gameover(auxdeck);
    }

    for (k = 0; k < 40; k++)
    {
        if (tableP1[k] != "xx")
        {
            j = k;
        }
    }
    
    j--;

    for (i = 0; i < 7; i++)
    {
        if (handP1[i] != "xx")
        {
            tableP1[j] = handP1[i];
            handP1[i] = "xx";
            j--;
        }
    }

    for (k = 0; k < 40; k++)
    {
        if (tableP2[k] != "xx")
        {
            j = k;
        }
    }
    
    j--;

    for (i = 0; i < 7; i++)
    {
        if (handP2[i] != "xx")
        {
            tableP2[j] = handP2[i];
            handP2[i] = "xx";
            j--;
        }
    }

    cout << "Fim de jogo!\n\n";

    for(i = 0; i < 40; i++)
    {
        if (tableP1[i] != "xx")
        {
            scoreP1++;
        }
        if (tableP2[i] != "xx")
        {
            scoreP2++;
        }
    }

    print_table(tableP1, sizetable);
    print_table(tableP2, sizetable);

    if (scoreP1 > scoreP2)
    {
        cout << player1 << " venceu, com" << scoreP1 << " pontos\n";
    }

    if (scoreP2 > scoreP1)
    {
        cout << player2 << " venceu, com" << scoreP2 << " pontos\n";
    }

    if (scoreP1 == scoreP2)
    {
        cout << "Empate!\n";
    }

    return 0;
}