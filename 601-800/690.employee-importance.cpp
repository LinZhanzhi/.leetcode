#include <vector>        // For std::vector
#include <unordered_map>  // For std::unordered_map
using namespace std;      // To avoid prefixing std::

/*
 * @lc app=leetcode id=690 lang=cpp
 *
 * [690] Employee Importance
 */

// @lc code=start
// Definition for Employee.
// class Employee {
// public:
//     int id;
//     int importance;
//     vector<int> subordinates;
// };

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        // Build a map from employee id to Employee* for fast lookup
        unordered_map<int, Employee*> emp_map;
        for (Employee* emp : employees) {
            emp_map[emp->id] = emp;
        }
        // Use a helper function to recursively sum importance
        return dfsImportance(id, emp_map);
    }
private:
    // Helper function to recursively sum importance for an employee and all subordinates
    int dfsImportance(int id, unordered_map<int, Employee*>& emp_map) {
        // Get the Employee object for this id
        Employee* emp = emp_map[id];
        int total = emp->importance; // Start with this employee's importance
        // Recursively add the importance of all direct subordinates
        for (int sub_id : emp->subordinates) {
            total += dfsImportance(sub_id, emp_map);
        }
        return total;
    }
};
// @lc code=end

