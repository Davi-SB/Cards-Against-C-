#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ifstream inputFile("D:/Estudos/Faculdade/codes/.vscode/CAH_projetin/output/WhiteDeck.txt");
    ofstream outputFile("D:/Estudos/Faculdade/codes/.vscode/CAH_projetin/output/PUSHBACK.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Erro ao abrir os arquivos!" << endl;
        return 1;
    }

    string line;
    int lineNumber = 1;

    while (getline(inputFile, line)) {
        outputFile << "vec.push_back(\"" << line << "\");" << endl;
        lineNumber++;
    }

    inputFile.close();
    outputFile.close();

    cout << "---- Deu bom ----" << endl;

    return 0;
}