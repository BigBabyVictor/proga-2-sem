#include "queue.h"
#include <iostream>

Queue::Queue() : max_size(10) {}

Queue::Queue(int max_size) : max_size(max_size) {}

Queue::Queue(const Queue &other) : data(other.data), max_size(other.max_size) {}

int Queue::length() const {
    return data.size();
}

bool Queue::enqueue(const std::string &value) {
    if (length() < max_size) {
        data.push_back(value);
        return true;
    }
    return false;
}

std::string Queue::dequeue() {
    if (!data.empty()) {
        std::string first = data.front();
        data.erase(data.begin());
        return first;
    }
    return "";
}

std::string Queue::back() const {
    return data.empty() ? "" : data.back();
}

std::string Queue::front() const {
    return data.empty() ? "" : data.front();
}

void Queue::display() const {
    for (const auto &element : data) {
        std::cout << element << std::endl;
    }
}

