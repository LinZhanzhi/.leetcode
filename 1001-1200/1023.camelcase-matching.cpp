/*
 * Brief Digested Understanding:
 * The problem asks us to check if a query string can be formed by inserting lowercase letters into a given pattern string.
 * Essentially, the pattern must be a subsequence of the query, AND any character in the query that is not part of this subsequence must be lowercase. If the query contains an uppercase letter that isn't in the pattern (in the correct relative order), the match fails.
 *
 * High-Level Summary:
 * We iterate through each query string and try to match it against the pattern using a two-pointer approach.
 * 1. We maintain a pointer for the pattern.
 * 2. We iterate through the query string character by character.
 * 3. If the current query character matches the current pattern character, we advance the pattern pointer.
 * 4. If they don't match, we check if the query character is uppercase. If it is, the match is invalid immediately because we can only insert lowercase letters.
 * 5. If the query character is lowercase and doesn't match, we simply ignore it (treat it as an insertion).
 * 6. After processing the query, if we have successfully matched all characters in the pattern, return true. Otherwise, false.
 *
 * Time Complexity: O(N * L), where N is the number of queries and L is the average length of a query string.
 * Space Complexity: O(1) extra space (excluding the output vector).
 */
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> result;
        for (const string& query : queries) {
            result.push_back(isMatch(query, pattern));
        }
        return result;
    }

private:
    bool isMatch(const string& query, const string& pattern) {
        int p = 0; // Pointer for pattern
        for (char c : query) {
            if (p < pattern.length() && c == pattern[p]) {
                // Character matches the current pattern character
                p++;
            } else if (isupper(c)) {
                // Character doesn't match and is uppercase -> Invalid
                // We can only insert lowercase letters.
                return false;
            }
            // If it's lowercase and doesn't match, we skip it (insertion).
        }
        // We must have matched the entire pattern
        return p == pattern.length();
    }
};