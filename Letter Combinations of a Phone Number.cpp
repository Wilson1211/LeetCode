#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include<bits/stdc++.h> 

using namespace std;

void recall(vector<string>&ans ,string *cc){
	vector<string>tmp;
	string tt;
	int i, j;

	if(ans.size()==0){
		for(i=0;i<(*cc).size();i++){
			ans.push_back(string(1,(*cc)[i]));
		}
		return;
	}


	for(i=0;i<ans.size();i++){
		for(j=0;j<(*cc).size();j++){
			tmp.push_back(ans[i]+(*cc)[j]);
		}
	}
	ans.clear();
	ans.assign(tmp.begin(),tmp.end());
}

int main(){
    string tmp;
    vector<string> ans;
    string digits;
    vector<string> phone = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    getline(cin,digits);

    int *ina = new int[digits.size()];
    int i, j;
    for(i=0;i<digits.size();i++){
        tmp = digits[i];
        ina[i] = atoi(tmp.c_str());
    }

    //ans.push_back(phone[ina[0]]);

    for(i=0;i<digits.size();i++){
    	recall(ans,&phone[ina[i]-2]);
    }

    for(i=0;i<ans.size();i++){
    	cout<<ans[i]<<" ";
    }
    cout<<endl;
	return 0;
}