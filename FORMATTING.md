# 🎨 C++ Code Formatting Guide

This repository is configured with **clang-format** for consistent C++ code formatting across all DSA solutions.

## 📋 Table of Contents

- [Quick Start](#quick-start)
- [VS Code Setup](#vs-code-setup)
- [Command Line Usage](#command-line-usage)
- [Formatting Rules](#formatting-rules)
- [CI/CD Integration](#cicd-integration)

## 🚀 Quick Start

### Auto-format in VS Code

- **Format on Save**: ✅ Enabled automatically
- **Format on Type**: ✅ Enabled automatically
- **Format on Paste**: ✅ Enabled automatically

Just open any `.cpp` file in VS Code and start coding - formatting happens automatically!

### Command Line Formatting

```bash
# Format single file
Scripts/format.sh problem.cpp

# Format all C++ files in repository
Scripts/format.sh -a

# Check if files need formatting
Scripts/format.sh -c -a

# Dry run (see what would be formatted)
Scripts/format.sh -d -a
```

## 🛠️ VS Code Setup

### Required Extension

Install the **C/C++** extension by Microsoft:

```
ext install ms-vscode.cpptools
```

### Settings Applied

Our `.vscode/settings.json` includes:

- ✅ **Format on save/type/paste** enabled
- ✅ **clang-format** as default formatter
- ✅ **C++17** standard configured
- ✅ **IntelliSense** optimized for DSA
- ✅ **File associations** for all C++ headers

### Manual Formatting

- **Format Document**: `Shift + Option + F` (macOS) / `Shift + Alt + F` (Windows/Linux)
- **Format Selection**: `Cmd + K, Cmd + F` (macOS) / `Ctrl + K, Ctrl + F` (Windows/Linux)

## 📝 Command Line Usage

### Format Script Options

```bash
Scripts/format.sh [options] [files...]
```

| Option            | Description                       | Example                  |
| ----------------- | --------------------------------- | ------------------------ |
| `-a, --all`       | Format all C++ files              | `./format.sh -a`         |
| `-d, --dry-run`   | Show what would be formatted      | `./format.sh -d -a`      |
| `-c, --check`     | Check formatting (CI-friendly)    | `./format.sh -c -a`      |
| `-r, --recursive` | Format recursively in directories | `./format.sh -r Topics/` |
| `-h, --help`      | Show help message                 | `./format.sh -h`         |

### Common Use Cases

```bash
# Format specific problem
Scripts/format.sh Topics/Arrays/two_sum.cpp

# Format all problems in a topic
Scripts/format.sh Topics/Graphs/*.cpp

# Format entire topic directory
Scripts/format.sh -r Topics/Arrays/

# Check if repository is properly formatted (for CI)
Scripts/format.sh -c -a
```

### Direct clang-format Usage

```bash
# Format single file in-place
clang-format -i problem.cpp

# Preview formatting without changes
clang-format problem.cpp

# Format and output to another file
clang-format problem.cpp > formatted_problem.cpp
```

## 🎯 Formatting Rules

Our `.clang-format` configuration:

### Style Base

- **Base Style**: Google (modified for DSA)
- **C++ Standard**: C++17
- **Line Length**: 100 characters
- **Indentation**: 4 spaces (no tabs)

### Key Formatting Rules

```cpp
// ✅ Correct formatting examples

// Function formatting
int twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (map.find(complement) != map.end()) {
            return {map[complement], i};
        }
        map[nums[i]] = i;
    }
    return {};
}

// Class formatting
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // Implementation
    }

private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // Helper function
    }
};

// Control structures
if (condition) {
    doSomething();
} else {
    doSomethingElse();
}

// Loops
for (int i = 0; i < n; i++) {
    process(i);
}

while (!queue.empty()) {
    auto current = queue.front();
    queue.pop();
}
```

### Include Organization

```cpp
// System headers first
#include <iostream>
#include <vector>
#include <queue>

// Then standard library
#include <algorithm>
#include <unordered_map>

// Custom headers last (if any)
#include "custom_header.h"
```

## 🔧 Customization

### Modify Formatting Rules

Edit `.clang-format` in the repository root:

```yaml
# Example: Change indentation to 2 spaces
IndentWidth: 2
TabWidth: 2

# Example: Change line length to 120
ColumnLimit: 120

# Example: Change brace style
BreakBeforeBraces: Allman
```

### Per-Project VS Code Settings

Modify `.vscode/settings.json`:

```json
{
  "editor.formatOnSave": false, // Disable auto-format
  "C_Cpp.clang_format_style": "LLVM", // Use different style
  "editor.tabSize": 2 // Change tab size
}
```

## 🚦 CI/CD Integration

### GitHub Actions Example

```yaml
name: Format Check
on: [push, pull_request]
jobs:
  format:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v3
      - name: Install clang-format
        run: sudo apt-get install clang-format
      - name: Check formatting
        run: ./Scripts/format.sh -c -a
```

### Pre-commit Hook

```bash
#!/bin/sh
# .git/hooks/pre-commit
./Scripts/format.sh -c -a
if [ $? -ne 0 ]; then
    echo "❌ Code formatting check failed!"
    echo "Run: ./Scripts/format.sh -a"
    exit 1
fi
```

## 🔍 Troubleshooting

### Common Issues

**clang-format not found**

```bash
# macOS
brew install clang-format

# Ubuntu/Debian
sudo apt-get install clang-format

# Arch Linux
sudo pacman -S clang
```

**VS Code not formatting**

1. Install C/C++ extension
2. Check `.vscode/settings.json` exists
3. Verify `.clang-format` file is in project root
4. Restart VS Code

**Different formatting in terminal vs VS Code**

- Ensure both use the same `.clang-format` file
- Check VS Code C++ extension settings
- Verify clang-format version: `clang-format --version`

### Getting Help

```bash
# Show format script help
Scripts/format.sh --help

# Show clang-format options
clang-format --help

# Check current format style
clang-format --dump-config
```

## 📖 Best Practices

### 1. **Format Before Committing**

```bash
# Always format before git commit
Scripts/format.sh -a
git add .
git commit -m "Your message"
```

### 2. **Consistent Style Across Team**

- Never modify `.clang-format` without team discussion
- Use the format check script in CI/CD
- Format entire repository after style changes

### 3. **DSA-Specific Considerations**

- Keep line length reasonable for algorithm readability
- Use consistent indentation for nested loops
- Format comments clearly for problem explanations

---

**🎉 Happy coding with beautiful, consistent formatting!**
