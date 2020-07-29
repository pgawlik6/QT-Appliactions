#ifndef MATRIX_H
#define MATRIX_H


#include <iostream>
#include <vector>
#include "helpers.h"


typedef unsigned int uint;

template<class T>
class Matrix
{
private:
    //properties
    uint w,h;
    std::vector<std::vector<T> > data;
public:
    //properties
    //methods
    Matrix(uint=2,uint=2);
    //@todo operator=
    uint getW() const;
    uint getH() const;
    Matrix<T>& setW(uint);
    Matrix<T>& setH(uint);

    Matrix<T>& removeRow(uint);
    Matrix<T>& removeCol(uint);

    Matrix<T> transpose();
    Matrix<T> subMatrix(int, int);
    Matrix<T> algebraicComplements();
    Matrix<T> adjugate();
    Matrix<T> inverse();
    T firstMinor(int, int);
    T det();
    T tr();

    bool isSquareMatrix();
    bool isTriangularMatrix();
    bool isUpperTriangularMatrix();
    bool isLowerTriangularMatrix();
    bool isDiagonalMatrix();
    bool isSymmetricMatrix();
    bool isSingularMatrix();
    //static methods
    static Matrix<T> identity(uint);
    static Matrix<T> zeros(uint, uint);
    //Matrix operators
    T &operator()(uint,uint);
    T operator()(uint, uint) const;
    Matrix<T>& operator=(const Matrix<T>&);
    Matrix<T> operator+(Matrix<T>&);
    Matrix<T> operator-(Matrix<T>&);
    Matrix<T> operator*(Matrix<T>&);
    //Scalar operator
    Matrix<T> operator*(T);
    //Logical operators
    bool operator==(const Matrix<T>&) const;
    bool operator!=(const Matrix<T>&) const;

    //Display
    template <class U>
    friend std::ostream& operator<< (std::ostream&, const Matrix<U>&); //for debug purposes

};

template <class T>
Matrix<T>& Matrix<T>::setW(uint _w)
{
    w = _w;
    for(uint i = 0; i<h; i++){
        data[i].resize(w);
    }
    return *this;
}

template <class T>
Matrix<T>& Matrix<T>::setH(uint _h)
{
    h = _h;
    data.resize(h);
    return *this;
}

template <class T>
Matrix<T> &Matrix<T>::removeRow(uint i)
{
    //check if `i` is in bounds [0::h-1] and throw error if neccessary
    if(i>h){
        //throw;
    }
    data.erase(data.begin() + i);
    h = data.size();
    return *this;
}

template <class T>
Matrix<T> &Matrix<T>::removeCol(uint j)
{
    //check if `j` is in bounds [0::w-1] and throw error if neccessary
    if(j>w){
        //throw;
    }
    for (uint i=0;i<h;i++) {
        data[i].erase(data[i].begin() + j);
    }
    w = data[0].size();
    return *this;
}

template <class T>
Matrix<T>::Matrix(uint _h, uint _w) : w(_w), h(_h)
{
    data.resize(h);
    for(uint i = 0; i<h; i++){
        data[i].resize(w);
    }
}


template <class T>
uint Matrix<T>::getW() const
{
    return w;
}

template <class T>
uint Matrix<T>::getH() const
{
    return h;
}

template <class T>
Matrix<T> Matrix<T>::transpose()
{
    Matrix<T> trans(w,h);
    for(unsigned i=0;i<h;i++){
        for(unsigned j=0;j<w;j++){
            trans(j,i) = operator()(i,j);
        }
    }
    return trans;
}

/**
 * @param integer i index of row to be removed, ignore if i < 0
 * @param integer j index of column to be removed, ignore if j < 0
 * @return Matrix<T>
 */
template <class T>
Matrix<T> Matrix<T>::subMatrix(int i, int j)
{
    Matrix<T> tmp = *this;
    //removing rows first is optimal
    if(i >= 0){
        tmp.removeRow(static_cast<uint>(i));
    }
    if(j >= 0){
        tmp.removeCol(static_cast<uint>(j));
    }
    return tmp;
}

template <class T>
Matrix<T> Matrix<T>::algebraicComplements()
{
    if(!isSquareMatrix()){
        //throw;
        return false;
    }
    uint n = w;
    Matrix<T> algCompMat(n,n);
    for (uint i=0;i<n;i++) {
        for (uint j=0;j<n;j++) {
            algCompMat(i,j) = ((i+j)%2 ? -1 : 1) * firstMinor(i,j);
        }
    }
    return algCompMat;
}

template<class T>
Matrix<T> Matrix<T>::adjugate()
{
    return algebraicComplements().transpose();
}

template<class T>
Matrix<T> Matrix<T>::inverse()
{
    if(det()==Helpers::Zero<T>()){
        //throw;
        return false;
    }
    return adjugate() * (Helpers::One<T>()/det());
}

template <class T>
T Matrix<T>::firstMinor(int i, int j)
{
    return subMatrix(i,j).det();
}

template<class T>
T Matrix<T>::det()
{
    if(!isSquareMatrix()){
        //throw *this;
        return false;
    }
    uint n = w;
    if(n == 1){
        return operator()(0,0);
    }
    T det = Helpers::Zero<T> ();
    for (uint i=0;i<n;i++) {
        det += (i%2 ? -1 : 1) * operator()(i,0) * firstMinor(i,0);
    }
    return det;
}
template<class T>
T Matrix<T>::tr(){
    if(!isSquareMatrix()){
        //throw;
        return false;
    }
    uint n = w;
    if(n == 1)
    {
        return operator()(0,0);
    }
    T tr = Helpers::Zero<T> ();
    for(uint i=0;i<n;i++){
        tr += operator()(i,i);
    }
    return tr;
}

