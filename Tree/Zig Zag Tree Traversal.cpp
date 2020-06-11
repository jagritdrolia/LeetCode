// Method 1 

https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

vector<vector<int>>v;
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        v.clear();
        if(root==NULL)
            return v;
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        s1.push(root);
        vector<int>tmp;
        while(!s1.empty() || !s2.empty()){
            
            while(!s1.empty()){
                TreeNode* temp=s1.top();
                    s1.pop();
                tmp.push_back(temp->val);
                if(temp->left)
                    s2.push(temp->left);
                if(temp->right)
                    s2.push(temp->right);
            }
           if(tmp.size()!=0)
            {
                 v.push_back(tmp);
                tmp.clear();
            }
            while(!s2.empty()){
                TreeNode* temp=s2.top();
                    s2.pop();
                tmp.push_back(temp->val);
                if(temp->right)
                    s1.push(temp->right);
                 if(temp->left)
                    s1.push(temp->left);
            }
            if(tmp.size()!=0)
            {
                 v.push_back(tmp);
                tmp.clear();
            }
        }
        return v;
    }
};

// Method 2

vector<vector<int>>v;
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        v.clear();
        if(root==NULL)
            return v;
        stack<TreeNode*>cur;
        stack<TreeNode*>next;
        cur.push(root);
        vector<int>tmp;
        bool lefttoright=true;
        while(!cur.empty()){
            TreeNode* temp=cur.top();
                cur.pop();
            if(temp){
                tmp.push_back(temp->val);
                if(lefttoright)
                {
                    if(temp->left)
                        next.push(temp->left);
                    if(temp->right)
                        next.push(temp->right);
                }
                else
                {
                    if(temp->right)
                        next.push(temp->right);
                    if(temp->left)
                        next.push(temp->left);
                }
            }
            if(cur.empty())
            {
                lefttoright=!lefttoright;
                v.push_back(tmp);
                tmp.clear();
                swap(cur,next);
            }
        }
        return v;
    }
};

Note:- if we want to reverse the zig zag traversal just reverse(v.begin(),v.end());
