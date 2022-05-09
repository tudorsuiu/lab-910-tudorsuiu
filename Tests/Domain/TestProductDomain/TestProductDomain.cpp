//
// Created by Tudor on 5/9/2022.
//

#include <cassert>
#include "TestProductDomain.h"
#include "../../../Domain/Product/Product.h"

void TestProductDomain::testProductDomain() {
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

void TestProductDomain::all() {
    testProductDomain();
}
