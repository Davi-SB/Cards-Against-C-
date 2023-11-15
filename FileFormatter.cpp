#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ifstream inputFile("D:/Estudos/Faculdade/codes/.vscode/CAH_private/CAH.txt");
    ofstream outputFile("D:/Estudos/Faculdade/codes/.vscode/CAH_private/CAH_limpo.txt");
    string line, concatLine;
    
    if (!inputFile.is_open()) {
        cout << "Erro ao abrir o arquivo." << endl;
        return 1;
    }

    while (getline(inputFile, line)) {
        // (line.find(str) == string::npos) retorna true quando str nao eh encontrada
        if (!line.empty() && (line.find("Cards") == string::npos) && (line.find("Against") == string::npos) && (line.find("Humanity") == string::npos)) {
            outputFile << line << endl;
        }
    }
    line.clear(); concatLine.clear();

    inputFile.close();
    outputFile.close();

    ifstream inputFile2("D:/Estudos/Faculdade/codes/.vscode/CAH_private/CAH_limpo.txt");
    ofstream outputFile2("D:/Estudos/Faculdade/codes/.vscode/CAH_private/CAH_concatenado.txt");
    
    if (!inputFile2.is_open()) {
        cout << "Erro ao abrir o arquivo2." << endl;
        return 1;
    }

    while (getline(inputFile2, line)) {
        line.erase(remove(line.begin(), line.end(), '\n'), line.end()); // remove '\n'
        concatLine += (line + " ");

        if ((line.find('.') != string::npos) || (line.find('?') != string::npos) || (line.find('!') != string::npos)) { // true se '.' eh encontrado
            outputFile2 << concatLine << endl;
            concatLine.clear();
        }
    }

    cout << "Tudo certo!!!" << endl;
    return 0;
}
