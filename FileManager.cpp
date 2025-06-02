#include "FileManager.h"

void FileManager::GuardarProductoFisico(const ProductoFisico &productoFisico, const string &nombreArchivo) {
	
	ofstream miArchivo(nombreArchivo, ios::binary);
	write(miArchivo, productoFisico);
	miArchivo.close();
}
ProductoFisico FileManager::LeerDatosProductoFisico(const string &nombreArchivo) {
	
	ProductoFisico productoFisico;
	ifstream LeerArchivo(nombreArchivo, ios::binary);
	
	if (!LeerArchivo.is_open()) {
		throw invalid_argument("No se puede leer el archivo:  [" + nombreArchivo + "]");
	}
	
	LeerArchivo.seekg (0);
	read(LeerArchivo, productoFisico);
	LeerArchivo.close();
	
	return productoFisico;
}

void FileManager::GuardarListaProductosFisicos(const vector<ProductoFisico> &ListaProductoFisico, const string &nombreArchivo) {
	
	ofstream miArchivo(nombreArchivo, ios_base::binary);
	for (auto &productoFisico : ListaProductoFisico) {
		write(miArchivo, productoFisico);
	}
	miArchivo.close();
}

vector<ProductoFisico> FileManager::LeerListaProductosFisicos(const string &nombreArchivo) {
	vector<ProductoFisico> ListaProductosFisicos;
	ProductoFisico productoFisico;
	ifstream LeerArchivo(nombreArchivo, ios::binary);
	
	if (!LeerArchivo.is_open()) {
		throw invalid_argument("No se puede abrir el archivo [" + nombreArchivo + "]");
	}
	LeerArchivo.seekg (0);
	while(LeerArchivo.good()){
		read(LeerArchivo, productoFisico);
		if (productoFisico.getNombre() != "") {
			ListaProductosFisicos.push_back(productoFisico);
		}
	}
	
	LeerArchivo.close();
	
	return ListaProductosFisicos;
}

ostream &FileManager::write(ostream &out, const ProductoFisico &productoFisico) {
	double precio = productoFisico.getPrecio();
	double peso = productoFisico.getPeso();
	
	size_t len = productoFisico.getNombre().size();
	out.write((char*)&len, sizeof(len));
	out.write(productoFisico.getNombre().c_str(), len);
	
	len = productoFisico.getTipo().size();
	out.write((char*)&len, sizeof(len));
	out.write(productoFisico.getTipo().c_str(), len);
	
	out.write((char*)(&precio), sizeof(productoFisico.getPrecio()));
	out.write((char*)(&peso), sizeof(productoFisico.getPeso()));
	
	return out;
}

istream &FileManager::read(istream &in, ProductoFisico &productoFisico) {
	double precio = 0.0, peso = 0.0;
	
	size_t len = 0;
	string nombre;
	in.read((char*)&len, sizeof(len));
	nombre.resize(len);
	in.read(&nombre[0], len);
	productoFisico.setNombre(nombre);
	
	len = 0;
	string tipo;
	in.read((char*)&len, sizeof(len));
	tipo.resize(len);
	in.read(&tipo[0], len);
	productoFisico.setTipo(tipo);
	
	in.read((char*)&precio, sizeof(double));
	in.read((char*)&peso, sizeof(double));
	productoFisico.setPrecio(precio);
	productoFisico.setPeso(peso);
	
	return in;
}
