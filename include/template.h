//
// Created by 大江流韵 on 2026/4/8.
//

#ifndef CPP_BASIC_TEMPLATE_H
#define CPP_BASIC_TEMPLATE_H
#include <vector>
template<typename T>
T add(T a, T b) {
    return a + b;
}

template<class C>
class Container {
    std::vector<C> items;
public:
    std::vector<C> getItems() {
        return items;
    }

    C getItem(int index) {
        return items[index];
    }

    void append(C item) {
        items.push_back(item);
    }

    int getSize() {
        return items.size();
    }
};

#endif //CPP_BASIC_TEMPLATE_H