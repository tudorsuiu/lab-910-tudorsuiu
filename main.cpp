#include <iostream>
#include "Tests/All/Test.h"
#include "UserInterface/Console.h"

int main() {
    Test test;
    test.all();

    RepositoryInFile<Product> productInFile("products.txt");
    RepositoryInFile<Banknote> banknoteInFile("banknotes.txt");
    ProductService productService(productInFile);
    BanknoteService banknoteService(banknoteInFile);
    Console console(productService, banknoteService);

    console.runMenu();
    return 0;
}
