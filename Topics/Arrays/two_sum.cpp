/*
Problem: Two Sum
Platform: LeetCode
Difficulty: Easy
Link: https://leetcode.com/problems/two-sum/
Company: Google, Amazon, Microsoft, Meta, Apple
Topics: Array, Hash Table

Problem Description:
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Time Complexity: O(n)
Space Complexity: O(n)

Approach:
1. Use hash map to store complement of each element
2. For each element, check if its complement exists in hash map
3. If found, return indices; otherwise, add current element to hash map
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap; // value -> index
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Check if complement exists in map
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            
            // Add current number to map
            numMap[nums[i]] = i;
        }
        
        return {}; // No solution found
    }
};

// Helper functions
void printArray(vector<int>& arr) {
    cout << "[";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

// Test cases and driver code
int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> test1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = solution.twoSum(test1, target1);
    cout << "Test 1 - Input: ";
    printArray(test1);
    cout << "Target: " << target1 << ", Output: ";
    printArray(result1);
    
    // Test Case 2
    vector<int> test2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = solution.twoSum(test2, target2);
    cout << "Test 2 - Input: ";
    printArray(test2);
    cout << "Target: " << target2 << ", Output: ";
    printArray(result2);
    
    // Test Case 3
    vector<int> test3 = {3, 3};
    int target3 = 6;
    vector<int> result3 = solution.twoSum(test3, target3);
    cout << "Test 3 - Input: ";
    printArray(test3);
    cout << "Target: " << target3 << ", Output: ";
    printArray(result3);
    
    return 0;
}

/*
Notes:
- Alternative approach: Brute force with O(n²) time complexity
- This hash map approach is optimal for this problem
- Consider edge cases: empty array, no solution, duplicate numbers
*/ 