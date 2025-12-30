/*
 * @lc app=leetcode id=284 lang=cpp
 *
 * [284] Peeking Iterator
 */

// Brief, Digested Understanding:
//
// The goal is to create an iterator that, in addition to the usual next() and
// hasNext() operations, also supports a peek() operation. The peek() operation
// should let us look at the next element in the iteration without actually
// advancing the iterator. This means that after calling peek(), a subsequent
// call to next() should still return the same value as peek() did, and only
// then move forward.
//
// The challenge is to implement this without modifying the underlying iterator
// or making a copy of the input data, and to ensure that all operations are
// efficient and correct for all valid sequences of calls.

// High-Level Summary:
//
// The solution uses a "lookahead" or "prefetch" approach: we always keep track
// of the next element in advance by storing it in a private variable. When the
// PeekingIterator is constructed, we immediately fetch the first element (if
// any) and store it. The peek() operation simply returns this stored value. The
// next() operation returns the stored value and then fetches the next one (if
// available). The hasNext() operation checks if our stored value is valid
// (i.e., if there are more elements).
//
// This approach ensures that peek(), next(), and hasNext() all work in O(1)
// time and space, and that the underlying iterator is only advanced when
// necessary. No extra copies of the input are made, and the interface is
// respected.

// @lc code=start
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

#include <vector> // Needed for std::vector<int>
using std::vector;

class PeekingIterator : public Iterator {
private:
  // This variable stores the next element in the iteration, if any.
  int nextVal;
  // This flag indicates whether there is a next element available.
  bool hasNextVal;

public:
  // Constructor: initializes the PeekingIterator with the given nums.
  // We immediately fetch the first element (if any) and store it.
  PeekingIterator(const vector<int> &nums) : Iterator(nums) {
    // Check if the underlying iterator has a next element.
    if (Iterator::hasNext()) {
      // If so, fetch and store it in nextVal.
      nextVal = Iterator::next();
      hasNextVal = true;
    } else {
      // If not, mark that there is no next element.
      hasNextVal = false;
    }
  }

  // Returns the next element in the iteration without advancing the iterator.
  int peek() {
    // Since we always keep the next element in nextVal, just return it.
    // The problem guarantees that peek() is only called when valid.
    return nextVal;
  }

  // Returns the next element and advances the iterator.
  int next() {
    // Store the current nextVal to return.
    int ret = nextVal;
    // Advance the underlying iterator and update nextVal and hasNextVal.
    if (Iterator::hasNext()) {
      // If there is another element, fetch and store it.
      nextVal = Iterator::next();
      hasNextVal = true;
    } else {
      // If not, mark that there are no more elements.
      hasNextVal = false;
    }
    // Return the previously stored value.
    return ret;
  }

  // Returns true if there are still elements in the iteration.
  bool hasNext() const {
    // Simply return our flag indicating if a next element is available.
    return hasNextVal;
  }
};
// @lc code=end
