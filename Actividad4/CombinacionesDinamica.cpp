#include <iostream>
using namespace std;
int fact(int n){
	int i, fact=1;
	for(i = n; i>1;i--){
		fact *= i;
	}
	return fact;
}
int nCr(int n, int r){
	int nume =1, i;
	for(i = n;i>r;i--){
		nume*= i;
	}
	return (nume/fact(n-r));
}

int main(){
	int n=10;
	double matriz[n][n];
	int p,r,bucle=0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<(n-i-1);j++){
			matriz[i][j]=0;
		}
		for(int k = 0; k<(i+1); k++){
			matriz[i][k] = nCr(i,k);
		}
	}
	while(bucle!=1){
		cin>>p>>r;
		if(p<0||r<0){
			bucle=1;
		}else if(p<r){
			cout<<"ERROR";
		}else{
			cout<<matriz[p][r]<<endl;
		}
		
	}
		
}