template <class T>
bool Matrix<T>::isSquareMatrix()
{
    return w == h;
}

template <class T>
bool Matrix<T>::isTriangularMatrix()
{
    return isUpperTriangularMatrix() || isLowerTriangularMatrix();
}

template <class T>
bool Matrix<T>::isUpperTriangularMatrix()
{
    if(!isSquareMatrix()){
        //throw;
        return false;
    }
    for (uint i=0;i<w;i++) {
        for (uint j=0;j<i;j++) {
            if(operator()(i,j) != Helpers::Zero<T>()){
                return false;
            }
        }
    }
    return true;
}

template <class T>
bool Matrix<T>::isLowerTriangularMatrix()
{
    if(!isSquareMatrix()){
        //throw;
        return false;
    }
    for (uint j=0;j<h;j++) {
        for (uint i=0;i<j;i++) {
            if(operator()(i,j) != Helpers::Zero<T>()){
                return false;
            }
        }
    }
    return true;
}

template <class T>
bool Matrix<T>::isDiagonalMatrix()
{
    if(!isSquareMatrix()){
        //throw;
        return false;
    }

    Matrix<T> x(w,w);
    for (uint i=0;i<w;i++) {
        x(i,i) = operator()(i,i);
    }
    return operator==(x);
}

template <class T>
bool Matrix<T>::isSymmetricMatrix()
{
    if(!isSquareMatrix()){
        //throw;
        return false;
    }
    for(uint i=0;i<h;i++){
        for(uint j=0;j<w;j++){
            if(operator()(i,j) != operator()(j,i)){
                return false;
            }
        }
    }
    return true;
}

template <class T>
bool Matrix<T>::isSingularMatrix()
{
    if(!isSquareMatrix()){
        //throw;
        return false;
    }

    return det() == Helpers::Zero<T> ();
}

template <class T>
Matrix<T> Matrix<T>::identity(uint n)
{
    Matrix<T> identity(n,n);
    for(uint i=0;i<n;i++){
        identity(i,i) = 1;
    }
    return identity;
}

template <class T>
Matrix<T> Matrix<T>::zeros(uint w, uint h)
{
    Matrix<T> zeros(w,h);
    return zeros;
}

template <class T>
T &Matrix<T>::operator()(uint x, uint y)
{
    return data[x][y];
}

template <class T>
T Matrix<T>::operator()(uint x, uint y) const
{
    return data[x][y];
}

template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T> & a)
{
    uint h = a.getH(), w = a.getW();
    Matrix<T> newMatrix(h,w);
    for (uint i=0;i<h;i++) {
        for (uint j=0;j<w;j++) {
            newMatrix(i,j) = a(i,j);
        }
    }
    return newMatrix;
}

template <class T>
Matrix<T> Matrix<T>::operator+(Matrix<T> &A)
{
    if(A.getH()!=h || A.getW()!=w){
        //throw;
        return false;
    }
    Matrix<T> add(w,h);
    for(uint i=0;i<h;i++){
        for(uint j=0;j<w;j++){
            add(i,j) = this->data[i][j] + A(i,j);
        }
    }
    return add;
}

template <class T>
Matrix<T> Matrix<T>::operator-(Matrix<T> &A)
{
    if(A.getH()!=h || A.getW()!=w){
        //throw;
        return false;
    }
    Matrix<T> sub(w,h);
    for(uint i=0;i<h;i++){
        for(uint j=0;j<w;j++){
            sub(i,j) = this->data[i][j] - A(i,j);
        }
    }
    return sub;
}

template <class T>
Matrix<T> Matrix<T>::operator*(Matrix<T> &A)
{
    Matrix<T> multi(w,A.getH());
    if(h == A.getW()){
        for(uint i=0;i<w;i++){
            for(uint j=0;j<A.getH();j++){
                T temp = Helpers::Zero<T>();
                for(uint k=0;k<h;k++){
                    temp += this->data[i][k] * A(k,j);
                }
                multi(i,j) = temp;
            }
        }

        return multi;
    }else {
        //throw;
        return false;
    }
}

template <class T>
Matrix<T> Matrix<T>::operator*(T scalar)
{
    Matrix<T> result(w,h);
    for(uint i=0;i<w;i++){
        for(uint j=0;j<h;j++){
            result(i,j) = this->data[i][j] * scalar;
        }
    }
    return result;
}

template <class T>
bool Matrix<T>::operator==(const Matrix<T> & a) const
{
    if(a.getH() != h || a.getW() != w){
        //throw;
        return false;
    }
    for (uint i=0;i<h;i++) {
        for (uint j=0;j<w;j++) {
            if(!Helpers::Equal(operator()(i,j), a(i,j)) ){
                return false;
            }
        }
    }
    return true;
}


template <class T>
bool Matrix<T>::operator!=(const Matrix<T> & a) const
{
    return !operator==(a);
}

template <class U>
std::ostream& operator<<(std::ostream& out,const Matrix<U>& a)
{
    uint w = a.getW(),h = a.getH();
    for(uint i=0;i<h;i++){
        for(uint j=0;j<w;j++){
            out<<a(i,j)<<" "; //
        }
        if(i != h-1){
            out<<std::endl;
        }
    }
    return out;
}


#endif // MATRIX_H
