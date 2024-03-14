#include <bits/stdc++.h>
using namespace std;

void getPermutation(vector<string> &result,string str,int index){
    int n=str.length();

    if(index==n){
        result.push_back(str);
        return;
    }


    for(int i=index;i<n;i++){
        swap(str[i],str[index]);
        getPermutation(result,str,index+1);
        swap(str[i],str[index]);
    }
}

string findkthPermutation(int n,int k){
    string str="";
    vector<string> result;
    for(int i=1;i<=n;i++){
        str.push_back(i+'0');
    }

    getPermutation(result,str,0);
    sort(result.begin(),result.end());
    
    return result[k-1];

}


int main()
{   

    string x=findkthPermutation(3,4);
    cout<<x<<endl;
	return 0;
}