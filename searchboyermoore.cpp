#include<bits/stdc++.h>
using namespace std;

void badCharacterOccurance(string pat,unordered_map<char,int> &badchar){
    for(int i=0;i<pat.length();i++){
        badchar[pat[i]]=i;
    }
}

vector<int> searchBoyerMoyer(string txt,string pat){
        vector<int> occurences;
        int n=txt.length();
        int m=pat.length();

        unordered_map<char,int> badchar;
        badCharacterOccurance(pat,badchar);
        int shift=0;

        while(shift<=n-m){
            int j=m-1;
            
            while(j>=0&&pat[j]==txt[shift+j]){
                j--;
            }

            if(j<0){
                occurences.push_back(shift);
                shift+=(shift+m<n)?m-badchar[txt[shift+m]]:1;
            }
            else{
                char badcharKey=txt[shift+j];
                int badcharShift=badchar.count(badcharKey)?badchar[badcharKey]:-1;
                shift+=max(1,j-badcharShift);
            }
        }

        return occurences;
}

int main(){
    
	string txt="AABAACAADAABAABA";
    string pat="AABA";

    vector<int>  ans=searchBoyerMoyer(txt,pat);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
   
    return 0;
}