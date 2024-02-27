#include <iostream>
using namespace std;
bool esta(int lista[],int numero,int n){
	for(int i=0;i<n;i++)
		if(lista[i]==numero){
			cout<<"Esta"<<endl;
			return true;
		}
		cout<<"No esta"<<endl;
	return false;
}
int combinaciones(int digitos,int lista[],int contador){
	if(contador==digitos){
		for(int i=0;i<digitos;i++){
			cout << lista[i]+1 << " ";
		}
		cout<<endl;
	}else{
		for(int j=0;j<digitos;j++){
			cout<<"("<<j+1<<")"<<endl;
			if(!esta(lista,j,contador)){
				lista[contador]=j;
				combinaciones(digitos,lista,contador+1);
			}else{
				cout<<"Salta if"<<endl;
			}
		}
	}
}
int main(){
	int digitos;
	cin>>digitos;
	int lista[digitos];
	combinaciones(digitos,lista,0);
	return 0;
}
