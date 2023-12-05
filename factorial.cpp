#include<bits/stdc++.h>
using namespace std;

vector<int> multiply(vector<int> &result,int x){
        int carry =0;
        for(int i=0;i<result.size();i++){
            int product=result[i]*x+carry;
            result[i]=product%10;
            carry=product/10;
        }
        
        while(carry){
            result.push_back(carry%10);
            carry=carry/10;
        }
        
        return result;
    }

    vector<int> factorial(int N){
       vector<int> result;
       result.push_back(1);
       for(int i=2;i<=N;i++){
           result=multiply(result,i);
       }
       
       reverse(result.begin(),result.end());
       return result;
    }


int main(){

    int N=5;
    vector<int> ans=factorial(N);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }
    return 0;
}