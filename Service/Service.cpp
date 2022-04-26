//
// Created by Tudor on 4/18/2022.
//

#include "Service.h"

void Service::create(Product entity) {
    repository.addEntity(entity);
}

std::vector<Product> Service::read() {
    return repository.getAll();
}

void Service::update(int index, Product newEntity) {
    repository.updateEntity(index, newEntity);
}

void Service::del(int index) {
    repository.deleteEntity(index);
}
