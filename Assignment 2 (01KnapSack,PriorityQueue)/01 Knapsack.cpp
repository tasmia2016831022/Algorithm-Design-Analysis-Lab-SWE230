#include<bits/stdc++.h>
using namespace std;
long long dp[100][100];
long long cost[100];
long long weight[100];
long long cap;

int func(int i, int w ) ///ith element
{
    if(i<=0 || w>=cap)
    {
        return 0;
        cout<<"invalid"<<endl;
    }
    if(dp[i][w]!=-1)
    {
        return dp[i][w];
        cout<<"stored"<<dp[i][w]<<endl;
    }

    int profit1, profit2;

    profit1=0;
    profit2=0;

    if(w+weight[i]<=cap)
    profit1=cost[i]+func(i-1,w+weight[i]);

    profit2=func(i-1,w);

    return dp[i][w]=max(profit1,profit2);
    cout<<dp[i][w]<<endl;

}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>weight[i]>>cost[i];
    }
    cin>>cap;
    memset(dp,-1,sizeof dp);
    cout <<func(n,0)<< endl;

    return 0;
}
