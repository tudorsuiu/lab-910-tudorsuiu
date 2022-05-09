//
// Created by Tudor on 5/9/2022.
//

#include <cassert>
#include "TestProductService.h"
#include "../../../Domain/Product/Product.h"
#include "../../../Service/ProductService.h"

void TestProductService::testProductService() {
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

void TestProductService::all() {
    testProductService();
}
