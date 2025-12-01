#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    stack<TreeNode *> stack1;
    stack<TreeNode *> stack2;

    void pushAll(TreeNode *node)
    {
        while (node != nullptr)
        {
            stack1.push(node);
            node = node->left; // Move to the leftmost node
        }
    }

    void pushAllRev(TreeNode *node)
    {
        while (node != nullptr)
        {
            stack2.push(node);
            node = node->right; // Move to the rightmost node
        }
    }

    int next()
    {
        TreeNode *temp = stack1.top();
        stack1.pop();
        if (temp->right)
        {
            pushAll(temp->right);
        }
        return temp->val;
    }

    int before()
    {
        TreeNode *temp = stack2.top();
        stack2.pop();
        if (temp->left)
        {
            pushAllRev(temp->left);
        }
        return temp->val;
    }

    bool findTarget(TreeNode *root, int k)
    {
        if (!root)
            return false;

        pushAll(root);
        pushAllRev(root);

        int left = next();
        int right = before();

        while (left < right)
        {
            int sum = left + right;
            if (sum == k)
            {
                return true;
            }
            else if (sum < k)
            {
                left = next();
            }
            else
            {
                right = before();
            }
        }
        return false;
    }
    // bool findTarget(TreeNode *root, int k)
    // {
    //     if (!root)
    //         return false;
    //         Solution(TreeNode *root){
    //             pushAll(root);
    //     pushAllRev(root);
    //         }

    //     int next()
    //     {
    //         TreeNode *temp = nodeStack.top();
    //         nodeStack.pop();
    //         if (temp->right)
    //         {
    //             pushAll(temp->right);
    //         }
    //         return temp->val;
    //     }

    //     int before()
    //     {
    //         TreeNode *temp = revNodeStack.top();
    //         revNodeStack.pop();
    //         if (temp->left)
    //         {
    //             pushAllRev(temp->left);
    //         }
    //         return temp->val;
    //     }


    //     if(next() + before() == k) {return true;}
    //     else if (next() + before() < k){
    //         next();
    //     } else {
    //         before();
    //     }
    //     return false;
    // }

    // void pushAll(TreeNode * node)
    // {
    //     while (node != nullptr)
    //     {
    //         nodeStack.push(node);
    //         node = node->left; // Move to the leftmost node
    //         }
    //     }
    //     void pushAllRev(TreeNode* node)
    // {
    //     while (node != nullptr)
    //     {
    //         revNodeStack.push(node);
    //         node = node->right; // Move to the rightmost node
            
    //     }
    // }
};

int main()
{
    TreeNode *root1 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(5);
    root1->left->right = new TreeNode(2);
    root1->right->left = new TreeNode(4);
    root1->right->right = new TreeNode(6);
    root1->right->right->right = new TreeNode(7);

    Solution sol;
    sol.findTarget(root1, 9);
    return 0;
}