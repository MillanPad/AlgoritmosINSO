#include <iostream>
#include <cstring>
using namespace std;
void ordenar(int *x,int len){
  int permutacion;
  for(int i=1;i<len;i++){
		for(int j=1;j<(len);j++){
			if(x[j-1]>x[j]){
        		permutacion=x[j-1];
        		x[j-1]=x[j];
        		x[j]=permutacion;
			}
		}
	}
}

int main(){
	int cantidad;
	double resistencia;
	int casos;
	int coches =0;
	int contador=0;
	cin>>casos;
	for(int i=0;i<casos;i++){
		cin>>cantidad;
		cin>>resistencia;
		int *pilas=new int[cantidad];
		for(int j=0;j<cantidad;j++){
			cin>>pilas[j];
		}
		ordenar(pilas,cantidad);
		while(cantidad>=2){
			if(contador==cantidad-1)
				break;
			if(pilas[contador]+pilas[cantidad-1]>=resistencia){
				coches++;
				memmove(&pilas[contador],&pilas[contador+1],sizeof(int)*(cantidad-1-contador));
				pilas[cantidad-1]=0;
				cantidad-=2;
				contador=0;
			}
			contador++;
		}
		if(cantidad>=2){
			if(pilas[0]+pilas[1]>=resistencia)
				coches++;
		}
		contador=0;
		cout<<coches<<endl;
		coches=0;
		pilas=NULL;
		delete[] pilas;
	}
}
