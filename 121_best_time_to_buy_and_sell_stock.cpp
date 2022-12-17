#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int max_profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < min)
            {
                min = prices[i];
            }
            else
            {
                int profit = prices[i] - min;
                max_profit = (profit > max_profit) ? profit: max_profit;
            }
        }
        return max_profit;
    }
};

struct obj
{
    vector<int> prices;
    int expected;
} tests[2];

void print_result(obj test, int result)
{
    cout << "prices = [ ";
    for (int i = 0; i < test.prices.size(); i++)
    {
        if (i == 0)
        {
            cout << test.prices[i];
        }
        else
        {
            cout << ", " << test.prices[i];
        }
    }
    cout << " ]" << endl;
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


int main ()
{
    Solution solution;

    tests[0].prices = {7, 1, 5, 3, 6, 4};
    tests[0].expected = 5;

    tests[1].prices = {7, 6, 4, 3, 1};
    tests[1].expected = 0;
    for (obj test: tests)
    {
        print_result(test, solution.maxProfit(test.prices));
    }
    
    
    return 0;
}