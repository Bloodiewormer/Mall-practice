#pragma once
#include"Ventas.h"

class ContVentas
{
private:
	Ventas** vec;
	int can;
	int tam;
public:
	ContVentas(int n) {
		vec = new Ventas * [n];
		can = 0;
		tam = n;
		//Limpieza del vector
		for (int i = 0; i < tam; i++)
			vec[i] = NULL;
	}

	~ContVentas() {
		for (int i = 0; i < can; i++) {
			delete vec[i];
		}
		delete[] vec;
	}
	int gananciasTotalesPorNTiendas(string numeroTienda) {
		int gananciasTotales = 0;

		for (int i = 0; i < can; i++) {
			if (vec[i]->getNumeroDeTienda() == numeroTienda) {
				// El producto pertenece a la tienda seleccionada, suma su precio a las ganancias totales
				gananciasTotales += vec[i]->getPrecio();
			}
		}

		cout << "Las ganancias totales de la tienda " << numeroTienda << " son: " << gananciasTotales << endl;

		return gananciasTotales;
	}

	int IngresosTotalesDelMall() {
		int ingresosTotales = 0;

		for (int i = 0; i < can; i++) {
			Ventas* venta = vec[i];
			ingresosTotales += (venta->getPrecio() * venta->getUnidadesVendidas());
		}

		return ingresosTotales;
	}

	bool ingresarVentas(string codigo, int precio, int cantVendida,string NumeroDeTienda) {
		if (can < tam) {
			Ventas* venta = new Ventas(codigo, precio, cantVendida, NumeroDeTienda);
			vec[can++] = venta;
			return true;
		}
		else {
			return false;
		}
	}



	string toString() {
		stringstream s;
		s << "-----Listado de Ventas-----" << endl;
		for (int i = 0; i < can; i++)
		{
			s << vec[i]->toString() << endl;
		}
		s << "------------------------------" << endl;
		return s.str();

	}


};