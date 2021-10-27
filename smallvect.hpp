#include <iostream>
#include <complex>
#include <vector>

template <int N,class T>
class SmallVector{

public:
  static const int dim = N;
  typedef T value_type; 
  
private:
  std::vector<T> x;

public:

  SmallVector(): x(N,T()){}  

  SmallVector(const SmallVector<N,T>&) = default;  

  SmallVector(SmallVector<N,T>&&) = default;

  SmallVector<N,T>& operator=(const SmallVector<N,T>&) = default;

  SmallVector<N,T>& operator=(SmallVector<N,T>&&) = default;

  T& operator[](std::size_t j){return x[j];}

  const T& operator[](std::size_t j) const {return x[j];}  

  friend std::ostream& operator<<(std::ostream& o, const SmallVector<N,T>& v){
    for(int j=0; j<N; ++j){o<<v[j]<<"\t";} return o;}

  SmallVector<N,T>& operator+=(const SmallVector<N,T>& v){
    for(int j=0; j<x.size(); ++j){x[j]+=v[j];} return *this;}
  
  SmallVector<N,T> operator+(SmallVector<N,T> v){
    return v+=*this;}

  SmallVector<N,T>& operator-=(const SmallVector<N,T>& v){
    for(int j=0; j<x.size(); ++j){x[j]-=v[j];} return *this;}  

  SmallVector<N,T> operator-(const SmallVector<N,T>& v){
    return SmallVector<N,T>(*this)-=v;}
  
  
};

typedef SmallVector<1,double> R1;
typedef SmallVector<2,double> R2;
typedef SmallVector<3,double> R3;
typedef SmallVector<4,double> R4;
typedef SmallVector<5,double> R5;

typedef SmallVector<1,std::complex<double>> C1;
typedef SmallVector<2,std::complex<double>> C2;
typedef SmallVector<3,std::complex<double>> C3;
typedef SmallVector<4,std::complex<double>> C4;
typedef SmallVector<5,std::complex<double>> C5;
