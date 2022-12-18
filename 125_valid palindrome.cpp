#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length() - 1;
        
        while (start < end)
        {
            while (start < end && (!isdigit(s[start]) && !isalpha(s[start] )))
            {
                start++;
            }
            while (start < end && ( !isdigit(s[end]) && !isalpha(s[end] )))
            {            
                end--;
            }

            if (start < end)
            {
                if (tolower(s[start]) != tolower(s[end]))
                {
                    return false;
                }                
                start++;
                end--;     
            } 
        }
        return true;
    }
};

struct test {
    string s;
    bool expected;
} testcases[5];

void print_result(test testcase, bool result)
{
    static int n = 1;
    cout << "Test case #" << n << endl;
    cout << "string s = " << testcase.s << endl;;
    cout << "Result = " << result << endl;;
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
    n++;
}

int main()
{
    testcases[0].s = "A man, a plan, a canal: Panama";
    testcases[0].expected = true;

    testcases[1].s = "race a car";
    testcases[1].expected = false;

    testcases[2].s = " ";
    testcases[2].expected = true;

    testcases[3].s = ".,";
    testcases[3].expected = true;

    testcases[4].s = "0P";
    testcases[4].expected = false;

    Solution solution;
    for (test testcase : testcases) {
        print_result(testcase, solution.isPalindrome(testcase.s));
    }
    


    return 0;
}