#include <iostream>
#include <fstream>
using namespace std;

// escritor para ter o arquivo *exemplo* das frases numeradas

int main() {

    ofstream arquivozada("BlackDeck.txt");

    // 0 - 23*20-3 == 0 - 456

    for (int i = 0; i < 92; i++) {
        if(i < 10) {
            arquivozada << "0";
        }
        arquivozada << i << ". BLACK" << i << endl;
    }
    
    cout << "DEU BOM!" << endl;

    return 0;
}

/*#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ofstream arquivozada("WhiteDeck.txt");

    // 0 - 23*20-3 == 0 - 456

    for (int i = 0; i < 457; i++) {
        if(i < 100) {
            arquivozada << "0";
            if(i < 10) {
                arquivozada << "0";
            }
        }
        arquivozada << i << ". WHITE" << i << endl;
    }
    
    cout << "DEU BOM!" << endl;

    return 0;
}*/

/*#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Nome do arquivo que você deseja ler
    char nomeArquivo[] = "BlackDeck.txt";

    ofstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return 1; // Encerra o programa com código de erro
    }

    arquivo << "Frase _____ numero 1." << endl;
    arquivo << "Frase: numero 222" << endl;
    arquivo << "Frase  3??" << endl;

    // Fecha o arquivo
    arquivo.close();

    cout << "Deu bom" << endl;

    return 0; // Encerra o programa com sucesso
}*/

/*
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        cout << rand()%3 << endl;
    }
    

    return 0;
}*/
