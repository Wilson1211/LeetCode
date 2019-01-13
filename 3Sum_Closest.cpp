#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
//class Solution {
//public:
//    int threeSumClosest(vector<int>& nums, int target) {
int main(){
	    int i=0, j, k;
	    int s1=0,s2=0;    	

	    // input
		vector<int> nums;
		string ss;
		string tmp;
		int target;
		getline(cin,ss);
		ss+=" ";
		while(s1<ss.size()){
			if(ss[s1]==' '){
				tmp=ss.substr(s2,s1-s2);
				j = atoi(tmp.c_str());
				nums.push_back(j);
				s2=s1;
			}
			s1++;
		}
		cin >> target;

		sort(nums.begin(),nums.end());
		int min=abs(nums[0]+nums[1]+nums[2]-target);
		int min_value=nums[0]+nums[1]+nums[2];
		int value;
    	vector<int> store;
    	
 		for(i=0;i<nums.size()-2;i++){
 			j=i+1;
 			k = nums.size()-1;
 			while(j<k){
 				value = nums[i]+nums[j]+nums[k];
 				if(abs(value-target)<min){
 					min = abs(value-target);
 					min_value=value;
 				}else if(value>target){
 					k--;
 				}else{
 					j++;
 				}
 			}
 		}
 		cout<<min_value<<endl;
		return 0;
}
    
//};