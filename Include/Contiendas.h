#pragma once
#include "Tienda.h"

class Contiendas
{
private:
	Tienda** vec;
	int can;
	int tam;
	ContVentas* ventas;

public:
	Contiendas(int n) {
		vec = new Tienda * [n];
		can = 0;
		tam = n;
		ventas = new ContVentas(100);  // Inicializa el objeto ContVentas
		for (int i = 0; i < tam; i++)
			vec[i] = NULL;
	}
	~Contiendas() {
		delete ventas;  // Limpia la memoria al destruir Contiendas
		for (int i = 0; i < can; i++) {
			delete vec[i];
		}
		delete[] vec;
	}

	void seleccionarTiendaYEditarProductos() {
		string numeroTienda;
		cout << "Ingrese el número de la tienda que desea editar: ";
		cin >> numeroTienda;

		// Busca si existe la tienda con el número ingresado
		for (int i = 0; i < can; i++) {
			if (vec[i]->getNumeroDeTienda() == numeroTienda) {
				vec[i]->agregarExistenciaDeProducto();
				return; // Tienda encontrada y producto actualizado, salir del método
			}
		}

		cout << "La tienda con número " << numeroTienda << " no existe en el Mall." << endl;
	}

	void preguntarSobreProductoporcodigo() {
		string numeroTienda;
		cout << "Ingrese el número de tienda que desea consultar: ";
		cin >> numeroTienda;

		// Busca si existe la tienda con el número ingresado
		for (int i = 0; i < can; i++) {
			if (vec[i]->getNumeroDeTienda() == numeroTienda) {
				vec[i]->toString();
				vec[i]->preguntarSobreProductoporcodigo();
				return; // Tienda encontrada, salir del método
			}

		}
	}
	void crearTienda() {
		string numT;
		string nomT;

		cout << "Ingrese el codigo de la tienda: ";
		cin >> numT;
		if (!existeTiendaConNumero(numT)) {
			cout << "Ingrese el nombre de la tienda: ";
			cin >> nomT;

			Tienda* tien = new Tienda(numT, nomT);
			if (can < tam) {
				vec[can++] = tien;
			}
			else {
				cout << "El arreglo de tiendas está lleno." << endl;
				delete tien;
			}
		}
		else {
			cout << "Esa tienda ya existe." << endl;
		}
	}

	void eliminarTiendaPorNumero(string numeroTienda) {
		int posicion = -1;

		// Busca la posición de la tienda con el número especificado
		for (int i = 0; i < can; i++) {
			if (vec[i]->getNumeroDeTienda() == numeroTienda) {
				posicion = i;
				break;
			}
		}

		if (posicion != -1) {
			// La tienda con el número especificado existe, la eliminamos
			delete vec[posicion];

			// Desplazamos las tiendas restantes para llenar el espacio eliminado
			for (int i = posicion; i < can - 1; i++) {
				vec[i] = vec[i + 1];
			}

			can--; // Decrementamos la cantidad de tiendas
			cout << "La tienda con número " << numeroTienda << " ha sido eliminada." << endl;
		}
		else {
			cout << "La tienda con número " << numeroTienda << " no existe en el Mall." << endl;
		}
	}



	void ingresarUnProducto() {
		int pos = -1;
		string codT;
		cout << "Ingrese el numero de tienda donde desea ingresar el Producto: ";
		cin >> codT;

		// Verifica si la tienda con el número ingresado existe
		for (int i = 0; i < can; i++) {
			if (vec[i]->getNumeroDeTienda() == codT) {
				pos = i;
				break; // Tienda encontrada, sal del bucle
			}
		}

		if (pos != -1) {
			vec[pos]->ingreseUnProducto(); // La tienda existe, ingresa el producto
		}
		else {
			cout << "La tienda con número " << codT << " no existe." << endl;
		}
	}

	int posDeTiendaNumeroDeTienda(string codT) {
		for (int i = 0; i < can; i++)
			if (vec[i]->getNumeroDeTienda() == codT)
				return i;
		return -1;
	}


	bool existeTiendaConNumero(string codT) {
		for (int i = 0; i < can; i++)
			if (vec[i]->getNumeroDeTienda() == codT)
				return true;
		return false;
	}
	
