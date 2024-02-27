#include<iostream>
using namespace std;

void ordenarSeleccion(int x[],int len)
{
	int permutacion=0;
	int minimo=0;
  	for(int i=0;i<len ;i++){
  		minimo=i;
    	for(int j = i +1  ; j < len   ; j++){
       		if(x[minimo] > x[j]){
        	    minimo=j;	
			}
        }
		permutacion=x[i];
		x[i]=x[minimo];
		x[minimo]=permutacion;
    
    
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
 ordenarSeleccion(x,n);
}

