/*
 * @lc app=leetcode id=966 lang=cpp
 *
 * [966] Vowel Spellchecker
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * We need to implement a spellchecker that corrects a query word based on a given wordlist.
 * The correction rules have a strict precedence:
 * 1. Exact Match: If the query is exactly in the wordlist, return it.
 * 2. Capitalization Match: If the query matches a word case-insensitively, return the first such match in the wordlist.
 * 3. Vowel Match: If the query matches a word case-insensitively ignoring vowels (treating all vowels as the same placeholder), return the first such match.
 * 4. No Match: Return an empty string.
 *
 * High-Level Summary:
 * -------------------
 * We can solve this efficiently using hash maps for fast lookups.
 * We will preprocess the wordlist into three data structures:
 * 1. exactSet: A set containing all original words for O(1) exact match checks.
 * 2. capMap: A map from "lowercase word" -> "first original word". This handles case-insensitive matches.
 * 3. owelMap: A map from "lowercase word with vowels masked" -> "first original word". This handles vowel errors.
 *
 * During preprocessing, we iterate through the wordlist and populate these maps. Crucially, for capMap and owelMap, we only insert if the key is not already present, ensuring we respect the "first match" rule.
 *
 * For each query, we check the maps in the order of precedence: exactSet -> capMap -> owelMap.
 *
 * Time Complexity:
 *   - Preprocessing: O(N * L), where N is the number of words and L is the max length of a word.
 *   - Querying: O(M * L), where M is the number of queries.
 * Space Complexity: O(N * L) to store the maps and set.
 */

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
private:
    // Helper to convert a string to lowercase
    string toLower(string s) {
        for (char &c : s) {
            c = tolower(c);
        }
        return s;
    }

    // Helper to convert a string to lowercase and replace vowels with '*'
    string toDevowel(string s) {
        string res = "";
        for (char c : s) {
            char lowerC = tolower(c);
            if (lowerC == 'a' || lowerC == 'e' || lowerC == 'i' || lowerC == 'o' || lowerC == 'u') {
                res += '*';
            } else {
                res += lowerC;
            }
        }
        return res;
    }

public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exactSet;
        unordered_map<string, string> capMap;
        unordered_map<string, string> vowelMap;

        // Preprocess wordlist
        for (const string& word : wordlist) {
            // 1. Exact match set
            exactSet.insert(word);

            // 2. Capitalization map (store first occurrence)
            string lowerWord = toLower(word);
            if (capMap.find(lowerWord) == capMap.end()) {
                capMap[lowerWord] = word;
            }

            // 3. Vowel map (store first occurrence)
            string devowelWord = toDevowel(word);
            if (vowelMap.find(devowelWord) == vowelMap.end()) {
                vowelMap[devowelWord] = word;
            }
        }

        vector<string> result;
        result.reserve(queries.size());

        for (const string& query : queries) {
            // Rule 1: Exact Match
            if (exactSet.count(query)) {
                result.push_back(query);
                continue;
            }

            // Rule 2: Capitalization Match
            string lowerQuery = toLower(query);
            if (capMap.count(lowerQuery)) {
                result.push_back(capMap[lowerQuery]);
                continue;
            }

            // Rule 3: Vowel Match
            string devowelQuery = toDevowel(query);
            if (vowelMap.count(devowelQuery)) {
                result.push_back(vowelMap[devowelQuery]);
                continue;
            }

            // Rule 4: No Match
            result.push_back("");
        }

        return result;
    }
};
// @lc code=end
