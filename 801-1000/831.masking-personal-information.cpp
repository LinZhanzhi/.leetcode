/*
 * @lc app=leetcode id=831 lang=cpp
 *
 * [831] Masking Personal Information
 */

// Brief Digested Understanding:
// ----
// This problem asks us to mask personal information that could be either an
// email address or a phone number. For emails, we must mask the name portion
// (between the start and the '@') by keeping the first and last character and
// replacing everything else in the name with 5 asterisks, also lowercasing the
// entire email address. For phone numbers, we must keep only the last 4 digits
// visible and mask the rest in a standard format: '***-***-XXXX', with possible
// country code masking as "+**-***-***-XXXX" (1 up to 3 digits in the country
// code). Non-digit separators should be removed before processing a phone
// number.

// High-Level Summary:
// ----
// The main idea is to first determine if the input is an email (contains '@')
// or a phone number. For emails, use string manipulation to lower-case and
// properly mask the name portion, always using five asterisks regardless of
// name length. For phone numbers, filter out all non-digit characters, then
// format based on the length of the resulting digit string: the last 10 digits
// are always the local part, and any extra digits in front are the country
// code. We use string operations to assemble the final result. The operations
// used are all O(N), with N being the length of the input string. Space
// complexity is O(N) for the strings we construct. Helper functions are used
// for email masking, digit extraction, and phone masking.

// @lc code=start
#include <cctype>
#include <string>

using std::string; // Bring std::string into scope for clarity.

class Solution {
public:
  // Main function: decides whether to mask as email or phone,
  // then dispatches to the appropriate helper.
  string maskPII(string s) {
    if (isEmail(s)) {
      // If the input is an email, mask as email.
      return maskEmail(s);
    } else {
      // Otherwise, assume it is a phone number.
      return maskPhone(s);
    }
  }

private:
  // Helper function to check if input is an email address
  bool isEmail(const string &s) {
    // Email must contain a single '@' symbol per the constraints.
    return s.find('@') != string::npos;
  }

  // Helper function to mask email addresses according to the rules.
  string maskEmail(const string &s) {
    // Find the position of '@' in the string.
    size_t at_pos = s.find('@');
    // Extract the name part (before '@') and the domain part (after '@').
    string name = s.substr(0, at_pos);
    string domain = s.substr(at_pos + 1);

    // Convert the name and domain to lowercase.
    toLower(name);
    toLower(domain);

    // Compose the masked name: always first letter, five asterisks,
    // then last letter — even if name is only two characters long.
    string masked_name;
    masked_name += name[0];                 // First letter
    masked_name += "*****";                 // Five asterisks for middle
    masked_name += name[name.length() - 1]; // Last letter

    // Combine the masked name and lower-cased domain with '@'.
    return masked_name + "@" + domain;
  }

  // Helper function to convert string to lowercase in-place.
  void toLower(string &s) {
    for (char &c : s) {
      c = std::tolower(c);
    }
  }

  // Helper function to mask phone numbers.
  string maskPhone(const string &s) {
    // Extract only the digits from the input.
    string digits = extractDigits(s);

    // The last 10 digits are the 'local' part of the number.
    string local = digits.substr(digits.length() - 10);

    // The digits before the last 10 (0 to 3) form the country code.
    int country_code_len = digits.length() - 10;
    string result;

    // If there is a country code, start with '+' and appropriate stars and a
    // dash.
    if (country_code_len > 0) {
      result += '+';
      // Add one '*' for each extra country code digit.
      result += string(country_code_len, '*');
      result += '-';
    }

    // Standard US format follows, regardless of country code.
    // Add the masked portions, then the actual last 4 digits.
    result += "***-***-";
    result += local.substr(6, 4); // Last 4 digits (positions 6 to 9 of local)
    return result;
  }

  // Helper function to remove all non-digit characters and return string of
  // digits.
  string extractDigits(const string &s) {
    string digits;
    for (char c : s) {
      if (std::isdigit(c)) {
        digits += c;
      }
    }
    return digits;
  }
};
// @lc code=end
