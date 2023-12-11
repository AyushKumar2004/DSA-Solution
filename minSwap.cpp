#include<bits/stdc++.h>
using namespace std;

int minSwap(int arr[], int n, int k) {
        int fav=0;
        for(int i=0;i<n;i++){
            if(arr[i]<=k){
                fav++;
            }
        }
        
        int nonFav=0;
        for(int i=0;i<fav;i++){
            if(arr[i]>k){
                nonFav++;
            }
        }
        
        int l=0;
        int r=fav-1;
        int result=INT_MAX;
        while(r<n){
            result=min(result,nonFav);
            r++;
            if(arr[r]>k&&r<n) nonFav++;
            if(arr[l]>k&&l<n) nonFav--;
            l++;
        }
        
        return result==INT_MAX?0:result;
    
    }


int main(){

    int arr[6]={1,4,3,6,2,1};
	int n=6;
    int x=4;
    int z=minSwap(arr,n,x);
    
	cout<<z<<endl;

    return 0;
}