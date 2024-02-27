#include<iostream>
using namespace std;

void ordenarInsercion(int x[],int len)
{
	int valor_ayuda=0;
	int posicion=0;
  	for(int i=1;i<len;i++){
    	valor_ayuda=x[i];
    	posicion = i -1;
    	while(((posicion)>=0) && (x[posicion]> valor_ayuda)){
    		x[posicion+1]=x[posicion];
    		posicion--;
		}
    	x[posicion+1] = valor_ayuda;
		
    

      /*No tener en cuenta el siguiente bucle de impresion  para el calculo de la complejidad*/
    	for(int k=0;k<len;k++)
			cout<<x[k]<<" ";
    	cout<<endl;
    }  
}


int main()
{
 int n;
 cin>>n;
 int *x=new int[n];
 for(int i=0;i<n;i++)
   cin>>x[i];
 ordenarInsercion(x,n);
}


