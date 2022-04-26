//
// Created by Tudor on 4/26/2022.
//

#ifndef LAB_910_TUDORSUIU_IREPOSITORY_H
#define LAB_910_TUDORSUIU_IREPOSITORY_H

template<class T> class IRepository {
public:
    virtual void addEntity(T entity) = 0;
    virtual std::vector<T> getAll() = 0;
    virtual void updateEntity(unsigned int code, T newEntity) = 0;
    virtual void deleteEntity(unsigned int code) = 0;
};


#endif //LAB_910_TUDORSUIU_IREPOSITORY_H
