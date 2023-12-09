#include<bits/stdc++.h>
using namespace std;

int maxProfit(int prices[],int n){
    int* profit=new int[n];

    for(int i=0;i<n;i++){
        profit[i]=0;
    }

    int maxi=prices[n-1];
    for(int i=n-2;i>=0;i--){
        if(maxi<prices[i]){
            maxi=prices[i];
        }

        profit[i]=max(profit[i+1],maxi-prices[i]);
    }

    int mini=prices[0];
    for(int i=1;i<n;i++){
        if(mini>prices[i]){
            mini=prices[i];
        }

        profit[i]=max(profit[i-1],profit[i]+(prices[i]-mini));
    }

    int result=profit[n-1];
    delete []profit;

    return result;
}


int main(){

    int arr[7]={2, 30, 15, 10, 8, 25, 80};
	int n=7;
    int k=4;
	int x=maxProfit(arr,n);
    cout<<x<<endl;
	

    return 0;
}