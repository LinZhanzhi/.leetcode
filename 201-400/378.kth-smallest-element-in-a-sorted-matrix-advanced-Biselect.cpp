/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */
/*
 * Brief, Digested Understanding:
 * ----
 * We are given an n x n matrix where each row and column is sorted in ascending
 * order. The goal is to find the kth smallest element in the matrix. Instead of
 * using binary search, we will use a divide-and-conquer selection algorithm
 * inspired by the X+Y paper, which recursively reduces the problem to smaller
 * submatrices and uses rank-based selection.
 *
 * High-Level Summary:
 * ----
 * This solution implements the "biselect" algorithm for order statistics in
 * sorted matrices. The algorithm recursively selects two nearby order
 * statistics in a reduced submatrix, computes their ranks in the full matrix,
 * and then either returns the answer directly or selects from a small auxiliary
 * list. The key primitives are:
 *   - rank(A, v): counts the number of elements in A less than v.
 *   - pick(L, k): selects the kth smallest element from an unsorted list L in
 * linear time. The overall time complexity is O(n), and space complexity is
 * O(n) for the auxiliary list.
 */

#include <algorithm>
#include <utility> // For std::pair
#include <vector>

using std::max;
using std::min;
using std::nth_element;
using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to find the kth smallest element in the matrix
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    int matrixSize = matrix.size();
    // The biselect function returns a pair: (kth, kth) smallest, so we take the
    // first
    return biselect(matrix, 0, 0, matrixSize, k, k).first;
  }

private:
  // Helper function to count the number of elements in the submatrix
  // matrix[startRow : startRow+size][startCol : startCol+size] less than value
  int countLessThan(const vector<vector<int>> &matrix, int startRow,
                    int startCol, int size, int value) {
    int numLessThan = 0;
    // For each row, start from the rightmost column and move left
    for (int row = startRow; row < startRow + size; ++row) {
      int col = startCol + size - 1; // Reset col for each row!
      // Move left while elements are >= value
      while (col >= startCol && matrix[row][col] >= value) {
        --col;
      }
      // All elements to the left of col (inclusive) are < value
      numLessThan += (col - startCol + 1);
    }
    return numLessThan;
  }

  // Helper function to select the kth smallest element from an unsorted list
  int selectKthSmallest(vector<int> &unsortedList, int k) {
    // If the list is empty or k is out of bounds, return -1 (should not happen
    // in correct logic)
    if (unsortedList.empty() || k < 1 || k > (int)unsortedList.size())
      return -1;
    // nth_element rearranges so that the element at unsortedList[k-1] is the
    // kth smallest
    nth_element(unsortedList.begin(), unsortedList.begin() + k - 1,
                unsortedList.end());
    return unsortedList[k - 1];
  }

  // The main recursive biselect function
  // Returns a pair: (kth smallest, k'th smallest) in the submatrix
  // matrix[startRow : startRow+size][startCol : startCol+size]
  std::pair<int, int> biselect(const vector<vector<int>> &matrix, int startRow,
                               int startCol, int size, int kthOrder,
                               int kthOrderPrime) {
    // Base case: for very small submatrices, flatten and sort directly
    if (size <= 2) {
      vector<int> flattenedValues;
      for (int row = startRow; row < startRow + size; ++row) {
        for (int col = startCol; col < startCol + size; ++col) {
          flattenedValues.push_back(matrix[row][col]);
        }
      }
      std::sort(flattenedValues.begin(), flattenedValues.end());
      // Return the kth and k'p smallest elements as a pair
      return std::make_pair(flattenedValues[kthOrder - 1],
                            flattenedValues[kthOrderPrime - 1]);
    }

    // Reduce the submatrix by taking every other row and column (i.e.,
    // submatrix of size size/2)
    int reducedSize = size / 2 + (size % 2); // Handle odd size
    vector<int> reducedRowIndices, reducedColIndices;
    for (int i = 0; i < reducedSize; ++i) {
      // Only add indices if they are within the bounds of the matrix
      if (startRow + i * 2 < (int)matrix.size())
        reducedRowIndices.push_back(startRow + i * 2);
      if (startCol + i * 2 < (int)matrix[0].size())
        reducedColIndices.push_back(startCol + i * 2);
    }

    // The reduced submatrix may be smaller than reducedSize x reducedSize if at
    // the edge
    int actualReducedRows = reducedRowIndices.size();
    int actualReducedCols = reducedColIndices.size();

    // Build the reduced submatrix
    vector<vector<int>> reducedSubmatrix(actualReducedRows,
                                         vector<int>(actualReducedCols));
    for (int i = 0; i < actualReducedRows; ++i)
      for (int j = 0; j < actualReducedCols; ++j)
        reducedSubmatrix[i][j] =
            matrix[reducedRowIndices[i]][reducedColIndices[j]];

    // Recursively select two candidates in the reduced submatrix
    // Clamp kthOrder and kthOrderPrime to the size of the reduced submatrix
    int maxOrder = actualReducedRows * actualReducedCols;
    int reducedKthOrder = min(kthOrder, maxOrder);
    int reducedKthOrderPrime = min(kthOrderPrime, maxOrder);

    std::pair<int, int> candidatePair = biselect(
        reducedSubmatrix, 0, 0, min(actualReducedRows, actualReducedCols),
        reducedKthOrder, reducedKthOrderPrime);
    int candidateA = candidatePair.first, candidateB = candidatePair.second;

    // Compute ranks of candidateA and candidateB in the full submatrix
    int rankA = countLessThan(matrix, startRow, startCol, size, candidateA);
    int rankB = countLessThan(matrix, startRow, startCol, size, candidateB);

    // Build the auxiliary list: all elements strictly between candidateA and
    // candidateB
    vector<int> betweenCandidatesList;
    for (int row = startRow; row < startRow + size; ++row) {
      for (int col = startCol; col < startCol + size; ++col) {
        if (matrix[row][col] > candidateA && matrix[row][col] < candidateB) {
          betweenCandidatesList.push_back(matrix[row][col]);
        }
      }
    }

    // Select the kth and k'p smallest elements using the ranks and the
    // auxiliary list
    int kthSmallestValue, kthPrimeSmallestValue;
    if (rankA == kthOrder - 1) {
      kthSmallestValue = candidateA;
    } else if (kthOrder == rankB - size + 1) {
      kthSmallestValue = candidateB;
    } else {
      // The kth smallest is in betweenCandidatesList
      // Defensive: check if the index is valid
      int idx = kthOrder - rankA - 1;
      if (idx >= 0 && idx < (int)betweenCandidatesList.size())
        kthSmallestValue = selectKthSmallest(betweenCandidatesList, idx + 1);
      else
        kthSmallestValue = candidateB; // fallback, should not happen
    }

    if (rankA == kthOrderPrime - 1) {
      kthPrimeSmallestValue = candidateA;
    } else if (kthOrderPrime == rankB - size + 1) {
      kthPrimeSmallestValue = candidateB;
    } else {
      int idx = kthOrderPrime - rankA - 1;
      if (idx >= 0 && idx < (int)betweenCandidatesList.size())
        kthPrimeSmallestValue =
            selectKthSmallest(betweenCandidatesList, idx + 1);
      else
        kthPrimeSmallestValue = candidateB; // fallback, should not happen
    }

    // Return the pair of kth and k'p smallest elements
    return std::make_pair(kthSmallestValue, kthPrimeSmallestValue);
  }
};
// @lc code=end
