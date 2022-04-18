//
// Created by Tudor on 4/18/2022.
//

#include <iostream>
#include "Console.h"

void Console::showMenu() {
    std::cout << '\n';
    std::cout << "_________------MENU------_________" << '\n';
    std::cout << "1. Add product" << '\n';
    std::cout << "2. Check product" << '\n';
    std::cout << "3. Update product" << '\n';
    std::cout << "4. Delete product." << '\n';
    std::cout << "x. Exit." << '\n';
    std::cout << "__________________________________" << '\n';
    std::cout << "Select option:";
}

void Console::runMenu() {
    char option;
    do {
        showMenu();
        std::cin >> option;
        std::cout << '\n';
        switch(option) {
            case '1': {
                Product product;
                std::cin >> product;

                repository.addEntity(product);
                break;
            }
            case '2': {
                std::cout << repository;
                break;
            }
            case '3': {
                Product newProduct;
                std::cin >> newProduct;

                int index;
                index = repository.getPosByCode(newProduct.getCode());

                if(index != -1) {
                    repository.updateEntity(index, newProduct);
                }
                break;
            }
            case '4': {
                unsigned int code;
                std::cout << "Delete product with code:";
                std::cin >> code;

                int index;
                index = repository.getPosByCode(code);

                repository.deleteEntity(index);
                break;
            }
            case 'x': {
                break;
            }
            default: {
                std::cout << "Invalid option! Please try again!" << '\n';
            }
        }
    }while(option != 'x');
}