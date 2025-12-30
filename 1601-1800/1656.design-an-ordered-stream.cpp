/*
 * @lc app=leetcode id=1656 lang=cpp
 *
 * [1656] Design an Ordered Stream
 */

/*
Problem:

You are given a stream of n (idKey, value) pairs arriving in arbitrary order,
where idKey is an integer between 1 and n and value is a string.

No two pairs have the same id.

After each insertion, you must return the largest possible chunk of values
that appear next in the order (i.e., starting from the smallest idKey not yet
returned), so that concatenating all returned chunks gives the values in order
of their IDs.

Solution:
We use a vector<string> of size n to store the values at their corresponding
positions (idKey-1). We maintain a pointer 'ptr' to the next idKey to return. On
each insert, we store the value, and then collect all consecutive non-empty
values starting from ptr, returning them as a chunk, and advancing ptr
accordingly.
*/

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class OrderedStream {
private:
  vector<string> stream; // stores values at index idKey-1
  int ptr;               // points to the next idKey to return (0-based)

public:
  // Constructor: initializes the stream with n empty strings and ptr to 0
  OrderedStream(int n) : stream(n), ptr(0) {}

  // Inserts (idKey, value) and returns the next chunk of values in order
  vector<string> insert(int idKey, string value) {
    // Store the value at the correct position (idKey-1)
    stream[idKey - 1] = value;

    vector<string> res;
    /*
     * The pointer 'ptr' always points to the next idKey (0-based) that should
     * be returned. After inserting a value, we check if the value at 'ptr' is
     * non-empty. If so, we collect all consecutive non-empty values starting
     * from 'ptr'. This forms the largest possible chunk to return in order. We
     * advance 'ptr' past all these returned values, so that next time we only
     * return values that have not yet been returned.
     */
    while (ptr < stream.size() && !stream[ptr].empty()) {
      res.push_back(stream[ptr]);
      ++ptr;
    }
    // If the inserted value does not fill the current 'ptr' position,
    // or there are gaps before 'ptr', we return an empty vector.
    // Otherwise, we return the chunk of consecutive values starting from 'ptr'.
    return res;
  }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
// @lc code=end
