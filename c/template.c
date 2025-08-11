// Compilar y correr (test): gcc -std=c11 -O2 template.c && ./a.out
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*
SPEC:
- Entradas:
- Salidas:
- Reglas/empates:
- Edge cases:
*/

// Ejemplo de tipos de entrada/salida (ajusta a tu ejercicio)
typedef struct { const char *id; int score; } Pair;

// --- solve ---
// Ajusta la firma a tu problema.
// Devuelve puntero a memoria dinámica si corresponde (y el tamaño vía out param).
Pair* solve(const Pair *items, size_t n, int k, size_t *out_m) {
    // TODO: implementar
    // Sugerencia para Top-K por score:
    // 1) copiar items a buffer mutable
    // 2) qsort con comparador: score desc, luego id asc
    // 3) truncar a m = min(k, n) y copiar a salida
    (void)items; (void)n; (void)k; (void)out_m;
    return NULL;
}

// --- utilidades de comparación para tests ---
static int cmp_pair(const void *a, const void *b) {
    const Pair *pa = (const Pair*)a, *pb = (const Pair*)b;
    if (pa->score != pb->score) return (pb->score - pa->score); // desc
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
    const Pair *items; size_t n; int k;
    const Pair *expected; size_t m;
} TestCase;

int main(void) {
    // Ejemplos (Top-K por score). Cambiá a tu ejercicio cuando corresponda.
    const Pair A[] = { {"a",10}, {"b",5}, {"c",7} };
    const Pair Aexp[] = { {"a",10}, {"c",7} };

    const Pair B[] = {};
    const Pair Bexp[] = {};

    const Pair C_[] = { {"x",5}, {"y",5}, {"a",9} };
    const Pair Cexp[] = { {"a",9}, {"x",5} };

    TestCase cases[] = {
        { A, 3, 2, Aexp, 2 },
        { B, 0, 0, Bexp, 0 },
        { C_, 3, 2, Cexp, 2 },
    };

    int fails = 0;
    for (size_t i = 0; i < sizeof(cases)/sizeof(cases[0]); ++i) {
        size_t out_m = 0;
        Pair *got = solve(cases[i].items, cases[i].n, cases[i].k, &out_m);

        // normalizar y comparar (ordena por si la salida no vino ya ordenada)
        qsort(got, out_m, sizeof(Pair), cmp_pair);
        Pair *exp_sorted = malloc(cases[i].m * sizeof(Pair));
        memcpy(exp_sorted, cases[i].expected, cases[i].m * sizeof(Pair));
        qsort(exp_sorted, cases[i].m, sizeof(Pair), cmp_pair);

        if (!arrays_equal(got, out_m, exp_sorted, cases[i].m)) {
            fprintf(stderr, "FAIL case %zu\n", i+1);
            fails++;
        }
        free(exp_sorted);
        free(got);
    }
    if (fails) { fprintf(stderr, "%d test(s) failed\n", fails); return 1; }
    puts("OK");
    return 0;
}
