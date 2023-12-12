#include<bits/stdc++.h>
using namespace std;

int find_median(vector<int> v)
		{
		    sort(v.begin(),v.end());
		    int n=v.size();
		    int ans=0;
		    if(n%2==0){
		        int mid=n/2-1;
		        ans=(v[mid]+v[mid+1])/2;
		    }
		    else{
		        int mid=n/2;
		        ans=v[mid];
		    }
		    
		    return ans;
		}


int main(){

    vector<int> arr={1,4,3,6,2,3};
    int z=find_median(arr);
    
	cout<<z<<endl;

    return 0;
}