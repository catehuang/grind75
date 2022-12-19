#include <iostream>
#include <cmath>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

int getHeight(TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = getHeight(root->left);
    int right = getHeight(root->right);
    if (left == -1 || right == -1)
    {
        return -1;
    }
    if (abs(left - right) > 1)
    {
        return -1;
    }
    return max(left , right) + 1;
}

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
        {
            return true;
        }
        if (getHeight(root) == -1)
        {
            return false;
        }
        return true;
    }
};

void inorder(TreeNode* root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}


int main()
{
    Solution solution;
    TreeNode *root = NULL;

    TreeNode *root1 = new TreeNode(3);
    root = root1;
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1 = root1->right;
    root1->left = new TreeNode(15);
    root1->right = new TreeNode(7);
    cout << "Test case#1" << endl;
    cout << "root = [3,9,20,null,null,15,7]" << endl;
    cout << "Inorder checking: ";
    inorder(root);
    cout << endl;
    
    if (solution.isBalanced(root) == true)
    {
        cout << "=== PASS ===" << endl;
    }
    else
    {
        cout << "!!!! FAIL !!!!" << endl;
    }
    cout << endl;

    TreeNode *root2 = new TreeNode(1);
    root = root2;
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2 = root2->left;
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(3);
    root2 = root2->left;
    root2->left = new TreeNode(4);
    root2->right = new TreeNode(4);
    cout << "Test case#2" << endl;
    cout << "root = [1,2,2,3,3,null,null,4,4]" << endl;
    cout << "Inorder checking: ";
    inorder(root);
    cout << endl;
    if (solution.isBalanced(root) == false)
    {
        cout << "=== PASS ===" << endl;
    }
    else
    {
        cout << "!!!! FAIL !!!!" << endl;
    }
    cout << endl;

    cout << "Test case#3" << endl;
    cout << "root = []" << endl;
    if (solution.isBalanced(new TreeNode()) == true)
    {
        cout << "=== PASS ===" << endl;
    }
    else
    {
        cout << "!!!! FAIL !!!!" << endl;
    }
    cout << endl;

    return 0;
}