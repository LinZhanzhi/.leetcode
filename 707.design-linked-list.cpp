/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 */

/*
 * Brief Digested Understanding:
 * ----
 * This problem asks us to build, from scratch, a linked list structure that can
 * efficiently support both access (get) and modifications (add/delete at head,
 * tail, or arbitrary index). Nodes should contain values and pointers to next
 * (and optionally previous) nodes. No standard library linked list usage is
 * allowed; we must implement the internals ourselves, including node structure,
 * tracking size, and careful corner case management (like empty lists, index
 * bounds, etc).
 *
 * High-Level Summary:
 * ----
 * We'll use a **singly linked list** design for simplicity. Each node stores
 * its value and pointer to the next node. We'll maintain a dummy/sentinel head
 * node to simplify edge case insertions and deletions at the head. The list
 * also tracks its current size, allowing efficient index checking. The main
 * operations (get, add, delete) will be implemented by modular traversal and
 * helper methods, with special care for list boundaries and length constraints.
 * - **Time Complexity**: All operations are O(1) for head/tail, O(N) for
 * arbitrary index (with N = list length).
 * - **Space Complexity**: O(N) space for N nodes; no auxiliary structures
 * needed.
 */

// @lc code=start
class MyLinkedList {
private:
  // Definition for singly-linked list node.
  struct Node {
    int val;    // Value stored at this node.
    Node *next; // Pointer to the next node.

    Node(int v) : val(v), next(nullptr) {} // Node constructor.
  };

  Node *head; // Dummy/sentinel head node to simplify edge cases.
  int size;   // Tracks number of real nodes in the list.

  // Helper function to get pointer to node at POS-1, for insertions &
  // deletions. Returns pointer to the node just before index (0-based).
  Node *getPrevNode(int index) {
    // Start from dummy head.
    Node *curr = head;
    for (int i = 0; i < index; ++i) {
      curr = curr->next; // Traverse forward.
    }
    return curr;
  }

public:
  // Constructor: Initializes the linked list with a dummy head node and zero
  // size.
  MyLinkedList() {
    head = new Node(0); // Sentinel head node (does not store list data).
    size = 0;           // List is initially empty.
  }

  // Returns the value at the given index (0-based); returns -1 if index is
  // invalid.
  int get(int index) {
    // Check if index is out of valid range [0, size - 1].
    if (index < 0 || index >= size)
      return -1;

    Node *curr = head->next; // First real node is after dummy head.
    // Walk to the desired index.
    for (int i = 0; i < index; ++i) {
      curr = curr->next;
    }
    return curr->val;
  }

  // Inserts a new node with value val at the head (start) of the list.
  void addAtHead(int val) {
    addAtIndex(0, val); // Head insertion is same as insert at index 0.
  }

  // Appends a node with value val at the tail (end) of the list.
  void addAtTail(int val) {
    addAtIndex(size, val); // Tail insertion is same as insert at current size.
  }

  // Inserts a node with value val before index-th node.
  // If index == size, node is appended. If index > size, do nothing.
  void addAtIndex(int index, int val) {
    // Only allow insert at indices in [0, size].
    if (index < 0 || index > size)
      return;

    // Find node just before insertion point (using dummy head).
    Node *prev = getPrevNode(index);

    // Create new node and insert after 'prev'.
    Node *newNode = new Node(val);
    newNode->next = prev->next;
    prev->next = newNode;

    size++; // List size increases by one.
  }

  // Deletes the node at the given index if valid.
  void deleteAtIndex(int index) {
    // Only delete if index is within current list: [0, size - 1]
    if (index < 0 || index >= size)
      return;

    // Find node just before the one to delete.
    Node *prev = getPrevNode(index);

    // 'toDelete' is the node to actually remove from the list.
    Node *toDelete = prev->next;

    prev->next = toDelete->next; // Unhook node from list.
    delete toDelete;             // Free memory of node.

    size--; // List size decreases by one.
  }

  // ~MyLinkedList() is not strictly required for LeetCode but in real code,
  // should delete all nodes here to prevent memory leaks.
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
