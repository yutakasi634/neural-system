#ifndef operatorForVector
#define operatorForVector
#include <iostream>
#include <vector>
#include <stdexcept>

//vectorに対する四則演算のオーバーロード

//+
template<typename T>
std::vector<T> operator+(const std::vector<T>& self,const std::vector<T>& other){
  if(self.size() != other.size())
    throw std::invalid_argument("You put different size vector.");  
  std::vector<T> result(self.size());
  for(std::size_t i = 0; i < self.size(); ++i)
    result[i] = self[i] + other[i];
  return result;
}
/*以下同様に修正*/

//-
template<typename T>
std::vector<T> operator-(const std::vector<T>& self,const std::vector<T>& other){
  if(self.size() != other.size())
    throw std::invalid_argument("You put different size vector.");
  std::vector<T> result;
  result.resize(self.size());
  for(std::size_t i = 0; i < self.size(); ++i)
    result[i] = self[i] - other[i];
  return result;
}


//vector * vector
template<typename T>
std::vector<T> operator*(const std::vector<T>& self,const std::vector<T>& other){
  if(self.size() != other.size())
    throw std::invalid_argument("You put different size vector.");  
  std::vector<T> result;
  result.resize(self.size());
  for(std::size_t i = 0; i < self.size(); ++i)
    result[i] = self[i] * other[i];
  return result;
}


//scholar * vector
template<typename T>
std::vector<T> operator*(const T& self,const std::vector<T>& other){
  std::vector<T> result;
  result.resize(other.size());
  for(std::size_t i = 0; i < other.size(); ++i)
    result[i] = self * other[i];
  return result;
}

//vector * scholar
template<typename T>
std::vector<T> operator*(const std::vector<T>& self,const T& other){
  std::vector<T> result;
  result.resize(self.size());
  for(std::size_t i = 0; i < self.size(); ++i)
    result[i] = self[i] * other;
  return result;
}

// vector / vector
template<typename T>
std::vector<T> operator/(const std::vector<T>& self,const std::vector<T>& other){
  if(self.size() != other.size())
    throw std::invalid_argument("You put different size vector.");    
  std::vector<T> result;
  result.resize(self.size());
  for(std::size_t i = 0; i < self.size(); ++i)
    result[i] = self[i] / other[i];
  return result;
}

// vector / scholar
template<typename T>
std::vector<T> operator/(const std::vector<T>& self,const T& other){ 
  std::vector<T> result;
  result.resize(self.size());
  for(std::size_t i = 0; i < self.size(); ++i)
    result[i] = self[i] / other;
  return result;
}

// scholar / vector
template<typename T>
std::vector<T> operator/(const T& self,const std::vector<T>& other){
  std::vector<T> result;
  result.resize(other.size());
  for(std::size_t i = 0; i < other.size(); ++i)
    result[i] = self / other[i];
  return result;
}

#endif
