#include <gtest/gtest.h>
#include "../buffer_circular.h"

TEST(BufferCircularTest, EnqueueAndDequeue) {
    BufferCircular buffer(5);
    buffer.enqueue(1);
    buffer.enqueue(2);
    ASSERT_EQ(buffer.dequeue(), 1);
    ASSERT_EQ(buffer.dequeue(), 2);
}

TEST(BufferCircularTest, IsEmpty) {
    BufferCircular buffer(5);
    ASSERT_TRUE(buffer.is_empty());
    buffer.enqueue(1);
    ASSERT_FALSE(buffer.is_empty());
    buffer.dequeue();
    ASSERT_TRUE(buffer.is_empty());
}

TEST(BufferCircularTest, IsFull) {
    BufferCircular buffer(2);
    ASSERT_FALSE(buffer.is_full());
    buffer.enqueue(1);
    ASSERT_FALSE(buffer.is_full());
    buffer.enqueue(2);
    ASSERT_TRUE(buffer.is_full());
}

TEST(BufferCircularTest, Overflow) {
    BufferCircular buffer(1);
    buffer.enqueue(1);
    ASSERT_THROW(buffer.enqueue(2), std::overflow_error);
}

TEST(BufferCircularTest, Underflow) {
    BufferCircular buffer(1);
    ASSERT_THROW(buffer.dequeue(), std::underflow_error);
}
