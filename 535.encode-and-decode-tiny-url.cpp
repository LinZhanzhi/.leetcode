/*
 * @lc app=leetcode id=535 lang=cpp
 *
 * [535] Encode and Decode TinyURL
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem is to design a system that can convert a long URL into a short,
 * unique "tiny" URL, and then later convert that tiny URL back to the original
 * long URL. The main challenge is to ensure that each long URL can be uniquely
 * mapped to a tiny URL and that the mapping is reversible within the same
 * instance of the class.
 *
 * High-Level Summary:
 * ----
 * We'll use two hash maps to store the mapping between long URLs and their
 * corresponding short URLs. When encoding, if the long URL has already been
 * encoded, we return the existing short URL; otherwise, we generate a new
 * unique code, store the mapping, and return the new tiny URL. When decoding,
 * we simply look up the code in our map to retrieve the original long URL. The
 * code generation uses a simple counter and base62 encoding to ensure
 * uniqueness and compactness.
 *
 * Time Complexity:
 *   - encode: O(1) average (hash map insert/lookup)
 *   - decode: O(1) average (hash map lookup)
 * Space Complexity:
 *   - O(N), where N is the number of unique URLs encoded
 */

#include <string>        // For std::string
#include <unordered_map> // For std::unordered_map
using std::string;
using std::unordered_map;

// @lc code=start
class Solution {
private:
  // Maps to store the bidirectional mapping between long and short URLs
  unordered_map<string, string> longToShort; // Maps long URL to short code
  unordered_map<string, string> shortToLong; // Maps short code to long URL

  // Counter to ensure unique short codes
  int counter = 1;

  // The base URL for all tiny URLs
  const string base = "http://tinyurl.com/";

  // Characters used for base62 encoding (0-9, a-z, A-Z)
  const string chars =
      "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

  // Helper function to convert an integer to a base62 string
  string intToBase62(int num) {
    // If num is 0, return "0"
    if (num == 0)
      return string(1, chars[0]);
    string code;
    // Convert the integer to base62
    while (num > 0) {
      code = chars[num % 62] + code;
      num /= 62;
    }
    return code;
  }

  // Helper function to extract the code part from a short URL
  string extractCode(const string &shortUrl) {
    // The code is the part after the last '/'
    size_t pos = shortUrl.find_last_of('/');
    if (pos == string::npos)
      return "";
    return shortUrl.substr(pos + 1);
  }

public:
  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    // If this long URL has already been encoded, return the existing short URL
    if (longToShort.count(longUrl)) {
      return base + longToShort[longUrl];
    }
    // Generate a new unique code using the counter and base62 encoding
    string code = intToBase62(counter++);
    // Store the mappings in both directions
    longToShort[longUrl] = code;
    shortToLong[code] = longUrl;
    // Return the full tiny URL
    return base + code;
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    // Extract the code from the short URL
    string code = extractCode(shortUrl);
    // Look up the code in the map to get the original long URL
    if (shortToLong.count(code)) {
      return shortToLong[code];
    }
    // If the code is not found, return an empty string (should not happen per
    // problem guarantee)
    return "";
  }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
// @lc code=end
