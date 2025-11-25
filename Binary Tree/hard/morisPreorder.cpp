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
    vector<int> getPreorder(TreeNode* root){
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
                    // IP->right =  curr;
                    result.push_back(curr->val);
                    IP->right =  curr;
                    curr =  curr->left;
                }
                else{
                    IP->right = NULL;
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

    vector<int> Preorder = sol.getPreorder(root);

    cout << "Binary Tree Morris Preorder Traversal: ";
    for (int i = 0; i < Preorder.size(); i++)
    {
        cout << Preorder[i] << " ";
    }
    cout << endl;
    return 0;
}