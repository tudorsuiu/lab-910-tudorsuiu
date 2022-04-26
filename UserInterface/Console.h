//
// Created by Tudor on 4/18/2022.
//

#ifndef LAB_910_TUDORSUIU_CONSOLE_H
#define LAB_910_TUDORSUIU_CONSOLE_H


#include "../Domain/Product.h"
#include "../Service/Service.h"

class Console {
private:
    Service service;
public:
    void showMenu();
    void runMenu();
};


#endif //LAB_910_TUDORSUIU_CONSOLE_H
