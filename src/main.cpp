#include "Mall.h"
int main() {
    string Nombre, nuevoNombre;
    int opcion;
    Mall* mall = new Mall();
    cout<<"Ingrese el nuevo nombre del centro comercial : "; cin >> nuevoNombre;mall->SetNombre(nuevoNombre);
    do {system("cls");
        do {
            cout << "Bienvenido al "<< mall->getNombre() <<"MALL" << endl << endl;
            cout << "\t~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~" << endl << endl;
            cout << "\t ( 1  ) Ingresar Nueva Tienda " << endl << endl;
            cout << "\t ( 2  ) Ingresar Nuevo Producto " << endl << endl;
            cout << "\t ( 3  ) Preguntar Por Tienda" << endl << endl;
            cout << "\t ( 4  ) Ganancias De Tiendas" << endl << endl;
            cout << "\t ( 5  ) Mostrar Todos Los Productos De Una Tienda" << endl << endl;
            cout << "\t ( 6  ) Mostrar Todas Las Tiendas" << endl << endl;
            cout << "\t ( 7  ) Ingresos Totales Del Mall" << endl << endl;
            cout << "\t ( 8  ) Agregar Existencia De Producto" << endl << endl;
            cout << "\t ( 9  ) Preguntar por Producto" << endl << endl;
            cout << "\t ( 10 ) Producto De Mayot Valor" << endl << endl;
            cout << "\t ( 11 ) Producto De Menor Valor " << endl << endl;
            cout << "\t ( 12 ) Realizar Venta " << endl << endl;
            cout << "\t ( 13 ) Eliminar Tienda" << endl << endl;
            cout << "\t ( 14 ) Eliminar Producto" << endl << endl;
            cout << "\t ( 15 ) Salir" << endl << endl;
            cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
            cout << "Opcion -> "; cin >> opcion; cout << endl;
        } while (opcion < 1 || opcion > 15);
        switch (opcion) {
        case 1: {
            system("cls");
            mall->crearTienda();
            system("pause");
            break;
        }
        case 2: {
            system("cls");
            mall->IngresarUnProducto();
            system("pause");
            break;
        }
        case 3: {
            system("cls");
            mall->preguntarPorTiendaPorNTienda();
            system("pause");
            break;
        }
        case 4: {
            system("cls");
            mall->gananciasTotalesPorNTiendas();
            system("pause");
            break;
        }
        case 5: {
            system("cls");
            mall->TodosLosProductosPorNTienda();
            system("pause");
            break;
        }case 6: {
            system("cls");
            mall->MostrarTodasLasTiendas();
            system("pause");
            break;
        }case 7: {
            system("cls");
            mall->IngresosTotalesDelMall();
            system("pause");
            break;
        }case 8: {
            system("cls");
            mall->seleccionarTiendaYEditarProductos();
            system("pause");
            break;
        }case 9: {
            system("cls");
            mall->preguntarSobreProductoporcodigo();
            system("pause");
            break;
        }case 10: {
            system("cls");
            mall->productoDeMayorValor();
            system("pause");
            break;
        }case 11: {
            system("cls");
            mall->productoDeMenorValor();
            system("pause");
            break;
        }case 12: {
            system("cls");
            mall->realizarVenta();
            system("pause");
            break;
        }case 13: {
            system("cls");
            mall->eliminarTienda();
            system("pause");
            break;
        }case 14: {
            system("cls");
            mall->eliminarProducto();
            system("pause");
            break;
        }
        }
    } while (opcion != 15);
    system("cls");
    cout << "Vuelva Pronto" << endl << endl;
    system("pause");
    delete mall;
    return 0;
}