#include <iostream>
using namespace std;
int cambio(int dinero ,int pt1,int pt2,int pt3,int pt4,int pt5,int pt6,int pt7,int pt8){
	while(dinero!=0){
		while(dinero>=500){
			dinero=dinero-500;
			pt1=pt1+1;
		}
		while(dinero>=200){
			dinero=dinero-200;
			pt2=pt2+1;
		}
		while(dinero>=100){
			dinero=dinero-100;
			pt3=pt3+1;
		}
		while(dinero>=50){
			dinero=dinero-50;
			pt4=pt4+1;
		}
		while(dinero>=25){
			dinero=dinero-25;
			pt5=pt5+1;
		}
		while(dinero>=10){
			dinero=dinero-10;
			pt6=pt6+1;
		}
		while(dinero>=5){
			dinero=dinero-5;
			pt7=pt7+1;
		}
		while(dinero>=1){
			dinero=dinero-1;
			pt8=pt8+1;
		}
	}
	cout<<pt1<<" "<<pt2<<" "<<pt3<<" "<<pt4<<" "<<pt5<<" "<<pt6<<" "<<pt7<<" "<<pt8<<" "<<endl;
}
int main(){
	int dinero;
	int bucle=0;
	int pt1,pt2,pt3,pt4,pt5,pt6,pt7,pt8;
	while(bucle!=1){
		pt1=pt2=pt3=pt4=pt5=pt6=pt7=pt8=0;
		cin>>dinero;
		if(dinero<0){
			bucle=1;
			return 0;
		}
		cambio(dinero,pt1,pt2,pt3,pt4,pt5,pt6,pt7,pt8);
	}
		
	return 0;
}
