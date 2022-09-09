#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node *links[26];
    bool flag=false;
    
    bool containsKey(char c)
    {
        return (links[c-'a']!=nullptr);
    }
    void put(char c,Node *node)
    {
        links[c-'a']=node;
    }
    Node *get(char c)
    {
        return links[c-'a'];
    }
    void setEnd()
    {
        flag=true;
    }
    bool isEnd()
    {
        return flag;
    }
    
        
};

class Trie {

    Node *root;
    
public:
    Trie() {
        root=new Node ();
    }
    
    void insert(string word) {
        Node *node=root;
        for (int i=0;i<word.size();i++)
        {
            if (!node->containsKey(word[i]))
                node->put(word[i],new Node());
            
            node =node->get(word[i]);
        }
        node->setEnd();
        
    }
    
    bool search(string word) {
        Node *node=root;
        for (int i=0;i<word.size();i++)
        {
            if (node->containsKey(word[i]))
                node=node->get(word[i]);
            else
                return false;
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
         Node *node=root;
        for (int i=0;i<prefix.size();i++)
        {
            if (node->containsKey(prefix[i]))
                node=node->get(prefix[i]);
            else
                return false;
        }
        return true;
    }
    
};


int main()
{
    Trie obj;
    obj.insert("Hello");
    cout<<obj.search("Hello")<<endl;
    cout<<obj.startsWith("He")<<endl;


}
