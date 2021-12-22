#include<iostream>
#include<queue>
#include<stack>
using namespace std;


struct Node 
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

void preorder_inorder_postorder(struct Node *root)
{
    stack<pair<struct Node *,int>> st;
    st.push({root,1});
    vector<int> pre,in,post;
    while (!st.empty())
    {
        auto it=st.top();
        if (it.second==1)
        {
            pre.push_back(it.first->data);
            st.top().second++;
            if (it.first->lchild)
               st.push({it.first->lchild,1});
        }
        else if (it.second==2)
        {
            in.push_back(it.first->data);
            st.top().second++;
            if (it.first->rchild)
                st.push({it.first->rchild,1});
        }
        else
        {
            post.push_back(it.first->data);
            st.pop();
        }
    }
     
    cout<<"preorder:";
    for (int i=0;i<pre.size();i++)
         cout<<pre[i]<<" ";
    cout<<endl; 
     cout<<"inorder:";
    for (int i=0;i<in.size();i++)
         cout<<in[i]<<" ";
    cout<<endl; 
     cout<<"postorder:";
    for (int i=0;i<post.size();i++)
         cout<<post[i]<<" ";
    cout<<endl; 


}

struct Node * Binary_tree(struct Node *root)
{
  struct Node *p,*t;
  queue<struct Node*>q;
  int x;
  cout<<"enter the value of root Node";
  cin>>x;
  root=new struct Node;
  root->data=x;
  root->lchild=root->rchild=nullptr;
  q.push(root);
  while(!q.empty())
  {
      p=q.front();
      q.pop();
      cout<<"enter the value of left child of"<<p->data;
      cin>>x;
      if (x!=-1)
      {
          t=new struct Node;
          t->data=x;
          t->lchild=t->rchild=nullptr;
          p->lchild=t;
          q.push(t);
      }
      t=nullptr;
      cout<<"enter the value of Right child of"<<p->data;
      cin>>x;
      if (x!=-1)
      {
          t=new struct Node;
          t->data=x;
          t->lchild=t->rchild=nullptr;
          p->rchild=t;
          q.push(t);
      }
      
  }
return root;

}

int height(struct Node *p)
{
    if (p==nullptr)
    return 0;
    int x=height(p->lchild);
    int y=height(p->rchild);
    return 1+max(x,y);
}
 bool isBalanced(struct Node* root) {
        if (root==nullptr)
            return true;
        if (root->lchild==nullptr && root->rchild==nullptr)
            
            return true;
        else
        {
            int x=height(root->lchild);
            int y=height(root->rchild);
            if (abs(x-y)>1) return false;
            
            bool left=isBalanced(root->lchild);
            bool right=isBalanced(root->rchild);
            if (left==false || right==false)
                return false;
            return true;
        }
        
    }

int main()
{
   struct Node *root=nullptr;
    root=Binary_tree(root);
    preorder_inorder_postorder(root);
}