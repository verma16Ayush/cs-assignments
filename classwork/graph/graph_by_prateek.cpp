#include <iostream>
#include<queue>
using namespace std;

class Node
{
    public:
        int data;
        Node*left;
        Node*right;

        Node(int d)
        {
            data = d;
            left = NULL;
            right = NULL;
        }
};

Node* buildTree()
{
    int d;
    cin>>d;

    if(d==-1)
    {
        return NULL;
    }
    Node * root = new Node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void print(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    //Otherwise, print root first followed by subtrees(children)
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

void printIn(Node*root)
{
    if(root==NULL)
    {
        return;
    }
    //Otherwise Left Root Right
    printIn(root->left);
    cout<<root->data<<" ";
    printIn(root->right);
}

void printPost(Node*root)
{
    if(root==NULL)
    {
        return;
    }
    printPost(root->left);
    printPost(root->right);
    cout<<root->data<<" ";
}

int height(Node*root)
{
    if(root==NULL){
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls,rs) + 1;

}

void printKthLevel(Node*root,int k)
{
    if(root==NULL)
    {
        return;
    }
    if(k==1)
    {
        cout<<root->data<<" ";
        return;
    }
    printKthLevel(root->left,k-1);
    printKthLevel(root->right,k-1);
    return;

}

void printAllLevels(Node*root)
{
    int H = height(root);

    for(int i=1;i<=H;i++)
    {
        printKthLevel(root,i);
        cout<<endl;
    }
    return;
}

int count(Node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1 + count(root->left) + count(root->right);
}

void bfs(Node *root)
{
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* f = q.front();
        cout<<f->data<<",";
        q.pop();

        if(f->left)
        {
            q.push(f->left);
        }
        if(f->right)
        {
            q.push(f->right);
        }
    }
    return;
}


int main(){ 
    Node* root = buildTree();
    //cout<<count(root)<<endl;
    //printAllLevels(root);
    bfs(root);

return 0;
}