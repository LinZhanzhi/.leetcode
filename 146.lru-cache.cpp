/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
#include <list>          // Include the list container for maintaining LRU order
#include <unordered_map> // Include the unordered_map for fast key lookup

// LRUCache class definition
class LRUCache {
public:
  LRUCache(int capacity)
      : cap(capacity) {} // Constructor initializes cache capacity

  int get(int key) {
    auto it = cache.find(key); // Try to find the key in the cache
    if (it == cache.end())     // If key is not found
      return -1;               // Return -1 to indicate a miss
    // Move the accessed node to the front (most recently used)
    lru.splice(lru.begin(), lru,
               it->second); // Move the accessed node to the front of the list
    return it->second->second; // Return the value associated with the key
  }

  void put(int key, int value) {
    auto it = cache.find(key); // Try to find the key in the cache
    if (it != cache.end()) {   // If key exists in cache
      // Update value and move to front
      it->second->second = value;               // Update the value
      lru.splice(lru.begin(), lru, it->second); // Move the node to the front
    } else {                                    // If key does not exist
      if (lru.size() == cap) {                  // If cache is at capacity
        // Remove least recently used
        int old_key =
            lru.back().first; // Get the key of the least recently used item
        lru.pop_back(); // Remove the least recently used item from the list
        cache.erase(old_key); // Remove the key from the map
      }
      lru.emplace_front(
          key, value); // Insert the new key-value pair at the front of the list
      cache[key] =
          lru.begin(); // Update the map with the iterator to the new node
    }
  }

private:
  int cap; // Maximum capacity of the cache
  std::list<std::pair<int, int>>
      lru; // Doubly linked list to store keys and values in LRU order
  std::unordered_map<int, std::list<std::pair<int, int>>::iterator>
      cache; // Map from key to list iterator for O(1) access
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
