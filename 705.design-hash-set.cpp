/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 */

// @lc code=start
class MyHashSet {
private:
  static const int SIZE = 1000001;
  bool data[SIZE];

public:
  MyHashSet() {
    for (int i = 0; i < SIZE; ++i) {
      data[i] = false;
    }
  }

  void add(int key) { data[key] = true; }

  void remove(int key) { data[key] = false; }

  bool contains(int key) { return data[key]; }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end
