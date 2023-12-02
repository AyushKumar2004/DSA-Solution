#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<=1){
            return 0;
        }

        int minPrice=INT_MAX;
        int minProfit=0;

        for(int i=0;i<n;i++){
            if(prices[i]<minPrice){
                minPrice=prices[i];
            }
            else if(prices[i]-minPrice>minProfit){
                minProfit=prices[i]-minPrice;
            }
        }


        return minProfit;
    }



int main(){

    vector<int> nums={1,2,3};

    int x=maxProfit(nums);

    cout<<x<<endl;

    return 0;
}