#include<bits/stdc++.h>
using namespace std;

const int no_of_char=256;
    
    string smallestWindow (string s, string p)
    {
        int l1=s.length();
        int l2=p.length();
        
        int start=0;
        int start_index=-1;
        int min_len=INT_MAX;
        int count=0;
        
        int mp1[no_of_char]={0};
        int mp2[no_of_char]={0};
        
        for(int i=0;i<l2;i++){
            mp1[p[i]]++;
        }
        
        for(int j=0;j<l1;j++){
            mp2[s[j]]++;
            
            if(mp2[s[j]]<=mp1[s[j]]){
                count++;
            }
            
            if(count==l2){
                while(mp2[s[start]]>mp1[s[start]]||mp1[s[start]]==0){
                    if(mp2[s[start]]>mp1[s[start]]) mp2[s[start]]--;
                    start++;
                }
                
                int len_window=j-start+1;
                if(min_len>len_window){
                    min_len=len_window;
                    start_index=start;
                }
            }
        }
        if(start_index==-1){
            return "-1";
        }
        return s.substr(start_index,min_len);
    }

int main(){
    
	string s="timetopractice";
    string p="toc";

    cout<<smallestWindow(s,p)<<endl;
   
    return 0;
}