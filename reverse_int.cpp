#include <iostream>
using namespace std;
int reverse(int x) {
    int minus=0;
    if (x<0){
        x = -x;
        minus=1;
    }
    long long int y=0;
    int r=0;
    while(1){
        r=x%10;
        y = y*10+r;
        x = x/10;
        if(x==0){break;}
    }
    if(minus==1){y = -y;}
    return y;
}

int main(void){
	
	cout<<reverse(-1235)<<endl;
	return 0;
	
}