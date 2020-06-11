https://leetcode.com/problems/binary-tree-inorder-traversal/

// Iteratively Solution using Stack

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
        if(root==NULL)
            return v;
        stack<TreeNode*>s;
        TreeNode * cur=root;
        while(!s.empty()||cur!=NULL){
            
            while(cur!=NULL){
                    s.push(cur);
                cur=cur->left;
            }
                cur=s.top();
                    s.pop();
            v.push_back(cur->val);
            cur=cur->right;
        }
        return v;
    }
};
