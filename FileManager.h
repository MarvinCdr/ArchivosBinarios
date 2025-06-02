#include <string>
#include <fstream>
#include <vector>
#include "ProductoFisico.h"

using namespace std;

class FileManager {
public:
	
	static void GuardarProductoFisico(const ProductoFisico& productoFisico, const string& nombreArchivo);
	static ProductoFisico LeerDatosProductoFisico(const string& nombreArchivo);
	static void GuardarListaProductosFisicos(const vector<ProductoFisico>& ListaProductosFisicos, const string& nombreArchivo);
	static vector<ProductoFisico> LeerListaProductosFisicos(const string& nombreArchivo);
	static ostream& write(ostream& out, const ProductoFisico& productoFisico);
	static istream& read(istream& in, ProductoFisico& productoFisico);
};
