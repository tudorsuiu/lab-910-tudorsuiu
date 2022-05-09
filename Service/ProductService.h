//
// Created by Tudor on 4/18/2022.
//

#ifndef LAB_910_TUDORSUIU_PRODUCTSERVICE_H
#define LAB_910_TUDORSUIU_PRODUCTSERVICE_H


#include "../Domain/Product/Product.h"
#include "../Repository/Repository.h"
#include "../Repository/IRepository.h"
#include "../Repository/RepositoryInFile.h"
#include "../Domain/Product/ProductValidator.h"

class ProductService {
private:
    ProductValidator validator;
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
     * Read product with given index
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

    /**
     * Get number of products by given name
     * @param productName: string - given name
     * @return: unsigned int - number of products
     */
    unsigned int numberOfProductsByName(std::string productName);

    /**
     * Returns a vector with all products that appear only once
     * @return: vector<Product> - all products but with only one appearence
     */
    std::vector<Product> showUniqueProducts();

    /**
     *
     * @param index
     * @return
     */
    bool doesExist(unsigned int index);
};


#endif //LAB_910_TUDORSUIU_PRODUCTSERVICE_H
