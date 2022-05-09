//
// Created by Tudor on 4/30/2022.
//

#include "BanknoteService.h"
#include "../Domain/MyException.h"

BanknoteService::BanknoteService(IRepository<Banknote> &iRepository) : repository(iRepository) {}

void BanknoteService::create(Banknote entity) {
    if(doesExist(entity.getIndex())) {
        throw MyException("There already exist a banknote with this id.");
    }
    validator.validate(entity);
    repository.addEntity(entity);
}

Banknote BanknoteService::read(unsigned int index) {
    if(!doesExist(index)) {
        throw MyException("Banknote with given id doesn't exist.");
    }
    return repository.getAll()[repository.getPosByIndex(index)];
}

std::vector<Banknote> BanknoteService::read() {
    return repository.getAll();
}

void BanknoteService::update(unsigned int index, Banknote newEntity) {
    if(!doesExist(index)) {
        throw MyException("The banknote that was going to be updated wasn't found.");
    }
    validator.validate(newEntity);
    repository.updateEntity(index, newEntity);
}

void BanknoteService::del(unsigned int index) {
    if(!doesExist(index)) {
        throw MyException("Banknote with given id doesn't exist.");
    }
    repository.deleteEntity(index);
}

void BanknoteService::updateAll(std::vector<Banknote> newVector) {
    for(int i = 0; i < 5; i++) {
        repository.updateEntity(newVector[i].getIndex(), newVector[i]);
    }
}

Banknote BanknoteService::getBanknoteByValue(unsigned int value) {
    for(int i = 0; i < repository.getAll().size(); i++) {
        if(repository.getAll()[i].getValue() == value) {
            return repository.getAll()[i];
        }
    }
}

bool BanknoteService::doesExist(unsigned int index) {
    for(int i = 0; i < repository.getAll().size(); i++) {
        if(index == repository.getAll()[i].getIndex()) {
            return true;
        }
    }
    return false;
}

std::vector<Banknote> BanknoteService::change(unsigned int productPrice,
                                       unsigned int insertedAmount) {
    unsigned int changeValue = insertedAmount - productPrice;
    std::vector<Banknote> changeVector;
    changeVector.push_back(Banknote(1, 100, 0));
    changeVector.push_back(Banknote(2, 50, 0));
    changeVector.push_back(Banknote(3, 10, 0));
    changeVector.push_back(Banknote(4, 5, 0));
    changeVector.push_back(Banknote(5, 1, 0));

    if(repository.getAll().size() != 5 ||
    (repository.getAll()[0].getNoOccurrences() == 0 &&
    repository.getAll()[1].getNoOccurrences() == 0 &&
    repository.getAll()[2].getNoOccurrences() == 0 &&
    repository.getAll()[3].getNoOccurrences() == 0 &&
    repository.getAll()[4].getNoOccurrences() == 0)) {
        return changeVector;
    }
    else {
        for(int i = 0; i < repository.getAll().size(); i++) {
            while(changeValue >= repository.getAll()[i].getValue() && repository.getAll()[i].getNoOccurrences() > 0) {
                changeValue -= repository.getAll()[i].getValue();

                Banknote updatedBanknote(repository.getAll()[i].getIndex(), repository.getAll()[i].getValue(), repository.getAll()[i].getNoOccurrences() - 1);
                repository.updateEntity(repository.getAll()[i].getIndex(), updatedBanknote);

                Banknote newBanknote(changeVector[i].getIndex(), changeVector[i].getValue(), changeVector[i].getNoOccurrences() + 1);
                changeVector[i] = newBanknote;
            }
        }
    }
    return changeVector;
}
