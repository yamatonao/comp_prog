#include <stdio.h>
#include <iostream>

using namespace std;

int main(void){
	long long int w;
	long long int a;
	long long int wa;
	long long int b;
	long long int wb;

	long long int ans;

	scanf("%lld %lld %lld",&w, &a, &b);

	wa = a + w;
	wb = b + w;

	if(wb - wa > 0){
		if(b - wa < 0){ans = 0;}
		else{ans = b - wa;}
	}else{
		if(a - wb < 0){ans = 0;}
		else{ans = a - wb;}
	}

	printf("%lld\n",ans);

	return 0;
}