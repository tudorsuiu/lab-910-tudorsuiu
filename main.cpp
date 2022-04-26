#include <iostream>
#include "Tests/Test.h"
#include "UserInterface/Console.h"

int main() {
    RepositoryInFile<Product> repositoryInFile("products.txt");
    Service service(repositoryInFile);
    Console console(service);

    console.runMenu();
    return 0;
}
