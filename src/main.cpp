#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Keno.h"

using namespace std;

bool validate_file(string filename)
{
    // Checa se o arquivo existe
    fstream my_file;
    my_file.open(filename, ios::in);
    if (!my_file)
    {
        cout << "Arquivo não encontrado" << endl;
        return 0;
    }

    // Checa o numero de linhas e se possui caracteres nao numericos
    int number_of_lines = 0;
    string line;
    ifstream myfile(filename);

    while (getline(myfile, line))
    {
        line.erase(line.find_last_not_of("\n\r\t") + 1);
        if (line.find_first_not_of("0123456789. ") < line.size())
        {
            cout << "Possui um caractere especial." << endl;
            return 0;
        }
        ++number_of_lines;
    }

    // Checa se o numero de linhas esta correto
    if (number_of_lines != 3)
    {
        cout << "Numero de linhas incorreto" << endl;
        return 0;
    }

    // Checa o numero de spots
    stringstream ss(line);
    string number_string;
    int count_spots = 0;

    while (ss >> number_string)
    {
        count_spots++;
    }

    // Checa se o numero de spots esta correto
    if (count_spots > 15)
    {
        cout << "Mais de 15 spots no arquivo de apostas." << endl;
        return 0;
    }

    // Checa se possui spots repetidos
    int spots[count_spots];
    stringstream sss(line);

    for (int i = 0; i < count_spots; i++)
    {
        sss >> number_string;
        for (int j = 0; j <= i; j++)
        {
            if (spots[j] == stoi(number_string))
            {
                cout << "Spot repetido no arquivo de apostas." << endl;
                return 0;
            }
        }
        spots[i] = stoi(number_string);
    }

    // Se passou por todos os testes, retorna true
    return 1;
}

int main(int argc, char *argv[])
{
    if (!(argv[1]))
    {
        cout << "Erro!" << endl;
        cout << "Passe o arquivo de entrada como parametro." << endl;
        return 0;
    }
    cout << "Lendo arquivo de apostas [" << argv[1] << "], por favor aguarde.." << endl;

    if (!(validate_file(argv[1])))
    {
        cout << "Erro no arquivo de apostas." << endl;
        return 0;
    }

    ifstream infile(argv[1]);
    string line;
    getline(infile, line);
    float ic = stof(line);
    getline(infile, line);
    int nr = stoi(line);
    getline(infile, line);
    string spots_string = line;

    stringstream ss(spots_string);
    string number_string;
    int counter = 0;

    while (ss >> number_string)
    {
        counter++;
    }

    int spots[counter];
    stringstream sss(spots_string);

    for (int i = 0; i < counter; i++)
    {
        sss >> number_string;
        spots[i] = stoi(number_string);
    }

    Keno keno_bet(ic, nr, &spots[0], &spots[counter]);
    keno_bet.run_bets();

    return 0;
}
