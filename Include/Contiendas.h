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
	Contiendas(int n);
	~Contiendas();

	void seleccionarTiendaYEditarProductos();
	void preguntarSobreProductoporcodigo();
	void crearTienda();
	void eliminarTiendaPorNumero(string numeroTienda);
	void ingresarUnProducto();
	int posDeTiendaNumeroDeTienda(string codT);
	bool existeTiendaConNumero(string codT);
	Tienda* getTiendaEnPosicion(int posicion);
	void mostrarTodasLasTiendas();
	void MostrarTodosLosProductosDeUnaTienda();
	void productoDeMenorValor();
	void productoDeMayorValor();
	void realizarVentaEnTienda();
	void gananciasTotalesPorNTiendas();
	void IngresosTotalesDelMall();
	string toString();
};

