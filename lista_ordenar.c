#include<stdlib.h>
#include<stdio.h>

struct Nodo {
    int dato;
    struct Nodo *siguiente_nodo;
};

struct Nodo *crea_nodo(struct Nodo *siguiente_nodo,int dato){
    struct Nodo *nuevo_nodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if(nuevo_nodo == NULL){
        printf("\nError al crear el nuevo nodo");
        exit(0);
    }

    nuevo_nodo->dato = dato;
    nuevo_nodo->siguiente_nodo = siguiente_nodo;
    return nuevo_nodo;
};


int esta_vacia(struct Nodo *primer_nodo){
    return (primer_nodo == NULL);
}

struct Nodo *borra_inicio(struct Nodo *primer_nodo){
	if(esta_vacia(primer_nodo)){
		printf("\nNo hay elementos para borrar");
		return NULL;
	}
	struct Nodo *aux = primer_nodo;
	primer_nodo = primer_nodo->siguiente_nodo;
	aux->siguiente_nodo=NULL; // borrar la flecha del nodo donde está parado aux
	free(aux);
	
	return primer_nodo;
}

struct Nodo *inserta_inicio(struct Nodo *primer_nodo,int dato){
    struct Nodo *nuevo_nodo = crea_nodo(primer_nodo,dato);
    primer_nodo = nuevo_nodo;

    //numera_nodos(primer_nodo);
    return primer_nodo;
}


struct Nodo *imprimir_lista(struct Nodo *primer_nodo){
    
    if(esta_vacia(primer_nodo)){
        printf("\nNo hay elementos para imprimir.");
    }
    printf("\n\nElementos de la Lista: \n");
    while (primer_nodo != NULL)
    {
        printf("[ %d ]-->",primer_nodo->dato);
        primer_nodo = primer_nodo->siguiente_nodo;
    }
}

struct Nodo *en_orden(struct Nodo *primer_nodo,int dato){

    struct Nodo *nuevo_nodo = crea_nodo(primer_nodo,dato);
    /*
    Comprobamos que la lista este vacia, si es asi agregamos el nuevo_nodo como Primer
    Nodo en todo lo contario agregamos el otro nuevo_nodo2 a la lista  */
    if (esta_vacia(primer_nodo))
    {
        primer_nodo = nuevo_nodo;
        return primer_nodo;
    }
    else{
        /*
        Si existe primer_nodo con el dato que queremos agregar lo omitimos 
        y solo agregamos los Nuevos valores distintos a los que ya estan 
        en la lista al mismo tiempo ordenamos la lista de forma ascendente
        siempre verificando que el primer dato sea mayor que el segundo dato.
        */
        struct Nodo *nuevo_nodo2 = crea_nodo(primer_nodo,dato);
        struct Nodo *aux = primer_nodo;
        int pivote = 0;

        //Agregamos los VALORES DISTINTOS DE LA LISTA Y ORDENAMOS.
            if(aux->dato != dato){
                printf("\nLista Sin elementos repetidos.");
                primer_nodo = nuevo_nodo2;
                
                while (aux->siguiente_nodo != NULL)
                {
                    if(aux->dato > aux->siguiente_nodo->dato){
                        pivote = aux->dato;
                        aux->dato = aux->siguiente_nodo->dato;
                        aux->siguiente_nodo->dato = pivote;
                    }
                aux = aux->siguiente_nodo;
                }
                return primer_nodo;
            }
            //En este caso solo ordenamos la lista, pero sin AGREGAR los repetidos
            else{
                while (aux->siguiente_nodo != NULL)
                {
                    printf("\nLista con el dato %d repetido, pero no fue agregado.",dato);
                    if(aux->dato > aux->siguiente_nodo->dato){
                        pivote = aux->dato;
                        aux->dato = aux->siguiente_nodo->dato;
                        aux->siguiente_nodo->dato = pivote;
                        printf("%d Nodo 1",aux->dato);
                    }
                    aux = aux->siguiente_nodo;
                }
            }
        }
    return primer_nodo;
}

struct Nodo *borrar_en_orden(struct Nodo *primer_nodo, int dato_a_borrar){
   
    if(esta_vacia(primer_nodo)){
        printf("\nNo hay datos en la lista para eliminar");
    
    }

    struct Nodo *aux = primer_nodo;
    while(aux->siguiente_nodo != NULL){
        
        
        aux = aux->siguiente_nodo;
    }

