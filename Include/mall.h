#pragma once
#include "contiendas.h"

class Mall{
private:
	string Nombre;
	Contiendas* Contienda;//flecha
public:
	Mall() {
		Nombre = "";
		Contienda = new Contiendas(100); // Crear una instancia de Contiendas
	}
	virtual ~Mall() {
		delete[] Contienda;
	}
	
	void SetNombre(string nuevoNombre) {Nombre = nuevoNombre;}
	string getNombre() {return Nombre; }


	void crearTienda() {
		Contienda->crearTienda();

	}

	void IngresarUnProducto() {
		Contienda->ingresarUnProducto();
	}

	void preguntarPorTiendaPorNTienda(){
		string numTienda;
		cout << "Ingrese el número de tienda que desea buscar: ";
		cin >> numTienda;
		// Verificar si la tienda con el número ingresado existe
		if (Contienda->existeTiendaConNumero(numTienda)) {
			int pos = Contienda->posDeTiendaNumeroDeTienda(numTienda);
			cout << "Información de la tienda #" << numTienda << ":" << endl;
			cout << Contienda->getTiendaEnPosicion(pos)->toString() << endl;
		}
		else {
			cout << "La tienda con número " << numTienda << " no existe." << endl;
		}
	}

	void MostrarTodasLasTiendas() {
		Contienda->mostrarTodasLasTiendas();
	}
	
	void TodosLosProductosPorNTienda() {
		Contienda->MostrarTodosLosProductosDeUnaTienda();
	}

	void productoDeMayorValor() {
		Contienda->productoDeMayorValor();
	}

	void productoDeMenorValor() {
		Contienda->productoDeMenorValor();
	}
	void preguntarSobreProductoporcodigo() {
		Contienda->preguntarSobreProductoporcodigo();
	}

	void seleccionarTiendaYEditarProductos() {
		Contienda->seleccionarTiendaYEditarProductos();
	}
	void IngresosTotalesDelMall() {
		Contienda->IngresosTotalesDelMall();
	}

	void gananciasTotalesPorNTiendas() {
		Contienda->gananciasTotalesPorNTiendas();
	}

	void realizarVenta() {
		Contienda->realizarVentaEnTienda();
	}
	void eliminarTienda() {
		string num;
		cout << "ingrese el numero de tienda que desea eliminar"; cin >> num;
		Contienda->eliminarTiendaPorNumero(num);
	}
	void eliminarProducto() {

	}
};

