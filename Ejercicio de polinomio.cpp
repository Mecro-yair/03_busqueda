#include <iostream>
using namespace std;


struct monomio{
	int coef;
	int exp;
};

void ordenaPol(int,monomio[]);
int SecuencialDes(monomio [], int ,monomio);

int main(){
	int n;
	cout << "Digite la cantidad de datos a almacenar:\n"; cin >> n;
	monomio ter[n];
	monomio dato;
	for(int i =0;i<n;i++){
		cout << "Digite el coeficiente para el dato "<<i+1<<" : "; cin >> ter[i].coef;
		cout << "Digite el exponente para el dato "<<i+1<<" : "; cin >> ter[i].exp;	
	}
	ordenaPol(n,ter);
	
	for(int i =0;i<n;i++){
		cout << "\nDato: "<<i+1<<endl;
		cout << "Coeficiente es: "<<ter[i].coef<<" y El exponente es: "<<ter[i].exp;
	}
	
	cout << "\n\nDigite un coeficiente y un exponente a buscar: "; cin>>dato.coef>>dato.exp;
	if(SecuencialDes(ter, n,dato)==-1){
		cout << "Los datos digitados no corresponden al polinomio";
	}else{
		cout << "Los datos digitados coinciden con uno de los elementos del polinomio.";
	}
	return 0;
}

int SecuencialDes(monomio A[], int n,monomio dato) {
    int pos = -1;
    int i = 0;
    while (i <= n && A[i].coef!=dato.coef && A[i].exp!=dato.exp) {
        i = i + 1;
    }
    if (i <= n) {
        pos = i;
    }
    return pos;
}


void ordenaPol(int n,monomio t[]){
	monomio aux[n];
	for(int i=1;i<n;i++){
		for(int j=n-1;j>=i;j--){
			if(t[j].exp < t[j-1].exp){
				aux[j] = t[j];
				t[j] = t[j-1];
				t[j-1]=aux[j];
			}
		}
	}	
}