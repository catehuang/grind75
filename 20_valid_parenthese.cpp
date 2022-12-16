#include <iostream>
#include <string>
#include <list>
using namespace std;

class Solution 
{
    public:
        bool isValid(string s)
        {
            list<char> char_list;
            for (auto c: s)
            {
                if (c == '[' || c== '(' || c == '{')
                {
                    char_list.push_back(c);
                }
                else
                {
                    char left_part = char_list.back();
                    if (c == ']' && left_part != '[')
                    {
                        return false; 
                    } 
                    else if (c == ')' && left_part != '(')
                    {
                        return false;
                    }
                    else if (c =='}' && left_part != '{')
                    {
                        return false;
                    }
                    if (!char_list.empty())
                    {
                        char_list.pop_back();
                    }
                }
            }
            return char_list.empty()? true: false;
        }
};

struct obj 
{
    string s;
    bool expected;
};

void print_result(obj test, bool result) {
    cout << "s = " << test.s << endl;
    cout << "Result = " << result << endl;
    cout << "Expected = " << test.expected << endl;
    if (result == test.expected)
    {
        cout << "=== PASS ===" << endl;
    }
    else
    {
        cout << "=== FAIL ===" << endl;
    }
    cout << endl;
}

int main()
{
    Solution solution;
    obj test;

    test.s = "()";
    test.expected = true;
    print_result(test, solution.isValid(test.s));

    test.s = "()[]{}";
    test.expected = true;
    print_result(test, solution.isValid(test.s));

    test.s = "(]";
    test.expected = false;
    print_result(test, solution.isValid(test.s));

    test.s = "[";
    test.expected = false;
    print_result(test, solution.isValid(test.s));

    return 0;
}