#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>
#include <sstream>

using namespace std;

class Producto {
public:
	Producto();
	virtual ~Producto();
	
	virtual double convertirPrecio();
	
	const string &getNombre() const;
	
	void setNombre(const string &nombre);
	
	double getPrecio() const;
	
	void setPrecio(double precio);
	
	const string &getTipo() const;
	
	void setTipo(const string &tipo);
	
	friend ostream &operator<<(ostream &os, const Producto &producto);
	
	string toString() const;
private:
	string nombre;
	string tipo;
	double precio;
	
	virtual double aplicarDescuento();
};

#endif

