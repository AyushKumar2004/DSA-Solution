#include<bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int,int> m1;
    
    for(int i=0;i<n;i++){
        m1[a1[i]]++;
    }
    
    for(int i=0;i<m;i++){
        if(m1.find(a2[i])==m1.end()||m1[a2[i]]==0){
            return "No";
        }
        
        m1[a2[i]]--;
    }
    
    return "Yes";
}


int main(){

    int a1[8]={11, 7, 1, 13, 21, 3, 7, 3};
	int n=8;
    int a2[5]={11, 3, 7, 1, 7};
    int m=5;
    string x=isSubset(a1,a2,n,m);
    cout<<x<<endl;
	

    return 0;
}