#include<iostream>

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
 int n, p;
 double comb;
 cin>>n>>p;

 if(p>n){
 	cout<<"ERROR";
 }else{
 	comb=nCr(n,p);
 	cout<<comb;
 }
 return 0; 
}
