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
     * @param index: unsigned int - entity index
     * @param newEntity: T class object - updated entity
     */
    virtual void updateEntity(unsigned int index, T newEntity) = 0;

    /**
     * Delete entity
     * @param index: unsigned int - entity index
     */
    virtual void deleteEntity(unsigned int index) = 0;

    /**
     * Get position by object index
     * @param index: unsigned int - object index
     * @return: int - object position
     */
    virtual int getPosByIndex(unsigned int index) = 0;
};


#endif //LAB_910_TUDORSUIU_IREPOSITORY_H
