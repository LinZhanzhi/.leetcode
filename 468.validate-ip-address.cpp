/*
 * @lc app=leetcode id=468 lang=cpp
 *
 * [468] Validate IP Address
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The task is to determine if a given string is a valid IPv4 address, a valid
 * IPv6 address, or neither.
 * - An IPv4 address has four decimal numbers (0-255) separated by dots, with no
 * leading zeros.
 * - An IPv6 address has eight groups of 1-4 hexadecimal digits separated by
 * colons, and allows leading zeros. The code must check the format and value
 * constraints for both types and return the correct label.
 *
 * High-Level Summary:
 * ----
 * The solution splits the input string by '.' or ':' to check if it matches the
 * IPv4 or IPv6 format, respectively. For IPv4, it checks for exactly 4 parts,
 * each a valid decimal number in [0,255] with no leading zeros. For IPv6, it
 * checks for exactly 8 parts, each a valid 1-4 character hexadecimal string. If
 * neither format matches, it returns "Neither". The code is modularized with
 * helper functions for splitting and validating each part. Time Complexity:
 * O(N), where N is the length of the input string (each character is processed
 * a constant number of times). Space Complexity: O(1) extra (ignoring the space
 * for split parts, which is bounded).
 */

#include <cctype> // For std::isdigit, std::isxdigit
#include <string> // For std::string
#include <vector> // For std::vector

using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to determine the type of IP address
  string validIPAddress(string queryIP) {
    // If the string contains '.', try IPv4 validation
    if (queryIP.find('.') != string::npos) {
      return isValidIPv4(queryIP) ? "IPv4" : "Neither";
    }
    // If the string contains ':', try IPv6 validation
    else if (queryIP.find(':') != string::npos) {
      return isValidIPv6(queryIP) ? "IPv6" : "Neither";
    }
    // If neither, it's not a valid IP address
    else {
      return "Neither";
    }
  }

private:
  // Helper function to split a string by a delimiter
  vector<string> split(const string &s, char delimiter) {
    vector<string> parts;
    string part;
    for (size_t i = 0; i < s.size(); ++i) {
      if (s[i] == delimiter) {
        parts.push_back(part);
        part.clear();
      } else {
        part += s[i];
      }
    }
    parts.push_back(part); // Add the last part
    return parts;
  }

  // Helper function to check if a string is a valid IPv4 address
  bool isValidIPv4(const string &ip) {
    vector<string> parts = split(ip, '.');
    // IPv4 must have exactly 4 parts
    if (parts.size() != 4)
      return false;
    for (const string &part : parts) {
      // Each part must be non-empty and at most 3 digits
      if (part.empty() || part.size() > 3)
        return false;
      // No leading zeros unless the part is exactly "0"
      if (part.size() > 1 && part[0] == '0')
        return false;
      // Each character must be a digit
      for (char c : part) {
        if (!std::isdigit(c))
          return false;
      }
      // Convert to integer and check range [0, 255]
      int num = 0;
      try {
        num = std::stoi(part);
      } catch (...) {
        return false; // Not a valid integer
      }
      if (num < 0 || num > 255)
        return false;
    }
    // Check for trailing or leading dots (e.g., "1.1.1.1.")
    if (ip.front() == '.' || ip.back() == '.')
      return false;
    return true;
  }

  // Helper function to check if a string is a valid IPv6 address
  bool isValidIPv6(const string &ip) {
    vector<string> parts = split(ip, ':');
    // IPv6 must have exactly 8 parts
    if (parts.size() != 8)
      return false;
    for (const string &part : parts) {
      // Each part must be non-empty and at most 4 characters
      if (part.empty() || part.size() > 4)
        return false;
      // Each character must be a valid hexadecimal digit
      for (char c : part) {
        if (!std::isxdigit(c))
          return false;
      }
    }
    // Check for trailing or leading colons (e.g., "2001:db8::1")
    if (ip.front() == ':' || ip.back() == ':')
      return false;
    return true;
  }
};
// @lc code=end
