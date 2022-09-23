#include <iostream>
#include <conio.h>
#include "Invitado.h"
using namespace std;
bool ingresoInvitado(Invitado *vec);
bool egresoInvitado(Invitado vec[]);
int main(){
int opc;
Invitado invitados[5];
int contInvitados = 0;

  while (true) {
    system("cls");
  cout<< "1 - CARGAR INVITADOS"<<endl;
  cout<< "2 - INGRESO DE INVITADO"<<endl;
  cout<< "3 - EGRESO DE INVITADO"<<endl;
  cout<< "4 - LISTA DE INVITADOS"<<endl;
  cout<< "0 - SALIR" <<endl;
  cin >> opc;
  switch (opc) {
    case 1:
    {
      if(contInvitados<5){
      invitados[contInvitados].cargarInvitado();
      cout << "SE CARGO INVITADO: " << invitados[contInvitados].getNombre() << endl;
      contInvitados++;
      system("pause>nul");
      }
    }
    break;
    case 2:
    {
      bool var = ingresoInvitado(invitados);
      if (var) {
        cout << "SE CARGO HORARIO DE ENTRADA" << endl;
      system("pause>nul");
      }
    }
      break;
    case 3:
    {
      bool var = egresoInvitado(invitados);
      if (var) {
        cout << "SE CARGO HORARIO DE SALIDA" << endl;
        system("pause>nul");
      }
    }
      break;
    case 4:
    {
      for (int i = 0; i < 5; i++) {
        if (invitados[i].getEstado()) {
          invitados[i].mostrarInvitado();
        };
      }
      system("pause>nul");
    }
      break;
    case 0:
      return 0;
      break;
    }
  }
}

/// FUNCIONES ///>
bool ingresoInvitado(Invitado vec[]) {
  int dni, cont=0;
  string nombre;
  float horaIngreso;

  cout << "Ingrese el DNI del Invitado: " << endl;
  cin >>dni;
  cout << "Ingrese el Nombre del Invitado: " << endl;
  cin.ignore();
  getline(cin, nombre);
  cout << "Ingrese Hora de Ingreso: " << endl;
  cin >> horaIngreso;
  while (cont <5) {
    if (vec[cont].getDNI() == dni) {
      vec[cont].setEntrada(horaIngreso);
      return true;
    }
      cont++;
  }
  return false;
}

bool egresoInvitado(Invitado vec[]) {
  int dni, cont = 0;
  float horaEgreso;

  cout << "Ingrese el DNI del Invitado: " << endl;
  cin >> dni;
  cout << "Ingrese Hora de Egreso: " << endl;
  cin >> horaEgreso;
  while (cont < 5) {
    if (vec[cont].getDNI() == dni && vec[cont].getEntrada() != -1) {
      vec[cont].setSalida(horaEgreso);
      return true;
    }
    cont++;
  }
  return false;
}