	Tienda* getTiendaEnPosicion(int posicion) {
		if (posicion >= 0 && posicion < can) {
			Tienda* tienda = vec[posicion];
			return tienda;
		}
		else {
			cout << "Posición fuera de rango." << endl;
			return nullptr;
		}
	}
	void mostrarTodasLasTiendas() {
		if (can == 0) {
			cout << "No hay tiendas registradas en el Mall." << endl;
		}
		else {
			cout << "Información de todas las tiendas:" << endl;
			for (int i = 0; i < can; i++) {
				cout << "Tienda #" << i + 1 << ":" << endl;
				cout << vec[i]->toString() << endl;
			}
		}
	}

	void MostrarTodosLosProductosDeUnaTienda() {
		string numeroTienda;
		cout << "Ingrese el número de tienda que desea consultar: ";
		cin >> numeroTienda;

		// Busca si existe la tienda con el número ingresado
		for (int i = 0; i < can; i++) {
			if (vec[i]->getNumeroDeTienda() == numeroTienda) {
				vec[i]->toString();
				vec[i]->MostrarTodosLosProductosDeUnaTienda(numeroTienda);
				return; // Tienda encontrada, salir del método
			}
		}

		cout << "La tienda con número " << numeroTienda << " no existe en el Mall." << endl;
	}
	void productoDeMenorValor() {
		string numeroTienda;
		cout << "Ingrese el número de tienda que desea consultar: ";
		cin >> numeroTienda;

		// Busca si existe la tienda con el número ingresado
		for (int i = 0; i < can; i++) {
			if (vec[i]->getNumeroDeTienda() == numeroTienda) {
				vec[i]->toString();
				vec[i]->productoDeMenorValor();
				return; // Tienda encontrada, salir del método
			}
		}

		cout << "La tienda con número " << numeroTienda << " no existe en el Mall." << endl;

	}
	void productoDeMayorValor() {
		string numeroTienda;
		cout << "Ingrese el número de tienda que desea consultar: ";
		cin >> numeroTienda;

		// Busca si existe la tienda con el número ingresado
		for (int i = 0; i < can; i++) {
			if (vec[i]->getNumeroDeTienda() == numeroTienda) {
				vec[i]->toString();
				vec[i]->productoDeMayorValor();
				return; // Tienda encontrada, salir del método
			}
		}

		cout << "La tienda con número " << numeroTienda << " no existe en el Mall." << endl;

	}
	void realizarVentaEnTienda() {
		string numeroTienda;
		cout << "Ingrese el número de la tienda en la que desea realizar la venta: ";
		cin >> numeroTienda;

		for (int i = 0; i < can; i++) {
			if (vec[i]->getNumeroDeTienda() == numeroTienda) {
				string codP;
				int cant;
				cout << "Ingrese el código del producto: ";
				cin >> codP;
				cout << "Ingrese la cantidad: ";
				cin >> cant;
				vec[i]->realizarVenta(codP, cant,numeroTienda);
				return;
			}
		}

		cout << "La tienda con número " << numeroTienda << " no existe en el Mall." << endl;
	}
	
	void gananciasTotalesPorNTiendas() {
		string numeroTienda;
		cout << "Ingrese el número de tienda para calcular ganancias: ";
		cin >> numeroTienda;

		int posicion = posDeTiendaNumeroDeTienda(numeroTienda);

		if (posicion != -1) {
			// La tienda con el número especificado existe
			vec[posicion]->gananciasTotalesPorNTiendas();
		}
		else {
			cout << "La tienda con número " << numeroTienda << " no existe en el Mall." << endl;
		}
	}
	void IngresosTotalesDelMall() {
		
		int ingresosTotales = ventas->IngresosTotalesDelMall();
		cout << "Los ingresos totales del mall son: " << ingresosTotales << endl;
	}
	string toString() {
		stringstream s;
		s << "-------------Listado-------------" << endl;
		for (int i = 0; i < can; i++)
			s << vec[i]->toString() << endl;
		s << "---------------------------------" << endl;
		return s.str();
	}

};


