#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <stdlib.h> 
#include <string>
using namespace std;


int main(){
   	//vector<vector<int>> fourSum(vector<int>& nums, int target) {}
	int i, j, k,target;
	string input;
	string ttarget;
	string tmp;
	vector<int> nums;
	getline(cin,input);
	getline(cin,target);
	input += ' ';
	for(i=0;i<input.size();i++){
		if(input)
	}
	while(i<input.size()){
		if(input[i]==' '){
			tmp = input.substr(j,i);
			nums.push_back(atoi(tmp.c_str()));
		}
		i++;
	}
	target = atoi(ttarget.c_str());
	sort(nums.begin(),nums.end());
	
	return 0;
}