#include<bits/stdc++.h>
using namespace std;

struct node{
    int key;
    node(int a )
    {
        key =a;
    }
  //   /***
    bool operator <(const node &p)const{
    return key>p.key;
    }
  //  ***/
};

//struct compare {
//    bool operator() (node *a, node *b)
//    {
//        return (a->key >b->key);
//    }
//
//};

int main(){
    node a = node(5);
    node b = node(4);
    node c = node(8);

    priority_queue<node, vector<node>>myQueue;
    myQueue.push(a);
    myQueue.push(b);
    myQueue.push(c);

    while(!myQueue.empty())
    {
        node temp=myQueue.top();
        myQueue.pop();
        //cout<<temp->key<<endl;
         cout<<temp.key<<endl;

    }
    return 0;
}
/// modify priority queue without pointer
