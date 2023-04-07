#ifndef INTEGERSET_H
#define INTEGERSET_H

#include <iostream>
#include <bitset>

class IntegerSet {
public:
    IntegerSet();

    void add(int value);
    void remove(int value);

    IntegerSet operator+(const IntegerSet& other) const;
    bool operator==(const IntegerSet& other) const;
    bool operator!=(const IntegerSet& other) const;

    IntegerSet& operator+=(int value);
    IntegerSet& operator-=(int value);

    friend std::ostream& operator<<(std::ostream& os, const IntegerSet& set);

private:
    std::bitset<10> m_set;
};

#endif // INTEGERSET_H
