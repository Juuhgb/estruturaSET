#include "set.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int conjunto[100];       
    int tam;
} Set;

void add(Set *set, int elem) {
    for(int i = 0; i < set->tam; i++){
        if(set->conjunto[i] == elem){
            return;
        }
    }
    if(set->tam < MAX){
        set->conjunto[set->tam++] = elem;
    }
}

bool isEmpty(Set *set){
    return set->tam == 0;
}

int len(Set *set) {
    return set->tam;
}

bool isIn(Set *set, int elem) {
    for (int i = 0; i < set->tam; i++) {
        if (set->conjunto[i] == elem) return true;
    }
    return false;
}

bool isNotIn(Set *set, int elem) {
    return !isIn(set, elem);
}

bool isDisjoint(Set *set1, Set *set2){
    for(int i = 0; i < set1->tam; i++){
        if(isIn(set2, set1->conjunto[i])){
            return false;
        }
    }
    return true;
}

void removeElem(Set *set, int elem) {
    for (int i = 0; i < set->tam; i++) {
        if (set->conjunto[i] == elem) {
            for (int j = i; j < set->tam - 1; j++) {
                set->conjunto[j] = set->conjunto[j + 1];
            }
            set->tam--;
            return;
        }
    }
}

int pop(Set *set) {
    if (isEmpty(set)) {
        printf("Conjunto vazio\n");
        return -1;
    }

    int randomIndex = rand() % set->tam;
    int removedElement = set->conjunto[randomIndex];
    
    set->conjunto[randomIndex] = set->conjunto[set->tam - 1];
    set->tam--;

    return removedElement;
}

void clear(Set *set) {
    for (int i = 0; i < set->tam; i++){
        set->conjunto[i] = 0;
    }
    set->tam = 0;
}

Set setUnion(Set *set1, Set *set2) {
    Set result = {{0}, 0};
    for (int i = 0; i < set1->tam; i++) {
        add(&result, set1->conjunto[i]);
    }
    for (int i = 0; i < set2->tam; i++) {
        add(&result, set2->conjunto[i]);
    }
    return result;
}

Set intersection(Set *set1, Set *set2) {
    Set result = {{0}, 0};
    for (int i = 0; i < set1->tam; i++) {
        if (isIn(set2, set1->conjunto[i])) {
            add(&result, set1->conjunto[i]);
        }
    }
    return result;
}


Set difference(Set *set1, Set *set2) {
    Set result = {{0}, 0};
    for (int i = 0; i < set1->tam; i++) {
        if (!isIn(set2, set1->conjunto[i])) {
            add(&result, set1->conjunto[i]);
        }
    }
    return result;
}

Set symmetric_difference(Set *set1, Set *set2) {
    Set diff1 = difference(set1, set2);
    Set diff2 = difference(set2, set1);
    return setUnion(&diff1, &diff2);
}

bool isSubSet(Set *set1, Set *set2) {
    for (int i = 0; i < set1->tam; i++) {
        if (!isIn(set2, set1->conjunto[i])) {
            return false;
        }
    }
    return true;
}

bool isSuperSet(Set *set1, Set *set2) {
    for (int i = 0; i < set2->tam; i++) {
        if (!isIn(set1, set2->conjunto[i])) {
            return false;
        }
    }
    return true;
}

void copy(Set *set1, Set *set2){
    for(int i = 0; i < set1->tam; i++){
        set2->conjunto[i] = set1->conjunto[i];
    }
    set2->tam = set1->tam;
}

void print(Set *set){
    printf("{");
    for(int i = 0; i < set->tam; i++){
        printf("%d", set->conjunto[i]);
        if(i < set->tam - 1){
            printf(", ");
        }
    }
    printf("}\n");
}

int main(){
    Set set1 = {{2, 1, 4, 5, 8}, 5};
    Set set2 = {{1, 3, 5, 9}, 4};

    Set result = difference(&set1, &set2);

    printf("Diferença (A - B): ");
    for (int i = 0; i < result.tam; i++) {
        printf("%d ", result.conjunto[i]);
    }
    printf("\n");

    return 0;
}