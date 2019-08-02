#include<bits/stdc++.h>
using namespace std;
 
void buildt(int* arr, int* tree,int start, int end, int tn)
{
    if(start==end)
    {
        tree[tn]=arr[start];
        return;
    }
    int mid=(start+end)/2;
    buildt(arr,tree,start,mid,2*tn);
    buildt(arr,tree,mid+1,end,2*tn+1);
    tree[tn]=min(tree[2*tn],tree[2*tn+1]);
}
void update(int* arr, int* tree,int start, int end, int tn,int index,int val)
{
    if(start==end)
    {
        arr[index]=val;
        tree[tn]=val;
        return;
    }
    int mid=(start+end)/2;
    if(index>mid)
    {
        update(arr,tree,mid+1,end,2*tn+1,index,val);
    }
    else
    {
        update(arr,tree,start,mid,2*tn,index,val);
    }
    tree[tn]=min(tree[2*tn],tree[2*tn+1]); 
 
    return;
}
int query(int* tree,int start,int end,int tn,int left,int right)
{
    if(start>right || end<left)
    {
        return INT_MAX;
    }
    else if(start>=left && end<=right)
    {
        return tree[tn];
    }
    int mid=(start+end)/2;
    int ans1=query(tree,start,mid,2*tn,left,right);
    int ans2=query(tree,mid+1,end,2*tn+1,left,right);
    return min(ans1,ans2);
 
}
int main() {
 int m,n;
    cin >> m >> n;
    int *arr = new int[m];
    for(int i=0;i<m;i++)
    {
        cin >> arr[i];
    }
    int *tree = new int[4*m];
    buildt(arr,tree,0,m-1,1);
    while(n--)
    {
        char ch;
        int a,b;
        cin >> ch >> a >> b;
        if(ch=='u')
        {
            update(arr,tree,0,m-1,1,a-1,b);
 
        }
        else
        {
            cout << query(tree,0,m-1,1,a-1,b-1) << endl;
        }
    }
    return 0;
}
