#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

class Solution {
    public:

    // function to return Array of Strings from requiredParts string
    vector<string> getRequiredParts(string requiredParts) {
        vector<string> result;
        stringstream ss(requiredParts);
        string part;
        while (getline(ss, part, ',')) {
            result.push_back(part);
        }   
        return result;
    }

    vector<string> robotAssembly(vector<string>& allParts, string& requiredParts) {
       // from allParts create a map of Robot and its available parts
       unordered_map<string, unordered_set<string>> robotParts;
       for (string part : allParts) {
        string robot = part.substr(0, part.find("_"));
        string partName = part.substr(part.find("_") + 1);
        robotParts[robot].insert(partName);
       }

       // for each required part, check if the robot has all the parts
       vector<string> requiredPartsArray = getRequiredParts(requiredParts);
       vector<string> resultRobots;
       // for each robot check if it has all the parts
       for(auto &[robot, availableParts] : robotParts) {
        // check if the robot has all the parts
        bool hasAllParts = true;
        for(auto requiredPart : requiredPartsArray) {
            if(availableParts.find(requiredPart) == availableParts.end()) {
                hasAllParts = false;
                break;
            }
        }
        if(hasAllParts)
            resultRobots.push_back(robot);
       }
       return resultRobots;
    }
}; // ✅ Fixed: Added semicolon

// Helper function to print vector
void printResult(const vector<string>& result) {
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "\"" << result[i] << "\"";
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    
    // Sample input data
    vector<string> all_parts = { // ✅ Fixed: Use braces instead of brackets
        "Rosie_claw", "Rosie_sensors", "Dustie_case", "Optimus_sensors", 
        "Rust_sensors", "Rosie_case", "Rust_case", "Optimus_speaker", 
        "Rosie_wheels", "Rosie_speaker", "Dustie_case", "Dustie_arms", 
        "Rust_claw", "Dustie_case", "Dustie_speaker", "Optimus_case", 
        "Optimus_wheels", "Rust_legs", "Optimus_sensors" 
    };
    
    // Test cases
    string required_parts_1 = "sensors,case,speaker,wheels";
    string required_parts_2 = "sensors,case,speaker,wheels,claw";
    string required_parts_3 = "sensors,case,screws";
    
    // Test case 1
    cout << "Test case 1:" << endl;
    cout << "Required parts: " << required_parts_1 << endl;
    vector<string> result1 = solution.robotAssembly(all_parts, required_parts_1);
    cout << "Result: ";
    printResult(result1);
    cout << "Expected: [\"Optimus\", \"Rosie\"]" << endl << endl;
    
    // Test case 2
    cout << "Test case 2:" << endl;
    cout << "Required parts: " << required_parts_2 << endl;
    vector<string> result2 = solution.robotAssembly(all_parts, required_parts_2);
    cout << "Result: ";
    printResult(result2);
    cout << "Expected: [\"Rosie\"]" << endl << endl;
    
    // Test case 3
    cout << "Test case 3:" << endl;
    cout << "Required parts: " << required_parts_3 << endl;
    vector<string> result3 = solution.robotAssembly(all_parts, required_parts_3);
    cout << "Result: ";
    printResult(result3);
    cout << "Expected: []" << endl << endl;
    
    return 0;
}