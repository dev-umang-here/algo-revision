#!/bin/bash

# C++ Code Formatter Script using clang-format
# Usage: ./format.sh [options] [files...]

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Function to display usage
show_usage() {
    echo -e "${BLUE}C++ Code Formatter${NC}"
    echo "Usage: $0 [options] [files...]"
    echo ""
    echo "Options:"
    echo "  -a, --all         Format all C++ files in repository"
    echo "  -d, --dry-run     Show what would be formatted (no changes)"
    echo "  -c, --check       Check if files are properly formatted"
    echo "  -r, --recursive   Format files recursively in directories"
    echo "  -h, --help        Show this help message"
    echo ""
    echo "Examples:"
    echo "  $0 file.cpp                    # Format single file"
    echo "  $0 -a                          # Format all C++ files"
    echo "  $0 -d -a                       # Dry run for all files"
    echo "  $0 -c Topics/Arrays/*.cpp      # Check specific files"
    echo "  $0 -r Topics/                  # Format all files in Topics/"
}

# Function to format a single file
format_file() {
    local file=$1
    local dry_run=$2
    local check_only=$3
    
    if [ ! -f "$file" ]; then
        echo -e "${RED}Error: File '$file' not found!${NC}"
        return 1
    fi
    
    # Check if file needs formatting
    if clang-format "$file" | diff -q "$file" - > /dev/null 2>&1; then
        if [ "$check_only" = true ]; then
            echo -e "${GREEN}✓ $file${NC} - properly formatted"
        fi
        return 0
    fi
    
    if [ "$check_only" = true ]; then
        echo -e "${RED}✗ $file${NC} - needs formatting"
        return 1
    fi
    
    if [ "$dry_run" = true ]; then
        echo -e "${YELLOW}Would format: $file${NC}"
        return 0
    fi
    
    # Format the file
    if clang-format -i "$file"; then
        echo -e "${GREEN}✓ Formatted: $file${NC}"
        return 0
    else
        echo -e "${RED}✗ Failed to format: $file${NC}"
        return 1
    fi
}

# Function to find C++ files
find_cpp_files() {
    local directory=${1:-.}
    local recursive=$2
    local print_zero=${3:-false}
    
    local print_option=""
    if [ "$print_zero" = "-print0" ]; then
        print_option="-print0"
    fi
    
    if [ "$recursive" = true ]; then
        find "$directory" -type f \( -name "*.cpp" -o -name "*.h" -o -name "*.hpp" \) $print_option 2>/dev/null
    else
        find "$directory" -maxdepth 1 -type f \( -name "*.cpp" -o -name "*.h" -o -name "*.hpp" \) $print_option 2>/dev/null
    fi
}

# Main script logic
dry_run=false
check_only=false
format_all=false
recursive=false
files=()

# Parse command line arguments
while [[ $# -gt 0 ]]; do
    case $1 in
        -a|--all)
            format_all=true
            shift
            ;;
        -d|--dry-run)
            dry_run=true
            shift
            ;;
        -c|--check)
            check_only=true
            shift
            ;;
        -r|--recursive)
            recursive=true
            shift
            ;;
        -h|--help)
            show_usage
            exit 0
            ;;
        -*)
            echo -e "${RED}Unknown option: $1${NC}"
            show_usage
            exit 1
            ;;
        *)
            files+=("$1")
            shift
            ;;
    esac
done

# Check if clang-format is available
if ! command -v clang-format &> /dev/null; then
    echo -e "${RED}Error: clang-format not found!${NC}"
    echo "Install with: brew install clang-format"
    exit 1
fi

# Check if .clang-format exists
if [ ! -f ".clang-format" ]; then
    echo -e "${YELLOW}Warning: .clang-format file not found in current directory${NC}"
    echo "Using default formatting style"
fi

formatted_count=0
failed_count=0

# Format all files if --all option is used
if [ "$format_all" = true ]; then
    echo -e "${BLUE}Finding C++ files...${NC}"
    cpp_files=()
    while IFS= read -r -d '' file; do
        cpp_files+=("$file")
    done < <(find . -type f \( -name "*.cpp" -o -name "*.h" -o -name "*.hpp" \) -print0)
    
    if [ ${#cpp_files[@]} -eq 0 ]; then
        echo -e "${YELLOW}No C++ files found${NC}"
        exit 0
    fi
    
    echo -e "${BLUE}Found ${#cpp_files[@]} C++ files${NC}"
    echo ""
    
    for file in "${cpp_files[@]}"; do
        if format_file "$file" "$dry_run" "$check_only"; then
            ((formatted_count++))
        else
            ((failed_count++))
        fi
    done
    
elif [ ${#files[@]} -gt 0 ]; then
    # Format specified files
    for file in "${files[@]}"; do
        if [ -d "$file" ]; then
            # Handle directory
            echo -e "${BLUE}Processing directory: $file${NC}"
            dir_files=()
            while IFS= read -r -d '' dir_file; do
                dir_files+=("$dir_file")
            done < <(find_cpp_files "$file" "$recursive" -print0)
            
            for dir_file in "${dir_files[@]}"; do
                if format_file "$dir_file" "$dry_run" "$check_only"; then
                    ((formatted_count++))
                else
                    ((failed_count++))
                fi
            done
        else
            # Handle single file
            if format_file "$file" "$dry_run" "$check_only"; then
                ((formatted_count++))
            else
                ((failed_count++))
            fi
        fi
    done
else
    show_usage
    exit 1
fi

# Summary
echo ""
if [ "$dry_run" = true ]; then
    echo -e "${BLUE}Dry run complete:${NC}"
    echo -e "  Files that would be formatted: $formatted_count"
    echo -e "  Files with errors: $failed_count"
elif [ "$check_only" = true ]; then
    echo -e "${BLUE}Format check complete:${NC}"
    echo -e "  Properly formatted files: $formatted_count"
    echo -e "  Files needing formatting: $failed_count"
    [ $failed_count -eq 0 ] && exit 0 || exit 1
else
    echo -e "${BLUE}Formatting complete:${NC}"
    echo -e "  Successfully formatted: $formatted_count"
    echo -e "  Failed: $failed_count"
fi 