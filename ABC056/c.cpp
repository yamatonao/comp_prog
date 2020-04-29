#include <stdio.h>
#include <iostream>

using namespace std;

int main(void){
	long long int x;
	long long int sum;
	long long int ans;

	scanf("%lld", &x);

	for(long long int i = 0 ; sum < x; i++){
		sum += i;
		ans = i;
	}
	printf("%lld\n", ans);

	return 0;
}