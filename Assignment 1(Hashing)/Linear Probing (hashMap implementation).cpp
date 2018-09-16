#include<bits/stdc++.h>
using namespace std;
const int sz=20;

struct dataItem
{
    int data;
    int key;
};

struct dataItem* dataList[sz];
struct dataItem* singleItem;
struct dataItem* item;

int getHash(int key)
{
    return  key%sz;
}

struct dataItem *query(int key)
{
    int hashInd=getHash(key);

    while(dataList[hashInd]!=NULL)
    {
        if(dataList[hashInd]->key==key)
            return dataList[hashInd];
        ++hashInd;
        hashInd%=sz;
    }
return NULL;
}

void Insert(int key, int data)
{
    struct dataItem *item=(struct dataItem*)malloc(sizeof(struct dataItem));
    item->data=data;
    item->key=key;

    int hashInd=getHash(key);
    while(dataList[hashInd]!=NULL && dataList[hashInd]->key!=-1)
    {
        ++hashInd;
        hashInd%=sz;
    }
    dataList[hashInd]=item;

}

struct dataItem* del(struct dataItem* item)
{
    int key=item->key;
    int hashInd=getHash(key);

    while(dataList[hashInd]!=NULL)
    {
        if(dataList[hashInd]->key==key)
        {
            struct dataItem* temp =dataList[hashInd];
            dataList[hashInd]=singleItem;
            return temp;
        }
        ++hashInd;
        hashInd%=sz;
    }
    return NULL;
}

void display()
{
    int i=0;
    for(i=0; i<sz; i++)
    {
        if (dataList[i]!=NULL)
        {
            cout<<"( "<<dataList[i]->key<<" , "<<dataList[i]->data<<" )"<<endl;
        }
        else
            cout<<"( ~~ )"<<endl;
    }
}

int main()
{
    singleItem=(struct dataItem*)malloc(sizeof(struct dataItem));
    singleItem->data=-1;
    singleItem->key=-1;

    Insert(1,20);
    Insert(2,70);
    Insert(42,80);
    Insert(4,25);
    Insert(12,44);
    Insert(14,32);
    Insert(17,11);
    Insert(37,78);
    Insert(13,97);

    display();

    item=query(37);
    if(item!=NULL)
        cout<<"Found :"<<item->data<<endl;
    else
        cout<<"Not found"<<endl;

    del(item);

    display();

    item=query(37);
    if(item!=NULL)
        cout<<"Found :"<<item->data<<endl;
    else
        cout<<"Not found"<<endl;

    return 0;
}

