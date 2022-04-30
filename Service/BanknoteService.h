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
    /**
     * Constructor
     * @param iRepository: IRepository object - Interface
     */
    BanknoteService(IRepository<Banknote> &iRepository);

    /**
     * Add entity to repository
     * @param entity: Banknote object
     */
    void create(Banknote entity);

    /**
     * Read banknote with given index
     * @param index: unsigned int - banknote index
     * @return: Banknote object - banknote with given index
     */
    Banknote read(unsigned int index);

    /**
     * Reads all banknotes stored in repository
     * @return: vector - all banknotes stored in repository
     */
    std::vector<Banknote> read();

    /**
     * Updates a banknote by given index from repository
     * @param index: unsigned int index - Banknote index
     * @param newEntity: Banknote object - updated banknote
     */
    void update(unsigned int index, Banknote newEntity);

    /**
     * Delete banknote
     * @param index: unsigned int - banknote index
     */
    void del(unsigned int index);

    /**
     * Get position by banknote value
     * @param value: unsigned int - banknote value
     * @return: Banknote object - banknote with given code
     */
    Banknote getBanknoteByValue(unsigned int value);

    /**
     * 
     * @param productPrice
     * @param insertedAmount
     * @return
     */
    unsigned int change(unsigned int productPrice, unsigned int insertedAmount);
};


#endif //LAB_910_TUDORSUIU_BANKNOTESERVICE_H
