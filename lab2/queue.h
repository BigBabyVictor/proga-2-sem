#ifndef QUEUE_H
#define QUEUE_H

#include <string>
#include <vector>

class Queue {
public:
    Queue();
    Queue(int max_size);
    Queue(const Queue &other);

    int length() const;
    bool enqueue(const std::string &value);
    std::string dequeue();
    std::string back() const;
    std::string front() const;
    void display() const;

private:
    std::vector<std::string> data;
    int max_size;
};

#endif
