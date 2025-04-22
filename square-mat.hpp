//fikhman2005@gmail.com

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
          // Constructors and Destructor
          SquareMat(int n);
          ~SquareMat(){
            for (int i = 0; i < size; ++i)
              delete[] mat[i];
            delete[] mat;
            delete sum;
          }
          // Copy constructor
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
          // getters and setter
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

          //addition between two matrices
          SquareMat operator+ (SquareMat mat2);

          //subtraction between two matrices
          SquareMat operator- (SquareMat mat2);

          //unary minus
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
          //scalar with matrix multiplication
          friend SquareMat operator*(double scalar, SquareMat mat);

          //mulitplication between each equivalent elements of two matrices
          SquareMat operator% (SquareMat mat2);

          //matrix modolus scalar
          SquareMat operator% (int scalar);
          SquareMat operator/ (double &scalar){
            SquareMat result(this->size);
            for (int i = 0; i < this->size; ++i)
                for (int j = 0; j < this->size; ++j)
                    result.set(i, j, this->get(i, j) / scalar);
            return result;
          }

          //matrix power
          SquareMat operator^ (int scalar);
          SquareMat operator++(); // pre-increment     
          SquareMat operator++(int); // post-increment
          SquareMat operator--(); // pre-decrement 
          SquareMat operator--(int); // post-decrement

          //matrix transpose
          SquareMat operator~(){
            SquareMat result(this->size);
            for(int i = 0; i < size; ++i)
                for(int j = 0; j < size; ++j)
                    result.set(j, i, this->get(i, j));
            return result; 
          }

          //matrix indexing
          double* operator[](int i){
            if(i<0||i>=size)
                throw std::invalid_argument("index out of bounds");
            return mat[i];
          }
          //matrix comparison
          //operator ==, !=, >, <, >=, <=
          //the comparaison is based on the sum of the elements of the matrix
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

          //calculate the sum of the elements of the matrix
          void calculateSum() {
            *sum = 0;
            for(int i = 0; i < size; i++) {
                for(int j = 0; j < size; j++) {
                    *sum += mat[i][j];  
                }
            }
          }
          //calculate the determinant of the matrix
          double operator!();

          //copy assignment operator
          SquareMat operator=(SquareMat mat2);

          //addition assignment operator
          SquareMat operator+=(SquareMat mat2){
              *this = *this + mat2;
              return *this;
          }

          //subtraction assignment operator
          SquareMat operator-=(SquareMat mat2){
            *this = *this - mat2;
            return *this;
          }

          //multiplication with matrix assignment operator
          SquareMat operator*=(SquareMat mat2){
            *this = *this * mat2;
            return *this;
          }

          //modulus with scalar assignment operator
          SquareMat operator%=(int scalar){
            *this = *this % scalar;
            return *this;
          }

          //multiplication between equivalent elements of two matrices assignment operator
          SquareMat operator%=(SquareMat mat2){
            *this = *this % mat2;
            return *this;
          }

          //multiplication with scalar assignment operator
          SquareMat operator*=(double scalar){
            *this = *this *scalar;
            return *this;
          }

          //division with scalar assignment operator
          SquareMat operator/=(double scalar){
            *this = *this /scalar;
            return *this;
          }
          SquareMat createAMinor(int row,int col,SquareMat mat);
          void setIdentity();
          friend std::ostream& operator<<(std::ostream& os,SquareMat mat);



            

};
} 
