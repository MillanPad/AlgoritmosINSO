#include <iostream>
using namespace std;
void raizCuadrada(float numero,float medio,float error){
	float aux;
	cout<<medio<<endl;
	aux =(medio*medio)-numero;
	if(aux>error || aux<0){
		if(aux>numero){
			raizCuadrada(numero,medio/2,error);
		}else{
			raizCuadrada(numero,medio+(-aux)/2,error);
		}
	}else{
		return;
	}
}
int main(){
	float numero,error;
	cin>>numero;
	cin>>error;
	while(!(numero>=1||0<=error<1)){
		cout<<"ERROR"<<endl;
		cin>>numero;
		cin>>error;
	}
	raizCuadrada(numero,numero/2,error);
	return 0;
}
