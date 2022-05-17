//
// Created by Tudor on 5/9/2022.
//

#include "ProductValidator.h"
#include "../MyException.h"

void ProductValidator::validate(Product product) {
    if(product.getIndex() <= 0 || product.getIndex() > INT_MAX) {
        throw MyException("Product ID must be positive.");
    }
    else if(product.getCode() < 0 || product.getIndex() > INT_MAX) {
        throw MyException("Product code must be positive.");
    }
    else if(product.getName().size() == 0) {
        throw MyException("Product name size must be greater than 0.");
    }
    else if(product.getPrice() <= 0) {
        throw MyException("Product price must be positive.");
    }
}
