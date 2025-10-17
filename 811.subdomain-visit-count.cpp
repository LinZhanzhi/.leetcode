/*
 * @lc app=leetcode id=811 lang=cpp
 *
 * [811] Subdomain Visit Count
 */

// @lc code=start

#include <sstream>       // For parsing input strings
#include <string>        // To use std::string for domains
#include <unordered_map> // To use std::unordered_map for counting
#include <vector>        // To use std::vector for input/output

using std::string;
using std::unordered_map;
using std::vector;

/*
 * Brief Digested Understanding:
 * ----
 * The core of this problem is about tallying up how many times each
 * subdomain—at any level—has been visited, given a list of domains with their
 * visit counts. Each full domain implicitly "visits" all its parent subdomains
 * as well. For example, a visit to "a.b.c" is also a visit to "b.c" and "c".
 * The problem wants us to count up all visits for all possible subdomains and
 * return them with their correct counts in any order.
 *
 * High-Level Summary:
 * ----
 * The approach relies on parsing each domain-count string, splitting out the
 * count and the domain, and then for each domain, generating all of its
 * subdomains by splitting on '.' and reconstructing each possible suffix. We
 * use a hash map to keep a running count for each subdomain seen. At the end,
 * we convert our hash map into the required string output. This process stays
 * efficient because string splitting and map access are both fast, and the
 * scale of the problem is small (at most 10000 unique domains). Time
 * Complexity: O(N * L), where N = number of input domains, and L = max
 * length/#parts of a domain string. Space Complexity: O(U), where U = number of
 * unique subdomains.
 */

// Helper function: Parse a count-paired domain into <count, domain>
void parseCountDomain(const string &cpdomain, int &count, string &domain) {
  // Use a stringstream to separate integer and domain part efficiently
  std::istringstream iss(cpdomain);
  iss >> count >> domain;
  // This function extracts the integer into 'count' and the rest as 'domain'
}

// Helper function: For a domain string, return all its subdomains
vector<string> getSubdomains(const string &domain) {
  vector<string> result;
  int n = domain.size();
  result.push_back(domain); // Full domain itself is always a subdomain
  // Traverse and add each suffix subdomain after '.'
  for (int i = 0; i < n; ++i) {
    if (domain[i] == '.') {
      // Add substring from i+1 to end, which is the next subdomain
      result.push_back(domain.substr(i + 1));
    }
  }
  return result;
}

// Main solution class with modular helper function usage
class Solution {
public:
  vector<string> subdomainVisits(vector<string> &cpdomains) {
    unordered_map<string, int>
        counts; // Map to tally each subdomain's total visits

    // Loop through each input string
    for (const string &entry : cpdomains) {
      int count = 0;
      string domain;
      parseCountDomain(entry, count, domain); // Separate into count and domain

      // For every subdomain in this domain, accumulate the visit count
      vector<string> subdomains = getSubdomains(domain);
      for (const string &sub : subdomains) {
        counts[sub] += count; // Add visit count to the subdomain
      }
    }

    // Build the result: convert map to 'count domain' strings in a vector
    vector<string> result;
    for (const auto &kv : counts) {
      // Format: "<count> <domain>"
      result.push_back(std::to_string(kv.second) + " " + kv.first);
    }
    return result;
  }
};
// @lc code=end
