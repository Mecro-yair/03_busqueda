#include <iostream>
using namespace std;

int Binaria(int A[], int n, int dato) {
    int izq = 0;
    int der = n;
    int cen = 0;
    int pos = -1;

    while (izq <= der && cen == 0){
        int m = (izq + der) / 2;
        if (A[m] == dato){
            cen = 1;
            pos = m;
        }else{
            if (dato > A[m]) {
                izq = m + 1;
            } else {
                der = m - 1;
            }
        }
    }

    if (cen == 1) {
        return pos;
    } else {
        return -izq;
    }
}

int main() {
	int n,dato;
	cout<<"Posiciones en el arreglo 0,1,2,...\n";
	cout << "Digite la cantidad de datos al arreglo: "; cin>>n;
	int numeros[n];
	for(int i=0;i<n;i++){
		cout<<"Digite numeros de menor a mayor: "; cin >>numeros[i];
	}
	cout <<"Digite el numero a buscar: "; cin>>dato;
  	
    int resultado = Binaria(numeros, n, dato);

    if (resultado >= 0) {
        cout << "El numero " << dato << " se encuentra en la posicion " << resultado << "." <<endl;
    }else{
        cout << "El numero " << dato << " No se ha encontrado  en el arreglo. Deberia estar en la posicion " << -resultado << "." << endl;
    }

    return 0;
}
