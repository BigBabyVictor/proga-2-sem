#include <iostream>
#include "index_error.h"

template <int N, typename T>
class FixedArray {
private:
    T data[N];

public:
    T& operator[](int index) {
        if (index < 0 || index >= N) {
            throw IndexError("Index out of range");
        }
        return data[index];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= N) {
            throw IndexError("Index out of range");
        }
        return data[index];
    }

    int size() const {
        return N;
    }
};
