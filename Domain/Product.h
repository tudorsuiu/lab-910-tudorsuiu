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
     * @param code: unsigned int - product code
     * @param name: string - product name
     * @param price: unsigned int - product price
     */
    Product(unsigned int code, std::string name, unsigned int price);

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

    std::string toStringDelimiter(char sep) {
        return std::to_string(this->code) + sep + this->name + sep + std::to_string(this->price);
    }

    void loadFromString(std::string args, char sep) {
        std::vector<std::string> elements;
        std::stringstream ss (args);
        std::string object;
        while (getline (ss, object, sep)) {
            elements.push_back(object);
        }
        if(elements.size() == 3) {
            std::stringstream c(elements[0]);
            c >> this->code;
            this->name = elements[1];
            std::stringstream p(elements[2]);
            p >> this->price;
        }
    }

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
