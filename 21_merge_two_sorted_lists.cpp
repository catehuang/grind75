#include <iostream>
#include <vector>
using namespace std;
#include <string>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        ListNode *head = new ListNode(-1);
        ListNode *current = head;

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val <= list2->val)
            {
                current->next = list1;
                list1 = list1->next;
            }
            else
            {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        if (list1 != nullptr)
        {
            current->next = list1;
        }
        else
        {
            current->next = list2;
        }

        return head->next;
    }
};

struct Obj
{
    ListNode *list1;
    ListNode *list2;
    ListNode *expected;
};

ListNode* create_list_node(vector<int> v)
{
    ListNode *dummy = new ListNode();
    ListNode *head = new ListNode();
    dummy->next = head;

    for (int i = 0; i < v.size(); i++)
    {
        head->val = v[i];
        if (i != v.size() - 1) {
            head->next = new ListNode();
            head = head->next;
        }
    }
    return dummy->next;
}

string print_list_node(ListNode *list_node)
{
    string s = "";
    while (list_node != nullptr)
    {
        cout << list_node->val << " -> ";
        s += list_node->val + " -> ";
        list_node = list_node->next;
    }
    cout << "null" << endl;
    s += "null";
    return s;
}

void print_result(Obj test, ListNode *result)
{
    cout << "Merge two lists" << endl;
    cout << "list 1: ";
    print_list_node(test.list1);

    cout << "list 2: ";
    print_list_node(test.list2);

    cout << "Expected: ";
    string str_exp = print_list_node(test.expected);

    cout << "Result: ";
    string str_result = print_list_node(result);

    if (str_exp == str_result)
    {
        cout << "=== PASS ===" << endl;
    }
    else{
        cout << "=== FAIL ===" << endl;
    }
    cout << endl;
}

int main()
{
    Solution solution;
    Obj test;
    ListNode *list_node;
    
    vector<int> v1 = {1, 2, 4};
    vector<int> v2 = {1, 3, 4};
    vector<int> v3 = {1, 1, 2, 3, 4, 4};
    test.list1 = create_list_node(v1);
    test.list2 = create_list_node(v2);
    test.expected = create_list_node(v3);
    ListNode *result = solution.mergeTwoLists(test.list1, test.list2);
    print_result(test, result);

    test.list1 = nullptr;
    test.list2 = nullptr;
    test.expected = nullptr;
    result = solution.mergeTwoLists(test.list1, test.list2);
    print_result(test, result);
    
    v2 = {0};
    v3 = {0};
    test.list1 = nullptr;
    test.list2 = create_list_node(v2);
    test.expected = create_list_node(v3);
    result = solution.mergeTwoLists(test.list1, test.list2);
    print_result(test, result);

    return 0;
}