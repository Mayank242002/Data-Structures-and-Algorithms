#include<iostream>
#include <queue>
using namespace std;

struct Node 
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};
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
void Preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
int height(struct Node *p)
{
    if (p==nullptr)
    return 0;
    int x=height(p->lchild);
    int y=height(p->rchild);
    return 1+max(x,y);
}
int main()
{
    struct Node *root=nullptr;
    root=Binary_tree(root);
    Preorder(root);
    cout<<endl<<height(root)<<endl;
}
