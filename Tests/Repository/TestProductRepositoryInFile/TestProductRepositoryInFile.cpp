//
// Created by Tudor on 5/9/2022.
//

#include <cassert>
#include "TestProductRepositoryInFile.h"
#include "../../../Domain/Product/Product.h"
#include "../../../Repository/RepositoryInFile.h"

void TestProductRepositoryInFile::testProductRepositoryInFile() {
    RepositoryInFile<Product> repository("test.txt");

    Product p1(1, 1, "croissant", 3);
    Product p2(2, 2, "suc", 5);
    Product p3(3, 3, "ciocolata", 7);
    Product p4(4, 4, "popcorn", 4);
    Product p5(5, 5, "apa", 3);

    repository.addEntity(p1);
    repository.addEntity(p2);
    repository.addEntity(p3);
    repository.addEntity(p4);
    repository.addEntity(p5);
    assert(repository.getAll()[0] == p1);
    assert(repository.getAll()[1] == p2);
    assert(repository.getAll()[2] == p3);
    assert(repository.getAll()[3] == p4);
    assert(repository.getAll()[4] == p5);

    repository.deleteEntity(2);
    repository.deleteEntity(4);
    repository.deleteEntity(5);
    assert(repository.getAll().size() == 2);

    repository.updateEntity(1, Product(1, 1, "suc", 5));
    repository.updateEntity(3, Product(2, 2, "apa", 3));
    assert(repository.getAll()[0] == Product(1, 1, "suc", 5));
    assert(repository.getAll()[1] == Product(2, 2, "apa", 3));

    repository.deleteEntity(1);
    repository.deleteEntity(2);
}

void TestProductRepositoryInFile::all() {
    testProductRepositoryInFile();
}
