/*
 * @lc app=leetcode id=721 lang=cpp
 *
 * [721] Accounts Merge
 */

// Brief Digested Understanding:
// ----
// We are given a list of accounts, each consisting of a name and a list of
// emails. Some accounts may refer to the same person if they share at least one
// common email address, regardless of the account name. Our task is to merge
// accounts belonging to the same person (i.e., sharing emails) into a single
// account with the person’s name and a list of all unique emails (sorted).
// Accounts with no email overlap remain distinct, even if the names match.
// Return the merged accounts in any order, with each account's emails sorted
// alphabetically.

// High-Level Summary:
// ----
// The main algorithmic challenge is efficiently finding and merging accounts
// that are connected via shared emails. This is a classic "connected
// components" problem and can be solved using a Disjoint Set Union (Union-Find)
// structure. We treat each unique email as a node and use Union-Find to connect
// emails that belong to the same user (by linking emails appearing within the
// same account). We then group emails by their parent/root, and for each group,
// associate the account’s name (using an email->name map). The process includes
// sorting the emails in each group, assembling them into the required output
// format, and returning the answers.
//
// Time Complexity: O(NK*α(NK) + NKlog(NK))
//   - where N is the number of accounts, K is the max number of emails per
//   account, and α is the inverse Ackermann function (from Union-Find). The
//   sorting step for each group costs NKlog(NK) in the worst case.
// Space Complexity: O(NK) for mapping and storing all emails and temporary data
// structures.

// Solution implementation starts here.

#include <algorithm> // for std::sort
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution {
private:
  // Disjoint Set Union (Union-Find) data structure:
  // parent maps each email to its "root" email in the same connected component.
  unordered_map<string, string> parent;

  // Helper function: Finds the 'root' parent of an email with path compression.
  string find(const string &email) {
    // If the email is not its own parent, recursively find the root and update
    // parent.
    if (parent[email] != email)
      parent[email] = find(parent[email]);
    return parent[email];
  }

  // Helper function: Unites two emails (i.e., connects components).
  void unite(const string &email1, const string &email2) {
    // Find roots for both emails
    string root1 = find(email1);
    string root2 = find(email2);
    if (root1 != root2) {
      // For efficiency, attach one tree's root to the other (arbitrary)
      parent[root2] = root1;
    }
  }

public:
  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
    unordered_map<string, string>
        emailToName; // Map each email to the user name

    // Step 1: Build Union-Find structure for emails and record email-to-name
    // mappings.
    for (const auto &account : accounts) {
      const string &name = account[0];
      for (size_t i = 1; i < account.size(); ++i) {
        const string &email = account[i];
        // Initialize parent mapping if email is new (so it's its own parent
        // initially)
        if (!parent.count(email)) {
          parent[email] = email;
        }
        emailToName[email] = name; // Associate email with name
        // Union current email with the first email of the account (to connect
        // all in account)
        if (i > 1) {
          unite(account[1], email); // Connect all to the first email in account
        }
      }
    }

    // Step 2: Group emails by their representative parent
    unordered_map<string, unordered_set<string>>
        groups; // parent_email -> set of emails

    for (const auto &pair : parent) {
      const string &email = pair.first;
      // Find the group's "leader" (root parent) for each email
      string groupParent = find(email);
      groups[groupParent].insert(email);
    }

    // Step 3: Build output - for each group, get name and sorted emails
    vector<vector<string>> mergedAccounts;
    for (const auto &group : groups) {
      // Gather all emails for the group and sort
      vector<string> emails(group.second.begin(), group.second.end());
      std::sort(emails.begin(), emails.end());
      // Insert name at the beginning using any email from the group
      emails.insert(emails.begin(), emailToName[group.first]);
      mergedAccounts.push_back(std::move(emails));
    }
    return mergedAccounts;
  }
};
// @lc code=end
