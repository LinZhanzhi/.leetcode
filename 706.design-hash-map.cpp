/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 */

// @lc code=start
class MyHashMap {
private:
  static const int SIZE = 10007; // A prime number for hash table size
  struct Node {
    int key, value;
    Node *next;
    Node(int k, int v) : key(k), value(v), next(nullptr) {}
  };
  Node *table[SIZE];

  int hash(int key) { return key % SIZE; }

public:
  MyHashMap() {
    for (int i = 0; i < SIZE; ++i) {
      table[i] = nullptr;
    }
  }

  void put(int key, int value) {
    int idx = hash(key);
    Node *curr = table[idx];
    Node *prev = nullptr;
    while (curr) {
      if (curr->key == key) {
        curr->value = value;
        return;
      }
      prev = curr;
      curr = curr->next;
    }
    Node *newNode = new Node(key, value);
    if (prev) {
      prev->next = newNode;
    } else {
      table[idx] = newNode;
    }
  }

  int get(int key) {
    int idx = hash(key);
    Node *curr = table[idx];
    while (curr) {
      if (curr->key == key) {
        return curr->value;
      }
      curr = curr->next;
    }
    return -1;
  }

  void remove(int key) {
    int idx = hash(key);
    Node *curr = table[idx];
    Node *prev = nullptr;
    while (curr) {
      if (curr->key == key) {
        if (prev) {
          prev->next = curr->next;
        } else {
          table[idx] = curr->next;
        }
        delete curr;
        return;
      }
      prev = curr;
      curr = curr->next;
    }
  }

  ~MyHashMap() {
    for (int i = 0; i < SIZE; ++i) {
      Node *curr = table[i];
      while (curr) {
        Node *tmp = curr;
        curr = curr->next;
        delete tmp;
      }
    }
  }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end
