#include <stdio.h>
#include <iostream>

using namespace std;

int main(void){
	char first;
	char second;
	scanf("%c %c",&first,&second);
	
	if(first == 'H' && second == 'H'){
		printf("H\n");
	}else if(first == 'H' && second == 'D'){
		printf("D\n");
	}else if(first == 'D' && second == 'H'){
		printf("D\n");
	}else{
		printf("H\n");
	}

	return 0;
}