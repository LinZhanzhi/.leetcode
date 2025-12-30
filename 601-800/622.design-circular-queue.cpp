/*
 * @lc app=leetcode id=622 lang=cpp
 *
 * [622] Design Circular Queue
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The goal is to implement a fixed-size circular queue (ring buffer) that
 * supports basic queue operations: enqueue (add to rear), dequeue (remove from
 * front), and checks for empty/full status. The "circular" aspect means that
 * when the end of the buffer is reached, new elements can wrap around to the
 * beginning if space is available, making efficient use of the array.
 *
 * High-Level Summary:
 * ----
 * We use a fixed-size array to store the queue elements, and two pointers
 * (indices):
 *   - 'front' points to the index of the current front element.
 *   - 'rear' points to the index where the next element will be inserted.
 * We also track the current number of elements ('count') to distinguish between
 * empty and full states. All operations are O(1) time and space is O(k).
 * The indices are updated using modulo arithmetic to wrap around the array.
 */

// @lc code=start
#include <vector> // Include vector for the underlying storage

class MyCircularQueue {
private:
  std::vector<int> data; // Underlying array to store queue elements
  int front;             // Index of the front element
  int rear;              // Index where the next element will be inserted
  int count;             // Current number of elements in the queue
  int capacity;          // Maximum size of the queue

  // Helper function to move an index forward by one position, wrapping around
  int nextIndex(int idx) const {
    // Use modulo to wrap around to 0 if idx + 1 == capacity
    return (idx + 1) % capacity;
  }

  // Helper function to move an index backward by one position, wrapping around
  int prevIndex(int idx) const {
    // Use modulo to wrap around to capacity - 1 if idx == 0
    return (idx - 1 + capacity) % capacity;
  }

public:
  // Constructor: Initialize the queue with given size k
  MyCircularQueue(int k) : data(k), front(0), rear(0), count(0), capacity(k) {
    // 'data' is initialized with size k, all elements default to 0
    // 'front' and 'rear' both start at 0 (empty queue)
    // 'count' tracks the number of elements in the queue
  }

  // Insert an element into the circular queue
  bool enQueue(int value) {
    if (isFull()) {
      // Cannot insert if the queue is full
      return false;
    }
    // Place the new value at the 'rear' index
    data[rear] = value;
    // Move 'rear' forward to the next position (wrap around if needed)
    rear = nextIndex(rear);
    // Increase the count of elements
    ++count;
    return true;
  }

  // Delete an element from the circular queue
  bool deQueue() {
    if (isEmpty()) {
      // Cannot remove if the queue is empty
      return false;
    }
    // Move 'front' forward to the next position (wrap around if needed)
    front = nextIndex(front);
    // Decrease the count of elements
    --count;
    return true;
  }

  // Get the front item from the queue
  int Front() {
    if (isEmpty()) {
      // If empty, return -1 as specified
      return -1;
    }
    // Return the element at the 'front' index
    return data[front];
  }

  // Get the last item from the queue
  int Rear() {
    if (isEmpty()) {
      // If empty, return -1 as specified
      return -1;
    }
    // The last element is at the index just before 'rear'
    // Use prevIndex to handle wrap-around
    int lastIdx = prevIndex(rear);
    return data[lastIdx];
  }

  // Check whether the circular queue is empty
  bool isEmpty() {
    // Queue is empty if count is 0
    return count == 0;
  }

  // Check whether the circular queue is full
  bool isFull() {
    // Queue is full if count equals capacity
    return count == capacity;
  }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end
