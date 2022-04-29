//
// Created by Tudor on 4/18/2022.
//

#include <iostream>
#include "Console.h"

Console::Console(ProductService &service) : service(service) {}

void Console::showMenu() {
    std::cout << '\n';
    std::cout << "_________------MENU------_________" << '\n';
    std::cout << "a. Admin profile." << '\n';
    std::cout << "b. Buyer profile." << '\n';
    std::cout << "x. Exit." << '\n';
    std::cout << "__________________________________" << '\n';
    std::cout << "Select option:";
}

void Console::showAdminMenu() {
    std::cout << '\n';
    std::cout << "_________---ADMIN MENU---_________" << '\n';
    std::cout << "1. Add product" << '\n';
    std::cout << "2. Check product" << '\n';
    std::cout << "3. Update product" << '\n';
    std::cout << "4. Delete product." << '\n';
    std::cout << "x. Exit." << '\n';
    std::cout << "__________________________________" << '\n';
    std::cout << "Select option:";
}

void Console::showBuyerMenu() {
    std::cout << '\n';
    std::cout << "_________---BUYER MENU---_________" << '\n';
    std::cout << "1. Show products" << '\n';
    std::cout << "2. Insert money" << '\n';
    std::cout << "3. Choose product" << '\n';
    std::cout << "x. Exit." << '\n';
    std::cout << "__________________________________" << '\n';
    std::cout << "Select option:";
}

void Console::runMenu() {
    char menuOption;
    do {
        showMenu();
        std::cin >> menuOption;
        std::cout << '\n';
        switch(menuOption) {
            case 'a': {
                char adminOption;
                do {
                    showAdminMenu();
                    std::cin >> adminOption;
                    std::cout << '\n';
                    switch(adminOption) {
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
                            unsigned int index;
                            std::cout << "Update product with index:";
                            std::cin >> index;

                            Product newProduct;
                            std::cin >> newProduct;

                            service.update(index, newProduct);
                            break;
                        }
                        case '4': {
                            unsigned int index;
                            std::cout << "Delete product with code:";
                            std::cin >> index;

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
                }while(adminOption != 'x');
                break;
            }
            case 'b': {
                char buyerOption;
                unsigned int total = 0;
                do {
                    std::cout << "Total: " << total << " RON." << '\n';
                    showBuyerMenu();
                    std::cin >> buyerOption;
                    std::cout << '\n';
                    switch(buyerOption) {
                        case '1': {
                            for(int i = 0; i < service.read().size(); i++) {
                                Product product;
                                product = service.read()[i];
                                std::cout << "Product code: " << product.getCode() << '\n' <<
                                "Product name: " << product.getName() << '\n' <<
                                "Product price: " << product.getPrice() << '\n' << '\n';
                            }
                            break;
                        }
                        case '2': {
                            unsigned int credit;
                            std::cout << "Insert credit:";
                            std::cin >> credit;
                            if(credit == 1 || credit == 5 || credit == 10 || credit == 50 || credit == 100) {
                                total += credit;
                            }
                            else {
                                std::cout << "Our vending machine doesn't accept this type of currency." << '\n';
                            }
                            break;
                        }
                        case '3': {
                            unsigned int code;
                            std::cout << "Product code:";
                            std::cin >> code;
                            std::cout << "Please pick up your change: " << total - service.getProductByCode(code).getPrice() << " RON." << '\n';
                            total = 0;
                            break;
                        }
                        case 'x': {
                            break;
                        }
                        default: {
                            std::cout << "Invalid option! Please try again!" << '\n';
                        }
                    }
                }while(buyerOption != 'x');
                break;
            }
            case 'x': {
                break;
            }
            default: {
                std::cout << "Invalid option! Please try again!" << '\n';
            }
        }
    }while(menuOption != 'x');
}

