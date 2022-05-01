//
// Created by Tudor on 4/30/2022.
//

#ifndef LAB_910_TUDORSUIU_BANKNOTE_H
#define LAB_910_TUDORSUIU_BANKNOTE_H

#include <istream>
#include <ostream>

class Banknote {
private:
    unsigned int index;
    unsigned int value;
    unsigned int noOccurrences;
public:
    /**
     * Constructor
     */
    Banknote();

    /**
     * Cosntructor with parameters
     * @param index: unsigned int - banknote index
     * @param value: unsigned int - banknote value
     * @param noOccurrences: unsigned int - number of banknotes
     */
    Banknote(unsigned int index, unsigned int value, unsigned int noOccurrences);

    /**
     * Create banknote object from string
     * @param args: string - given string
     * @param sep: char - separator
     */
    Banknote(std::string args, char sep);

    /**
     * Copy-constructor
     * @param banknote: Banknote - banknote
     */
    Banknote(const Banknote& banknote);

    /**
     * Destructor
     */
    ~Banknote();

    /**
     * Index getter
     * @return: unsigned int - banknote index
     */
    unsigned int getIndex();

    /**
     * Index setter
     * @param index: unsigned int - banknote index
     */
    void setIndex(unsigned int index);

    /**
     * Value getter
     * @return: unsigned int - banknote value
     */
    unsigned int getValue();

    /**
     * Value setter
     * @param value: unsigned int - banknote value
     */
    void setValue(unsigned int value);

    /**
     * Number of banknotes getter
     * @return: unsigned int - number of banknotes
     */
    unsigned int getNoOccurrences();

    /**
     * Number of banknotes setter
     * @param noOccurrences: unsigned int - number of banknotes
     */
    void setNoOccurrences(unsigned int noOccurrences);

    /**
     * To string delimiter
     * @param sep: char - separator
     * @return: string - Banknote object transformed into string
     */
    std::string toStringDelimiter(char sep);

    /**
     * Load banknote from a string
     * @param args: string - given string
     * @param sep: char - separator
     */
    void loadFromString(std::string args, char sep);

    Banknote& operator=(const Banknote &banknote);

    bool operator==(const Banknote &rhs) const;
    bool operator!=(const Banknote &rhs) const;

    friend std::istream &operator>>(std::istream &is, Banknote &banknote);
    friend std::ostream &operator<<(std::ostream &os, const Banknote &banknote);
};


#endif //LAB_910_TUDORSUIU_BANKNOTE_H
