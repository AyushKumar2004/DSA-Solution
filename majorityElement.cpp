#include<bits/stdc++.h>
using namespace std;

int majorityElement(int a[], int size)
    {
        
        unordered_map<int,int> m;
        for(int i=0;i<size;i++){
            m[a[i]]++;
        }
        
        for(auto it:m){
            if(it.second>size/2){
                return it.first;
            }
        }
        
        return -1;
        
    }

int main(){
    
	int a[5]={3,2,3,1,3};
    int size=5;
    cout<<majorityElement(a,size)<<endl;

    return 0;
}