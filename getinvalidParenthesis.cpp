#include <bits/stdc++.h>
using namespace std;

int getMinParenthesis(string s){
        stack<char> st;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push('(');
            }
            else if(s[i]==')'){
                if( !st.empty() && st.top()=='('){
                    st.pop();
                }
                else{
                    st.push(')');
                }
            }
        }

        return st.size();
    }

    void solve(string s,unordered_map<string,int> &us,vector<string> &ans,int mra){
        if(us[s]!=0){
            return;
        }else{
            us[s]++;
        }
        if(mra<0){
            return;
        }
        if(mra==0){
            if(!getMinParenthesis(s)){
                ans.push_back(s);
            }
            return ;
        }
        
        for(int i=0;i<s.length();i++){
            if (s[i] != '(' && s[i] != ')') continue;
            string left=s.substr(0,i);
            string right=s.substr(i+1);
            solve(left + right,us,ans,mra-1);
        }
        return;
    }

    vector<string> removeInvalidParentheses(string s) {

        int mra=getMinParenthesis(s);
        unordered_map<string,int> us;
        vector<string> ans;
        solve(s,us,ans,mra);
        return ans;
        
    }

int main(){

    string s="()())()";
    vector<string> ans=removeInvalidParentheses(s);

    for(auto it:ans){
        cout<<it<<endl;
    }

	return 0;
}