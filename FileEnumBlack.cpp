#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {

    ifstream inputFile("D:/Estudos/Faculdade/codes/.vscode/CAH_private/BLACKSOURCE.txt");
    ofstream outputFile("D:/Estudos/Faculdade/codes/.vscode/CAH_projetin/output/BlackDeck.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Erro ao abrir os arquivos!" << endl;
        return 1;
    }

    string line;
    int lineNumber = 0;

    while (getline(inputFile, line)) {
        if(lineNumber < 10) outputFile << "0";
        outputFile << lineNumber << ". " << line << endl;
        lineNumber++;
    }

    inputFile.close();
    outputFile.close();

    cout << "---- Deu bom ----" << endl;

    return 0;
}