 //  https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
 
        1
       / \
      2   3
     / \   \
    4   5   7
    
 -----------------------------------------------------------------   
// Method 1 Using Queue
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return root;
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            Node* temp=q.front();
                q.pop();
            if(temp!=NULL){
                temp->next=q.front();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            else if(!q.empty()){
                q.push(NULL);
            }
        }
    return root;
    }
};
------------------------------------------------------------------------------

// Method 2 using Queue
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return root;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                Node* temp=q.front();
                q.pop();
                if(i+1<n)
                    temp->next=q.front();
                else
                    temp->next=NULL;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);	

            }
        }
    return root;
    }
};
--------------------------------------------------------------------------------
  // Method 3
   Recursion o(1) constant Space 
   
   Node* getmin(Node* root){
    Node*temp=root->next;
    while(temp!=NULL){
        if(temp->left)
            return temp->left;
        if(temp->right)
            return temp->right;
        temp=temp->next;
    }
    return NULL;
}
void connectutil(Node* root)
{
    if(root==NULL)
        return;
    if(root->next!=NULL)
        connectutil(root->next);
    if(root->left)
    {
        if(root->right){
            root->left->next=root->right;
            root->right->next=getmin(root);
        }
        else
            root->left->next=getmin(root);
        connectutil(root->left);
    }
    else if(root->right){
        root->right->next=getmin(root);
        connectutil(root->right);
    }
    else
        connectutil(getmin(root));
}
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return root;
        root->next=NULL;
        connectutil(root);
        return root;
    }
};
-----------------------------------------------------------

// Method 4 Iteration
o(1) Constant Space

Node* getmin(Node* root){
    Node*temp=root->next;
    while(temp!=NULL){
        if(temp->left)
            return temp->left;
        if(temp->right)
            return temp->right;
        temp=temp->next;
    }
    return NULL;
}
void connectutil(Node* root)
{
    if(root==NULL)
        return;
   while(root!=NULL){
       Node* q=root;
       while(q!=NULL){
           if(q->left){
               if(q->right)
                   q->left->next=q->right;
               else
                   q->left->next=getmin(q);
           }
           if(q->right)
               q->right->next=getmin(q);
           q=q->next;
       }
       if(root->left)
         root=root->left;
        else if(root->right)
            root=root->right;
       else
           root=root->next;
   }
}
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return root;
        root->next=NULL;
        connectutil(root);
        return root;
    }
};

----------------------------------------------------------------------------
 Method 5 Recursion
 O(1) Space
 
 class Solution {
public:
    Node* connect(Node* root) {
        connectHelper(root);
        return root;
    }

    void connectHelper(Node *root) {
        if (!root) return;
        Node *dummy=new Node(0);
        Node *pre=dummy;
        for (Node *cur = root; cur; cur = cur->next) {
            if (cur->left) {
                pre->next = cur->left;
                pre = pre->next;
            }
            if (cur->right) {
                pre->next = cur->right;
                pre = pre->next;
            }
        }
        connectHelper(dummy->next);
    }
};
