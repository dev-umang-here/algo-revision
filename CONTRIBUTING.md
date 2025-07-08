# Contributing to Algo-Revision

Thank you for your interest in contributing to this DSA repository! 🎉

## 📋 Table of Contents
- [Getting Started](#getting-started)
- [How to Contribute](#how-to-contribute)
- [Code Standards](#code-standards)
- [Folder Structure](#folder-structure)
- [Submission Guidelines](#submission-guidelines)

## 🚀 Getting Started

1. **Fork the Repository**
   ```bash
   git fork https://github.com/your-username/Algo-Revision.git
   ```

2. **Clone Your Fork**
   ```bash
   git clone https://github.com/your-username/Algo-Revision.git
   cd Algo-Revision
   ```

3. **Create a Branch**
   ```bash
   git checkout -b feature/add-problem-name
   ```

## 🤝 How to Contribute

### Adding New Problems

1. **Choose the Right Location**
   - For topic-based: `Topics/[TopicName]/problem_name.cpp`
   - For company-based: `Companies/[CompanyName]/problem_name.cpp`

2. **Use the Template**
   - Copy from `Templates/solution_template.cpp`
   - Fill in all required information

3. **Update README Files**
   - Add entry to the respective README.md
   - Update statistics and problem count

### Creating New Topics/Companies

1. **Create Directory Structure**
   ```bash
   mkdir Topics/NewTopic
   # or
   mkdir Companies/NewCompany
   ```

2. **Add README**
   - Copy `Templates/README.md`
   - Customize for the new topic/company

## 📝 Code Standards

### File Naming
- Use snake_case: `two_sum.cpp`, `longest_substring.cpp`
- Be descriptive and concise
- For multiple approaches: `problem_name_approach2.cpp`

### Code Structure
```cpp
/*
[Required Header with all metadata]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Main solution with meaningful function name
};

// Helper functions (if needed)

// Test cases in main()
int main() {
    // Comprehensive test cases
    return 0;
}

/*
[Optional notes section]
*/
```

### Documentation Requirements
- **Problem description**: Clear and concise
- **Examples**: At least 1-2 examples
- **Complexity analysis**: Time and space complexity
- **Approach explanation**: Step-by-step methodology
- **Test cases**: Multiple edge cases in main()

### Code Quality Guidelines
1. **Meaningful variable names**
   ```cpp
   // Good
   int maxProfit = 0;
   vector<int> leftMax(n);
   
   // Bad
   int mp = 0;
   vector<int> lm(n);
   ```

2. **Clear comments**
   ```cpp
   // Check if complement exists in hash map
   if (numMap.find(complement) != numMap.end()) {
       return {numMap[complement], i};
   }
   ```

3. **Consistent formatting**
   - 4 spaces for indentation
   - Spaces around operators
   - Consistent brace placement

## 📁 Folder Structure

```
Algo-Revision/
├── Topics/
│   ├── Arrays/
│   │   ├── README.md
│   │   └── problem_solutions.cpp
│   └── [Other Topics]/
├── Companies/
│   ├── Google/
│   │   ├── README.md
│   │   └── problem_solutions.cpp
│   └── [Other Companies]/
├── Templates/
└── Scripts/
```

## 📤 Submission Guidelines

### Before Submitting

1. **Test Your Solution**
   ```bash
   # Compile and test
   ./Scripts/compile.sh your_solution.cpp -r
   ```

2. **Verify Code Style**
   - Check indentation and formatting
   - Ensure all comments are clear
   - Verify template compliance

3. **Update Documentation**
   - Add problem to relevant README
   - Update statistics
   - Check all links work

### Pull Request Process

1. **Commit Messages**
   ```
   Add: Two Sum solution for Arrays topic
   
   - Implemented O(n) hash map approach
   - Added comprehensive test cases
   - Updated Arrays README with problem entry
   ```

2. **PR Title Format**
   ```
   [TOPIC/COMPANY] Add Problem Name Solution
   ```

3. **PR Description Template**
   ```markdown
   ## Problem Details
   - **Platform**: LeetCode/GeeksforGeeks/etc.
   - **Difficulty**: Easy/Medium/Hard
   - **Topic**: Array/String/Tree/etc.
   
   ## Solution Summary
   - **Approach**: Brief description
   - **Time Complexity**: O(...)
   - **Space Complexity**: O(...)
   
   ## Checklist
   - [ ] Solution follows template
   - [ ] Comprehensive test cases included
   - [ ] README updated with problem entry
   - [ ] Code compiles without errors
   - [ ] All comments are clear and helpful
   ```

### Review Process

1. **Automated Checks**
   - Code compilation
   - Template compliance
   - File naming conventions

2. **Manual Review**
   - Code quality and clarity
   - Solution correctness
   - Documentation completeness

## 🔍 Quality Checklist

Before submitting, ensure:

- [ ] **Header complete**: All metadata filled correctly
- [ ] **Solution tested**: Multiple test cases pass
- [ ] **Complexity analyzed**: Time/space complexity documented
- [ ] **Code formatted**: Consistent style throughout
- [ ] **Comments helpful**: Clear explanations for complex logic
- [ ] **README updated**: Problem added to relevant README
- [ ] **No compilation errors**: Code compiles cleanly
- [ ] **Edge cases considered**: Boundary conditions tested

## 🆘 Getting Help

- **Questions**: Open an issue with "Question" label
- **Bugs**: Report bugs with "Bug" label
- **Feature requests**: Suggest improvements with "Enhancement" label

## 🎯 Best Practices

1. **Start small**: Begin with Easy problems
2. **Be thorough**: Include edge cases and explanations
3. **Stay organized**: Follow the established structure
4. **Help others**: Review other contributions
5. **Keep learning**: Explore different approaches

---

**Happy Contributing! 🚀** 