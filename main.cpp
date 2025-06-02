#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdexcept>
#include <vector>
#include "FileManager.h"

using namespace std;

int main() {
	
	try {
		srand (time(NULL));
		
		ProductoFisico productoFisico1;
		productoFisico1.setNombre("PS5 Juego: Call of Duty");
		productoFisico1.setTipo("PS5");
		productoFisico1.setPeso(500);
		productoFisico1.setPrecio(59);
		
		ProductoFisico productoFisico2;
		productoFisico2.setNombre("PS5 Juego: Fifa");
		productoFisico1.setTipo("PS5");
		productoFisico2.setPeso(rand() % 500);
		productoFisico2.setPrecio(rand() % 59 + 100);
		
		FileManager fileManager;
		
		fileManager.GuardarProductoFisico(productoFisico1, "Juegos1.dat");
		
		ProductoFisico datosProductoFisico = fileManager.LeerDatosProductoFisico("Juegos1.dat");
		
		cout << "[Leer Archivo Binario]" << endl;
		cout << datosProductoFisico << endl;
		
		vector<ProductoFisico> ListaProductosFisicos;
		ListaProductosFisicos.push_back(productoFisico1);
		ListaProductosFisicos.push_back(productoFisico2);
		fileManager.GuardarListaProductosFisicos(ListaProductosFisicos, "Juegos2.dat");
		
		vector<ProductoFisico> DatosListaProductosFisicos = fileManager.LeerListaProductosFisicos("Juegos2.dat");
		
		cout << "[Leer Vector Archivo Binario]" << endl;
		for (auto &productoFisico : ListaProductosFisicos) {
			cout << productoFisico << endl;
		}
		
	} catch (exception& ex) {
		cerr << ex.what() << '\n' << endl;
	}
	return 0;
}
