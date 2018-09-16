#include<bits/stdc++.h>

using namespace std;

struct profile{
    string name,addres;
    /**various type of variable **/
    profile(string n,string a)
    {
        name=n;
        addres=a;
    }
};

struct node{
    string mobileNo;
    profile *p;
    struct node *nxt;

    node(string n,string a){
        p=new profile(n,a);
        nxt=NULL;}
};

const int mod=1000;
node *hashTable[mod+5];

int HashFun(string mobN)
{
    int ans=0;
    for(int i=0;i<mobN.size();i++)
        ans=(ans*10+(mobN[i]-'0'))%mod;
    return ans;
}

void _insert(string mobN,string name,string add)
{
    int index=HashFun(mobN);
    node *nNode=new node(name,add);
    node *last=hashTable[index];

    nNode->mobileNo=mobN;

    if(hashTable[index]==NULL)
        {
            hashTable[index]=nNode;return;
        }
    while(last->nxt!=NULL)
        last=last->nxt;
    last->nxt=nNode;
}

bool _search(string mobN)
{
    int index=HashFun(mobN);
    node *last=hashTable[index];

    while(last!=NULL)
    {
        if(last->mobileNo==mobN)
        {
            cout<<last->mobileNo<<"\n";
            cout<<last->p->name<<" "<<last->p->addres<<"\n";
            return true;
        }
        last=last->nxt;
    }
    return false;
}
int main()
{
  for(int i=0;i<mod;i++)
        hashTable[i]=NULL;

  string no,name,add;
  while(cout<<"\nInsert a profile : mobile_NO Name Address : " && cin>>no>>name>>add)
    {
        _insert(no,name,add);
        cout<<"Enter a mobile_no to search : ";cin>>no;
        cout<<_search(no)<<endl;
    }


  return 0;
}
