//
// Created by Tudor on 4/18/2022.
//

#ifndef LAB_910_TUDORSUIU_PRODUCT_H
#define LAB_910_TUDORSUIU_PRODUCT_H


#include <string>
#include <vector>
#include <sstream>

class Product {
private:
    unsigned int index;
    unsigned int code;
    std::string name;
    unsigned int price;
public:
    /**
     * Constructor
     */
    Product();

    /**
     * Constructor with parameters
     * @param index: unsigned int - product index
     * @param code: unsigned int - product code
     * @param name: string - product name
     * @param price: unsigned int - product price
     */
    Product(unsigned int index, unsigned int code, std::string name, unsigned int price);

    Product(std::string args, char sep);

    /**
     * Copy-constructor
     * @param product: Product - product
     */
    Product(const Product& product);

    /**
     * Destructor
     */
    ~Product();

    /**
     * Index getter
     * @return: unsigned int - product index
     */
    unsigned int getIndex();

    /**
     * Index setter
     * @param index: unsigned int - product index
     */
    void setIndex(unsigned int index);

    /**
     * Code getter
     * @return: unsigned int - product code
     */
    unsigned int getCode();

    /**
     * Code setter
     * @param code: unsigned int - new product code
     */
    void setCode(unsigned int code);

    /**
     * Name getter
     * @return: string - product name
     */
    std::string getName();

    /**
     * Name setter
     * @param name: string - new product name
     */
    void setName(std::string name);

    /**
     * Price getter
     * @return: unsigned int - product price
     */
    unsigned int getPrice();

    /**
     * Price setter
     * @param price: unsigned int - new product price
     */
    void setPrice(unsigned int price);

    /**
     * To string delimeter
     * @param sep: char - separator
     * @return: string - Product object transformed into string
     */
    std::string toStringDelimiter(char sep);

    /**
     * Load Product from a string
     * @param args: string - given string
     * @param sep: char - separator
     */
    void loadFromString(std::string args, char sep);

    Product& operator=(const Product& product);

    bool operator<(const Product &product) const;
    bool operator>(const Product &product) const;
    bool operator<=(const Product &product) const;
    bool operator>=(const Product &product) const;
    bool operator==(const Product &product) const;
    bool operator!=(const Product &product) const;

    friend std::istream &operator>>(std::istream &is, Product &product);
    friend std::ostream &operator<<(std::ostream &os, const Product &product);
};


#endif //LAB_910_TUDORSUIU_PRODUCT_H
