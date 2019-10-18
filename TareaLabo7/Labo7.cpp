#include <iostream>

using namespace std;



int main(){
	
	int precios[] = {0,1,5,8,9,10,17,17,20,24,30};
	
	int longitud = 5;
	int r[longitud+1];

	for(int i = 1 ; i <= longitud;i++ ){
		
		r[i] = -1;
		
		for(int j = 1; j <= i; j++ ){
			
			r[i] = max(r[i],precios[j] + r[i-j]);
			
		}
	}
	
	cout<< r[longitud];
	
	return 0;
}
