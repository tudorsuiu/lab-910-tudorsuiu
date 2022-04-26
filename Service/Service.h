//
// Created by Tudor on 4/18/2022.
//

#ifndef LAB_910_TUDORSUIU_SERVICE_H
#define LAB_910_TUDORSUIU_SERVICE_H


#include "../Domain/Product.h"
#include "../Repository/Repository.h"
#include "../Repository/IRepository.h"
#include "../Repository/RepositoryInFile.h"

class Service {
private:
    //Repository repository;
    IRepository<Product> &repository;
public:
    Service(RepositoryInFile<Product> repositoryInFile);

    /**
      * Add entity to repository
      * @param entity: ApartmentBill object
      */
    void create(Product entity);

    /**
     * Reads all apartment bills stored in repository
     * @return: vector - all apartment bills stored in repository
     */
    std::vector<Product> read();

    /**
     * Updates an apartment bill by given index from repository
     * @param index: int - Apartment bill location in repository
     * @param newEntity
     */
    void update(int index, Product newEntity);

    /**
     * Delete an apartment bill from repository
     * @param index: int - Apartment bill location in repository
     */
    void del(int index);
};


#endif //LAB_910_TUDORSUIU_SERVICE_H
