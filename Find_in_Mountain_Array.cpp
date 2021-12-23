//https://leetcode.com/problems/find-in-mountain-array/
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

    long sz;
    
    long dir(long id, MountainArray &mountainArr){
        long rr, ll, mid;
        mid = mountainArr.get(id);
        rr = mountainArr.get(id+1);
        ll = mountainArr.get(id-1);
        if(ll<mid && mid>rr){
            return 0;
        }else{
            if(ll>mid){
                return -1;
            }else{
                return 1;
            }
        }
    }
    
    long find_max(MountainArray &mountainArr){
        long rr_id = mountainArr.length()-1;
        long ll_id = 0;
        long mid_id = (ll_id+rr_id)/2;
        
        long rr, ll, mid;
        long indx = dir(mid_id, mountainArr);
        while(indx!=0){
            if(indx > 0){ // go right
                ll_id = mid_id+1;
            }else{ // go left
                rr_id = mid_id;
            }
            mid_id = (ll_id+rr_id)/2;
            indx = dir(mid_id, mountainArr);
        }
        //cout<<"mid_id: "<<mid_id<<endl;
        return mid_id;
    }
    
    long find_target(int &target, long &max_id, long lr, MountainArray &mountainArr){

        if(lr == 0 && target < mountainArr.get(0)){
            return -1;
        }else if(lr == 1 && target < mountainArr.get(sz-1)){
            return -1;
        }
        
        long rr_id, ll_id, mid_id;
        long rr, ll, num;
        if(lr == 0){
            rr_id = max_id;
            ll_id = 0;
        }else{
            rr_id = sz-1;
            ll_id = max_id;
        }
        mid_id = (ll_id+rr_id)/2;
        long flag = 0;
        while(mid_id != ll_id) {
            //rr = mountainArr.get(rr_id);
            //ll = mountainArr.get(ll_id);
            num = mountainArr.get(mid_id);

            if(num == target){
                break;
            }
            if(num<target){
                if(lr==0){
                    ll_id = mid_id;
                }else{
                    rr_id = mid_id;
                }
            }else{
                if(lr == 0){
                    rr_id = mid_id;
                }else{
                    ll_id = mid_id;
                }
            }
            mid_id = (ll_id+rr_id)/2;
        }
        if(num != target){
            num = mountainArr.get(rr_id);
            if(num == target){
                flag = 1;
                mid_id = rr_id;
            }
        }else{
            flag = 1;
        }
        cout<<"mid_id: "<<mid_id<<" ll_id: "<<ll_id<<" rr_id: "<<rr_id<<endl;
        if(flag){
            return mid_id;
        }else{
            return -1;
        }
    }


    int findInMountainArray(int target, MountainArray &mountainArr) {
        sz = mountainArr.length();
        long num;
        num = mountainArr.get(0);
        if(num==target) return 0;
        else{
            int rr, ll;
            int rr_id, ll_id, mid_id;
            rr_id = sz-1;
            ll_id = 0;
            mid_id = (ll_id+rr_id)/2;
            rr = mountainArr.get(rr_id);
            ll = mountainArr.get(ll_id);
            num = mountainArr.get(mid_id);
            long max, max_id;
            // first find the max;
            max_id = find_max(mountainArr);
            // find num on the left side of max
            mid_id = find_target(target, max_id, 0, mountainArr);
            
            if(mid_id != -1) {
                return mid_id;
            }
            // find right side of max
            mid_id = find_target(target, max_id, 1, mountainArr);
            if(mid_id != -1) {
                return mid_id;
            }

            return -1;
        }
    }