#!/bin/bash

# C++ Compilation Script for DSA Solutions
# Usage: ./compile.sh <filename.cpp> [options]

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Default compiler and flags
COMPILER="g++"
STD_VERSION="-std=c++17"
WARNING_FLAGS="-Wall -Wextra"
DEBUG_FLAGS="-g"
OPTIMIZATION_FLAGS="-O2"

# Function to display usage
show_usage() {
    echo -e "${BLUE}C++ DSA Solution Compiler${NC}"
    echo "Usage: $0 <filename.cpp> [options]"
    echo ""
    echo "Options:"
    echo "  -d, --debug     Compile with debug flags"
    echo "  -o, --optimize  Compile with optimization flags"
    echo "  -r, --run       Compile and run immediately"
    echo "  -c, --clean     Remove compiled executables"
    echo "  -h, --help      Show this help message"
    echo ""
    echo "Examples:"
    echo "  $0 two_sum.cpp              # Basic compilation"
    echo "  $0 two_sum.cpp -o           # Optimized compilation"
    echo "  $0 two_sum.cpp -d -r        # Debug compile and run"
}

# Function to compile C++ file
compile_cpp() {
    local filename=$1
    local flags=$2
    
    if [ ! -f "$filename" ]; then
        echo -e "${RED}Error: File '$filename' not found!${NC}"
        exit 1
    fi
    
    # Extract filename without extension
    local basename=$(basename "$filename" .cpp)
    local output_file="${basename}"
    
    echo -e "${BLUE}Compiling: $filename${NC}"
    echo -e "${YELLOW}Command: $COMPILER $STD_VERSION $WARNING_FLAGS $flags $filename -o $output_file${NC}"
    
    if $COMPILER $STD_VERSION $WARNING_FLAGS $flags "$filename" -o "$output_file"; then
        echo -e "${GREEN}✓ Compilation successful!${NC}"
        echo -e "${GREEN}Executable: $output_file${NC}"
        return 0
    else
        echo -e "${RED}✗ Compilation failed!${NC}"
        return 1
    fi
}

# Function to run executable
run_executable() {
    local filename=$1
    local basename=$(basename "$filename" .cpp)
    
    if [ -f "$basename" ]; then
        echo -e "${BLUE}Running: $basename${NC}"
        echo "----------------------------------------"
        ./"$basename"
        echo "----------------------------------------"
    else
        echo -e "${RED}Error: Executable '$basename' not found!${NC}"
    fi
}

# Function to clean executables
clean_executables() {
    echo -e "${YELLOW}Cleaning compiled executables...${NC}"
    find . -type f -executable -not -name "*.sh" -not -name "*.py" -delete
    echo -e "${GREEN}✓ Cleanup complete!${NC}"
}

# Main script logic
if [ $# -eq 0 ]; then
    show_usage
    exit 1
fi

filename=""
compile_flags=""
should_run=false
should_clean=false

# Parse command line arguments
while [[ $# -gt 0 ]]; do
    case $1 in
        -d|--debug)
            compile_flags="$compile_flags $DEBUG_FLAGS"
            shift
            ;;
        -o|--optimize)
            compile_flags="$compile_flags $OPTIMIZATION_FLAGS"
            shift
            ;;
        -r|--run)
            should_run=true
            shift
            ;;
        -c|--clean)
            should_clean=true
            shift
            ;;
        -h|--help)
            show_usage
            exit 0
            ;;
        *.cpp)
            filename=$1
            shift
            ;;
        *)
            echo -e "${RED}Unknown option: $1${NC}"
            show_usage
            exit 1
            ;;
    esac
done

# Execute requested actions
if [ "$should_clean" = true ]; then
    clean_executables
    exit 0
fi

if [ -z "$filename" ]; then
    echo -e "${RED}Error: No C++ file specified!${NC}"
    show_usage
    exit 1
fi

# Compile the file
if compile_cpp "$filename" "$compile_flags"; then
    if [ "$should_run" = true ]; then
        echo ""
        run_executable "$filename"
    fi
else
    exit 1
fi 