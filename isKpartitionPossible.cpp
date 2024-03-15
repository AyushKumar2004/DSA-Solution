#include <bits/stdc++.h>
using namespace std;

bool solve(int a[],int n,int k,int ans,int index,int sum,int visit[],int &cnt){
        
        if(sum>ans) return false;
        
        if(index>=n) return false;
        
        if(sum==ans){
            cnt++;
            return true;
        }
        
        for(int i=index;i<n;i++){
            
            if(visit[i]==1) continue;
            
            visit[i]=1;
            
            int possible=solve(a,n,k,ans,index+1,sum+a[i],visit,cnt);
            
            if(possible) return true;
            
            visit[i]=0;
        }
        return false;
    }
  
bool isKPartitionPossible(int a[], int n, int k){   
        int cnt=0;
        if(k==1) return true;
        int ans=0;
        for(int i=0;i<n;i++) ans+=a[i];
        int visit[n]={0};
        if(ans%k) return false;
        sort(a,a+n,greater<int>());
        for(int i=0;i<k;i++){
            solve(a,n,k,ans/k,0,0,visit,cnt);
        }
        
        if(cnt==k) return true;
        
        return false;
}


int main()
{   
    int a[5]={1,2,4,5,6};
    int n=5;
    int k=3;
    cout<<isKPartitionPossible(a,n,k);
	return 0;
}