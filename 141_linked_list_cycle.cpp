#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
        {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) // meets
            {
                return true;
            }
        }
        return false;
    }
};

struct obj
{
    vector<int> v;
    int pos;
    bool expected;
} testcases[3];

ListNode* create_head(vector<int> data, int pos) 
{
    ListNode* head = new ListNode(-1);
    ListNode* current = head;
    for (int x: data)
    {
        current->next = new ListNode(x);
        current = current->next;
    }
    if (pos > -1) {
        ListNode* connects_to = head;
        for (int i = 0; i <= pos; i++)
        {
            connects_to = connects_to->next;
        }
        current->next = connects_to;
    }

    return head->next;
}

void print_list_node(ListNode* head)
{
    while(head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void print_result(obj testcase, bool result)
{
    cout << "head = [";
    for (int i: testcase.v)
    {
        if (i != testcase.v[0]){
            cout << ",";
        }
        cout << i;
    }
    cout << "], position = " << testcase.pos << endl;
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
    testcases[0].v =  {3, 2, 0, -4};
    testcases[0].pos = 1;
    testcases[0].expected = true;

    testcases[1].v =  {1, 2};
    testcases[1].pos = 0;
    testcases[1].expected = true;

    testcases[2].v =  {1};
    testcases[2].pos = -1;
    testcases[2].expected = false;

    Solution solution;
    ListNode *head = NULL;
    for (obj testcase: testcases)
    {
        head = create_head(testcase.v, testcase.pos);
        //print_list_node(head);
        print_result(testcase, solution.hasCycle(head));
        solution.hasCycle(head);
    }
}