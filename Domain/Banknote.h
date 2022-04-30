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
    Banknote();
    Banknote(unsigned int index, unsigned int value, unsigned int noOccurrences);
    Banknote(std::string args, char sep);
    Banknote(const Banknote& banknote);
    ~Banknote();


    unsigned int getIndex();
    void setIndex(unsigned int index);
    unsigned int getValue();
    void setValue(unsigned int value);
    unsigned int getNoOccurrences();
    void getNoOccurrences(unsigned int noOccurrences);

    std::string toStringDelimiter(char sep);
    void loadFromString(std::string args, char sep);

    Banknote& operator=(const Banknote &banknote);

    friend std::istream &operator>>(std::istream &is, Banknote &banknote);
    friend std::ostream &operator<<(std::ostream &os, const Banknote &banknote);
};


#endif //LAB_910_TUDORSUIU_BANKNOTE_H
