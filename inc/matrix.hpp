#ifndef MATRIX_HPP_
#define MATRIX_HPP_

namespace advcpp {

template<typename T>
class Matrix {
public:                                                            
    explicit Matrix(unsigned int a_rows, unsigned int a_coloums);  
    ~Matrix();
    Matrix(const Matrix &a_other);                                      
    Matrix& operator=(const Matrix &a_other);                             
    

    T& operator()(unsigned int a_row, unsigned int a_column) noexcept;
    T const& operator()(unsigned int a_row, unsigned int a_column) const noexcept;

    T at(unsigned int a_row, unsigned int a_column) const;
    void Member(unsigned int a_row, unsigned int a_column, T a_member) const;                                                          

    unsigned int GetRows() const noexcept;
    unsigned int GetColumns() const noexcept;
  
private:
    unsigned int m_rows;
    unsigned int m_columns;
    T* m_matrix;
};

}//advcpp

#include "inl/matrix.hxx"
#endif /*MATRIX_HPP_*/
