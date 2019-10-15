#include <iostream>
#include <string>

using namespace std;

int main(){
	int n,x1,x2,e1,e2;
	
	cout<<"Ingrese tamanio de de las cadenas: ";
	cin>>n;
	
	int a[2][n];
	int f1[n];
	int f2[n];
	int t[2][n-1];
	
	string way1[n];
	string way2[n];
	
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < n; j++){
			cout<<"Ingrese a["<<i<<"]["<<j<<"]: ";
			cin>>a[i][j];
		}
	}
	
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < n - 1; j++){
			cout<<"Ingrese t["<<i<<"]["<<j<<"]: ";
			cin>>t[i][j];
		}
	}
	
	cout<<"Ingrese x1: ";
	cin>>x1;
	
	cout<<"Ingrese x2: ";
	cin>>x2;
	
	cout<<"Ingrese e1: ";
	cin>>e1;
	
	cout<<"Ingrese e2: ";
	cin>>e2;
	
	f1[0] = e1 + a[0][0];
	f2[0] = e2 + a[1][0];
	
	way1[0] = "a" + to_string(1) + "," + to_string(1);
	way2[0] = "a" + to_string(2) + "," + to_string(1);
	
	for(int i = 1 ; i < n;i++){
		if(f1[i-1] + a[0][i] <= f2[i-1] + t[1][i-1] + a[0][i]){
			f1[i] = f1[i-1] + a[0][i];
			way1[i] =way1[i-1]  + " " + "a" + to_string(1) + "," + to_string(i + 1); 
		}else{
			f1[i] = f2[i-1] + t[1][i-1] + a[0][i];
			way1[i] = way2[i-1] + " " + "a" + to_string(1) + "," + to_string(i + 1); 
		}
		
		if(f2[i-1] + a[1][i] <= f1[i - 1] + t[0][i-1] + a[1][i] ){
			f2[i] = f2[i-1] + a[1][i];
			way2[i] =way2[i-1] + " " +  "a" + to_string(2) + "," + to_string(i + 1); 
		}else{
			f2[i] = f1[i - 1] + t[0][i-1] + a[1][i]; 
			way2[i] = way1[i-1] + " " + "a" + to_string(2) + "," + to_string(i + 1);
		}
	}
	
	if(f1[n-1] + x1 < f2[n-1] + x2 ){
		cout<<f1[n-1] + x1<<endl;
		
		cout<<"Camino: ";
		
		cout<<way1[n-1]<<" ";
		
	}else{
		cout<<f2[n-1] + x2<<endl;
		
		cout<<"Camino: ";
		
		cout<<way2[n-1]<<" ";
		
	}
	
	
	return 0;
}
