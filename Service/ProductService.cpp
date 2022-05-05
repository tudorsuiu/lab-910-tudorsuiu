//
// Created by Tudor on 4/18/2022.
//

#include "ProductService.h"

ProductService::ProductService(IRepository<Product> &iRepository) : repository(iRepository) {}

void ProductService::create(Product entity) {
    repository.addEntity(entity);
}

Product ProductService::read(unsigned int index) {
    return repository.getAll()[repository.getPosByIndex(index)];
}

std::vector<Product> ProductService::read() {
    return repository.getAll();
}

void ProductService::update(unsigned int index, Product newEntity) {
    repository.updateEntity(index, newEntity);
}

void ProductService::del(unsigned int index) {
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
