/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * We need to implement a key-value store where each key can hold multiple values, each associated with a specific timestamp.
 * The set operation adds a value at a given timestamp.
 * The get operation retrieves the value associated with the largest timestamp less than or equal to the requested timestamp.
 *
 * High-Level Summary:
 * -------------------
 * We can use a Hash Map (unordered_map) to map each key to a list of (timestamp, value) pairs.
 * Since the problem statement guarantees that timestamps for set are strictly increasing, the list of pairs for any key will be naturally sorted by timestamp.
 *
 * For get(key, timestamp):
 * 1. Look up the list of pairs for the key. If not found, return "".
 * 2. Since the list is sorted by timestamp, we can use Binary Search (specifically upper_bound) to find the first element with a timestamp *greater* than the requested 	imestamp.
 * 3. The element immediately preceding this position will be the one with the largest timestamp <= requested timestamp.
 * 4. If the upper_bound returns the beginning of the list, it means all timestamps are greater than the requested one, so return "".
 *
 * Time Complexity:
 *   - set: O(1) (amortized) because we just push back to a vector.
 *   - get: O(log N) where N is the number of entries for that key, due to binary search.
 * Space Complexity: O(Total Entries) to store all key-value-timestamp triplets.
 */

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// @lc code=start
class TimeMap {
private:
    // Map key -> vector of {timestamp, value}
    // Using pair<int, string> to store timestamp and value.
    unordered_map<string, vector<pair<int, string>>> store;

public:
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        // Since timestamps are strictly increasing, we can just push back.
        store[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        // If key doesn't exist, return empty string
        if (store.find(key) == store.end()) {
            return "";
        }

        const vector<pair<int, string>>& values = store[key];

        // Use binary search to find the first element with timestamp > requested timestamp
        // We want the element just before that.
        // upper_bound requires a value to compare. We can use a dummy pair with the target timestamp
        // and a comparator that only looks at the timestamp (first element of pair).

        auto it = upper_bound(values.begin(), values.end(), timestamp,
            [](int val, const pair<int, string>& p) {
                return val < p.first;
            });

        // If 'it' is the begin(), it means all elements have timestamp > requested timestamp.
        // So no valid value exists <= timestamp.
        if (it == values.begin()) {
            return "";
        }

        // Otherwise, the element before 'it' is the answer.
        return prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end
