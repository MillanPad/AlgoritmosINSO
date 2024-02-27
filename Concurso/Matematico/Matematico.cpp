#include <iostream>
using namespace std;
bool recursivo(int numero){
	float comprobar;
	comprobar=numero%3;
	if(numero!=1){
		//cout<<numero;
		if(numero-5==0 || numero<0){
			return false;
		}
		if(comprobar==0 && numero!=6){
			return recursivo(numero/3);
		}else if(comprobar!=0 || numero==6){
			return recursivo(numero-5);
		}
	}else{
		return true;
	}
	
}
int main(){
	int numero;
	bool confirma;
	do{
		cin>>numero;
		if(numero==0){
			break;
		}
		confirma=recursivo(numero);
		if(confirma==true){
			cout<<"SI"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}while(1);
	return 0;
}
