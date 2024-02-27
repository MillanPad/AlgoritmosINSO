#include<iostream>
using namespace std;

void  combinar (int a[ ] , int len_a , int b[ ] , int len_b , int c[ ])
{
  /*Añadir código que permite combinar dos arrays */
  	int i=0,j=0,k=0;
  	while((i<len_a) && (j<len_b)){
  		if(a[i]<= b[j]){
  			c[k] = a[i];
  			i++;
		}else{
			c[k] = b[j];
			j++;
		}
		k++;
  	}
 	while(i< len_a){
 		c[k] = a[i];
  		i++;
  		k++;
  	}
  	while(j<len_b){
  		c[k] = b[j];
		j++;
		k++;	
	}
}


void ordenarMergeSort (int x[], int len)
{
  int temp[len];
  if (len==1){
		return;
	}else
    {
      /*Ordenar dos mitades */
		int mitad = len/2;
      /*Combinar ambas mitades y guardarlo en temp */
		int *a = new int[mitad];
		int *b = new int[len-mitad];
		for(int i = 0;i<mitad;i++){
			a[i] = x[i];
		}
		for(int j=mitad;j<len;j++){
			b[j-mitad] = x[j];
		}
      /*Copiar del array temporal al array resultado */
      ordenarMergeSort(a,mitad);
      ordenarMergeSort(b,len-mitad);
      combinar(a,mitad,b,len-mitad,temp);
      for (int k = 0; k < len; k++)
	{
	  x[k] = temp[k];
	  cout<<x[k]<<" ";
	}
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
 ordenarMergeSort(x,n);
}

