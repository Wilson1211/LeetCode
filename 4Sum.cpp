#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <stdlib.h> 
#include <string>
using namespace std;

vector<vector<int>> ans;

void find3sum(vector<int> &nums,int begin,int target){
	int i, j, k;
	int tt;
	//extern vector<vector<int>> ans;
	//vector<int> tmp;
	for(i=begin+1;i<nums.size()-2;i++){
		j = i+1;
		k = nums.size()-1;
		tt = target - nums[i];
		while(j<k){
			if(nums[j]+nums[k] == tt){
				//tmp.push_back(nums[begin],nums[i],nums[j],nums[k]);
				vector<int> tmp = {nums[begin],nums[i],nums[j],nums[k]};
				ans.push_back(tmp);
				tmp.clear();
				k--;
				while(nums[k]==nums[k+1]){k--;}
				while(nums[j]==nums[j+1]){j++;}
			}else if(nums[j]+nums[k]>tt){
				k--;
			}else{
				j++;
			}
		}
	}
}

int main(){
   	//vector<vector<int>> fourSum(vector<int>& nums, int target) {}
	int i=0, j=0, k=0,target;
	string input;
	string ttarget;
	string tmp;
	vector<int> nums;
	//vector<vector<int>> ans;
	getline(cin,input);
	getline(cin,ttarget);
	input += ' ';
	int negflag=1;
	while(i<input.size()){
		if(input[i]==' '){
			//if(negflag==-1){j++;}
			tmp = input.substr(j,i);
			nums.push_back(negflag*atoi(tmp.c_str()));
			negflag *= negflag;
			j = i+1;
		}else if(input[i]=='-'){
			negflag = -1;
			j = i+1;
		}
		i++;
		//j=i;
	}
	target = atoi(ttarget.c_str());
	//sort(nums.begin(),nums.begin()+nums.size());
	sort(nums.begin(),nums.end());
	for(i=0;i<nums.size();i++){
		find3sum(nums,i,target-nums[i]);
	}

	vector<int>::iterator it;
	for(i=0;i<ans.size();i++){
		for(it = ans[i].begin();it!=ans[i].end();it++){
			cout<<*it<<" ";
		}
		cout<<endl;
	}
	return 0;
}