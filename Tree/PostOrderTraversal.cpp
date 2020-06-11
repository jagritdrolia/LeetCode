https://leetcode.com/problems/binary-tree-postorder-traversal/


// Method 1 using Stack Time:O(N) space:- O(N)

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        if(root==NULL)
            return v;
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty()){
            TreeNode* temp=s.top();
                s.pop();
            v.push_back(temp->val);
            if(temp->left)
                s.push(temp->left);
            if(temp->right)
                s.push(temp->right);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};

......................................................
//Method 2  using Stack Time:O(N) space:- O(H) where as H= height of the tree

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        if(root==NULL)
            return v;
        stack<TreeNode*>s;
        TreeNode * cur=root;
        while(!s.empty()||cur!=NULL){
            while(cur!=NULL){
                v.push_back(cur->val);
                if(cur->left)
                    s.push(cur->left);
                cur=cur->right;
            }
            if(!s.empty()){
                cur=s.top();
                    s.pop();
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
