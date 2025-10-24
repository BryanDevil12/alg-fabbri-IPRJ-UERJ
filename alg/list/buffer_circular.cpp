#include "buffer_circular.h"
#include <stdexcept>

BufferCircular::BufferCircular(int size) : head(0), tail(0), size(size), full(false) {
    buffer = new int[size];
}

BufferCircular::~BufferCircular() {
    delete[] buffer;
}

bool BufferCircular::is_full() {
    return full;
}

bool BufferCircular::is_empty() {
    return (!full && (head == tail));
}

void BufferCircular::enqueue(int item) {
    if (is_full()) {
        throw std::overflow_error("Buffer is full");
    }
    buffer[tail] = item;
    tail = (tail + 1) % size;
    full = (head == tail);
}

int BufferCircular::dequeue() {
    if (is_empty()) {
        throw std::underflow_error("Buffer is empty");
    }
    int item = buffer[head];
    full = false;
    head = (head + 1) % size;
    return item;
}
