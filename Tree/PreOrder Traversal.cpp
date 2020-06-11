https://leetcode.com/problems/binary-tree-preorder-traversal/

// 1 Method Recursion

// 2 Method Iteratively using Stack  Time: O(N) Space: O(N)

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>v;
        if(root==NULL)
            return v;
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty()){
            TreeNode* temp=s.top();
                s.pop();
            v.push_back(temp->val);
            if(temp->right)
                s.push(temp->right);
            if(temp->left)
                s.push(temp->left);
        }
        return v;
    }
};

............................................

// 3 Method  Space :- O(H)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>v;
        if(root==NULL)
            return v;
        stack<TreeNode*>s;
        TreeNode * cur=root;
        while(!s.empty()||cur!=NULL){
            while(cur!=NULL){
                v.push_back(cur->val);
                if(cur->right)
                    s.push(cur->right);
                cur=cur->left;
            }
            if(!s.empty()){
                cur=s.top();
                    s.pop();
            }
        }
        return v;
    }
};

