#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        string str = ransomNote;
        int pos = 0;
        while (pos < magazine.length())
        {
            size_t found = str.find(magazine.at(pos));
            if (found != string::npos)
            {
                str.erase(str.begin()+found);
            }
            if (str.length() == 0)
            {
                return true;
            }            
            pos++;
        }

        return false;
    }
};

struct obj
{
    string ransomNote;
    string magazine;
    bool expected;
} testcases[3];

void print_result(obj testcase, bool result)
{
    cout << "ransomNote = " << testcase.ransomNote << ", magazine = " << testcase.magazine << endl;
    cout << "Result = " << result << endl;
    cout << "Expected = " << testcase.expected << endl;
    if (result == testcase.expected)
    {
        cout << "=== PASS ===" << endl;
    }
    else
    {
        cout << "!!!! FAIL !!!!" << endl;
    }
    cout << endl;
}

int main()
{
    Solution solution;
    testcases[0] = {"a", "b", false};
    testcases[1] = {"aa", "ab", false};
    testcases[2] = {"aa", "aab", true};

    for (obj testcase: testcases)
    {
        print_result(testcase, solution.canConstruct(testcase.ransomNote, testcase.magazine));
    }
    
    return 0;
}