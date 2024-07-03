// UgryumovaAS_03_18.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
using namespace std;

#include <iostream>
#include <fstream>
#include <string>
#include <list>

class Country {
public:
    string NameCountry;
    string Capital;
    int S = 0;
    int Population = 0;

    bool operator <(const Country& other)const {
        return NameCountry < other.NameCountry;
    }
};

list<Country> Countries;
//Запись в файл
void writeInFile() {
    Country country = Country();
    ofstream inFile;
    inFile.open("Country.txt");
    
    

    if (inFile.is_open()) {
        cout << "введите название страны\n";
        cin >> country.NameCountry;
        inFile << "\n" + country.NameCountry;
        cout << "введите название столицы\n";
        cin >> country.Capital;
        inFile << "\n" + country.Capital;
        cout << "введите площадь\n";
        cin >> country.S;
        inFile << "\n" + country.S;
        cout << "введите количество населения\n";
        cin >> country.Population;
        inFile << "\n" + country.Population ;
        Countries.push_back(country);
    }
    inFile.close();
}

//Чтение из файла по возрастанию
void ReadFileMax() {
    
    Country country = Country();

    ifstream outFile("Country.txt");
    if (outFile.is_open()) {
        string line;
        while (getline(outFile, line)) {
            
            cin >> country.NameCountry;
            cin >> country.Capital;
            cin >> country.S;
            cin >> country.Population;

            Countries.push_back(country);
        }
        Countries.sort();

    }
    outFile.close();

    cout << country.NameCountry;
    cout << country.Capital;
    cout << country.S;
    cout << country.Population;
}
//Чтение из файла по убыванию
void ReadFileMin() {

    Country country = Country();
    ifstream outFile("Country.txt");
    if (outFile.is_open()) {
        string line;
        while (getline(outFile, line)) {
            cin >> country.NameCountry;
            cin >> country.Capital;
            cin >> country.S;
            cin >> country.Population;

            Countries.push_back(country);
        }
        Countries.sort();
        Countries.reverse();
    }
    outFile.close();
    cout << country.NameCountry;
    cout << country.Capital;
    cout << country.S;
    cout << country.Population;
    
}
int main()
{
    
    setlocale(LC_ALL, "Russian");
    int variant = 0;
    cout << "выберите:\n1 Добавить в файл страну\n2 Вывести страны в порядке возрастания\n3 Вывести страны в порядке убывания\n";
    cin >> variant;
    switch (variant)
    {
    case 1:
        writeInFile();
        break;
    case 2:
        ReadFileMax();
        break;
    case 3:
        ReadFileMin();
        break;
    default:
        break;
    }
}
