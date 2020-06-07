
// Doubly Linked List Approach

class node
{
    public:
        string web_page;
        node* next;
        node* prev;
        node(string url)
        {
            this->web_page=url;
            this->prev=NULL;
            this->next=NULL;
        }
};
node* head;
node* cur;
class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        head= new node(homepage);
        cur=head;
    }
    
    void visit(string url) {
        struct node*temp;
        temp=new node(url);
        cur->next=temp;
        temp->prev=cur;
        cur=temp;
    }
    
    string back(int steps) {
        while(cur->prev!=NULL && steps!=0)
            cur=cur->prev,steps--;
        return cur->web_page;
        
    }
    
    string forward(int steps) {
         while(cur->next!=NULL && steps!=0)
            cur=cur->next,steps--;
        return cur->web_page;
    }
};

// Vector Approach 

vector<string> history;
int pos = 0;
BrowserHistory(string homepage) { history.push_back(homepage); }
void visit(string url) {
    ++pos;
    history.resize(pos);
    history.push_back(url);
}
string back(int steps) {
    pos = max(0, pos - steps);
    return history[pos];
}
string forward(int steps) {
    pos = min((int)history.size() - 1, pos + steps);
    return history[pos];
}

// Stack Approach

stack<string> back, forward;
string cur;
BrowserHistory(string homepage) { cur = homepage; }
void visit(string url) {
    forward = stack<string>();
    back.push(cur);
    cur = url;
}
string back(int steps) {
    while (--steps >= 0 && !back.empty()) {
        forward.push(cur);
        cur = back.top();
        back.pop();
    }
    return cur;
}
string forward(int steps) {
    while (--steps >= 0 && !forward.empty()) {
        back.push(cur);
        cur = forward.top();
        forward.pop();
    }
    return cur;
}
/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
