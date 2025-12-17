#ifndef COP4530_MATRIX_HPP_IMPL
#define COP4530_MATRIX_HPP_IMPL

#include <ostream>
#include <iostream>
#include <utility>
#include "Vector.h"  

template <typename Object>
matrix<Object>::matrix(int rows, int cols)
    : array(rows, cop4530::Vector<Object>(cols, Object())) {}

template <typename Object>
matrix<Object>::matrix(const cop4530::Vector< cop4530::Vector<Object> >& v)
    : array(v) {}

template <typename Object>
matrix<Object>::matrix(cop4530::Vector< cop4530::Vector<Object> >&& v)
    : array(std::move(v)) {}

template <typename Object>
const cop4530::Vector<Object>& matrix<Object>::operator[](int row) const{
    return array[row];
}

template <typename Object>
cop4530::Vector<Object>& matrix<Object>::operator[](int row){
    return array[row];
}

template <typename Object>
int matrix<Object>::numrows() const{
    return array.size();
}

template <typename Object>
int matrix<Object>::numcols() const {
    return numrows() ? array[0].size() : 0;
}

template <typename Object>
void matrix<Object>::print(std::ostream& os ){
    for(int i = 0; i < numrows(); ++i){
        for(int j = 0; j < numcols(); ++j){
            if(j) os << ' ';
            os << array[i][j];
        }
        os << '\n';
    }
}

template <typename Object>
void matrix<Object>::setValueAll(Object t) {
    for (int i = 0; i < numrows(); ++i)
        for (int j = 0; j < numcols(); ++j)
            array[i][j] = t;
}


template <typename Object>
std::ostream& operator<<(std::ostream& os, matrix<Object>& m){
    m.print(os);
    return os;
}

template <typename Object>
matrix<Object> operator*(matrix<Object>& m1, matrix<Object>& m2){
    const int r1 = m1.numrows();
    const int c1 = m1.numcols();
    const int c2 = m2.numcols();

    matrix<Object> res(r1, c2);
    for(int i = 0; i < r1; ++i){
        for(int j = 0; j < c2; ++j){
            Object sum{};
            for(int k = 0; k < c1; ++k)
                sum = sum + (m1[i][k] * m2[k][j]);
            res[i][j] = sum;
        }
    }
    return res;
}

#endif 

