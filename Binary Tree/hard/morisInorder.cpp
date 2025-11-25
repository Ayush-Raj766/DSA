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

class Solution{
    public :  
    vector<int> getInorder(TreeNode* root){
        vector<int> result;
        TreeNode* curr = root ;
        while (curr != NULL){
            if(curr->left == NULL){
                result.push_back(curr->val);
                curr=curr->right;
            }

            else {
                TreeNode* IP = curr->left;
                while(IP->right != NULL && IP->right != curr){
                    IP = IP->right;
                }

                if(IP->right == NULL){
                    IP->right =  curr;
                    curr =  curr->left;
                }
                else{
                    IP->right = NULL;
                    result.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return result;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);

    Solution sol;

    vector<int> inorder = sol.getInorder(root);

    cout << "Binary Tree Morris Inorder Traversal: ";
    for (int i = 0; i < inorder.size(); i++)
    {
        cout << inorder[i] << " ";
    }
    cout << endl;
    return 0;
}