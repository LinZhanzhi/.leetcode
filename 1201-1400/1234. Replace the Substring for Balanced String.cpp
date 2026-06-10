/*
You are given a string s of length n containing only four kinds of characters: 'Q', 'W', 'E', and 'R'.

A string is said to be balanced if each of its characters appears n / 4 times where n is the length of the string.

Return the minimum length of the substring that can be replaced with any other string of the same length to make s balanced. If s is already balanced, return 0.



Example 1:

Input: s = "QWER"
Output: 0
Explanation: s is already balanced.
Example 2:

Input: s = "QQWE"
Output: 1
Explanation: We need to replace a 'Q' to 'R', so that "RQWE" (or "QRWE") is balanced.
Example 3:

Input: s = "QQQW"
Output: 2
Explanation: We can replace the first "QQ" to "ER".


Constraints:

n == s.length
4 <= n <= 105
n is a multiple of 4.
s contains only 'Q', 'W', 'E', and 'R'.
*/
class Solution
{
public:
    int balancedString(string s)
    {
        /*
        for the string to be balanced, each character must appear n/4 times.
        equivalently, all substrings of s must have that all 4 characters appear at most n/4 times.
        so when the the substring is the whole string, since all 4 characters appear at most n/4 times, and they sum up to n, they must all appear exactly n/4 times.
        and if there is any substring with any character appearing more than n/4 times, then the whole string must have that character appearing more than n/4 times, and thus the string is not balanced.
        but there can be more than one violating substring.
        actually if a substring is violating, then adding any prefix or suffix to it will also be violating, so we only need to consider the minimal violating substring, which is the one with the smallest length.

        let's consider fixing a violating string after we identify it.
        since we can only fix 1 violating string, of course we want the rest of string s to not be violating, other wise we will have to fix more than 1 violating string, which is not allowed.
        we just calculate number of each character needed to make each appear n/4 times, and put them in the violating strings position . and that's the fix.

        so actually we just want the minimal substring that excluding it will leave the rest of the string non-violating.
        then if the substring is violating, we give a fix. if not, it wouldn't hurt anything.
        */
        int n = s.size();
        // use a hash map to count the number of each character in the string
        unordered_map<char, int> count;
        for (char c : s)
        {
            count[c]++;
        }
        // if the string is already balanced, return 0
        if (count['Q'] == n / 4 && count['W'] == n / 4 && count['E'] == n / 4 && count['R'] == n / 4)
        {
            return 0;
        }
        // use a sliding window to find the minimal substring that excluding it will leave the rest of the string non-violating
        // for each right pointer, we move the left pointer while keeping the rest of the string is non-violating, and update the minimum length of the substring.
        int left = 0, right = 0, minLength = n;
        while (right < n)
        {
            count[s[right]]--;
            while (left < n && count['Q'] <= n / 4 && count['W'] <= n / 4 && count['E'] <= n / 4 && count['R'] <= n / 4)
            {
                minLength = min(minLength, right - left + 1);
                count[s[left]]++;
                left++;
            }
            right++;
        }
        return minLength;
    }
};