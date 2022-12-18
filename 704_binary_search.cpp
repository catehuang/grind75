#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int middle;
       
        while (start <= end)
        {
            middle = (start + end) / 2;
            if (target == nums[middle])
            {
                return middle;
            }
            else if (target < nums[middle])
            {
                end = middle - 1;
            } 
            else
            {
                start = middle + 1;
            }
        }
        return -1;
    }
};

struct obj
{
    vector<int> nums;
    int target;
    int expected;
} testcases[3];

void print(obj testcase, int result)
{
    static int n = 1;
    cout << "Test case #" << n << endl;
    cout << "nums = [";
    for (int i = 0; i < testcase.nums.size(); i++)
    {
        if (i != 0)
        {
           cout << ",";
        }
        cout << testcase.nums[i];
    }
    cout << "], target = " << testcase.target << endl;
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
    n++;
}

int main()
{
    Solution solution;
    testcases[0].nums = {-1, 0, 3, 5, 9, 12};
    testcases[0].target = 9;
    testcases[0].expected = 4;

    testcases[1].nums = {-1,0,3,5,9,12};
    testcases[1].target = 2;
    testcases[1].expected = -1;

    testcases[2].nums = {5};
    testcases[2].target = 5;
    testcases[2].expected = 0;
    
    for (obj testcase: testcases)
    {
        print(testcase, solution.search(testcase.nums, testcase.target));
    }
    return 0;
}