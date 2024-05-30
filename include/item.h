#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
private:
    std::string name;

public:
    Item(const std::string& name);
    std::string getName() const;
};

#endif // ITEM_H
