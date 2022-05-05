//
// Created by Tudor on 4/18/2022.
//

#ifndef LAB_910_TUDORSUIU_CONSOLE_H
#define LAB_910_TUDORSUIU_CONSOLE_H


#include "../Domain/Product.h"
#include "../Service/ProductService.h"
#include "../Service/BanknoteService.h"

class Console {
private:
    ProductService productService;
    BanknoteService banknoteService;
public:
    Console(ProductService &serviceProduct, BanknoteService &serviceBanknote);
    void showMenu();
    void showAdminMenu();
    void showBuyerMenu();
    void insertMoney(unsigned int &inserted, unsigned int credit, Product &product);
    void pickUpChange(unsigned int &inserted, Product &product, std::vector<Banknote> copy);
    void runMenu();
};


#endif //LAB_910_TUDORSUIU_CONSOLE_H
