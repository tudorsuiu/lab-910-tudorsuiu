//
// Created by Tudor on 4/18/2022.
//

#include <iostream>
#include "Console.h"
#include "../Domain/DoubleCompare/DoubleCompare.h"
#include "../Domain/MyException.h"

Console::Console(ProductService &serviceProduct, BanknoteService &serviceBanknote) : productService(serviceProduct),
                                                                                     banknoteService(serviceBanknote) {}

void Console::showMenu() {
    std::cout << '\n';
    std::cout << "_________------MENU------_________" << '\n';
    std::cout << "1. Admin profile." << '\n';
    std::cout << "2. Buyer profile." << '\n';
    std::cout << "x. Exit." << '\n';
    std::cout << "__________________________________" << '\n';
    std::cout << "Select option:";
}

void Console::showAdminMenu() {
    std::cout << '\n';
    std::cout << "_________---ADMIN MENU---_________" << '\n';
    std::cout << "1. Add product." << '\n';
    std::cout << "2. Check products." << '\n';
    std::cout << "3. Update product." << '\n';
    std::cout << "4. Delete product." << '\n';
    std::cout << "5. Add banknote." << '\n';
    std::cout << "6. Check banknotes." << '\n';
    std::cout << "7. Update banknote." << '\n';
    std::cout << "8. Delete banknote." << '\n';
    std::cout << "x. Exit." << '\n';
    std::cout << "__________________________________" << '\n';
    std::cout << "Select option:";
}

void Console::showBuyerMenu() {
    std::cout << '\n';
    std::cout << "_________---BUYER MENU---_________" << '\n';
    std::cout << "1. Show products." << '\n';
    std::cout << "2. Buy product." << '\n';
    std::cout << "x. Exit." << '\n';
    std::cout << "__________________________________" << '\n';
    std::cout << "Select option:";
}

void Console::uiAddProduct() {
    try {
        Product product;
        std::cin >> product;
        productService.create(product);
    }
    catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
}

void Console::uiCheckProducts() {
    try {
        for(int i = 0; i < productService.read().size(); i++) {
            std::cout << productService.read()[i] << '\n';
        }
    }
    catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
}

void Console::uiUpdateProduct() {
    try {
        unsigned int index;
        std::cout << "Update product with index:";

        if(std::cin >> index) {
            Product newProduct;
            std::cin >> newProduct;
            productService.update(index, newProduct);
        }
        else {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            throw MyException("Id must be a positive number.");
        }
    }
    catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
}

void Console::uiDeleteProduct() {
    try {
        unsigned int index;
        std::cout << "Delete product with index:";
        if(std::cin >> index) {
            productService.del(index);
        }
        else {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            throw MyException("Id must be a positive number.");
        }
    }
    catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
}

void Console::uiAddBanknote() {
    try {
        Banknote banknote;
        std::cin >> banknote;
        banknoteService.create(banknote);
    }
    catch(std::exception &e) {
        std::cout << e.what() << '\n';
    }
}

void Console::uiUpdateBanknote() {
    try {
        unsigned int index;
        std::cout << "Update banknote with index:";
        if(std::cin >> index) {
            Banknote newBanknote;
            std::cin >> newBanknote;
            banknoteService.update(index, newBanknote);
        }
        else {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            throw MyException("Id must be a positive number.");
        }
    }
    catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
}

void Console::uiCheckBanknotes() {
    try {
        for(int i = 0; i < banknoteService.read().size(); i++) {
            std::cout << banknoteService.read()[i] << '\n';
        }
    }
    catch(std::exception &e) {
        std::cout << e.what() << '\n';
    }
}

void Console::uiDeleteBanknote() {
    try {
        unsigned int index;
        std::cout << "Delete banknotes with index:";
        if(std::cin >> index) {
            banknoteService.del(index);
        }
        else {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            throw MyException("Id must be a positive number.");
        }
    }
    catch(std::exception &e) {
        std::cout << e.what() << '\n';
    }
}

