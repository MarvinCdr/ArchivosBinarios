#include "ProductoFisico.h"

ProductoFisico::ProductoFisico() {
	
}

ProductoFisico::~ProductoFisico() {
	
}

double ProductoFisico::getPeso() const{
	return peso;
}

void ProductoFisico::setPeso(double peso){
	ProductoFisico::peso = peso;
}

double ProductoFisico::aplicarDescuento(){
	return getPrecio() * 0.30;
}

ostream &operator<< (ostream &os, const ProductoFisico &producto){
	os << static_cast<const Producto &>(producto) << "Peso: " << producto.peso;
	return os;
}

string ProductoFisico::toString() const{
	stringstream ss;
	ss << (*this);
	return ss.str();
}
