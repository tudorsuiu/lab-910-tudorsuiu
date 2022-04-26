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

                service.create(product);
                break;
            }
            case '2': {
                for(int i = 0; i < service.read().size(); i++) {
                    std::cout << service.read()[i] << '\n';
                }
                break;
            }
            case '3': {
                Product newProduct;
                std::cin >> newProduct;

                int index;
                index = newProduct.getCode() - 1;

                if(index != -1) {
                    service.update(index, newProduct);
                }
                break;
            }
            case '4': {
                unsigned int code;
                std::cout << "Delete product with code:";
                std::cin >> code;

                int index;
                index = code - 1;

                service.del(index);
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