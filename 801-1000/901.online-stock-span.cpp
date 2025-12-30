/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */

// Brief Digested Understanding:
// ----
// The core task is to support price registration (one price per day) and,
// immediately for each such registration, answer: for how many consecutive
// days (ending today) has the price been less than or equal to today's price?
// This asks: count back including today until a day where the price was
// strictly greater than today's. Brute-force look-back would be too slow; we
// need something smarter to support many fast queries.

// High-Level Summary:
// ----
// We'll use a *monotonic stack* to efficiently track past price/answer pairs.
// When a new price comes in, we'll pop off all stack items with prices less
// than or equal to the new price, aggregating their spans. In effect, each
// stack element represents a day where the price was strictly higher than any
// future day remaining in the stack. The top of the stack always gives us the
// closest previous day with a price higher than today (or none). This reduces
// the problem from O(N^2) lookback to O(N) total time for many calls. Each
// price enters and leaves the stack only once.
//
// Time complexity: *amortized* O(1) per `next()` call (overall O(N) for N
// days). Space complexity: O(N), where N is the number of days (prices).

#include <stack>
#include <utility> // For std::pair

using std::pair;
using std::stack;

class StockSpanner {
private:
  // The stack stores pairs: {price, span}
  // - price: the stock price for a specific previous day
  // - span: how many consecutive days (ending at that day) where the price
  //         was less than or equal to that day's price, i.e., the span
  stack<pair<int, int>> monoStack;

  // Helper function to calculate the span for a new day's price
  int calculateSpan(int price) {
    // Start the span at 1 (today itself always counts)
    int span = 1;

    // Pop stack's top while the price at the top is less than or equal to
    // today's price. Aggregate the span from popped elements.
    while (!monoStack.empty() && monoStack.top().first <= price) {
      // Add the popped day's span to today's span, because that whole
      // range was strictly less than or equal to the current day's price
      span += monoStack.top().second;
      monoStack.pop();
    }
    // Push the current (price, span) onto the stack for future lookups
    monoStack.push({price, span});
    return span;
  }

public:
  // Constructor: simply clear the stack for a new object
  StockSpanner() {
    // Ensures the stack is empty at the start
    while (!monoStack.empty())
      monoStack.pop();
  }

  // Registers the next price and returns the span for today
  int next(int price) {
    // Delegate logic to the helper for modularity and clarity
    return calculateSpan(price);
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end
