#pragma once
#include"ContVentas.h"
#include"ContProductos.h"
class Tienda
{
private:
	string nombret;
	string numTienda;
	ContVentas* Vent;
	ConProdutos* contP;
public:
	Tienda() {
		nombret = "Departamento de Ventas.";
		numTienda = "0001";
		Vent = new ContVentas(100);  // Crear un objeto ContVentas
		contP = new ConProdutos(100);  // Crear un objeto ConProdutos
	}

	Tienda(string NT, string nom) {
		nombret = nom;
		numTienda = NT;
		Vent = new ContVentas(100);  // Crear un objeto ContVentas
		contP = new ConProdutos(100);  // Crear un objeto ConProdutos
	}
	~Tienda() {
		delete Vent;  // Eliminar el objeto ContVentas
		delete contP;  // Eliminar el objeto ConProdutos
	}

	string getNumeroDeTienda() { return numTienda; }

	bool ingreseUnProducto() {
		string nP;
		string cod;
		int pre;
		int cP;
		cout << "NO USE ESPACIOS" << endl;
		cout << "Ingrese el nombre del Producto...";
		cin >> nP;
		cout << "Ingrese el codigo del producto...";
		cin >> cod;
		if (contP->buscarProductoPorCodigo(cod) != nullptr) {
			cout << "El producto con el código " << cod << " ya existe en esta tienda." << endl;
			return false; 
		}
		cout << "Ingrese el precio del producto...";
		cin >> pre;
		cout << "Ingrese la existencia del producto...";
		cin >> cP;
		Producto* Prod1 = new Producto(nP, cod, pre, cP);
		contP->ingresarProducto(*Prod1);
		return true; 
	}
	

	void MostrarTodosLosProductosDeUnaTienda(string numeroTienda) {
		if (numTienda == numeroTienda) {
			cout << "Productos de la tienda " << numeroTienda << ":" << endl;
			cout << contP->toString();
		}
		else {
			cout << "La tienda con número " << numeroTienda << " no coincide con esta tienda (" << numTienda << ")." << endl;
		}
	}
	//void agrgarExistenciaDeProducto(string codigoProducto, int cantidad) {
	//	Producto* producto = contP->buscarProductoPorCodigo(codigoProducto);

	//	if (producto != nullptr) {
	//		producto->agregarExistencia(cantidad);
	//		cout << "Se agregaron " << cantidad << " unidades al producto " << codigoProducto << "." << endl;
	//	}
	//	else {
	//		cout << "Producto no encontrado." << endl;
	//	}
	//}
	
	void agregarExistenciaDeProducto() {
		string codigo;
		int cantidad;

		cout << "Ingrese el código del producto: ";
		cin >> codigo;

		Producto* producto = contP->buscarProductoPorCodigo(codigo);

		if (producto != nullptr) {
			cout << "Ingrese la cantidad a agregar: ";
			cin >> cantidad;
			producto->agregarExistencia(cantidad);
			cout << "Existencia actualizada con éxito." << endl;
		}
		else {
			cout << "Producto no encontrado." << endl;
		}
	}

	void preguntarSobreProductoporcodigo() {
		string codigo;
		cout << "Ingrese el código del producto que desea consultar: ";
		cin >> codigo;

		Producto* producto = contP->buscarProductoPorCodigo(codigo);

		if (producto != nullptr) {
			cout << "Información del producto con código " << codigo << ":" << endl;
			cout << producto->toString() << endl;
		}
		else {
			cout << "Producto no encontrado." << endl;
		}
	}
	

	void productoDeMayorValor() {
		Producto* productoMayorValor = contP->encontrarProductoDeMayorValor();
		if (productoMayorValor != NULL) {
			cout << "Producto de mayor valor en la tienda " << numTienda << ":" << endl;
			cout << productoMayorValor->toString() << endl;
		}
		else {
			cout << "No hay productos en esta tienda." << endl;
		}
	}

	void productoDeMenorValor() {
		Producto* productoMenorValor = contP->encontrarProductoDeMenorValor();
		if (productoMenorValor != NULL) {
			cout << "Producto de menor valor en la tienda " << numTienda << ":" << endl;
			cout << productoMenorValor->toString() << endl;
		}
		else {
			cout << "No hay productos en esta tienda." << endl;
		}
	}

	void realizarVenta(string codP, int cant,string CDT) {
		// Buscar el producto por código
		Producto* producto = contP->buscarProductoPorCodigo(codP);
		if (producto != nullptr) {
			if (cant <= producto->getCantidad()) {
				int precioUnitario = producto->getPrecio();
				int montoTotal = cant * precioUnitario;
				string codigoDeTienda = (CDT); 
				Vent->ingresarVentas(codP, cant, montoTotal, codigoDeTienda);
				producto->venderP(cant);
				cout << "Venta realizada con éxito. Monto total: " << montoTotal << endl;
			}
			else {
				cout << "No hay suficiente stock para realizar esta venta." << endl;
			}
		}
		else {
			cout << "Producto no encontrado." << endl;
		}
	}
	void gananciasTotalesPorNTiendas() {
		Vent->gananciasTotalesPorNTiendas(numTienda);
	}

	void IngresosTotalesDelMall() {
		Vent->IngresosTotalesDelMall();

	}
	string toString() {
		stringstream s;
		s << "_______________Tienda_____________" << endl
			<< "El nombre de la tienda es:" << nombret << endl
			<< "El Numero de la tienda es:" << numTienda << endl
			<< "__________________________________";

		//falta
		return s.str();
	}


};