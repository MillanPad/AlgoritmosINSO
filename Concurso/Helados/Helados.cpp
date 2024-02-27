#include <iostream>
#include <string>
//El valor 1 es la C y el 2 la V
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

void conversion(int todo,int helados[][],char helado[]){
	for(int i=0;i<todo;i++){
		if(lista->getValor(i)==1){
			helado[i]='C';
		}else if(lista->getValor(i)==2){
			helado[i]='V';
		}	
	}
}
int main(){
	int casos;
	int chocolate, vainilla;
	int combinaciones=0;
	cin>>casos;
	for(int i=0;i<casos;i++){
		cin>>chocolate;
		cin>>vainilla;
		char helado[chocolate+vainilla-1];
		int helados[chocolate+vainilla-1][chocolate+vainilla-1];
		if(chocolate+vainilla<=15){
				combinaciones=nCr(chocolate,vainilla);
				for(int j=0;j<chocolate;j++){
					for(int k=0;k<vainilla;k++){
						
					}
				}
			}else{
				combinaciones=nCr(vainilla,chocolate);
			}
			cout<<endl;
		}
	}
	return 0;
}
