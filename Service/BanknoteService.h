//
// Created by Tudor on 4/30/2022.
//

#ifndef LAB_910_TUDORSUIU_BANKNOTESERVICE_H
#define LAB_910_TUDORSUIU_BANKNOTESERVICE_H


#include <vector>
#include "../Domain/Banknote/Banknote.h"
#include "../Repository/IRepository.h"
#include "../Domain/Banknote/BanknoteValidator.h"

class BanknoteService {
private:
    BanknoteValidator validator;
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
     * Updates all entities from repository
     * @param newVector: vector<Banknote> - our new vector
     */
    void updateAll(std::vector<Banknote> newVector);

    /**
     * Get position by banknote value
     * @param value: unsigned int - banknote value
     * @return: Banknote object - banknote with given code
     */
    Banknote getBanknoteByValue(unsigned int value);

    /**
     * Determine the banknotes that our customer is picking up as change
     * @param productPrice: unsigned int - product price
     * @param insertedAmount: unsigned int - inserted amount
     * @return: vector<Banknote> - banknotes that our customer is picking up as change
     */
    std::vector<Banknote> change(unsigned int productPrice, unsigned int insertedAmount);

    /**
     * Verify if there exist a banknote with the same id
     * @param index: unsigned int - id to be verified
     * @return: true if there exist a banknote with the same id, false otherwise
     */
    bool doesExist(unsigned int index);
};


#endif //LAB_910_TUDORSUIU_BANKNOTESERVICE_H
