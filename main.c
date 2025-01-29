#include <stdio.h>
#include "set.h"

int main() {
    Set set1 = {{0}, 0};
    Set set2 = {{0}, 0};
    Set result = {{0}, 0};

    add(&set1, 1);
    add(&set1, 2);
    add(&set1, 2);
    add(&set1, 4);

    add(&set2, 3);
    add(&set2, 4);
    add(&set2, 5);
    add(&set2, 6);

    printf("Conjunto 1: ");
    print(&set1);

    printf("Conjunto 2: ");
    print(&set2);

    printf("Conjunto 1 esta vazio? %s\n", isEmpty(&set1) ? "Sim" : "Nao");

    printf("Tamanho do Conjunto 1: %d\n", len(&set1));

    printf("%s\n", isIn(&set1, 3) ? "Sim" : "Nao");

    printf("%s\n", isNotIn(&set1, 7) ? "Sim" : "Nao");

    printf("Conjunto 1 e Conjunto 2 sao disjuntos? %s\n", isDisjoint(&set1, &set2) ? "Sim" : "Nao");

    removeElem(&set1, 2);
    printf("Conjunto 1 apos remover o elemento 2: ");
    print(&set1);

    int popped = pop(&set1);
    printf("Elemento removido aleatoriamente do Conjunto 1: %d\n", popped);
    printf("Conjunto 1 apos pop: ");
    print(&set1);

    clear(&set2);
    printf("Conjunto 2 apos clear: ");
    print(&set2);

    add(&set2, 3);
    add(&set2, 4);
    add(&set2, 5);
    add(&set2, 6);

    result = setUnion(&set1, &set2);
    printf("Uniao de Conjunto 1 e Conjunto 2: ");
    print(&result);

    result = intersection(&set1, &set2);
    printf("Intersecao de Conjunto 1 e Conjunto 2: ");
    print(&result);

    result = difference(&set1, &set2);
    printf("Diferenca entre Conjunto 1 e Conjunto 2: ");
    print(&result);

    result = symmetric_difference(&set1, &set2);
    printf("Diferenca simetrica entre Conjunto 1 e Conjunto 2: ");
    print(&result);

    printf("Conjunto 1 eh subconjunto de Conjunto 2? %s\n", isSubSet(&set1, &set2) ? "Sim" : "Não");

    printf("Conjunto 1 eh superconjunto de Conjunto 2? %s\n", isSuperSet(&set1, &set2) ? "Sim" : "Não");

    copy(&set1, &result);
    printf("Copia do Conjunto 1: ");
    print(&result);

    return 0;
}