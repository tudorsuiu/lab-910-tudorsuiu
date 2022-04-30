//
// Created by Tudor on 4/30/2022.
//

#include "BanknoteService.h"

BanknoteService::BanknoteService(IRepository<Banknote> &iRepository) : repository(iRepository) {}

void BanknoteService::create(Banknote entity) {
    repository.addEntity(entity);
}

Banknote BanknoteService::read(unsigned int index) {
    return repository.getAll()[repository.getPosByIndex(index)];
}

std::vector<Banknote> BanknoteService::read() {
    return repository.getAll();
}

void BanknoteService::update(unsigned int index, Banknote newEntity) {
    repository.updateEntity(index, newEntity);
}

void BanknoteService::del(unsigned int index) {
    repository.deleteEntity(index);
}

Banknote BanknoteService::getBanknoteByValue(unsigned int value) {
    for(int i = 0; i < repository.getAll().size(); i++) {
        if(repository.getAll()[i].getValue() == value) {
            return repository.getAll()[i];
        }
    }
}
