#include <ostream>
#include "List.h"
#include "Node.h"
 using namespace std;
template <typename T>

class ListLinked : public List<T>{
  
 private:
  // miembros privados
  Node<T>* first;
  int n;
  
public:
  
  ListLinked(){
    n = 0;
    first = nullptr;
  }
  
  ~ListLinked(){
	  while(first != nullptr){
	    Node<T>* aux = first->next;
	    delete first;
	    first = aux;
	  }
  }
  
  T operator[](int pos){
    if(pos > n || pos < 0){
      throw std::out_of_range("Número fuera de rango del array");
    }
    else{
      Node<T>* aux = first;
      for(int i = 1; i < pos; i ++){
        aux = aux ->next;
        }
      return aux->data;
    }
  }
  
  friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
    out<<"List -> [ ";
    
    Node<T>* aux = list.first;
    
    while(aux){
      out<< aux->data;
      if(aux->next != nullptr)
	out<<",";
      
      aux = aux->next;
    }
    out<<"]";
    return out;
  }
  virtual  void prepend(T e) override{
    Node <T> *aux = new Node<T>(e, first);
    first = aux;
    n++;
    }
  
  
  virtual void append(T e) override{
    if (first == nullptr)
      prepend(e);
    else{
      
      Node<T> * act = first;
      for(int i = 1; i< size(); i++){	 
	act = act->next;	
      }
      Node<T>* aux = new Node<T>(e , act->next);
      act->next = aux;
      
    }
    n++;
  }
  
  virtual void insert(int pos, T e) override{
    if(pos > n || pos < 0){
      throw std::out_of_range("Número fuera de rango del array");
    }
    if(pos == 0)
      prepend(e);
    
    else if(pos == n)
      append(e);
    
    else{
      
      Node<T> * act = first;
      for(int i = 1; i < pos ; i++){
	act = act->next;
      }
      Node<T>* aux = new Node<T>(e, act->next);
      act ->next =aux ;
      n++;
    }
  }
  
  
  T remove(int pos) override{
            if (pos < 0 || pos >= n) { throw std:: out_of_range("Posición no válida del array\n"); }
            else{
                T x;
                if(pos == 0){
                    Node<T>* aux = first;
                    x = aux->data;
                    first = first->next;
                    delete aux;
                }else{
                    Node<T>* aux = first->next;
                    Node<T>* prev = first;
                    for(int i = 1; i < pos; i++){
                        aux = aux->next;
                        prev = prev->next;
                    } 
                    x = aux->data;
                    prev->next = aux->next;
                    delete aux;
                } 
                n--;
                return x;
            } 
        } 

  virtual T get(int pos) override{
    if(pos > size()-1 || pos < 0){
      throw std::out_of_range("Número fuera de rango del array");
    }
    else{
      Node<T>* aux = first;
      for(int i = 0; i < pos; i ++){
	aux = aux ->next;
	}
      return aux->data;
    }
  }
  virtual int search(T e) override{
    Node<T>* aux = first;
    for(int i = 0; i < n ; i++){
      
      if ( aux ->data == e){
	return i;
      }
      aux= aux->next;
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
  
};
