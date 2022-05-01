//
// Created by Tudor on 4/18/2022.
//

#include "Test.h"
#include "../Domain/Product.h"
#include "../Repository/Repository.h"
#include "../Service/ProductService.h"
#include "../Domain/Banknote.h"
#include "../Service/BanknoteService.h"
#include <cassert>
#include <iostream>

void Test::productDomain() {
    Product product;
    assert(product.getIndex() == 0);
    assert(product.getCode() == 0);
    assert(product.getPrice() == 0);

    product.setIndex(1);
    product.setCode(1);
    product.setName("corn");
    product.setPrice(5);
    assert(product.getIndex() == 1);
    assert(product.getCode() == 1);
    assert(product.getName() == "corn");
    assert(product.getPrice() == 5);

    Product product1(2, 2, "corn", 6);
    assert(product1.getIndex() == 2);
    assert(product1.getCode() == 2);
    assert(product1.getName() == "corn");
    assert(product1.getPrice() == 6);

    assert(product == product1 == false);

    product = product1;
    assert(product.getIndex() == 2);
    assert(product.getCode() == 2);
    assert(product.getName() == "corn");
    assert(product.getPrice() == 6);
}

void Test::banknoteDomain() {
    Banknote banknote;
    assert(banknote.getIndex() == 0);
    assert(banknote.getValue() == 0);
    assert(banknote.getNoOccurrences() == 0);

    banknote.setIndex(1);
    banknote.setValue(1);
    banknote.setNoOccurrences(10);
    assert(banknote.getIndex() == 1);
    assert(banknote.getValue() == 1);
    assert(banknote.getNoOccurrences() == 10);


    Banknote banknote1(2, 5, 10);
    assert(banknote1.getIndex() == 2);
    assert(banknote1.getValue() == 5);
    assert(banknote1.getNoOccurrences() == 10);

    banknote = banknote1;
    assert(banknote1.getIndex() == 2);
    assert(banknote1.getValue() == 5);
    assert(banknote1.getNoOccurrences() == 10);
}

void Test::repository() {
    Repository<Product> repository;

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
}

void Test::repositoryInFile() {

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

void Test::productService() {
    Repository<Product> repository;
    ProductService service(repository);

    Product p1(1, 1, "croissant", 3);
    Product p2(2, 2, "suc", 5);
    Product p3(3, 3, "ciocolata", 7);
    Product p4(4, 4, "popcorn", 4);
    Product p5(5, 5, "apa", 3);

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

    service.update(2, Product(1, 1, "suc", 5));
    service.update(5, Product(2, 2, "apa", 3));
    assert(service.read()[0] == Product(1, 1, "suc", 5));
    assert(service.read()[1] == Product(2, 2, "apa", 3));
}

void Test::banknoteService() {
    Repository<Banknote> repository;
    BanknoteService service(repository);

    Banknote b1(1, 100, 10);
    Banknote b2(2, 50, 10);
    Banknote b3(3, 10, 10);
    Banknote b4(4, 5, 10);
    Banknote b5(5, 1, 10);

    service.create(b1);
    service.create(b2);
    service.create(b3);
    service.create(b4);
    service.create(b5);
    assert(service.read()[0] == b1);
    assert(service.read()[1] == b2);
    assert(service.read()[2] == b3);
    assert(service.read()[3] == b4);
    assert(service.read()[4] == b5);

    service.del(1);
    service.del(3);
    service.del(4);
    assert(service.read().size() == 2);

    service.update(2, Banknote(2, 50, 20));
    service.update(5, Banknote(5, 1, 20));
    assert(service.read()[0] == Banknote(2, 50, 20));
    assert(service.read()[1] == Banknote(5, 1, 20));

    service.del(2);
    service.del(5);
    assert(service.read().empty());

    service.create(b1);
    service.create(b2);
    service.create(b3);
    service.create(b4);
    service.create(b5);
    assert(service.read()[0] == b1);
    assert(service.read()[1] == b2);
    assert(service.read()[2] == b3);
    assert(service.read()[3] == b4);
    assert(service.read()[4] == b5);

    std::vector<Banknote> result = service.change(23, 100);
    assert(result[0] == Banknote(1, 100, 0));
    assert(result[1] == Banknote(2, 50, 1));
    assert(result[2] == Banknote(3, 10, 2));
    assert(result[3] == Banknote(4, 5, 1));
    assert(result[4] == Banknote(5, 1, 2));

    assert(service.read()[0] == Banknote(1, 100, 10));
    assert(service.read()[1] == Banknote(2, 50, 9));
    assert(service.read()[2] == Banknote(3, 10, 8));
    assert(service.read()[3] == Banknote(4, 5, 9));
    assert(service.read()[4] == Banknote(5, 1, 8));
}

void Test::all() {
    std::cout << "All tests passed!" << '\n' << '\n';
    productDomain();
    banknoteDomain();
    repository();
    repositoryInFile();
    productService();
    banknoteService();
}
