//
// Created by Tudor on 4/30/2022.
//

#ifndef LAB_910_TUDORSUIU_BANKNOTESERVICE_H
#define LAB_910_TUDORSUIU_BANKNOTESERVICE_H


#include <vector>
#include "../Domain/Banknote.h"
#include "../Repository/IRepository.h"

class BanknoteService {
private:
    IRepository<Banknote> &repository;
public:
    BanknoteService(IRepository<Banknote> &iRepository);
    void create(Banknote entity);
    Banknote read(unsigned int index);
    std::vector<Banknote> read();
    void update(unsigned int index, Banknote newEntity);
    void del(unsigned int index);
    Banknote getBanknoteByValue(unsigned int value);
};


#endif //LAB_910_TUDORSUIU_BANKNOTESERVICE_H
