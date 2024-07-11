#include "Contiendas.h"

Contiendas::Contiendas(int n) {
	// Initialize your resources here
	vec = new Tienda * [n];
	can = 0;
	tam = n;
	ventas = new ContVentas(100);  // Inicializa el objeto ContVentas
	for (int i = 0; i < tam; i++)
		vec[i] = NULL;
}

Contiendas::~Contiendas() {
	delete ventas;  // Limpia la memoria al destruir Contiendas
	for (int i = 0; i < can; i++) {
		delete vec[i];
	}
	delete[] vec;

}

void Contiendas::seleccionarTiendaYEditarProductos() {

	string numeroTienda;
	cout << "Ingrese el numero de la tienda que desea editar: ";
	cin >> numeroTienda;

	// Busca si existe la tienda con el n�mero ingresado
	for (int i = 0; i < can; i++) {
		if (vec[i]->getNumeroDeTienda() == numeroTienda) {
			vec[i]->agregarExistenciaDeProducto();
			return; // Tienda encontrada y producto actualizado, salir del metodo
		}
	}

	cout << "La tienda con numero " << numeroTienda << " no existe en el Mall." << endl;
}

void Contiendas::preguntarSobreProductoporcodigo() {

	string numeroTienda;
	cout << "Ingrese el numero de la tienda que desea consultar: ";
	cin >> numeroTienda;

	// Busca si existe la tienda con el n�mero ingresado
	for (int i = 0; i < can; i++) {
		if (vec[i]->getNumeroDeTienda() == numeroTienda) {
			vec[i]->preguntarSobreProductoporcodigo();
			return; // Tienda encontrada, salir del m�todo
		}
	}
	cout << "La tienda con n�mero " << numeroTienda << " no existe en el Mall." << endl;
}

void Contiendas::crearTienda() {

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
			cout << "El arreglo de tiendas est� lleno." << endl;
			delete tien;
		}
	}
	else {
		cout << "Esa tienda ya existe." << endl;
	}
}

void Contiendas::eliminarTiendaPorNumero(string numeroTienda) {

	int posicion = -1;

	// Busca la posici�n de la tienda con el n�mero especificado
	for (int i = 0; i < can; i++) {
		if (vec[i]->getNumeroDeTienda() == numeroTienda) {
			posicion = i;
			break;
		}
	}

	if (posicion != -1) {
		// La tienda con el n�mero especificado existe, la eliminamos
		delete vec[posicion];

		// Desplazamos las tiendas restantes para llenar el espacio eliminado
		for (int i = posicion; i < can - 1; i++) {
			vec[i] = vec[i + 1];
		}

		can--; // Decrementamos la cantidad de tiendas
		cout << "La tienda con n�mero " << numeroTienda << " ha sido eliminada." << endl;
	}
	else {
		cout << "La tienda con n�mero " << numeroTienda << " no existe en el Mall." << endl;
	}
}

void Contiendas::ingresarUnProducto() {

	int pos = -1;
	string codT;
	cout << "Ingrese el numero de tienda donde desea ingresar el Producto: ";
	cin >> codT;

	// Verifica si la tienda con el n�mero ingresado existe
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
		cout << "La tienda con n�mero " << codT << " no existe." << endl;
	}
}

int Contiendas::posDeTiendaNumeroDeTienda(string codT) {

	for (int i = 0; i < can; i++)
		if (vec[i]->getNumeroDeTienda() == codT)
			return i;
	return -1;
}

bool Contiendas::existeTiendaConNumero(string codT) {

	for (int i = 0; i < can; i++)
		if (vec[i]->getNumeroDeTienda() == codT)
			return true;
	return false;
}

Tienda* Contiendas::getTiendaEnPosicion(int posicion) {

	if (posicion >= 0 && posicion < can) {
		Tienda* tienda = vec[posicion];
		return tienda;
	}
	else {
		cout << "Posici�n fuera de rango." << endl;
		return nullptr;
	}
}

void Contiendas::mostrarTodasLasTiendas() {

	if (can == 0) {
		cout << "No hay tiendas registradas en el Mall." << endl;
	}
	else {
		cout << "Informaci�n de todas las tiendas:" << endl;
		for (int i = 0; i < can; i++) {
			cout << "Tienda #" << i + 1 << ":" << endl;
			cout << vec[i]->toString() << endl;
		}
	}
}

void Contiendas::MostrarTodosLosProductosDeUnaTienda() {
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

void Contiendas::productoDeMenorValor() {

	string numeroTienda;
	cout << "Ingrese el n�mero de tienda que desea consultar: ";
	cin >> numeroTienda;

	// Busca si existe la tienda con el n�mero ingresado
	for (int i = 0; i < can; i++) {
		if (vec[i]->getNumeroDeTienda() == numeroTienda) {
			vec[i]->toString();
			vec[i]->productoDeMenorValor();
			return; // Tienda encontrada, salir del m�todo
		}
	}

	cout << "La tienda con n�mero " << numeroTienda << " no existe en el Mall." << endl;
}

void Contiendas::productoDeMayorValor() {

	string numeroTienda;
	cout << "Ingrese el n�mero de tienda que desea consultar: ";
	cin >> numeroTienda;

	// Busca si existe la tienda con el n�mero ingresado
	for (int i = 0; i < can; i++) {
		if (vec[i]->getNumeroDeTienda() == numeroTienda) {
			vec[i]->toString();
			vec[i]->productoDeMayorValor();
			return; // Tienda encontrada, salir del m�todo
		}
	}

	cout << "La tienda con n�mero " << numeroTienda << " no existe en el Mall." << endl;
}

void Contiendas::realizarVentaEnTienda() {

	string numeroTienda;
	cout << "Ingrese el n�mero de la tienda en la que desea realizar la venta: ";
	cin >> numeroTienda;

	for (int i = 0; i < can; i++) {
		if (vec[i]->getNumeroDeTienda() == numeroTienda) {
			string codP;
			int cant;
			cout << "Ingrese el c�digo del producto: ";
			cin >> codP;
			cout << "Ingrese la cantidad: ";
			cin >> cant;
			vec[i]->realizarVenta(codP, cant, numeroTienda);
			return;
		}
	}

	cout << "La tienda con n�mero " << numeroTienda << " no existe en el Mall." << endl;
}

void Contiendas::gananciasTotalesPorNTiendas() {

	string numeroTienda;
	cout << "Ingrese el n�mero de tienda para calcular ganancias: ";
	cin >> numeroTienda;

	int posicion = posDeTiendaNumeroDeTienda(numeroTienda);

	if (posicion != -1) {
		// La tienda con el n�mero especificado existe
		vec[posicion]->gananciasTotalesPorNTiendas();
	}
	else {
		cout << "La tienda con n�mero " << numeroTienda << " no existe en el Mall." << endl;
	}
}

void Contiendas::IngresosTotalesDelMall() {

	int ingresosTotales = ventas->IngresosTotalesDelMall();
	cout << "Los ingresos totales del mall son: " << ingresosTotales << endl;
}

string Contiendas::toString() {

	stringstream s;
	s << "-------------Listado-------------" << endl;
	for (int i = 0; i < can; i++)
		s << vec[i]->toString() << endl;
	s << "---------------------------------" << endl;
	return s.str();
}