#include <iostream>
#include "Tests/Test.h"
#include "UserInterface/Console.h"

int main() {
    Test test;
    test.all();

    RepositoryInFile<Product> repositoryInFile("products.txt");
    Service service(repositoryInFile);
    Console console(service);

    console.runMenu();
    return 0;
}
