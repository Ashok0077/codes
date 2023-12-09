
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(string str,vector<string> &ans,string substr,int index){
	if(index>=str.length()){
		if(substr.length()>0){
		ans.push_back(substr);
		}
		return;
	}

	solve(str,ans,substr,index+1);

	substr=substr+str[index];

	solve(str,ans,substr,index+1);
}


vector<string> subsequences(string str){
	
	vector<string> ans;
	string substr="";

	solve(str,ans,substr,0);

	return ans;
	
}

int main(){
    
    string s="abc";
    vector<string> ans;
    ans=subsequences(s);
    
    int n=ans.size();
    
    for(int i=0;i<n;i++){
        int m=ans[i].size();
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}