/*
Problem: Word Ladder
Platform: LeetCode
Difficulty: Hard
Link: https://leetcode.com/problems/word-ladder/
Company: Google, Amazon, Microsoft, Meta, Apple, LinkedIn
Topics: Graph, BFS, String Manipulation, Shortest Path

Problem Description:
A transformation sequence from word beginWord to word endWord using a dictionary wordList is
a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
- Every adjacent pair of words differs by exactly one letter
- Every si for 1 <= i <= k is in wordList
- sk == endWord
Return the length of the shortest transformation sequence from beginWord to endWord.

Example:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: "hit" -> "hot" -> "dot" -> "dog" -> "cog" = 5 words

Time Complexity: O(M² × N) where M = word length, N = total words
Space Complexity: O(M × N) for the BFS queue and visited set

Approach:
1. Use BFS to find shortest path in unweighted graph
2. Each word is a node, edges exist between words differing by 1 character
3. Use set for O(1) word lookup and visited tracking
4. Generate neighbors by changing each character position
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // TODO: Implement BFS approach - Standard Solution
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Your implementation here
        return 0;
    }
    
    // TODO: Implement Bidirectional BFS - Optimized Approach
    int ladderLengthBidirectional(string beginWord, string endWord, vector<string>& wordList) {
        // Your implementation here
        return 0;
    }
    
    // TODO: Bonus - Word Ladder II - Return all shortest paths
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // Your implementation here
        return {};
    }
};

// Helper functions
void printWordList(const vector<string>& wordList) {
    cout << "Word List: [";
    for (size_t i = 0; i < wordList.size(); i++) {
        cout << "\"" << wordList[i] << "\"";
        if (i < wordList.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

void printPaths(const vector<vector<string>>& paths) {
    cout << "All shortest paths:" << endl;
    for (const auto& path : paths) {
        cout << "  ";
        for (size_t i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) cout << " -> ";
        }
        cout << endl;
    }
}

// Test cases and driver code
int main() {
    Solution solution;
    
    // Test Case 1: Standard case
    cout << "=== Test Case 1 ===" << endl;
    string beginWord1 = "hit";
    string endWord1 = "cog";
    vector<string> wordList1 = {"hot", "dot", "dog", "lot", "log", "cog"};
    
    cout << "Begin: \"" << beginWord1 << "\", End: \"" << endWord1 << "\"" << endl;
    printWordList(wordList1);
    
    int result1 = solution.ladderLength(beginWord1, endWord1, wordList1);
    cout << "Shortest ladder length: " << result1 << endl;
    cout << "Expected: 5" << endl << endl;
    
    // Test Case 2: No transformation possible
    cout << "=== Test Case 2 ===" << endl;
    string beginWord2 = "hit";
    string endWord2 = "cog";
    vector<string> wordList2 = {"hot", "dot", "dog", "lot", "log"};
    
    cout << "Begin: \"" << beginWord2 << "\", End: \"" << endWord2 << "\"" << endl;
    printWordList(wordList2);
    
    int result2 = solution.ladderLength(beginWord2, endWord2, wordList2);
    cout << "Shortest ladder length: " << result2 << endl;
    cout << "Expected: 0 (endWord not in wordList)" << endl << endl;
    
    // Test Case 3: Direct transformation
    cout << "=== Test Case 3 ===" << endl;
    string beginWord3 = "cat";
    string endWord3 = "bat";
    vector<string> wordList3 = {"bat"};
    
    cout << "Begin: \"" << beginWord3 << "\", End: \"" << endWord3 << "\"" << endl;
    printWordList(wordList3);
    
    int result3 = solution.ladderLength(beginWord3, endWord3, wordList3);
    cout << "Shortest ladder length: " << result3 << endl;
    cout << "Expected: 2" << endl << endl;
    
    return 0;
}

/*
Implementation Notes:
- BFS guarantees shortest path in unweighted graphs
- Bidirectional BFS can be 2x faster by expanding from both ends
- Key optimization: Use sets for O(1) lookup instead of vector searching
- Generate neighbors by trying all 26 characters at each position
- Common follow-ups: Word Ladder II (all paths), Word Break, Edit Distance
- Real-world applications: Spell checkers, DNA sequence analysis
- Time complexity can be improved with preprocessing (building adjacency list)
*/ 