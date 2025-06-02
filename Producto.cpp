#include "Producto.h"

Producto::Producto() {
	
}

Producto::~Producto() {
	
}

const string &Producto::getNombre() const{
	return nombre;
}

void Producto::setNombre(const string &nombre){
	Producto::nombre = nombre;
}

double Producto::getPrecio() const{
	return precio;
}

void Producto::setPrecio(double precio){
	Producto::precio = precio;
}

double Producto::convertirPrecio(){
	double PrecioFinal = precio - aplicarDescuento();
	return PrecioFinal;
}

double Producto::aplicarDescuento(){
	return getPrecio();
}

const string &Producto::getTipo() const{
	return tipo;
}

void Producto::setTipo(const string &tipo){
	Producto::tipo = tipo;
}

ostream &operator<<(ostream &os, const Producto &producto){
	os << "name: " <<producto.nombre << "type: " << producto.tipo << "price: " << producto.precio;
	return os;
}

string Producto::toString() const{
	stringstream ss;
	ss <<(*this);
	return ss.str();
}

