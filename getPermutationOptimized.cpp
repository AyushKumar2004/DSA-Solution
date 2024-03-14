#include <bits/stdc++.h>
using namespace std;

void getPermutation(int n,int k,set<int> s,string &str,int fact[]){
    
    if(n==0) return;
    int val;
    if(k<=0 || k<=fact[n-1]){
        val=k==0? *s.rbegin():*s.begin();
    }
    else{
        int index=k/fact[n-1];
        k=k%fact[n-1];

        if(k==0) index--;

        val=*next(s.begin(),index);
    }
    str+=to_string(val);
    s.erase(val);
    return getPermutation(n-1,k,s,str,fact);
}

string findkthPermutation(int n,int k){
    
    int fact[10]={1,1,2,6,24,120,720,5040,40320,362880};
    set<int> s;
    for(int i=1;i<=n;i++) s.insert(i);

    string str="";
    getPermutation(n,k,s,str,fact);

    return str;
}


int main()
{   

    string x=findkthPermutation(3,4);
    cout<<x<<endl;
	return 0;
}