    imprimir_lista(primer_nodo);

    return primer_nodo;
}

struct Nodo *lista_invertida(struct Nodo *primer_nodo){
    /*Con los datos obetinidos en la lista uno podemos invertir los valores de la primera lista 
    declaramos un aux que vaya recorriendo cada una de las posiciones de la primer lista y 
    con la ayuda de la funcion insertar_inicio inicimos una lista_2 con los mismo valores 
    que la lista 1, pero de tal forma que ahora sea de atras hacia enfrente*/
        struct Nodo *aux = primer_nodo;

        if(esta_vacia(primer_nodo)){
            printf("\nNo existen datos en la lista 1.");
        }

        struct Nodo *lista_2 = NULL;
    /*Pasamos recorremos toda la lista y con la ayuda de la funcion insertar_inico.
     Pasamos los parametros de la lista_2 y aux->dato.*/
        while(aux != NULL){
            lista_2 = inserta_inicio(lista_2,aux->dato);
            aux = aux->siguiente_nodo;
        }
    return lista_2;
}




/*En esta función buscamos todos los elementos repetidos y encuentra un elemento repetido lo 
quitamos de la lista*/
struct Nodo *quita_repetidos(struct Nodo *primer_nodo){
	
    if(esta_vacia(primer_nodo)){
        printf("\n La lista esta vacia no se puede imprimir");
    }
    else{
    	
      struct Nodo *aux_1; 
      struct Nodo *aux_2 = primer_nodo;
    /*Hacemos un recorrido de toda la lista entrando al ciclo y por cada iteración si existe
    un número igual aque ya existe lo omitimos con ayuda de los dos puntaros antes ya definidos.*/
    while (aux_2 != NULL && aux_2->siguiente_nodo != NULL) {

        if(aux_2->dato != aux_2->siguiente_nodo->dato){
          aux_2 = aux_2->siguiente_nodo;
        }else{
            aux_1 = aux_2->siguiente_nodo; 
            aux_2->siguiente_nodo = aux_2->siguiente_nodo->siguiente_nodo; 
            free(aux_1);   
		} 
	}
        while(primer_nodo != NULL){
            return primer_nodo;
            primer_nodo = primer_nodo->siguiente_nodo;
            }
    }
}




//Funcion Principal 
int main(int argc, char const *argv[])
{
   struct Nodo *primer_nodo = NULL;
   
    // primer_nodo = en_orden(primer_nodo,1);
    // primer_nodo = en_orden(primer_nodo,5);
    // primer_nodo = en_orden(primer_nodo,9);
    // primer_nodo = en_orden(primer_nodo,11);
    // primer_nodo = en_orden(primer_nodo,45);
    // primer_nodo = en_orden(primer_nodo,89);
    // primer_nodo = en_orden(primer_nodo,102);
    // primer_nodo = en_orden(primer_nodo,202);
    // primer_nodo = en_orden(primer_nodo,8);
    // primer_nodo = en_orden(primer_nodo,2);
    // primer_nodo = en_orden(primer_nodo,150);
    // primer_nodo = en_orden(primer_nodo,74);
    // primer_nodo = en_orden(primer_nodo,36);
    // primer_nodo = en_orden(primer_nodo,36);
    
    // imprimir_lista(primer_nodo);
    
    // struct Nodo *lista_2 = NULL;
    // lista_2 = lista_invertida(primer_nodo);
    // imprimir_lista(lista_2);

    
   
    
    primer_nodo = inserta_inicio(primer_nodo,1);
    primer_nodo = inserta_inicio(primer_nodo,1);
    primer_nodo = inserta_inicio(primer_nodo,1);
    primer_nodo = inserta_inicio(primer_nodo,2);
    primer_nodo = inserta_inicio(primer_nodo,2);
    primer_nodo = inserta_inicio(primer_nodo,4);
    primer_nodo = inserta_inicio(primer_nodo,5);
    primer_nodo = inserta_inicio(primer_nodo,6);
    primer_nodo = inserta_inicio(primer_nodo,6);
    primer_nodo = inserta_inicio(primer_nodo,6);
    imprimir_lista(primer_nodo);
    primer_nodo = quita_repetidos(primer_nodo);
    imprimir_lista(primer_nodo);
    
    
    return 0;
}

