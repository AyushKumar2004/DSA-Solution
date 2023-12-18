#include<bits/stdc++.h>
using namespace std;

string longestPalin (string S) {
        int n=S.length();
        int start=0;
        int end=1;
        int low,high;
        for(int i=1;i<n;i++){
            low=i-1;
            high=i;
            while(low>=0&&high<n&&S[low]==S[high]){
                if(high-low+1>end){
                    start=low;
                    end=high-low+1;
                }
                low--;
                high++;
            }
            
            low=i-1;
            high=i+1;
            while(low>=0&&high<n&&S[low]==S[high]){
                if(high-low+1>end){
                    start=low;
                    end=high-low+1;
                }
                low--;
                high++;
            }
        }
        
        return S.substr(start,end);
    }

	

int main(){
    
	string S="aaaabbaa";
	string z=longestPalin(S);
	cout<<z<<endl;
    return 0;
}