#pragma once
#include <iostream>
#include <string>
using namespace std;

class Invitado
{
private:
  string _nombre;
  int _dni;
  float _horaEntrada;
  float _horaSalida;
  bool _estado;
  int _cantInvitados;
  
public:
  //ctor
  Invitado() {
    _nombre = " ";
    _dni = 0;
    _horaEntrada = -1;
    _horaSalida = -1;
    _estado = false;
    _cantInvitados = 0;
  }

  void setNombre(string nombre) {_nombre = nombre;}
  void setDNI(int dni) {_dni = dni;}
  void setEntrada(float entrada) {_horaEntrada = entrada;}
  void setSalida(float salida) {_horaSalida = salida;}
  void setEstado(bool estado) { _estado = estado; }

  string getNombre() { return _nombre; }
  int getDNI() { return _dni; }
  float getEntrada() {return  _horaEntrada ; }
  float getSalida() {return  _horaSalida; }
  bool getEstado() {return _estado; }

  void cargarInvitado() {
    if (_cantInvitados < 5){
    cout << "Ingrese NOMBRE: " << endl;
    cin.ignore();
    getline(cin, _nombre);
    cout << "Ingrese DNI: " << endl;
    cin >> _dni;
    _estado = true;
    _cantInvitados++;
    }
    else {
      cout << "Ya se cargaron los 5 invitados" << endl;
    }
  }
  void mostrarInvitado() {
    if (_estado==true){
      cout << "INVITADO: " << _nombre << endl;
      cout << "DNI: " << _dni << endl;
      if(_horaEntrada != -1){
        cout << "INGRESO A LAS: " << _horaEntrada<<endl;
      }
      else {
        cout << "NO FUE AL EVENTO."<<endl;
      }
      if (_horaSalida != -1 && _horaEntrada != -1) {
        cout << "EGRESO A LAS: " << _horaSalida << endl;
        cout << "ESTUVO: " << _horaSalida - _horaEntrada << endl;
      }
      else if(_horaEntrada != -1 && _horaSalida ==-1) {
        cout << "AUN PERMANECE EN EL EVENTO." << endl;
      }
        cout << "-----------------------------------" << endl;
    }
  }

  
};

