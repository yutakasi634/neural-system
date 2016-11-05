#ifndef VECTOR1
#define VECTOR1
#include <iostream>
#include <vector>

//vectorに対する四則演算のオーバーロード

//+
template<typename T>
std::vector<T> operator+(const std::vector<T>& self,const std::vector<T>& other){
  try{
    if(self.size() != other.size())
      throw "You input different size vector.";
  }
  catch(char* err){
    std::cout << "error:" << err << "\n";
    std::vector<T> re;
    return re;
  }
  
  std::vector<T> result;
  result.resize(self.size());
  for(std::size_t i = 0; i < self.size(); ++i)
    result[i] = self[i] + other[i];
  return result;
}


//-
template<typename T>
std::vector<T> operator-(const std::vector<T>& self,const std::vector<T>& other){
  try{
    if(self.size() != other.size())
      throw "You input different size vector.";
  }
  catch(char* err){
    std::cout << "error:" << err << "\n";
    return 1;
  }
  
  std::vector<T> result;
  result.resize(self.size());
  for(std::size_t i = 0; i < self.size(); ++i)
    result[i] = self[i] - other[i];
  return result;
}


//vector * vector
template<typename T>
std::vector<T> operator*(const std::vector<T>& self,const std::vector<T>& other){
  try{
    if(self.size() != other.size())
      throw "You input different size vector.";
  }
  catch(char* err){
    std::cout << "error:" << err << "\n";
    return 1;
  }
  
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
  try{
    if(self.size() != other.size())
      throw "You input different size vector.";
  }
  catch(char* err){
    std::cout << "error:" << err << "\n";
    return 1;
  }
  
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
