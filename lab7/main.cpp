#include <iostream>
#include "CircleBuffer.h"

using namespace std;

template <class T>
void printInformation(const CircleBuffer<T>& buffer) {
    cout << "Capacity: " << buffer.capacity() << endl;
    cout << "Size: " << buffer.size() << endl;
    cout << "Elements: ";
    for (const auto& element : buffer) {
        cout << element << ' ';
    }
    cout << endl;
}

int main() {
    CircleBuffer<int> buffer(5);

    buffer.push_front(1);
    buffer.push_back(78);
    buffer.push_back(90);
    buffer.push_front(100);

    printInformation(buffer);
    cout << endl;

    buffer.resize(100);
    buffer.pop_back();
    buffer.pop_front();
    buffer.insert(1, 91);
    buffer.remove(0);
    printInformation(buffer);

    return 0;
}
