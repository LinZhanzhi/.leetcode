/*
 * @lc app=leetcode id=609 lang=cpp
 *
 * [609] Find Duplicate File in System
 */

// Brief, Digested Understanding:
//
// The problem is about finding groups of files in a simulated file system that
// have exactly the same content. Each input string describes a directory and
// all its files, with each file's content given in parentheses. We need to
// return all groups of file paths where the files have identical content (i.e.,
// duplicates). The main challenge is to efficiently parse the input, extract
// file paths and contents, and group files by their content.

// High-Level Summary:
//
// The solution parses each directory info string, extracting the directory path
// and each file's name and content. It uses a hash map to group file paths by
// their content. After processing all input, it collects all groups where more
// than one file shares the same content (i.e., duplicates). The approach is
// efficient, using a single pass through the input and constant-time hash map
// operations.
// - Time Complexity: O(N * L), where N is the number of input strings and L is
// the average length of each string.
// - Space Complexity: O(T), where T is the total number of files (for storing
// file paths and content mapping).

#include <sstream>       // For std::istringstream to split strings
#include <string>        // For std::string and string operations
#include <unordered_map> // For std::unordered_map to group files by content
#include <vector>        // For std::vector

using std::istringstream;
using std::string;
using std::unordered_map;
using std::vector;

class Solution {
public:
  // Main function to find duplicate files based on their content
  vector<vector<string>> findDuplicate(vector<string> &paths) {
    // This map will group file paths by their content.
    // Key: file content, Value: vector of file paths with that content.
    unordered_map<string, vector<string>> contentToPaths;

    // Process each directory info string in the input
    for (const string &dirInfo : paths) {
      // Parse the directory info string into directory path and file entries
      string directory;
      vector<std::pair<string, string>> files =
          parseDirectoryInfo(dirInfo, directory);

      // For each file, build its full path and group it by its content
      for (const auto &file : files) {
        // file.first is the file name, file.second is the file content
        string fullPath = directory + "/" + file.first;
        contentToPaths[file.second].push_back(fullPath);
      }
    }

    // Collect all groups of file paths that have duplicate content (i.e., more
    // than one file)
    vector<vector<string>> result;
    for (const auto &entry : contentToPaths) {
      // Only consider groups with at least two files (duplicates)
      if (entry.second.size() > 1) {
        result.push_back(entry.second);
      }
    }
    return result;
  }

private:
  // Helper function to parse a directory info string into directory path and
  // file entries Returns a vector of (file name, file content) pairs, and sets
  // the directory path
  vector<std::pair<string, string>> parseDirectoryInfo(const string &dirInfo,
                                                       string &directory) {
    vector<std::pair<string, string>> files; // vector of (file name, file
    // content) pairs
    istringstream iss(dirInfo);
    iss >> directory; // The first token is always the directory path

    string fileEntry;
    // Process each file entry in the directory info string
    while (iss >> fileEntry) {
      // Find the position of '(' which separates file name and content
      size_t leftParen = fileEntry.find('(');
      size_t rightParen = fileEntry.find(')', leftParen);

      // Extract file name (before '(') and content (inside parentheses)
      string fileName = fileEntry.substr(0, leftParen);
      string fileContent =
          fileEntry.substr(leftParen + 1, rightParen - leftParen - 1);

      // Store the (file name, file content) pair
      files.emplace_back(fileName, fileContent);
    }
    return files;
  }
};
// @lc code=end
