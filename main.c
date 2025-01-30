#include <stdio.h>
#include "set.h"

int main() {
    Set set1 = {{0}, 0};
    Set set2 = {{0}, 0};
    Set result = {{0}, 0};

    add(&set1, 1);
    add(&set1, 2);
    add(&set1, 3);
    add(&set1, 7);
    add(&set1, 44);

    add(&set2, 3);
    add(&set2, 4);
    add(&set2, 5);
    add(&set2, 6);
    add(&set2, 7);

    printf("====================================\n");
    printf("Conjunto 1: ");
    print(&set1);
    printf("Conjunto 2: ");
    print(&set2);

    printf("\n");

    printf("Conjunto 1 esta vazio? %s\n", isEmpty(&set1) ? "Sim" : "Nao");

    //tamanho
    printf("Tamanho do Conjunto 1: %d\n", len(&set1));
    printf("Tamanho do Conjunto 2: %d\n", len(&set2));

    printf("\n");

    //IsIn e IsNotIn
    printf("numero 3 esta no set1? %s\n", isIn(&set1, 3) ? "sim" : "nao");
    printf("numero 7 nao esta no set1? %s\n", isNotIn(&set1, 7) ? "Sim" : "Nao");

    printf("\n");

    //Testando a funcao isDisjoint
    printf("Conjunto 1 e Conjunto 2 sao disjuntos? %s\n", isDisjoint(&set1, &set2) ? "Sim" : "Nao");

    //testando removeElem
    removeElem(&set1, 2);
    printf("Conjunto 1 apos remocao do valor 2: ");
    print(&set1);

    printf("\n");

    //Testando a funcao pop
    int popped = pop(&set1);
    printf("Elemento removido aleatoriamente do Conjunto 1: %d\n", popped);
    printf("Conjunto 1 apos pop: ");
    print(&set1);

    printf("\n");

    //testando setUnion
    result = setUnion(&set1, &set2);
    printf("Uniao de Conjunto 1 e Conjunto 2: ");
    print(&result);

    printf("\n");

    result = intersection(&set1, &set2);
    printf("conjunto 1:\n");
    print(&set1);
    printf("conjunto 2:\n");
    print(&set2);

    printf("\n");

    printf("Intersecao de Conjunto 1 e Conjunto 2: ");// valores comuns nos 2 conjuntos
    print(&result);

    printf("\n");

    result = difference(&set1, &set2);
    printf("Diferenca entre Conjunto 1 e Conjunto 2: "); // set1 - set2
    print(&result);

    printf("\n");

    //retorna elementos 
    result = symmetric_difference(&set1, &set2);
    printf("Retorna um conjunto com os elementos exclusivos entre os dois conjuntos: ");
    print(&result);


    //IsSubSet e isSuperSet
    printf("Conjunto 1 eh subconjunto de Conjunto 2? %s\n", isSubSet(&set1, &set2) ? "Sim" : "Nao");
    printf("Conjunto 1 eh superconjunto de Conjunto 2? %s\n", isSuperSet(&set1, &set2) ? "Sim" : "Nao");

    printf("\n");

    clear(&set1);
    add(&set1, 8);
    add(&set1, 9);
    add(&set1, 10);

    //copia do conjunto 1 para o 2
    copy(&set1, &set2);
    printf("Copia do Conjunto 1 para o 2: ");
    print(&set2);


    //limpando os conjuntos
    clear(&set1);
    clear(&set2);

    return 0;
}