#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node *nxt;
    node(){nxt=NULL;}
};

const int mod=10;
node *hashTable[mod+5];

int HashFun(int index)
{
    return (index%mod);
}

void _insert(int deta)
{
    int index=HashFun(deta);
    node *nNode=new node();
    node *last=hashTable[index];

    nNode->data=deta;

    if(hashTable[index]==NULL)
        {
            hashTable[index]=nNode;return;
        }
    while(last->nxt!=NULL)
        last=last->nxt;
    last->nxt=nNode;
}

bool _search(int deta)
{
    int index=HashFun(deta);
    node *last=hashTable[index];
    cout<<"path : ";
    while(last!=NULL)
    {
        cout<<last->data<<"\n";
        if(last->data==deta)return true;

        last=last->nxt;
    }
    cout<<"\n";
    return false;
}
int main()
{
  for(int i=0;i<mod;i++)
        hashTable[i]=NULL;
  int deta;
  while(cout<<"Insert a data : " && cin>>deta)
  {
  	_insert(deta);
  	cout<<"search : ";cin>>deta;
  	if(_search(deta))cout<<"Exist"<<"\n";
  	else cout<<"Doesn't exist\n";
  }

  return 0;
}
