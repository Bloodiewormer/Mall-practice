#pragma once
#include<iostream>
#include<sstream>
using namespace std;

class Producto
{
private:
	string nombreP;
	string codigo;
	int precio;
	int cantProd;
public:
	Producto(): nombreP(""),codigo(""),precio(0),cantProd(0){}
	Producto(string nom, string cod, int pre, int CP)
		:nombreP(nom), codigo(cod), precio(pre), cantProd(CP){}
	virtual ~Producto() {}

	//sets
	

	
	//gets
	int getPrecio() {return precio;}
	string getCodigo() {return codigo;}
	int getCantidad() { return cantProd; }

	void venderP(int cantidad) {
		if (cantidad > 0 && cantidad <= cantProd) {
			cantProd -= cantidad;
		}
	}

	void agregarExistencia(int cantidad) {
		if (cantidad > 0) {
			cantProd += cantidad;
		}
	}

	string toString() {
		stringstream s;
		s << "_______________Producto_____________" << endl
			<< "El nombre del producto es:" << nombreP << endl
			<< "El codigo del producto es:" << codigo << endl
			<< "El precio de este producto es:" << precio << endl
			<< "El stock de este producto es:" << cantProd << endl;

		return s.str();
	}



};
