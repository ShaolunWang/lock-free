#include "ringbuffer/ringbuffer.hpp"
#include <gtest/gtest.h>

TEST(RingBufferTest, StartsEmpty) {
  RingBuffer<int> q(8);
  int x;
  EXPECT_FALSE(q.pop(x));
}

TEST(RingBufferTest, PushPopSingleElement) {
  RingBuffer<int> q(8);

  EXPECT_TRUE(q.emplace(42));

  int x;
  EXPECT_TRUE(q.pop(x));
  EXPECT_EQ(x, 42);

  EXPECT_FALSE(q.pop(x));
}

TEST(RingBufferTest, FillUntilFull) {
  constexpr size_t capacity = 4;
  RingBuffer<int> q(capacity);

  size_t emplaced = 0;
  while (q.emplace(emplaced)) {
    emplaced++;
  }

  EXPECT_FALSE(q.emplace(999));
}
