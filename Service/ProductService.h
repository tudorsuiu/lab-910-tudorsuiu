//
// Created by Tudor on 4/18/2022.
//

#ifndef LAB_910_TUDORSUIU_PRODUCTSERVICE_H
#define LAB_910_TUDORSUIU_PRODUCTSERVICE_H


#include "../Domain/Product.h"
#include "../Repository/Repository.h"
#include "../Repository/IRepository.h"
#include "../Repository/RepositoryInFile.h"

class ProductService {
private:
    //Repository repository;
    IRepository<Product> &repository;
public:
    /**
     * Constructor
     * @param iRepository: IRepository object - Interface
     */
    ProductService(IRepository<Product> &iRepository);

    /**
      * Add entity to repository
      * @param entity: Product object
      */
    void create(Product entity);

    /**
     * Read product with given code
     * @param index: unsigned int - product index
     * @return: Product object - product with given index
     */
    Product read(unsigned int index);

    /**
     * Reads all products stored in repository
     * @return: vector - all products stored in repository
     */
    std::vector<Product> read();

    /**
     * Updates a product by given index from repository
     * @param index: int - Product index
     * @param newEntity: Product object - updated product
     */
    void update(unsigned int index, Product newEntity);

    /**
     * Delete product
     * @param index: unsigned int - product index
     */
    void del(unsigned int index);

    /**
     * Get position by product code
     * @param code: unsigned int - product code
     * @return: Product object - product with given code
     */
    Product getProductByCode(unsigned int code);
};


#endif //LAB_910_TUDORSUIU_PRODUCTSERVICE_H
