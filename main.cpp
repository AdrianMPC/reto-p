#include "./c_dbmanager.h"

#include <iostream>

int main(){
    std::string input;
    std::cout << "Ingrese la dirección donde se encuentra el CSV: ";
    std::getline(std::cin, input);

    DBManager o_dbmanager(input);
    return 0;
}