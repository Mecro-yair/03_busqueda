#include <iostream>
#include <string>
using namespace std;

struct Fecha{
    int dia;
	int mes; 
	int anio;
};

struct Personal{
    string dni;
	string nombre;
    Fecha fechaNacimiento;  
};

void ordenaPorFecha(Personal [], int);
bool compararFechas(Fecha, Fecha);
int Binaria(Personal [], int,Personal);

int main(){
    int n;
    cout << "Digite la cantidad de personas: "; cin >> n;
    Personal personas[n];
    Personal dato;
    for(int i = 0; i < n; i++){
        cout << "DNI: "; cin >> personas[i].dni;
        cout << "Nombre: "; cin.ignore(); getline(cin, personas[i].nombre); //en una linea para simplificar codigo
        cout << "Dia de nacimiento: "; cin >> personas[i].fechaNacimiento.dia;
        cout << "Mes de nacimiento: "; cin >> personas[i].fechaNacimiento.mes;
        cout << "Año de nacimiento: "; cin >> personas[i].fechaNacimiento.anio;
        cout << "----------------------------"<<endl;
    }

    cout << "\nOrdenado por fecha de nacimiento\n";
    ordenaPorFecha(personas, n);
    for(int i = 0; i < n; i++){
        cout << personas[i].dni << " " << personas[i].nombre << " " 
             << personas[i].fechaNacimiento.dia << "/" << personas[i].fechaNacimiento.mes 
             << "/" << personas[i].fechaNacimiento.anio << endl;
    }
    cout << "\nDigite la fecha a buscar: \n"; 
    cout << "Digite el dia: "; cin >>dato.fechaNacimiento.dia;
    cout << "Digite el mes: "; cin >>dato.fechaNacimiento.mes;
    cout << "Digite el año: "; cin >>dato.fechaNacimiento.anio;
    if (Binaria(personas, n,dato)<0){
    	cout << "La fecha digitada no existe.\nSi existiera estaria en la posicion "<<-(Binaria(personas, n,dato))<<"."<<endl;
	}else{
		cout << "La fecha digitada si existe en el arreglo.";
	}
    
    return 0;
}
int Binaria(Personal A[], int n,Personal dato) {
    int izq = 0;
    int der = n;
    int cen = 0;
    int pos = -1;

    while (izq <= der && cen == 0){
        int m = (izq + der) / 2;
        if (A[m].fechaNacimiento.dia == dato.fechaNacimiento.dia && A[m].fechaNacimiento.mes == dato.fechaNacimiento.mes && A[m].fechaNacimiento.anio == dato.fechaNacimiento.anio){
            cen = 1;
            pos = m;
        }else{
            if (dato.fechaNacimiento.dia > A[m].fechaNacimiento.dia || dato.fechaNacimiento.mes > A[m].fechaNacimiento.mes || dato.fechaNacimiento.anio > A[m].fechaNacimiento.anio) {
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

void ordenaPorFecha(Personal a[], int n) {
    Personal aux;
    int j;
    for (int i=1; i<n;i++) {
        aux = a[i]; 
        j = i-1;
        while (j>=0 && compararFechas(aux.fechaNacimiento, a[j].fechaNacimiento)) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = aux;
    }
}


bool compararFechas(Fecha a, Fecha b) {
    if (a.anio != b.anio) {
        return a.anio < b.anio;
	}
    if (a.mes != b.mes){
        return a.mes < b.mes;
	} 
    return a.dia < b.dia;
}

