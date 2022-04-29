//
// Created by Tudor on 4/18/2022.
//

#ifndef LAB_910_TUDORSUIU_CONSOLE_H
#define LAB_910_TUDORSUIU_CONSOLE_H


#include "../Domain/Product.h"
#include "../Service/ProductService.h"

class Console {
private:
    ProductService service;
public:
    Console(ProductService &service);
    void showMenu();
    void showAdminMenu();
    void showBuyerMenu();
    void runMenu();
};


#endif //LAB_910_TUDORSUIU_CONSOLE_H
