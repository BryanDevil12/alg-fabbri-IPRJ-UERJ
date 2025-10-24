#ifndef BUFFER_CIRCULAR_H
#define BUFFER_CIRCULAR_H

class BufferCircular {
private:
    int* buffer;
    int head;
    int tail;
    int size;
    bool full;

public:
    BufferCircular(int size);
    ~BufferCircular();
    bool is_full();
    bool is_empty();
    void enqueue(int item);
    int dequeue();
};

#endif // BUFFER_CIRCULAR_H
