#include<stdio.h>
#include<stdbool.h>

bool soma(int a, int b){
	if((a+b) > 5){
		printf("GG\n");
		return true;
	}else{
		printf("GG\n");
		return false;
	}
}

int main(){
	int a = 4;
	int b = 6;
	
	bool s = soma(a,b);
	
	if(s){
		return 0;
	}
}
