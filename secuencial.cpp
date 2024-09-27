#include <iostream>
using namespace std;

int SecuencialDes(int [], int , int );
int SecuencialOrd(int [], int , int );
int main(){
	int dato,n; 
	int arreglo[]={1,2,3,4,5,6};
    cout << "Digite la cantidad de numeros del arreglo:"; cin >> n;
	int numeros[n];
    for(int i=0;i<n;i++){
        cout << "Digite el numero para la posicion: "<<i<<" del arreglo:\n";
        cin >> numeros[i];
    }

	cout << "Digite un numero a buscar: ";
	cin >> dato;
	if(SecuencialDes(numeros,n,dato)==-1){
		cout << "No se han encontrado resultados.";
	}else{
		cout << "El numero "<<dato<<" se encuentra en al posicion ("<<SecuencialDes(numeros,n,dato)<<") del arreglo";
	}
	
	cout <<"\n\nDe este arreglo ordenado: arreglo[]={1,2,3,4,5,6}\nDigite un numero a buscar: ";cin >>dato;
	if(SecuencialOrd(arreglo,6,dato)<0){
		cout <<"No se ha encontrado resultados.";
	}else{
		cout << "El numero "<<dato<<" se encuentra en al posicion ("<<SecuencialOrd(arreglo,6,dato)<<") del arreglo";
	}
	return 0;
}

int SecuencialDes(int A[], int n, int dato) {
    int pos = 0;
    int i = 0;
    while (i <= n && A[i] != dato) {
        i = i + 1;
    }
    if (i <= n) {
        pos = i;
        return pos;
    }
    return -1;
}

int SecuencialOrd(int A[], int n, int dato){
    int i = 0;
    int pos = 0;
    while (i <= n && A[i] < dato) {
        i = i + 1;
    }
    if (i > n || A[i] > dato) {
        pos = -i;
    } else {
        pos = i;
    }

    return pos;
}