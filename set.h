#ifndef SET_H
#define SET_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX 100

// Estrutura do conjunto
typedef struct {
    int conjunto[MAX];
    int tam;
} Set;

// Declaração de funções
void add(Set *set, int elem);
bool isEmpty(Set *set);
int len(Set *set);
bool isIn(Set *set, int elem);
bool isNotIn(Set *set, int elem);
bool isDisjoint(Set *set1, Set *set2);
void removeElem(Set *set, int elem);
int pop(Set *set);
void clear(Set *set);
Set setUnion(Set *set1, Set *set2);
Set intersection(Set *set1, Set *set2);
Set difference(Set *set1, Set *set2);
Set symmetric_difference(Set *set1, Set *set2);
bool isSubSet(Set *set1, Set *set2);
bool isSuperSet(Set *set1, Set *set2);
void copy(Set *set1, Set *set2);
void print(Set *set);

#endif // SET_H
