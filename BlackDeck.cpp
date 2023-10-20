#include <iostream>
#include <string>
#include <vector>
#include <fstream> // arquivos
#include <cstdlib>
#include <ctime>
using namespace std;

// o jogador que vai decidir a carta branca vencedora deve jogar a 
// carta 0 na hora de jogar uma carta branca

struct Player {
    string name;
    int score;
    int cur_card;

    Player() : score(0) {} // Construtor que inicializa o score com 0
};

void Control(vector<string> vec, string str, int cont) {

    cout << "\t------- controle ----------" << endl;
    cout << "Linha armazenada: " << str << endl;
    cout << "Tamanho: " << str.size() << endl;
    cout << "vector[i]: " << vec[cont] << endl; 
    cout << "tam vector[i]: " << vec[cont].size() << endl;
    cout << "\t---------------------------" << endl << endl;
}

void LoadDeck(vector<string>& vec, int& qtd, string str) {

    string str_linha;
    str_linha.clear();
    //int index = -1; // breakpoint

    ifstream BlackDeck(str); // abre o arquivo como input

    if (!BlackDeck.is_open()) { // chega se foi aberto
        cerr << "Erro ao abrir o arquivo." << endl;
        exit(1); // Encerra o programa com código de erro
    }

    while (getline(BlackDeck, str_linha)) { // executa enquanto houver linhas para ler
        
        vec.push_back(str_linha); // insere a carta no vector
        qtd++; // imcrementa a quantidade de cartas

        //index++;// breakpoint
        //Control(----------);// breakpoint

        str_linha.clear(); // limpa a string
    }

    BlackDeck.close(); // fecha o BlackDeck
}

void RandomCard(string& carta_atual, vector<string>& vec, int& qtd) {
    // seleciona aleatoriamente uma string do vector para retornar
    // retira essa string do vector para que ela não seja sorteada novamente

    int rand_index = (rand()% qtd);

    // precaução
    if((rand_index >= qtd) || (rand_index < 0)) { cout << "ERRO RandomCard" << endl; exit(1); }
    if (vec.empty()) { cout << "ERRO RandomCard: O vetor está vazio." << endl; exit(1); }
    
    carta_atual.clear();
    carta_atual =  vec[rand_index];

    vec.erase(vec.begin() + rand_index);
    qtd--;
}

void Pause(string txt) {
    cout << txt;
    cin.ignore(33,'\n');
}

void Menu(vector<Player>& vec_players) {

    int qtd_players;
    Player player_atual;

    cout << endl << "\t\t- - - - - | C++ Against Humanity | - - - - -" << endl << endl;

    // cadastro dos jogadores
    cout << "Quantos jogadores vao se arriscar dessa vez?" << endl << ".: ";
    cin >> qtd_players; 
    cin.ignore();

    //scanf(%99[^\n], str);

    cout << endl << "Insiram seus nomes: " << endl;

    for (int i = 0; i < qtd_players; i++) {
        cout << "\tPlayer " << i+1 << ": ";
        getline(cin, player_atual.name);
        //player_atual.score = 0; // so caso o construtor esteja errado
        vec_players.push_back(player_atual);
    }

    
}

void TakeCard(string carta, bool& next) {

    int choice=0;

    while (choice != 1 && choice != 2) {
        cout << endl << "\t\t- - - - - | C++ Against Humanity | - - - - -" << endl << endl;
        cout << "Escoha uma opcao: " << endl << "\t1. Puxar uma Carta Preta" << "\t2. Terminar a partida" << endl << "\t.: ";
        cin >> choice; 
        cin.ignore();
    }
    
    if(choice == 2) next = false;
    else { // choice == 1

        cout << "\n\t- " << carta << " -" << endl << endl;
        Pause("Pressione <ENTER> quando as cartas tiverem sido escolhidas. . .");
    }
}

void ThrowCard(vector<Player>& vec_players, vector<string>& vec_deck) {

    bool run = true;

    cout << endl << "\t\t- - - - - Joguem suas cartas - - - - -" << endl;

    for (size_t i = 0; i < (vec_players.size()); i++) {
        
        while (run) {
            cout << "- " << vec_players[i].name << ": ";
            cin >> vec_players[i].cur_card;

            if(vec_players[i].cur_card >= 0 && vec_players[i].cur_card <= static_cast<int>(vec_deck.size())) run = false;
            else cout << "Digite um valor valido!!" << endl;
        }
        run = true;        
    }
    
    //for (Player x : vec_players) { cout << x.cur_card << endl;} // breakpoint
}

