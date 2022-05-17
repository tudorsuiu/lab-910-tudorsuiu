//
// Created by Tudor on 4/18/2022.
//

#include "ProductService.h"
#include "../Domain/MyException.h"

ProductService::ProductService(IRepository<Product> &iRepository) : repository(iRepository) {}

void ProductService::create(Product entity) {
    if(doesExist(entity.getIndex())) {
        throw MyException("There already exist a product with this id.");
    }
    validator.validate(entity);
    repository.addEntity(entity);
}

Product ProductService::read(unsigned int index) {
    if(!doesExist(index)) {
        throw MyException("Product with given id doesn't exist.");
    }
    return repository.getAll()[repository.getPosByIndex(index)];
}

std::vector<Product> ProductService::read() {
    if(repository.getAll().size() == 0) {
        throw MyException("There are no products to show.");
    }
    return repository.getAll();
}

void ProductService::update(unsigned int index, Product newEntity) {
    if(!doesExist(index)) {
        throw MyException("The product that was going to be updated wasn't found.");
    }
    validator.validate(newEntity);
    repository.updateEntity(index, newEntity);
}

void ProductService::del(unsigned int index) {
    if(!doesExist(index)) {
        throw MyException("Product with given id doesn't exist.");
    }
    repository.deleteEntity(index);
}

Product ProductService::getProductByCode(unsigned int code) {
    for(int i = 0; i < repository.getAll().size(); i++) {
        if(repository.getAll()[i].getCode() == code) {
            return repository.getAll()[i];
        }
    }
    return Product(0, 0, "", 0);
}

unsigned int ProductService::numberOfProductsByName(std::string productName) {
    unsigned int numberOfProducts = 0;
    for(int i = 0; i < repository.getAll().size(); i++) {
        if(repository.getAll()[i].getName() == productName) {
            numberOfProducts++;
        }
    }
    return numberOfProducts;
}

std::vector<Product> ProductService::showUniqueProducts() {
    std::vector<Product> result;
    for(int i = 0; i < repository.getAll().size(); i++) {
        bool found = false;
        for(int j = 0; j < result.size(); j++) {
            if(repository.getAll()[i] == result[j]) {
                found = true;
            }
        }
        if(found == false) {
            result.push_back(repository.getAll()[i]);
        }
    }
    return result;
}

bool ProductService::doesExist(unsigned int index) {
    for(int i = 0; i < repository.getAll().size(); i++) {
        if(index == repository.getAll()[i].getIndex()) {
            return true;
        }
    }
    return false;
}
