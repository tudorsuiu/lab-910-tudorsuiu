//
// Created by Tudor on 4/18/2022.
//

#include "Test.h"
#include "../Domain/Product.h"
#include "../Repository/Repository.h"
#include "../Service/Service.h"
#include <cassert>
#include <iostream>

void Test::domain() {
    Product product;
    assert(product.getCode() == 0);
    assert(product.getPrice() == 0);

    product.setCode(1);
    product.setName("corn");
    product.setPrice(5);
    assert(product.getCode() == 1);
    assert(product.getName() == "corn");
    assert(product.getPrice() == 5);

    Product product1(2, "corn", 6);
    assert(product1.getCode() == 2);
    assert(product1.getName() == "corn");
    assert(product1.getPrice() == 6);

    assert(product == product1 == false);

    product = product1;
    assert(product.getCode() == 2);
    assert(product.getName() == "corn");
    assert(product.getPrice() == 6);
}

void Test::repository() {
    Repository<Product> repository;

    Product p1(1, "croissant", 3);
    Product p2(2, "suc", 5);
    Product p3(3, "ciocolata", 7);
    Product p4(4, "popcorn", 4);
    Product p5(5, "apa", 3);

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

    repository.deleteEntity(repository.getPosByCode(2));
    repository.deleteEntity(repository.getPosByCode(4));
    repository.deleteEntity(repository.getPosByCode(5));
    assert(repository.getAll().size() == 2);

    repository.updateEntity(repository.getPosByCode(1), Product(1, "suc", 5));
    repository.updateEntity(repository.getPosByCode(3), Product(2, "apa", 3));
    assert(repository.getAll()[0] == Product(1, "suc", 5));
    assert(repository.getAll()[1] == Product(2, "apa", 3));
}

void Test::service() {
    RepositoryInFile<Product> repositoryInMemory("tests.txt");
    Service service(repositoryInMemory);

    Product p1(1, "croissant", 3);
    Product p2(2, "suc", 5);
    Product p3(3, "ciocolata", 7);
    Product p4(4, "popcorn", 4);
    Product p5(5, "apa", 3);

    service.create(p1);
    service.create(p2);
    service.create(p3);
    service.create(p4);
    service.create(p5);
    assert(service.read()[0] == p1);
    assert(service.read()[1] == p2);
    assert(service.read()[2] == p3);
    assert(service.read()[3] == p4);
    assert(service.read()[4] == p5);

    service.del(1);
    service.del(3);
    service.del(4);
    assert(service.read().size() == 2);

    service.update(0, Product(1, "suc", 5));
    service.update(1, Product(2, "apa", 3));
    assert(service.read()[0] == Product(1, "suc", 5));
    assert(service.read()[1] == Product(2, "apa", 3));
}

void Test::all() {
    std::cout << "All tests passed!" << '\n' << '\n';
    domain();
    repository();
    service();
}
