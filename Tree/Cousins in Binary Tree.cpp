/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
bool cousin(TreeNode* root, int x,int y)
{
    if(root==NULL)
        return false;
    if(root->left && root->right && ((root->left->val==x && root->right->val==y)||(root->right->val==x && root->left->val==y)))
        return true;
    
        return (cousin(root->left,x,y) || cousin(root->right,x,y));
}
int level(TreeNode* root,int x,int l)
{
    if(root==NULL)
        return 0;
    if(root->val==x)
        return l;
    int res=level(root->left,x,l+1);
    if(res!=0)
        return res;
    return level(root->right,x,l+1);
    
}
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(level(root,x,1)==level(root,y,1))
        {
            if(cousin(root,x,y))
                return false;
            else
                return true;
        }
        else
            return false;
    }
};