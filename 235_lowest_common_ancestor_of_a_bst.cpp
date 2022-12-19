#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

struct obj
{
    vector<int> root;
    int p, q, expected;
} testcases[3];

TreeNode* insert(TreeNode *root, int value)
{
    TreeNode* parent = NULL;
    TreeNode* current = root;    

    // traverse to the right position
    while (current != NULL)
    {
        parent = current;
        if (value < current->val) {
            //cout << "go down to the left of  " << current->val << ", ";
            current = current->left;
        }
        else
        {
            //cout << "go down to the right of  " << current->val << ", ";
            current = current->right;
        }
    }
    // the root is empty
    if (parent == NULL)
    {
        //cout << "create a node " << value << endl;
        return new TreeNode(value);
    }
    else if (value < parent->val)
    {
        //cout << "create a node " << value << endl;
        parent->left = new TreeNode(value);
    }
    else
    {
        //cout << "create a node " << value << endl;
        parent->right = new TreeNode(value);
    }
    return parent;
}

TreeNode* create_a_tree(vector<int> &v)
{
    TreeNode *tree = NULL;
    tree = insert(tree, v[0]);
    for (int i = 1; i < v.size(); i++)
    {
        insert(tree, v[i]);
    }
    return tree;
}

class Solution {
public:
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        // both nodes on the left side of root (including middle)
        if (p->val <= root->val && q->val <= root->val)
        {
            if (p == root || q == root)
            {
                return root;
            }
            helper(root->left, p, q);
        } 
        // both nodes on the right side of root (including middle)
        else if  (p->val >= root->val && q->val >= root->val)
        {
            if (p == root || q == root)
            {
                return root;
            }
            helper(root->right, p ,q);
        }
        // two nodes on the different side of node
        else
        {
            return root;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        return helper(root, p, q);
    }
};

TreeNode* find_node(TreeNode* root, int value)
{
    while (root != NULL)
    {
        if (value == root->val)
        {
            return root;
        }
        else if (value < root->val)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

TreeNode* visit_node(TreeNode* root, int value)
{
    while (root != NULL)
    {
        if (value == root->val)
        {
            return root;
        }
        else if (value < root->val)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

void print_result(obj testcase, TreeNode *result)
{
    static int n = 1;
    int expected = testcase.expected;
    cout << "Test case  #" << n << endl;
    cout << "root = [";
    for (int i = 0; i < testcase.root.size(); i++)
    {
        if (i != 0)
        {
            cout << "," ;
        }
        cout << testcase.root[i];
    }
    cout << "], p = " << testcase.p << ", q = " << testcase.q << endl;
    cout << "Result: " << result->val << endl;
    cout << "Expected: " << expected << endl;
    if (result->val == expected)
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
    testcases[0].root = {6,2,8,0,4,7,9,NULL,NULL,3,5};
    testcases[0].p = 2;
    testcases[0].q = 4;
    testcases[0].expected = 2;

    testcases[1].root = {6,2,8,0,4,7,9,NULL,NULL,3,5};
    testcases[1].p = 2;
    testcases[1].q = 8;
    testcases[1].expected = 6;
    
    testcases[2].root = {2, 1};
    testcases[2].p = 2;
    testcases[2].q = 1;
    testcases[2].expected = 2;

    Solution solution;
    for (obj testcase : testcases)
    {
        TreeNode *tree = create_a_tree(testcase.root);
        TreeNode *p = visit_node(tree, testcase.p);
        TreeNode *q = visit_node(tree, testcase.q);

        TreeNode *r = solution.lowestCommonAncestor(tree, p, q);
        print_result(testcase, r);
    }
    
    return 0;
}