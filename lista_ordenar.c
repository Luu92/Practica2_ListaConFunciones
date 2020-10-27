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
    
   

    return primer_nodo;
}

struct Nodo *quitar_repetidos(struct Nodo *primer_nodo){
    if(esta_vacia(primer_nodo)){
        printf("\nLa lista esta vacia no se puede imprimir");
    }
    else{
        struct Nodo *aux1 = primer_nodo;
        struct Nodo *aux2 = primer_nodo->siguiente_nodo;

        while(aux2->siguiente_nodo != NULL){
            
            if(aux1->dato == aux2->dato){
                printf("Entro chido aqui");
                aux2 = aux1->siguiente_nodo->siguiente_nodo;
                aux1 = primer_nodo->siguiente_nodo;
                aux1->siguiente_nodo=NULL;
                aux1=aux1->siguiente_nodo;
                aux2=aux2->siguiente_nodo;
            }
            else{
                printf("Sigue avanzando");
                aux1 = aux1->siguiente_nodo;
                aux2 = aux2->siguiente_nodo;
            }
        
        //aux2 = aux2->siguiente_nodo;
        }
    }
return primer_nodo;
}




//Funcion Principal 
int main(int argc, char const *argv[])
{
    struct Nodo *primer_nodo = NULL;
   
    // primer_nodo = en_orden(primer_nodo,2);
    // primer_nodo = en_orden(primer_nodo,3);
    // primer_nodo = en_orden(primer_nodo,1);
    // primer_nodo = en_orden(primer_nodo,0);
    // primer_nodo = borrar_en_orden(primer_nodo,2);
    // imprimir_lista(primer_nodo);
    
   
    primer_nodo = inserta_inicio(primer_nodo,61);
    primer_nodo = inserta_inicio(primer_nodo,62);
    primer_nodo = inserta_inicio(primer_nodo,62);
    //imprimir_lista(primer_nodo);
    primer_nodo = quitar_repetidos(primer_nodo);
    imprimir_lista(primer_nodo);
    return 0;
}
