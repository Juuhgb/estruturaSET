#ifndef SET_H
#define SET_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

typedef struct {
    int conjunto[MAX];       
    int tam;
} Set;

// Adiciona um elemento ao conjunto, se ele ainda não estiver presente
void add(Set *set, int elem);

// Verifica se o conjunto está vazio
bool isEmpty(Set *set);

// Retorna o número de elementos no conjunto
int len(Set *set);

// Verifica se um elemento está no conjunto
bool isIn(Set *set, int elem);

// Verifica se um elemento não está no conjunto
bool isNotIn(Set *set, int elem);

// Verifica se dois conjuntos são disjuntos (não possuem elementos em comum)
bool isDisjoint(Set *set1, Set *set2);

// Remove um elemento do conjunto
void removeElem(Set *set, int elem);

// Remove e retorna um elemento aleatório do conjunto
int pop(Set *set);

// Remove todos os elementos do conjunto
void clear(Set *set);

// Retorna a união de dois conjuntos
Set setUnion(Set *set1, Set *set2);

// Retorna a interseção de dois conjuntos
Set intersection(Set *set1, Set *set2);

// Retorna a diferença entre dois conjuntos (elementos que estão em set1 mas não em set2)
Set difference(Set *set1, Set *set2);

// Retorna a diferença simétrica entre dois conjuntos (elementos que estão em um dos conjuntos, mas não em ambos)
Set symmetric_difference(Set *set1, Set *set2);

// Verifica se set1 é um subconjunto de set2
bool isSubSet(Set *set1, Set *set2);

// Verifica se set1 é um superconjunto de set2
bool isSuperSet(Set *set1, Set *set2);

// Copia os elementos de set1 para set2
void copy(Set *set1, Set *set2);

// Imprime os elementos do conjunto
void print(Set *set);

#endif // SET_H