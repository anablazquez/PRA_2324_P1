#include <ostream>
#include "List.h"

template <typename T>

class ListArray : public List<T>{

 private:
  // miembros privados
  T* arr;
  int max;
  int n;
  static const int MINSIZE = 2;
  void resize(int new_size){
   
     T aux[new_size];
      for(int i = 0; i < new_size ;i++)
        aux[i] = arr[i];

      delete arr;
      
      arr = new int [new_size];
      for(int i = 0; i < new_size ;i++)
        arr[i] = aux[i];

      max = new_size;
    
  }

 public:
  
  ListArray(){
 
    arr = new int [MINSIZE];
    max = 2;
    n = 0;
  }
  
  ~ListArray(){
    delete[] arr;
  }

  T operator[](int pos){
    if(pos > n || pos < 0){
      throw std::out_of_range("Número fuera de rango del array");
    }
    else 
      return arr[pos];
  }
  
  friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
    out<<"List -> [ ";
	  for(int i = 0; i < list.n ; i++){
      out<< list.arr[i]<<" ";

    }
	  out<<"]";
    return out;
  }

  virtual void insert(int pos, T e) override{
    if(pos > n || pos < 0){
      throw std::out_of_range("Número fuera de rango del array");
    }
     if(size() == max)
             resize(size()*2);

      if (pos == 0){
	prepend(e);
      }
      else if(pos == n){
	append(e);
      }
      else{
	      for(int i = n ; i > pos ; i--){
		      arr[i] = arr[i-1];	 		
	      }
	      arr[pos] = e;
	      n++;
      }
 	
  } 
  virtual  void prepend(T e) override{
      if(size() == max)
	     resize(size()*2);
      else{
	      for(int i = n; i > 0; i --){
		      arr[i] = arr[i-1];

	      }
arr[0] = e;
	      n++;
      } 
    }
    
    
    
    
  virtual void append(T e) override{
      if(size() == max)
             resize(size()*2);

      arr[n] = e;
      n++;
    }

  virtual   T remove(int pos) override{
      T aux;
	  if(pos > size()-1 || pos < 0){
	throw std::out_of_range("Número fuera de rango del array");
      }
      else{
	    aux = arr[pos];  
	    
	    for(int i = pos; i < n; i++){
		arr[i] = arr[i+1];
	      }
	   n--;
	return aux;
      }
      
    }
    
  virtual T get(int pos) override{
      if(pos > size()-1 || pos < 0){
	throw std::out_of_range("Número fuera de rango del array");
      }
      else{
	return arr[pos];
      }
    }
  virtual int search(T e) override{
      for(int i = 0; i < n ; i++){
	if ( arr[i] == e)
	  return i;
      }
      return -1;
    }
  virtual bool empty() override{
      if(n == 0)
	return true;
      else return false;
    }
    
  virtual int size() override{
      return n;
    }
   
    // miembros públicos, incluidos los heredados de List<T>
  };
	
