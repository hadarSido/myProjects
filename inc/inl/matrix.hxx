#include <ostream>
#include <iostream>
#include <algorithm>
#include "matrix.hpp" 
#include "colorrgb.hpp" 

/*********************************************************************/
namespace advcpp {

template<typename T>
Matrix<T>::Matrix(unsigned int a_rows,unsigned int a_columns)
:m_rows(a_rows)
,m_columns(a_columns)
,m_matrix(new T[a_rows * a_columns]) //{0}
{}

template<typename T>
Matrix<T>::~Matrix() {
    delete[] m_matrix;
}

template<typename T>
Matrix<T>::Matrix(const Matrix& a_other)
: m_rows(a_other.m_rows)
, m_columns(a_other.m_columns)
, m_matrix(new T[m_rows * m_columns]){
    T* first = a_other.m_matrix;
    T* last = a_other.m_matrix + m_columns * m_rows;
    std::copy(first, last, m_matrix);
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& a_other) {
    if (this != &a_other) {
        T* temp = new T[a_other.m_rows * a_other.m_columns];
        T* first = a_other.m_matrix ;
        T* last = a_other.m_matrix + m_rows*m_columns;
        std::copy(first, last, temp);
        delete[] m_matrix;
        m_rows = a_other.m_rows;
        m_columns = a_other.m_columns;
        m_matrix = temp; 
    }
    return *this;
}

template <typename T>
T& Matrix<T>::operator()(unsigned int a_row, unsigned int a_column) noexcept {
    return m_matrix[a_row * m_columns + a_column];
}

template <typename T>
T const& Matrix<T>::operator()(unsigned int a_row, unsigned int a_column) const noexcept {
    return m_matrix[a_row * m_columns + a_column];
}

template<typename T>
unsigned int Matrix<T>::GetRows() const noexcept {
    return this->m_rows;
}
template<typename T>
unsigned int Matrix<T>::GetColumns() const noexcept {
    return this->m_columns;
}

template<typename T>
T Matrix<T>::at(unsigned int a_row, unsigned int a_column) const {
    if(a_row < this->m_rows && a_column < this->m_columns){
        throw "Out of range";
    }
    return this->m_matrix[a_row * a_column + a_column];
}

template<typename T>
void Matrix<T>::Member(unsigned int a_row, unsigned int a_column, T a_member) const {
    if(a_row < this->m_rows && a_column < this->m_columns){
        throw "Out of range";
    }
    this->m_matrix[a_row * a_column + a_column] = a_member;
}

}//advcpp