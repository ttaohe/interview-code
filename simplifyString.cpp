#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

string Simplify(string path) {
    vector<string> parts;
    stringstream ss(path);
    string part;
    
    // Split by '/'
    while (getline(ss, part, '/')) {
        if (part.empty() || part == ".") {
            continue;
        } else if (part == "..") {
            if (!parts.empty()) {
                parts.pop_back();
            }
        } else {
            parts.push_back(part);
        }
    }
    
    // Build result
    string result;
    for (const auto& p : parts) {
        result += "/" + p;
    }
    
    return result.empty() ? "/" : result;
}

int main() {
    vector<pair<string, string>> test_cases = {
        {"/home/root/Documents/../Pictures/./", "/home/root/Pictures"},
        {"/home/root/Documents/../ttt/./Pictures/./", "/home/root/ttt/Pictures"},
        {"/home/root/Documents/.../ttt/./Pictures/./", "/home/root/Documents/.../ttt/Pictures"},
        {"/../", "/"},
        {"/.../a/../b/c/../d/./", "/.../b/d"},
        {"/a/b/c/../../d/./", "/a/d"},
        {"/a/../../b/c/../../d/./", "/d"}
    };
    
    for (const auto& test_case : test_cases) {
        string result = Simplify(test_case.first);
        cout << "Input: " << test_case.first << endl;
        cout << "Expected: " << test_case.second << endl;
        cout << "Actual: " << result << endl;
        cout << (result == test_case.second ? "PASS" : "FAIL") << endl << endl;
    }
    
    return 0;
}