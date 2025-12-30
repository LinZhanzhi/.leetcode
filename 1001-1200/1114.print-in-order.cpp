/*
 * @lc app=leetcode id=1114 lang=cpp
 *
 * [1114] Print in Order
 */

// @lc code=start
#include <condition_variable>
#include <functional>
#include <mutex>

// This class ensures that the methods first(), second(), and third() are
// executed in order, regardless of the order in which their corresponding
// threads are started.
class Foo {
public:
private:
  // Mutex to protect shared state
  std::mutex mtx;
  // Condition variable to notify waiting threads
  std::condition_variable cv;
  // State variable to track which function should run next
  int state;

public:
  // Constructor initializes state to 0 (meaning first() should run first)
  Foo() : state(0) {}

  // This method should always be called first.
  void first(std::function<void()> printFirst) {
    std::unique_lock<std::mutex> lock(mtx);
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    // Update state to indicate that first() has finished
    state = 1;
    // Notify all waiting threads that state has changed
    cv.notify_all();
  }

  // This method should always be called second.
  void second(std::function<void()> printSecond) {
    std::unique_lock<std::mutex> lock(mtx);
    // Wait until first() has finished (state >= 1)
    cv.wait(lock, [this] { return state >= 1; });
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    // Update state to indicate that second() has finished
    state = 2;
    // Notify all waiting threads that state has changed
    cv.notify_all();
  }

  // This method should always be called third.
  void third(std::function<void()> printThird) {
    std::unique_lock<std::mutex> lock(mtx);
    // Wait until second() has finished (state >= 2)
    cv.wait(lock, [this] { return state >= 2; });
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
    // No need to update state or notify, as this is the last method
  }
};

// @lc code=end
