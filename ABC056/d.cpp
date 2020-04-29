#include <stdio.h>
#include <iostream>

using namespace std;

int main(void){
	long long int n;
	long long int k;
	long long int a[10000];

	scanf("%lld %lld", &n, &k);
	for(long long int i; i < n; i++){
		scanf("%lld", &(a[i]) );
	}

	return 0;
}