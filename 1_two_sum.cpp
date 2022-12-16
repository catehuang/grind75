#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
    public:
        vector<int> twoSum(vector<int> &nums, int target)
        {
            int find_this;
            map<int, int> m;
            map<int, int>::iterator it;
            for (int i = 0; i < nums.size(); i++)
            {
                find_this = target - nums[i];
                // the value we need isn't in the map => add the value to the map for others
                it = m.find(find_this);
                if (it == m.end())
                {
                    m.insert(pair<int, int>(nums[i], i));
                }
                else
                {
                    return {it->second, i};
                }
            }
            return {-1};
        }
};

struct test {
    vector<int> nums;
    int target;
    vector<int> expected;
};

void print_result(test test_case, vector<int> result)
{
    cout << "Input nums = [" << test_case.nums[0];
    for (int i = 1; i < test_case.nums.size(); i++)
    {
        cout << "," << test_case.nums[i];
    }
    cout << "], target = " << test_case.target << endl;

    cout << "Result = [" << result[0] << "," << result[1] << "]" << endl;
    cout << "Expected = [" << test_case.expected[0] << "," << test_case.expected[1] << "]" << endl; 
    if (test_case.expected == result) 
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
    test test1, test2, test3, tmp;

    test1.nums = {2, 7, 11, 15};
    test1.target = 9;
    test1.expected = {0, 1};
    tmp = test1;
    print_result(tmp, solution.twoSum(tmp.nums, tmp.target));

    test2.nums = {3, 2, 4};
    test2.target = 6;
    test2.expected = {1, 2};
    tmp = test2;
    print_result(tmp, solution.twoSum(tmp.nums, tmp.target));

    test3.nums = {3, 3};
    test3.target = 6;
    test3.expected = {0, 1};
    tmp = test2;
    print_result(tmp, solution.twoSum(tmp.nums, tmp.target));

    return 0;
}