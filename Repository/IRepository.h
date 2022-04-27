//
// Created by Tudor on 4/26/2022.
//

#ifndef LAB_910_TUDORSUIU_IREPOSITORY_H
#define LAB_910_TUDORSUIU_IREPOSITORY_H

template<class T> class IRepository {
public:
    /**
     * Add entity
     * @param entity: T class object
     */
    virtual void addEntity(T entity) = 0;

    /**
     * Get all entities from file/memory
     * @return: Vector<class T> - all entities stored in file/memory
     */
    virtual std::vector<T> getAll() = 0;

    /**
     * Update entity
     * @param code: unsigned int - entity code
     * @param newEntity: T class object - updated entity
     */
    virtual void updateEntity(unsigned int code, T newEntity) = 0;

    /**
     * Delete entity
     * @param code: unsigned int - entity code
     */
    virtual void deleteEntity(unsigned int code) = 0;
};


#endif //LAB_910_TUDORSUIU_IREPOSITORY_H
