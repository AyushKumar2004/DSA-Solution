#include<bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int N)
    {
        unordered_set<int> st;
        int longest=1;
        for(int i=0;i<N;i++){
            st.insert(arr[i]);
        }
        
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int cnt=1;
                int x=it;
                while(st.find(x+1)!=st.end()){
                    x=x+1;
                    cnt=cnt+1;
                }
                
                longest=max(longest,cnt);
            }
        }
        
        return longest;
    }


int main(){

    int arr[4]={2,3,-2,4};
	int n=4;
	int x=findLongestConseqSubseq(arr,n);
	cout<<x<<endl;

    return 0;
}