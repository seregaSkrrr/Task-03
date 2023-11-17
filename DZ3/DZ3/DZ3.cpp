#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include "Functions.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    //TASK 1
    cout <<"[][][][][][][][][][][][][][][][][][][][][]" <<endl;
    string S;
    cout << "Введите вашу строку с максимальным количеством пробелов: ";
    getline(cin, S);
    cout << S << endl;
    cout << Delete_Spaces(S) <<endl <<endl;

    //TASK 2
    cout << "[][][][][][][][][][][][][][][][][][][][][]" << endl;
    S = "//TASK 2\n int main() {\n\tstring S = \"String\"; \n\t//Initialization of string S  \n \tcout << S; //print S\n\t/*endl <<endl;*/\n}";
    cout << "До: " << S <<"\nПосле:\n";
    cout << Delete_Comments(S);

    //TASK 3
    cout << "\n[][][][][][][][][][][][][][][][][][][][][]" << endl;
    string First, Second;
    cout << "Введите изначальную строку: ";
    cin >> First;
    cout << "Введите что ищем в первой строке: ";
    cin >> Second;
    cout << Find(First, Second);

    //TASK 4
    cout << "\n[][][][][][][][][][][][][][][][][][][][][]" << endl;
    string str = "alpha 5+26 beta 72-35 gamma 32+45 ";
    cout << ComputeSumAndDifference(str) << std::endl;


    //TASK 5
    cout << "\n[][][][][][][][][][][][][][][][][][][][][]" << endl;
    int Number;
    cout << "Введите число для перевода в римское: ";
    cin >> Number;
    cout << Roman_to_arabic(Number);
    

    //TASK 6
    cout << "\n[][][][][][][][][][][][][][][][][][][][][]" << endl;
    cout << "Введите полный путь файла: ";
    cin >> S;
    File_info(S);

    return 0;
} 