void Console::insertMoney(double &inserted, double credit, Product &product) {
    while(doubleCompare::less(inserted, product.getPrice())) {
        std::cout << "Please insert credit (0.01/0.05/0.1/0.5/1/5/10/50/100/200/500):";
        std::cin >> credit;

        if(doubleCompare::equal(credit, 0.01) ||
        doubleCompare::equal(credit, 0.05) ||
        doubleCompare::equal(credit, 0.1) ||
        doubleCompare::equal(credit, 0.5) ||
        doubleCompare::equal(credit, 1) ||
        doubleCompare::equal(credit, 5) ||
        doubleCompare::equal(credit, 10) ||
        doubleCompare::equal(credit, 50) ||
        doubleCompare::equal(credit, 100) ||
        doubleCompare::equal(credit, 200) ||
        doubleCompare::equal(credit, 500)) {
            Banknote banknote = (banknoteService.getBanknoteByValue(credit));
            Banknote newBanknote(banknote.getIndex(), banknote.getValue(), banknote.getNoOccurrences() + 1);

            banknoteService.update(banknote.getIndex(), newBanknote);
            inserted += credit;
        }
        else {
            std::cout << "We don't accept that type of currency." << '\n';
        }
    }
}

void Console::pickUpChange(double &inserted, Product &product, std::vector<Banknote> copy) {
    std::vector<Banknote> result = banknoteService.change(product.getPrice(), inserted);
    if(productService.numberOfProductsByName(product.getName()) == 0) {
        std::cout << "We don't have this product." << '\n';
    }
    else {
        if (doubleCompare::equal(inserted, product.getPrice())) {
            std::cout << "Thanks for your purchase!" << '\n';
            unsigned int id = productService.getProductByCode(product.getCode()).getIndex();
            productService.del(id);
        } else {
            unsigned int checker = 0;
            for (int i = 0; i < result.size(); i++) {
                checker += result[i].getNoOccurrences();
            }
            if (checker == 0) {
                banknoteService.updateAll(copy);
                std::cout
                        << "Our vending machine doesn't have money. Pick up your money."
                        << '\n';
            } else {
                double change = 0;
                for (int i = 0; i < result.size(); i++) {
                    change += result[i].getValue() *
                              result[i].getNoOccurrences();
                }

                if (doubleCompare::equal(change, inserted - product.getPrice())) {
                    unsigned int id = productService.getProductByCode(product.getCode()).getIndex();
                    productService.del(id);
                    std::cout << "Please pick up your change: " << '\n';
                    for (int i = 0; i < result.size(); i++) {
                        if (result[i].getNoOccurrences() != 0) {
                            std::cout << result[i].getNoOccurrences()
                                      << " banknotes of "
                                      << result[i].getValue() << " RON."
                                      << '\n';
                        }
                    }
                    std::cout << "A total of: " << change << " RON." << '\n'
                              << "Thanks for your purchase!" << '\n';
                } else {
                    banknoteService.updateAll(copy);
                    std::cout
                            << "Our vending machine doesn't have money. Pick up your money."
                            << '\n';
                }
            }
        }
    }
}

void Console::runMenu() {
    char menuOption;
    do {
        showMenu();
        std::cin >> menuOption;
        std::cout << '\n';
        switch(menuOption) {
            case '1': {
                char adminOption;
                do {
                    showAdminMenu();
                    std::cin >> adminOption;
                    std::cout << '\n';
                    switch(adminOption) {
                        case '1': {
                            uiAddProduct();
                            break;
                        }
                        case '2': {
                            uiCheckProducts();
                            break;
                        }
                        case '3': {
                            uiUpdateProduct();
                            break;
                        }
                        case '4': {
                            uiDeleteProduct();
                            break;
                        }
                        case '5': {
                            uiAddBanknote();
                            break;
                        }
                        case '6': {
                            uiCheckBanknotes();
                            break;
                        }
                        case '7': {
                            uiUpdateBanknote();
                            break;
                        }
                        case '8': {
                            uiDeleteBanknote();
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
            case '2': {
                char buyerOption;
                do {
                    showBuyerMenu();
                    std::cin >> buyerOption;
                    std::cout << '\n';
                    std::vector<Product> uniqueItems = productService.showUniqueProducts();
                    switch(buyerOption) {
                        case '1': {
                            for(int i = 0; i < uniqueItems.size(); i++) {
                                Product product;
                                product = uniqueItems[i];
                                std::cout << "Product code: " << product.getCode() << '\n' <<
                                "Product name: " << product.getName() << '\n' <<
                                "Product price: " << product.getPrice() << '\n' << '\n';
                            }
                            break;
                        }
                        case '2': {
                            unsigned int code;
                            std::cout << "Please choose a product:";
                            std::cin >> code;

                            double inserted = 0;
                            double credit;
                            Product product = productService.getProductByCode(code);
                            std::vector<Banknote> copy = banknoteService.read();

                            insertMoney(inserted, credit, product);
                            pickUpChange(inserted, product, copy);
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

