#include "square-mat.hpp"
#include <cmath>
namespace Matrix
{
    SquareMat::SquareMat(int n) : size(n)
    {
        mat = new double*[size];
        *sum = 0;
        for (int i = 0; i < size; ++i)
            mat[i] = new double[size];
    }
    SquareMat SquareMat::operator+ (SquareMat &mat2)
    {
        if (this->size != mat2.size)
            throw std::invalid_argument("Matrix sizes do not match for addition");
        SquareMat *result = new SquareMat(this->size);
        for (int i = 0; i < this->size; ++i)
            for (int j = 0; j < this->size; ++j)
                result->set(i, j, this->get(i, j) + mat2.get(i, j));
        result->calculateSum();        
        return *result;
    }
    SquareMat SquareMat::operator- (SquareMat &mat2)
    {
        if (this->size != mat2.size)
            throw std::invalid_argument("Matrix sizes do not match for subtraction");
        SquareMat *result = new SquareMat(this->size);
        for (int i = 0; i < this->size; ++i)
            for (int j = 0; j < this->size; ++j)
                result->set(i, j, this->get(i, j) - mat2.get(i, j));
        result->calculateSum();
        return *result;
    }

    SquareMat SquareMat::operator*(SquareMat &mat2){
        if (this->size != mat2.size)
            throw std::invalid_argument("Matrix sizes do not match for multiplication");
        SquareMat *result = new SquareMat(this->size);
        for (int i = 0; i < this->size; ++i)
            for (int j = 0; j < this->size; ++j)
                result->set(i, j, 0);
        for (int i = 0; i < this->size; ++i)
            for (int j = 0; j < this->size; ++j)
                for (int k = 0; k < this->size; ++k)
                    result->set(i, j, result->get(i, j) + this->get(i, k) * mat2.get(k, j));
        result->calculateSum();
        return *result;
    }

    SquareMat SquareMat::operator%(SquareMat &mat2){
        if (this->size != mat2.size)
        {
            throw std::invalid_argument("Matrix sizes do not match for item-multiplication");
        }
        SquareMat *result = new SquareMat(this->size);
        for (int i = 0; i < this->size; ++i)
            for (int j = 0; j < this->size; ++j)
                result->set(i, j, this->get(i, j) * mat2.get(i, j));
        result->calculateSum();
        return *result;
        
    }
    SquareMat SquareMat::operator% (int &scalar){
        SquareMat *result = new SquareMat(this->size);
        for (int i = 0; i < this->size; ++i)
            for (int j = 0; j < this->size; ++j)
                result->set(i,j, this->get(i,j) * scalar);
        result->calculateSum();
        return *result;
    }
    
    SquareMat SquareMat::operator^ (int &scalar){
        SquareMat *result = new SquareMat(this->size);
        SquareMat *temp = new SquareMat(this->size);
        setIdentity(*result);
        for(int i=0;i<scalar;i++)
        {
            *temp = *result * (*this);
            delete result;
            result = temp;
        }
        delete temp;
        result->calculateSum();
        return *result;
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
    double SquareMat::operator!(){
        SquareMat *temp = nullptr;
        double result=0;
        if(this->size==1)
           return mat[0][0];
        else{
            for(int i=0;i<size;i++){
                delete temp;
                temp = createAMinor(i,0,*this);
                result+=pow(-1,i)*this->get(i,0)*temp->operator!();
            }
        }
        delete temp;
        return result;
     }

    void setIdentity(SquareMat &mat){
        for(int i=0;i<mat.getSize();i++){
            for(int j=0;j<mat.getSize();j++){
                if(i==j)
                    mat.set(i,j,1);
                else
                    mat.set(i,j,0);
            }
        }
    }
    std::ostream& operator<<(std::ostream& os,SquareMat &mat){
        for(int i=0;i<mat.size;i++){
            for(int j=0;j<mat.size;j++){
                os<<mat.get(i,j)<<" ";
            }
            os<<std::endl;
        }
        return os;

      }
    SquareMat* createAMinor(int row, int col, SquareMat &mat){
        SquareMat *temp = new SquareMat(mat.getSize()-1);
        int r=0,c=0;
        for(int i=0;i<mat.getSize();i++){
            for(int j=0;j<mat.getSize();j++){
                if(i!=row && j!=col){
                    temp->set(r,c,mat.get(i,j));
                    c++;
                    if(c==temp->getSize()){
                        c=0;
                        r++;
                    }
                }
            }
        }
        return temp;
    }
    

}

