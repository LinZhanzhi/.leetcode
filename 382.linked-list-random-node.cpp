/*
 * @lc app=leetcode id=382 lang=cpp
 *
 * [382] Linked List Random Node
 */

// Brief, Digested Understanding:
//
// The goal is to pick a random node's value from a singly linked list, ensuring
// that every node has an equal chance of being chosen. The challenge is to do
// this efficiently, even if the list is very large or its length is unknown,
// and ideally without using extra space proportional to the list size.
//
// High-Level Summary:
//
// The solution uses the "Reservoir Sampling" algorithm, which allows us to
// select a random element from a stream (or linked list) of unknown length in a
// single pass and with O(1) extra space. We traverse the list once for each
// getRandom() call, updating our chosen value with decreasing probability as we
// see more nodes. This ensures each node is chosen with equal probability. The
// constructor simply stores the head pointer for later use.
//
// Time Complexity: O(N) per getRandom() call, where N is the number of nodes in
// the list. Space Complexity: O(1) extra space (not counting the input list).

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
#include <cstdlib> // For rand()
#include <ctime>   // For seeding rand() if desired

class Solution {
private:
  ListNode *head_; // Store the head pointer for use in getRandom()

public:
  // Constructor: simply store the head pointer for later use.
  Solution(ListNode *head) {
    head_ = head;
    // Optionally, seed the random number generator once.
    // Uncomment the next line if you want to seed with time.
    // std::srand(std::time(nullptr));
  }

  // getRandom: Use reservoir sampling to pick a random node's value.
  int getRandom() {
    // Initialize the result with the value of the first node.
    int result = head_->val;
    ListNode *current = head_->next;
    int i = 2; // Start counting from the second node (1-based index)

    // Traverse the list starting from the second node.
    while (current != nullptr) {
      // For the i-th node, replace result with probability 1/i.
      // rand() % i gives a number in [0, i-1]. If it's 0, we replace.
      if (std::rand() % i == 0) {
        result = current->val;
      }
      current = current->next;
      ++i;
    }
    // After traversing the list, result holds the randomly chosen value.
    return result;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

/*
 * Why Reservoir Sampling Guarantees Equal Probability (Inductive Proof):
 * ---------------------------------------------------------------------
 * Reservoir sampling is a powerful algorithm for selecting k random items from
 * a stream (or linked list) of unknown length n, using only O(k) space. In the
 * case of this LeetCode problem, k = 1 (we want a single random node).
 *
 * The probability proof for reservoir sampling uses induction to show that
 * every item in the stream is selected with equal likelihood.
 *
 * Step-by-Step Inductive Proof (General k, Stream Length n):
 * ----------------------------------------------------------
 * Base Case:
 *   - When n = k, all k items are placed in the reservoir, so each is included
 * with probability 1 (k/k = 1).
 *
 * Inductive Hypothesis:
 *   - Assume that after processing n items, each has probability k/n of being
 * in the reservoir.
 *
 * Inductive Step:
 *   - When the (n+1)-th item arrives:
 *     - It is added to the reservoir with probability k/(n+1), replacing one of
 * the k reservoir items chosen uniformly at random.
 *     - Any existing item in the reservoir survives if it is not replaced. The
 * probability that a specific item survives is: (1 - (k/(n+1)) * (1/k)) +
 * (k/(n+1)) * ((k-1)/k) = n/(n+1)
 *     - So, the probability that a specific item remains in the reservoir after
 * n+1 items is: (k/n) * (n/(n+1)) = k/(n+1)
 *   - Thus, after n+1 items, every item (old or new) has probability k/(n+1) of
 * being in the reservoir.
 *
 * Special Case for k = 1 (Single Sample, as in this problem):
 * -----------------------------------------------------------
 * - For each node at position i (1-based), the probability it is chosen is:
 *     - It is selected at step i with probability 1/i, and survives all
 * subsequent steps with probability (i/(i+1)) * ... * ((n-1)/n)
 *     - The product telescopes to 1/n, so every node has exactly a 1/n chance
 * of being chosen.
 *
 * Summary Table:
 * ---------------
 * | Stream Length (n) | Reservoir Size (k) | Probability Per Item |
 * |-------------------|--------------------|---------------------|
 * | n = k             | k                  | 1                   |
 * | n > k             | k                  | k/n                 |
 *
 * This inductive proof holds for all variants of reservoir sampling and
 * demonstrates that every node in the linked list is selected with equal
 * probability, even though we do not know the length of the list in advance and
 * use only O(1) space.
 *
 * References:
 * [1] https://florian.github.io/reservoir-sampling/
 * [2] http://www.cse.cuhk.edu.hk/~taoyf/course/5705f10/lec7.pdf
 * [3]
 * https://cs-notes.gitbook.io/algorithm-notes/outline/overview-1/reservoir-sampling
 * [4] https://belanyi.fr/2024/08/02/reservoir-sampling/
 */
// @lc code=end
