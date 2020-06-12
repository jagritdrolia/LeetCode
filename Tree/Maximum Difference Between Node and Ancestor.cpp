//https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/


void findmax(TreeNode* root,int min_val,int max_val,int &ans)
{
    if(root==NULL)
        return ;
    min_val=min(min_val,root->val);
    max_val=max(max_val,root->val);
    
    ans=max(ans,abs(min_val-max_val));
    
    findmax(root->left,min_val,max_val,ans);
    findmax(root->right,min_val,max_val,ans);
    
}
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL)
            return 0;
        int ans=INT_MIN;
        findmax(root,root->val,root->val,ans);
        return ans;
    }
};
