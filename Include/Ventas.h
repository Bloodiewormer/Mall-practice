#pragma once
#include<iostream>
#include<sstream>
using namespace std;

class Ventas
{
private:
	string codigo;
	int precio;
	int cantVendida;
	string NumeroDeTienda;
public:
	Ventas(string cd, int pr, int CV,string NT)
		: codigo(cd), precio(pr), cantVendida(CV), NumeroDeTienda(NT){}
	~Ventas(){}

	string getNumeroDeTienda() { return NumeroDeTienda; }
	int getUnidadesVendidas() { return cantVendida; }
	int getPrecio() { return precio; }
	string getCodigo() { return codigo; }
	string toString() {
		stringstream s;
		s << "se ha vendido un total de: " << cantVendida << "unidades";
		return s.str();
	}

};

