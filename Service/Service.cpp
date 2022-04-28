//
// Created by Tudor on 4/18/2022.
//

#include "Service.h"

Service::Service(IRepository<Product> &iRepository) : repository(iRepository) {}

void Service::create(Product entity) {
    repository.addEntity(entity);
}

std::vector<Product> Service::read() {
    return repository.getAll();
}

void Service::update(unsigned int code, Product newEntity) {
    repository.updateEntity(code, newEntity);
}

void Service::del(unsigned int code) {
    repository.deleteEntity(code);
}
