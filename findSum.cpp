#include <bits/stdc++.h>
using namespace std;

bool check(int p,int n){
            int temp=p,f=5,count=0;
            while(f<=temp){
                count+=temp/f;
                f=f*5;
            }
            if(count>=n) return 1;
            
            return 0;
        }
    
int findNum(int n){   
                if(n==1) return 5;
                int start=0;
                int end=5*n;
                int ans;
                while(start<=end){
                    int mid=start+(end-start)/2;
                    if(check(mid,n)){
                        end=mid-1;
                        ans=mid;
                    }
                    else{
                        start=mid+1;
                    }
                }
                return ans;
}

int main(){

	cout<<findNum(100)<<endl;
    
	return 0;
}