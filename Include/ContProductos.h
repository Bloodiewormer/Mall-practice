#pragma once
#include"Productos.h"

class ConProdutos
{
private:
	Producto** vec;
	int can;
	int tam;
public:
	ConProdutos(int n) {
		vec = new Producto * [n];
		can = 0;
		tam = n;
		//Limpieza del vector
		for (int i = 0; i < tam; i++)
			vec[i] = NULL;
	}

	~ConProdutos() {
		for (int i = 0; i < can; i++) {
			delete vec[i];
		}
		delete[] vec;
	}


	bool ingresarProducto(Producto& prod) {
		if (can < tam) {
			vec[can++] = (Producto*) &prod;
			return true;
		}
		else {
			return false;
		}
	}


	Producto* buscarProductoPorCodigo(string codigo) {
		for (int i = 0; i < can; i++) {
			if (vec[i] != NULL && vec[i]->getCodigo() == codigo) {
				return vec[i];
			}
		}
		return NULL;
	}

	Producto* encontrarProductoDeMenorValor() {
		if (can == 0) {
			return NULL;
		}
		Producto* productoDeMenorValor = vec[0]; 
		for (int i = 1; i < can; i++) {
			if (vec[i]->getPrecio() < productoDeMenorValor->getPrecio()) {
				productoDeMenorValor = vec[i];
			}
		}

		return productoDeMenorValor;

	}
	Producto* encontrarProductoDeMayorValor() {
		if (can == 0) {
			return nullptr; // No hay productos en la lista
		}

		Producto* productoDeMayorValor = vec[0]; // Inicializamos con el primer producto
		for (int i = 1; i < can; i++) {
			if (vec[i]->getPrecio() > productoDeMayorValor->getPrecio()) { // Corrección aquí
				productoDeMayorValor = vec[i];
			}
		}

		return productoDeMayorValor;
	}

	

	string toString() {
		stringstream s;
		s << "-----Listado de Productos-----" << endl;
		for (int i = 0; i < can; i++)
		{
			s << vec[i]->toString() << endl;
		}
		s << "------------------------------" << endl;
		return s.str();

	}


};

