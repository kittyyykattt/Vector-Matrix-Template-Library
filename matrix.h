#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include "Vector.h"
using namespace cop4530;

template <typename Object>
class matrix {
	public:
		matrix( int rows, int cols );

		matrix( const Vector<Vector<Object>> & v );
		matrix( Vector<Vector<Object>> && v );

		const Vector<Object> & operator[]( int row ) const;
		Vector<Object> & operator[]( int row );

		int numrows( ) const;
		int numcols( ) const;
		void print(std::ostream &os = std::cout);
		void setValueAll(Object t);
	private:
		Vector<Vector<Object>> array;                      
};

template <typename Object>
std::ostream & operator<<(std::ostream &os, matrix<Object> &m);

template <typename Object>
matrix<Object> operator*(matrix<Object> & m1, matrix<Object> & m2);

#include "matrix.hpp"
#endif
