if(root == NULL) return NULL;

    if(root->val == n1 || root->val == n2){
        return root;
    }
    if(n1 < root->val && n2 < root->val){
        return LCA(root->left , n1 , n2);
    }
    if(n1 > root->val && n2 > root->val){
        return LCA(root->right , n1 , n2);
    }
    return root;