void ShowThrow(vector<Player>& vec_players, vector<string>& white_deck) {

    // exibir as cartas de forma aleatoria mas sem o numero da frente

    vector<string> jogadas;
    string str_aux;
    int n;

    for(Player x : vec_players) { // preenche o vector jogadas sem o numero da frase
        if(x.cur_card) {
            str_aux = white_deck[x.cur_card];
            str_aux.erase(0, 5);
            jogadas.push_back(str_aux);
            str_aux.clear();
        }
    }

    cout << endl;
    while (jogadas.size()) {
        n = (rand() % jogadas.size());
        cout << "\t- " << jogadas[n] << endl;
        jogadas.erase(jogadas.begin() + n);
    }
    cout << endl;

}

void ComputaScore(vector<Player>& vec_players) {

    int i=0, vencedor=-1;

    cout << endl << "\t\t- - - - - Quem venceu a rodada? - - - - -" << endl;
    

    for(Player x : vec_players) {
        i++;
        cout << i << ". " << x.name << endl;
    }

    while (vencedor > static_cast<int>(vec_players.size()) || vencedor < 0) {
        cout << endl << "Digite o numero do vencedor: ";
        cin >> vencedor; 
    }
    
    (vec_players[(vencedor-1)].score) += 10;

}

void SortDeCria(vector<Player>& vec_players) {
    Player aux;
    int qtd_players = vec_players.size();
    bool swapped = true;

    while (swapped) {
        swapped = false;
        for (int i = 1; i < qtd_players; i++) {
            if (vec_players[i-1].score < vec_players[i].score) {
                // swap
                aux = vec_players[i-1];
                vec_players[i-1] = vec_players[i];
                vec_players[i] = aux;
                swapped = true;
            }
        }
    }
}

void Scoreboard(vector<Player>& vec_players) {

    int i=0;

    SortDeCria(vec_players); // ordena o vector em ordem decrescente

    cout << endl << "\t\t- - - - " << vec_players[0].name << " venceu com " << vec_players[0].score << " pontos!!! - - - -" << endl << endl;

    cout << "Placar final: " << endl;
    
    for(Player x : vec_players) {
        i++;
        cout << i << ". " << x.name << " - " << x.score << "pts" << endl;
    }
}

int main() {

    srand(time(nullptr));

    vector<Player> vec_players;
    vector<string> vec_deck;
    vector<string> white_deck;
    string carta_atual;

    bool next = true;
    int qtd_frases=0;
    int qtd_brancas=0;

    LoadDeck(vec_deck, qtd_frases, "BlackDeck.txt"); // carrega as frases para vec_deck
    LoadDeck(white_deck, qtd_brancas, "WhiteDeck.txt"); // carrega o baralho branco

    Menu(vec_players);

    while (qtd_frases>0 && next) {

        RandomCard(carta_atual, vec_deck, qtd_frases);
        TakeCard(carta_atual, next);

        if(next) {
            // todos os jogadores devem inserir o numero das suas cartas
            ThrowCard(vec_players, vec_deck);
            
            // exibir as cartas de forma aleatoria sem os numeros do comeco, mas de 1 -
            ShowThrow(vec_players, white_deck);

            // pergunta pelo vencedor e computa a pontuacao
            ComputaScore(vec_players);
        }

        // limpa a string da carta ataul
        carta_atual.clear();    
    }   

    Scoreboard(vec_players);

    return 0;
}

    /*string RandomCard(vector<string> *vec, int *qtd) {
        // seleciona aleatoriamente uma string do vector para retornar
        // retira essa string do vector para que ela não seja sorteada novamente

        int rand_index = (rand()%(*qtd));

        // precaução
        if((rand_index >= (*qtd)) || (rand_index < 0)) { cout << "ERRO RandomCard" << endl; exit(1); }
        if ((*vec).empty()) { cout << "ERRO RandomCard: O vetor está vazio." << endl; exit(1); }
        
        string f_carta_atual = (*vec)[rand_index];

        (*vec).erase((*vec).begin() + rand_index);

        (*qtd)--;

        return f_carta_atual;
    }*/

    /*cout << "--------------RELATORIO MENU-----------------" << endl;
    for(Player x : vec_players) {
        cout << x.name << " - " << x.score << endl;
    }*/

    /*for(string str : vec_deck) {
    cout << str << "END" << endl;
    }*/
