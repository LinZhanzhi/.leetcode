/*
 * @lc app=leetcode id=725 lang=cpp
 *
 * [725] Split Linked List in Parts
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/**
 * Brief Digested Understanding:
 * ----
 * The problem requires us to split a singly-linked list into 'k' consecutive
 * parts such that the length of each part is as evenly distributed as possible.
 * If the list can't be evenly split, earlier parts get one extra node.
 * If there are more parts (k) than nodes, the extra parts should be nullptr.
 * The output should be a vector containing the head nodes of each of these
 * parts.
 *
 * In essence, we are partitioning a linked list into chunks of nearly equal
 * size, following left-to-right order, so that earlier parts are not smaller
 * than later ones.
 *
 * High-Level Summary:
 * ----
 * - First, calculate the total length of the linked list.
 * - Determine the base size of each part (length / k) and how many should get
 * an extra node (length % k).
 * - Then, for each part, use this sizing logic to detach and collect its nodes.
 * - For modularity, we use a helper function to count list nodes.
 * - Expected time complexity is O(N + k), where N is the number of nodes, since
 * we traverse the list at most twice: once for counting, then for splitting.
 * Space complexity is O(k) for the output array of heads.
 */

#include <vector> // Include vector for returning vector<ListNode*>
using std::vector;

class Solution {
public:
  /**
   * Split the given linked list into k consecutive parts and return
   * a std::vector<ListNode*> with the head of each part.
   * If the part is empty, the vector element is nullptr.
   */
  vector<ListNode *> splitListToParts(ListNode *head, int k) {
    int totalLength = getListLength(head); // Step 1: Find total number of nodes

    // Step 2: Determine the minimum part size and how many parts get an extra
    // node
    int minPartSize = totalLength / k; // Minimum nodes per part
    int extraNodes = totalLength % k;  // Some parts get one extra node

    vector<ListNode *> result; // Output vector of ListNode* (size k)
    ListNode *curr = head;     // Pointer for traversing list

    // Step 3: Split into k parts
    for (int i = 0; i < k; ++i) {
      // Start of the current part
      ListNode *partHead = curr;

      // Determine the size for this part: extra 1 node for first 'extraNodes'
      // parts
      int thisPartSize = minPartSize + (i < extraNodes ? 1 : 0);

      // For modularity, use helper to advance the pointer and break the part
      curr = splitOffPart(curr, thisPartSize);

      // Add this part's head (possibly nullptr) to result
      result.push_back(partHead);
    }
    // Step 4: Return the k parts
    return result;
  }

private:
  /**
   * Helper function that counts the number of nodes in a singly-linked list.
   * Returns the total length.
   */
  int getListLength(ListNode *head) {
    int length = 0;
    ListNode *node = head;
    // Traverse the entire list, incrementing the counter
    while (node) {
      ++length;
      node = node->next;
    }
    return length;
  }

  /**
   * Helper function to split off the first 'n' nodes from a list,
   * and return a pointer to the (n+1)-th node.
   *
   * The 'head' becomes the start of the part, which is terminated with nullptr.
   * If there are fewer than 'n' nodes, traverses as many as available.
   */
  ListNode *splitOffPart(ListNode *head, int n) {
    if (!head || n == 0)
      return head; // If empty or no nodes to take, just return
    ListNode *curr = head;
    // Traverse n-1 nodes, if possible
    for (int i = 1; i < n && curr; ++i) {
      curr = curr->next;
    }
    if (!curr)
      return nullptr; // If ran out of list, next part will be nullptr

    // Break the link after the nth node
    ListNode *nextPartHead = curr->next; // Save pointer to next part
    curr->next = nullptr;                // Terminate current part
    return nextPartHead; // Return starting node for the next part
  }
};
// @lc code=end
