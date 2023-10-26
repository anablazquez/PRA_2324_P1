#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
 
        Node<T>* first;
	int n ;


    public:

        ListLinked(){
		n=0;
		first= nullptr;
	}
	~ListLinked(){
		 Node<T>* toDelete = nullptr; 
		while(first!= nullptr){
		 Node<T>* aux = first->next;
		toDelete = first; // copiamos dirección de memoria
		delete toDelete; // liberamos memoria
		first =aux;}}



	T operator[](int pos){
		if( pos> n|| pos<0){
			throw std::out_of_range ("posicion no valida");}
		else{
			 Node<T>* aux= first;
			  for(int i=1; i<pos;i++){ //recorremos hasta que encontremos la posicion deseada
				  aux=aux-> next;}//pasamos al nodo iguiente 
			  return aux->data;}}
				
		friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
				out<<"List -> [ ";
    
   				 Node<T>* aux = list.first;
    
   			 	while(aux){
      					out<< aux->data;
      					if(aux->next != nullptr)// hasta que el contenico no sea 0 seguir
						out<<",";
      
     					 aux = aux->next;
    							}
   				 out<<"]";
      				 return out;} 
	};
