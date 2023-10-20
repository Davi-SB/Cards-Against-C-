#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#define cartas_mao 4
using namespace std;

void LoadDeck(vector<string>& vec) {
    string line;
    ifstream file("WhiteDeck.txt");
    if(!file.is_open()) { cout << "Erro em abrir arquivo" << endl; exit(1);}
    while (getline(file, line)) {
        vec.push_back(line);
        line.clear();
    } 
}

int main() {

    srand(time(nullptr));

    vector<string> vec_deck;
    string deck_mao[cartas_mao]={};
    int choice = 0, rand_i, cont=0;
    bool next = true;

    string str_num;
    int index_choice, num;
    bool run = true; 
    bool repeated = false;

    LoadDeck(vec_deck); // carrega as cartas para vec_deck
    
    for (int j = 0; j < cartas_mao; j++) {
        rand_i = rand() % (vec_deck.size());
        deck_mao[j] = vec_deck[rand_i];
    }
    
    while (next) {
        cout << endl << "\t\t- - - - - | C++ Against Humanity | - - - - -" << endl << endl;
        cout << "\tSeu baralho:" << endl;
        for(string x : deck_mao) {
            cout << x << endl;
        }
        run = true;
        cout << "Insira o numero da carta escolhida: ";
        cin >> choice; cin.ignore();

        if(choice>=0) {   
            for (int k = 0; (k < cartas_mao) && run; k++) {   
                
                str_num = deck_mao[k].substr(0, 3); // comecando do 0, extrai 3
                num = stoi(str_num);
                //cout << str_num << "  " << num << endl;

                if(num == choice) {
                    index_choice = k;
                    //cout << k << "  " << index_choice << endl;
                    run = false;
                }
            }

            if(!run){
                cout << endl << "--- " << deck_mao[index_choice] << " ---" << endl << endl;

                repeated = true;
                while (repeated) {
                    rand_i = rand() % (vec_deck.size());
                    
                    repeated = false;
                    for (int k = 0; k < cartas_mao; k++) {
                        if(vec_deck[rand_i] == deck_mao[k]) repeated = true;
                    }
                }
                
                deck_mao[index_choice].clear();
                deck_mao[index_choice] = vec_deck[rand_i];
                cout << "Pressione <ENTER> quando a votacao terminar. . ." << endl;
                cin.ignore(10, '\n'); // pause
                cont++;
            }
        }
        else { next = false; }
    }
    
    cout << "Jogo finalizado! " << cont << " cartas foram jogadas por voce! Jantou" << endl << endl;

    return 0;
}

/*
000. Frase zero
001. Frase um
002. Frase dois
003. Frase tres
004. Frase quatro
005. Frase cinco
006. Frase seis
007. Frase sete
008. Frase oito
009. Frase nove
010. Frase dez
*/