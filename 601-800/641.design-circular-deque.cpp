/*
 * @lc app=leetcode id=641 lang=cpp
 *
 * [641] Design Circular Deque
 */

/*
 * Brief Digested Understanding:
 * ----
 * This problem asks us to implement a double-ended queue (deque) with a fixed
 * maximum size, supporting efficient insertion and deletion from both the front
 * and rear ends. The deque should behave in a circular fashion, meaning that
 * when we reach the end of the underlying storage, we wrap around to the
 * beginning. We must provide methods to insert and delete at both ends, check
 * if the deque is empty or full, and retrieve the front and rear elements.
 *
 * High-Level Summary:
 * ----
 * We'll use a fixed-size array to store the elements, and two pointers (front
 * and rear) to track the current start and end positions. The circular nature
 * is handled by using modulo arithmetic to wrap the pointers. We also maintain
 * a count of the current number of elements to easily check for full/empty
 * conditions. Each operation (insert, delete, get, check) can be performed in
 * O(1) time. Space complexity is O(k), where k is the maximum size.
 */

// @lc code=start
#include <vector> // For using std::vector as the underlying storage.

class MyCircularDeque {
private:
  std::vector<int> data; // Fixed-size array to store deque elements.
  int front;             // Points to the index of the front element.
  int rear; // Points to the index where the next rear element will be inserted.
  int capacity; // Maximum number of elements the deque can hold.
  int count;    // Current number of elements in the deque.

  // Helper function to move an index forward circularly.
  int next(int idx) const {
    // Move to the next index, wrapping around if necessary.
    return (idx + 1) % capacity;
  }

  // Helper function to move an index backward circularly.
  int prev(int idx) const {
    // Move to the previous index, wrapping around if necessary.
    return (idx - 1 + capacity) % capacity;
  }

public:
  // Constructor: Initializes the deque with a maximum size of k.
  MyCircularDeque(int k) : data(k), capacity(k), count(0) {
    // The front pointer starts at 0 (the first position).
    // The rear pointer also starts at 0, indicating the next insertion at rear.
    front = 0;
    rear = 0;
  }

  // Adds an item at the front of Deque. Returns true if successful.
  bool insertFront(int value) {
    if (isFull()) {
      // Cannot insert if the deque is full.
      return false;
    }
    // Move front pointer backward to make space for the new element.
    front = prev(front);
    data[front] = value; // Place the new value at the new front.
    ++count;             // Increase the element count.
    return true;
  }

  // Adds an item at the rear of Deque. Returns true if successful.
  bool insertLast(int value) {
    if (isFull()) {
      // Cannot insert if the deque is full.
      return false;
    }
    data[rear] = value; // Place the new value at the current rear.
    rear = next(rear);  // Move rear pointer forward for the next insertion.
    ++count;            // Increase the element count.
    return true;
  }

  // Deletes an item from the front of Deque. Returns true if successful.
  bool deleteFront() {
    if (isEmpty()) {
      // Cannot delete if the deque is empty.
      return false;
    }
    front = next(front); // Move front pointer forward to remove the element.
    --count;             // Decrease the element count.
    return true;
  }

  // Deletes an item from the rear of Deque. Returns true if successful.
  bool deleteLast() {
    if (isEmpty()) {
      // Cannot delete if the deque is empty.
      return false;
    }
    rear = prev(rear); // Move rear pointer backward to remove the element.
    --count;           // Decrease the element count.
    return true;
  }

  // Gets the front item from the deque. Returns -1 if empty.
  int getFront() {
    if (isEmpty()) {
      // No elements to return.
      return -1;
    }
    // The front pointer always points to the front element.
    return data[front];
  }

  // Gets the last item from the deque. Returns -1 if empty.
  int getRear() {
    if (isEmpty()) {
      // No elements to return.
      return -1;
    }
    // The rear pointer points to the next insertion position,
    // so the last element is at prev(rear).
    return data[prev(rear)];
  }

  // Checks whether the deque is empty.
  bool isEmpty() { return count == 0; }

  // Checks whether the deque is full.
  bool isFull() { return count == capacity; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end
