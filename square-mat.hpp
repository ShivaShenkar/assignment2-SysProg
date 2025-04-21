

#include <iostream>
namespace Matrix
{
  class SquareMat
  {
        private:
          int size;
          double **mat;
          int* sum;

          
          
        public:
          SquareMat(int n);
          ~SquareMat(){
            for (int i = 0; i < size; ++i)
              delete[] mat[i];
            delete[] mat;
            delete sum;
          }
          SquareMat(const SquareMat& other) : size(other.size) {
            mat = new double*[size];
            sum = new int(*other.sum);
            for (int i = 0; i < size; ++i) {
                mat[i] = new double[size];
                for (int j = 0; j < size; ++j) {
                    mat[i][j] = other.mat[i][j];
                }
            }
          }
          SquareMat(int** matrix){
            int vert = sizeof(matrix)/sizeof(matrix[0]);
            int hor = sizeof(matrix[0])/sizeof(matrix[0][0]);
            if(vert!=hor)
              throw std::invalid_argument("Matrix is not square");
            size = vert;
            mat = new double*[size];
            sum = new int(0);
            for (int i = 0; i < size; ++i)
                mat[i] = new double[size];
            for (int i = 0; i < size; ++i)
                for (int j = 0; j < size; ++j)
                    mat[i][j] = matrix[i][j];
          }

          int getSize() const {return size;}
          void set(int i, int j, double value){
            if (i < 0 || i >= size || j < 0 || j >= size)
              throw std::out_of_range("Index out of range");
            mat[i][j] = value;
          }
          double get(int i, int j) const{
            if (i < 0 || i >= size || j < 0 || j >= size)
              throw std::out_of_range("Index out of range");
            return mat[i][j];
          }
          SquareMat operator+ (SquareMat mat2);
          SquareMat operator- (SquareMat mat2);
          SquareMat operator-(){
            SquareMat result(this->size);
            for(int i = 0; i < size; ++i)
                for(int j = 0; j < size; ++j)
                    result.set(i, j, -this->get(i, j));   
            return result;
          }
          SquareMat operator* (SquareMat mat2);
          SquareMat operator* (double scalar){
            SquareMat result(this->size);
            for(int i = 0; i < size; ++i){
              for(int j = 0; j < size; ++j)
              result.set(i,j, this->get(i,j) * scalar);
            }
            return result;
          }
          friend SquareMat operator*(double scalar, SquareMat mat);
          SquareMat operator% (SquareMat mat2);
          SquareMat operator% (int scalar);
          SquareMat operator/ (double &scalar){
            SquareMat result(this->size);
            for (int i = 0; i < this->size; ++i)
                for (int j = 0; j < this->size; ++j)
                    result.set(i, j, this->get(i, j) / scalar);
            return result;
          }
          SquareMat operator^ (int scalar);
          SquareMat operator++(); // pre-increment     
          SquareMat operator++(int); // post-increment
          SquareMat operator--(); // pre-decrement 
          SquareMat operator--(int); // post-decrement
          SquareMat operator~(){
            SquareMat result(this->size);
            for(int i = 0; i < size; ++i)
                for(int j = 0; j < size; ++j)
                    result.set(j, i, this->get(i, j));
            return result; 
          }
          double* operator[](int i){
            if(i<0||i>=size)
                throw std::invalid_argument("index out of bounds");
            return mat[i];
          }
          bool operator==(SquareMat mat2){
            mat2.calculateSum();
            (*this).calculateSum();
            return *(this->sum)==*(mat2.sum);
          }
          bool operator!=(SquareMat mat2){
            mat2.calculateSum();
            (*this).calculateSum();
            return *(this->sum)!=*(mat2.sum);
          }
          bool operator>(SquareMat mat2){
            mat2.calculateSum();
            (*this).calculateSum();
            return *(this->sum)>*(mat2.sum);
          }
          bool operator<(SquareMat mat2){
            mat2.calculateSum();
            (*this).calculateSum();
            return *(this->sum)<*(mat2.sum);
          }
          bool operator>=(SquareMat mat2){
            mat2.calculateSum();
            (*this).calculateSum();
            return *(this->sum)>=*(mat2.sum);
          }
          bool operator<=(SquareMat mat2){
            mat2.calculateSum();
            (*this).calculateSum();
            return *(this->sum)<=*(mat2.sum);
          }
          void calculateSum() {
            *sum = 0;
            for(int i = 0; i < size; i++) {
                for(int j = 0; j < size; j++) {
                    *sum += mat[i][j];  
                }
            }
          }
          double operator!();
          SquareMat operator=(SquareMat mat2);
          SquareMat operator+=(SquareMat mat2){
              *this = *this + mat2;
              return *this;
          }
          SquareMat operator-=(SquareMat mat2){
            *this = *this - mat2;
            return *this;
          }
          SquareMat operator*=(SquareMat mat2){
            *this = *this * mat2;
            return *this;
          }
          SquareMat operator%=(int scalar){
            *this = *this % scalar;
            return *this;
          }
          SquareMat operator%=(SquareMat mat2){
            *this = *this % mat2;
            return *this;
          }
          SquareMat operator*=(double scalar){
            *this = *this *scalar;
            return *this;
          }
          SquareMat operator/=(double scalar){
            *this = *this /scalar;
            return *this;
          }
          SquareMat createAMinor(int row,int col,SquareMat mat);
          void setIdentity();
          friend std::ostream& operator<<(std::ostream& os,SquareMat mat);



            

};
} 
