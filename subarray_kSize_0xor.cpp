#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("error.txt", "w", stderr); 
    freopen("output.txt", "w", stdout); 
#endif 
    int n,k;
    cin>>n>>k;
    long arr[n];
    
    long xorrk=0;
    int same[k],diff[k];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i]; 
        if(i<k)
        {
            xorrk^=arr[i];
            same[i]=0;
            diff[i]=0;
        }
    }
     
    for(int i=k;i<n;i++)
    {
        if(arr[i]==arr[i%k])
        {
            same[i%k]+=1;
        }
        else
        {
            diff[i%k]+=1;
        }
    }
    
    int ans=0;
    for(int i=0;i<k;i++)
    {
        ans+=diff[i];
    }
    
    if(xorrk==0)
    {
        cout<<ans<<endl;
    }
    else
    {
        int minn=0;
        for(int i=0;i<k;i++)
        {
            minn=min(minn,same[i]); 
        }
        ans+=(minn+1);
        cout<<ans<<endl;
    }
    
    
}