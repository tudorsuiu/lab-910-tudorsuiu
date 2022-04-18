//
// Created by Tudor on 4/18/2022.
//

#ifndef LAB_910_TUDORSUIU_CONSOLE_H
#define LAB_910_TUDORSUIU_CONSOLE_H


#include "../Domain/Product.h"
#include "../Repository/Repository.h"

class Console {
private:
    Repository<Product> repository;
public:
    void showMenu();
    void runMenu();
};


#endif //LAB_910_TUDORSUIU_CONSOLE_H
