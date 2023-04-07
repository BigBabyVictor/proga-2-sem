#include "IntegerSet.h"
#include <stdexcept>

IntegerSet::IntegerSet() {}

void IntegerSet::add(int value) {
    if (value < 0 || value > 9) {
        throw std::out_of_range("Value must be between 0 and 9.");
    }
    m_set.set(value);
}

void IntegerSet::remove(int value) {
    if (value < 0 || value > 9) {
        throw std::out_of_range("Value must be between 0 and 9.");
    }
    m_set.reset(value);
}

IntegerSet IntegerSet::operator+(const IntegerSet& other) const {
    IntegerSet result;
    result.m_set = m_set | other.m_set;
    return result;
}

bool IntegerSet::operator==(const IntegerSet& other) const {
    return m_set == other.m_set;
}

bool IntegerSet::operator!=(const IntegerSet& other) const {
    return m_set != other.m_set;
}

IntegerSet& IntegerSet::operator+=(int value) {
    add(value);
    return *this;
}

IntegerSet& IntegerSet::operator-=(int value) {
    remove(value);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const IntegerSet& set) {
    os << '{';
    bool first = true;
    for (int i = 0; i < 10; ++i) {
        if (set.m_set[i]) {
            if (!first) {
                os << ", ";
            }
            os << i;
            first = false;
        }
    }
    os << '}';
    return os;
}
