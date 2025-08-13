// Compilar y correr (test): gcc -std=c11 -O2 template.c && ./a.out
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*
SPEC:
Entradas: arreglo de pares {id, score}, entero k
Salidas: arreglo con los k elementos con mayor score, ordenados score desc / id asc
Empates: desempata por id ascendente
*/


typedef struct { const char *id; int score; } Pair;
typedef struct { Pair *data; size_t size; } PairArray;

static int cmp_pair(const void *a, const void *b);
static int arrays_equal(const Pair *a, size_t na, const Pair *b, size_t nb);


PairArray solve(const PairArray input, int k) {
    // 1) Clamp
    // 2) Make a copy
    // 3) Sort
    // 4) Truncate
    // 5) Return
    size_t m = (k <= 0) ? 0u : ( (size_t)k < input.size ? (size_t)k : input.size );

    PairArray input_copy = { .data = malloc(input.size * sizeof(Pair)), .size = input.size };
    memcpy(input_copy.data, input.data, input.size * sizeof(Pair));

    qsort(input_copy.data, input_copy.size, sizeof(Pair), cmp_pair);

    PairArray output = { .data = m ? malloc(m * sizeof(Pair)) : NULL, .size = m };
    memcpy(output.data, input_copy.data, m * sizeof(Pair));

    free(input_copy.data);
    
    return output;
}

static int cmp_pair(const void *a, const void *b) {
    const Pair *pa = (const Pair*)a, *pb = (const Pair*)b;
    if (pa->score != pb->score) 
        return (pb->score > pa->score) - (pb->score < pa->score); // desc
    return strcmp(pa->id, pb->id); // asc
}
static int arrays_equal(const Pair *a, size_t na, const Pair *b, size_t nb) {
    if (na != nb) return 0;
    for (size_t i = 0; i < na; ++i) {
        if (a[i].score != b[i].score || strcmp(a[i].id, b[i].id) != 0) return 0;
    }
    return 1;
}

// --- mini harness ---
typedef struct {
    const Pair *items; 
    size_t n; 
    int k;
    const Pair *expected; 
    size_t m;
} TestCase;

int main(void) {
    TestCase tests[] = {
        { (Pair[]){{"a", 10}, {"b", 20}, {"c", 30}}, 3, 2, (Pair[]){{"c", 30}, {"b", 20}}, 2 },
        { (Pair[]){{"a", 10}, {"b", 20}, {"c", 30}}, 3, 0, (Pair[]){{}}, 0 },
        { (Pair[]){{"a", 10}, {"b", 20}, {"c", 30}}, 3, 5, (Pair[]){{"c", 30}, {"b", 20}, {"a", 10}}, 3 },
        { (Pair[]){{"a", 10}, {"b", 20}, {"c", 30}}, 3, -1, (Pair[]){{}}, 0 },
        { (Pair[]){{"z", 10}, {"a", 10}, {"b", 20}}, 3, 3, (Pair[]){{"b", 20}, {"a", 10}, {"z", 10}}, 3 }
    };

    for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i) {
        const TestCase *tc = &tests[i];
        PairArray input = { .data = (Pair*)tc->items, .size = tc->n };
        PairArray result = solve(input, tc->k);
        assert(arrays_equal(result.data, result.size, tc->expected, tc->m));
        free(result.data);
    }

    printf("All tests passed!\n");
    return EXIT_SUCCESS;
}