#ifndef PRODUCTOFISICO_H
#define PRODUCTOFISICO_H
#include <ostream>
#include <sstream>
#include "Producto.h"

class ProductoFisico : public Producto{
public:
	ProductoFisico();
	virtual ~ProductoFisico();
	double getPeso() const;
	void setPeso (double peso);
	friend ostream &operator<<(ostream &os, const ProductoFisico &producto);
	string toString() const;
	
private:
	double peso;
	double aplicarDescuento() override;
};

#endif

