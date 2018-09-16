#include<bits/stdc++.h>
using namespace std;

const int sz=20;

struct info
{
    string s;
    int a,b;
    info(){}

    info(string name, int age, int bonus)
    {
        s=name;
       a=age;
     b=bonus;
    }
};

struct dataItem
{
    info data;
    int key;
};

struct dataItem* dataList[sz];
struct dataItem*  singleItem;
struct dataItem*  item;

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

void Insert(int key, info data)
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
            struct dataItem*  temp =dataList[hashInd];
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
            cout<<" ("<<dataList[i]->key<<","<<dataList[i]->data.s<<","<<dataList[i]->data.a<<","<<dataList[i]->data.b<<" )"<<endl;
        }
        else
            cout<<"( ~~~~ )"<<endl;
    }
}

int main()
{
    singleItem=(struct dataItem*)malloc(sizeof(struct dataItem));
    singleItem->data.a=-1;
    singleItem->data.b=-1;
    singleItem->key=-1;

      Insert(1,info("hasna",20,10));
    Insert(2,info("sammi",30,40));
    Insert(42,info("amani",70,50));
    Insert(4,info("saila",80,17));
    Insert(12,info("rumi",54,71));
    Insert(14,info("anis",53,5));
    Insert(17,info("tina",71,23));
    Insert(13,info("mun",57,101));
    Insert(37,info("mim",27,1001));

    display();

   item = query(37);
    if(item!=NULL)
        printf("Element Found: "),cout<<item->data.a <<","<<item->data.b<<","<<item->data.s<<endl;
    else
        printf("Not found\n");

    del(item);
    display();
    item = query(37);
    if(item!=NULL)
        printf("Element Found: "),cout<<item->data.a <<","<<item->data.b<<","<<item->data.s<<endl;
    else
        printf("Not found\n");

    return 0;
}


