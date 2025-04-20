

#include "square-mat.hpp"
#include <cmath>
namespace Matrix
{
    SquareMat::SquareMat(int n) : size(n)
    {
        mat = new double*[size];
        sum = new int(0);
        for (int i = 0; i < size; ++i)
            mat[i] = new double[size];
    }
    SquareMat SquareMat::operator+ (SquareMat mat2)
    {
        if (this->size != mat2.size)
            throw std::invalid_argument("Matrix sizes do not match for addition");
        SquareMat result(this->size);
        for (int i = 0; i < this->size; ++i)
            for (int j = 0; j < this->size; ++j)
                result.set(i, j, this->get(i, j) + mat2.get(i, j));
        result.calculateSum();        
        return result;
    }
    SquareMat SquareMat::operator-(SquareMat mat2) {
        if (this->size != mat2.size)
            throw std::invalid_argument("Matrix sizes do not match for subtraction");
        
        SquareMat result(this->size);
        for (int i = 0; i < this->size; ++i)
            for (int j = 0; j < this->size; ++j)
                result.set(i, j, this->get(i, j) - mat2.get(i, j));
        result.calculateSum();
        return result;
    }

    SquareMat operator*(double scalar, SquareMat mat)
    {
        SquareMat result(mat.getSize()); 
        for (int i = 0; i < mat.getSize(); ++i)
        {
            for (int j = 0; j < mat.getSize(); ++j)
            {
                result.set(i, j, scalar * mat.get(i, j)); 
            }
        }
        result.calculateSum();
        return result; 
    }

    SquareMat SquareMat::operator*(SquareMat mat2){
        if (this->size != mat2.size)
            throw std::invalid_argument("Matrix sizes do not match for multiplication");
        SquareMat result = SquareMat(this->size);
        for (int i = 0; i < this->size; ++i)
            for (int j = 0; j < this->size; ++j)
                result.set(i, j, 0);
        for (int i = 0; i < this->size; ++i)
            for (int j = 0; j < this->size; ++j)
                for (int k = 0; k < this->size; ++k)
                    result.set(i, j, result.get(i, j) + this->get(i, k) * mat2.get(k, j));
        result.calculateSum();
        return result;
    }

    SquareMat SquareMat::operator%(SquareMat mat2) {
        if (this->size != mat2.size)
            throw std::invalid_argument("Matrix sizes do not match for item-multiplication");
        
        SquareMat result(this->size);
        for (int i = 0; i < this->size; ++i)
            for (int j = 0; j < this->size; ++j)
                result.set(i, j, this->get(i, j) * mat2.get(i, j));
        result.calculateSum();
        return result;
    }
    SquareMat SquareMat::operator%(int scalar) {
        SquareMat result(this->size);
        for (int i = 0; i < this->size; ++i)
            for (int j = 0; j < this->size; ++j)
                result.set(i, j, this->get(i, j) * scalar);
        result.calculateSum();
        return result;
    }
    
    SquareMat SquareMat::operator^(int scalar) {
        if(scalar<0)
            throw std::invalid_argument("Exponent must be non-negative");
        SquareMat result(this->size);
        setIdentity(result);
        
        for(int i = 0; i < scalar; i++) {
            SquareMat temp = result * (*this);
            result = temp;
        }
        result.calculateSum();
        return result;
    }
    SquareMat SquareMat::operator++(){
        for(int i=0;i<this->size;i++){
            for(int j=0;j<this->size;j++){
                ++(this->mat[i][j]);
            }
        }
        this->calculateSum();
        return *this;
        
    }
    SquareMat SquareMat::operator++(int){
        for(int i=0;i<this->size;i++){
            for(int j=0;j<this->size;j++){
                (this->mat[i][j])++;
            }
        }
        this->calculateSum();
        return *this;
    }
    SquareMat SquareMat::operator--(){
        for(int i=0;i<this->size;i++){
            for(int j=0;j<this->size;j++){
                --(this->mat[i][j]);
            }
        }
        this->calculateSum();
        return *this;
        
    }
    SquareMat SquareMat::operator--(int){
        for(int i=0;i<this->size;i++){
            for(int j=0;j<this->size;j++){
                (this->mat[i][j])--;
            }
        }
        this->calculateSum();
        return *this;
        
    }
    double SquareMat::operator!() {
        if(this->size == 1)
            return mat[0][0];
        else {
            double result = 0;
            for(int i = 0; i < size; i++) {
                SquareMat minor = createAMinor(i, 0, *this);
                result += pow(-1, i) * this->get(i, 0) * !minor;
            }
            return result;
        }
    }

    void SquareMat::setIdentity(SquareMat mat){
        for(int i=0;i<mat.getSize();i++){
            for(int j=0;j<mat.getSize();j++){
                if(i==j)
                    mat.set(i,j,1);
                else
                    mat.set(i,j,0);
            }
        }
    }
    std::ostream& operator<<(std::ostream& os,SquareMat mat){
        for(int i=0;i<mat.size;i++){
            for(int j=0;j<mat.size;j++){
                os<<mat.get(i,j)<<" ";
            }
            os<<std::endl;
        }
        return os;

    }
    SquareMat SquareMat::createAMinor(int row, int col, SquareMat mat) {
        SquareMat temp(mat.getSize() - 1);
        int r = 0, c = 0;
        for(int i = 0; i < mat.getSize(); i++) {
            if(i != row) {
                c = 0;
                for(int j = 0; j < mat.getSize(); j++) {
                    if(j != col) {
                        temp.set(r, c, mat.get(i, j));
                        c++;
                    }
                }
                r++;
            }
        }
        return temp;
    }
    SquareMat SquareMat::operator=(SquareMat mat2) {
        if (this == &mat2)
            return *this;
            
        for (int i = 0; i < size; ++i)
            delete[] mat[i];
        delete[] mat;
        delete sum;    
        
        this->size = mat2.size;
        this->mat = new double*[size];
        this->sum = new int(0);
    
        for(int i = 0; i < size; i++) {
            mat[i] = new double[size];
            for(int j = 0; j < size; j++) {
                this->set(i, j, mat2.get(i, j));
            }
        }
        this->calculateSum();
        return *this;
    }

}

