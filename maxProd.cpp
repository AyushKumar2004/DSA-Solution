#include<bits/stdc++.h>
using namespace std;

long long maxProduct(vector<int> arr, int n) {
	   long long maxi=arr[0];
	   long long mini=arr[0];
	   long long ans=arr[0];
	   long long choice1,choice2;
	   for(int i=1;i<n;i++){
	        choice1=maxi*arr[i];
	        choice2=mini*arr[i];
	        maxi=max((long long)arr[i],max(choice1,choice2));
	        mini=min((long long)arr[i],min(choice2,choice1));
	        ans=max(maxi,ans);
	   }
	   
	   return ans;
	}


int main(){

    vector<int> arr={2,3,-2,4};
	int n=arr.size();
	long long x=maxProduct(arr,n);
	cout<<x<<endl;

    return 0;
}