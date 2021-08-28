#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int arr[30001];
int mm_idx[30001];
int dp[30001];

int call(int a, int b, int h);

int main(){
    
    int n;
    int max = 0, mmlen=0;
    int h1, ptr1;
    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    dp[n-1] = n;
    for(int i=n-2;i>=0;i--) {
        h1 = arr[i];
        dp[i] = n;
        int j = i+1;
        while(j<n){
            if(h1 <= arr[j]){
                dp[i] = j;
                break;
            }
            j = dp[j];
        }

    }

    int sum = 0;
    for(int i=0;i<n-1;) {
        int ptr1 = dp[i];
        if(ptr1 == n){
            int j = i+1;
            while((dp[j] != n)) {
                j = dp[j];
            }
            sum += call(i+1, j-1, arr[j]);
            //cout<<"a: "<<i+1<<" b: "<<j-1<<" arrj:"<<arr[j]<<endl;
            i = j;
            
        }else{
            sum += call(i+1, ptr1-1, arr[i]);
            //cout<<"a1: "<<i+1<<" b1: "<<ptr1-1<<" arri:"<<arr[i]<<endl;
            i = ptr1;
        }
    }


    cout<<"sum: "<<sum<<endl;

}

int call(int a, int b, int h){
    if(a>b) return 0;
    int tmp = 0;
    for(int i=a;i<=b;i++){
        tmp += arr[i];
    }
    return h*(b-a+1)-tmp;
}