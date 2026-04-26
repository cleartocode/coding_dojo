// Compilar y correr: gcc -std=c11 -O2 template.c && ./a.out
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// --- 1. Definiciones de Problema ---
typedef struct { const char *id; int score; } Pair;

/*
SPEC:
- Entradas: 
- Salidas: 
*/

// --- 2. Función a Testear ---
Pair* solve(const Pair *items, size_t n, int k, size_t *out_m) {
    if (n == 0 || k <= 0) { *out_m = 0; return NULL; }
    
    // Ejemplo rápido: solo para validar el harness
    *out_m = (n < (size_t)k) ? n : (size_t)k;
    Pair *res = malloc((*out_m) * sizeof(Pair));
    for(size_t i = 0; i < *out_m; i++) res[i] = items[i]; 
    
    return res;
}

// --- 3. Harness de Tests ---
typedef struct {
    Pair items[10]; size_t n; int k;
    Pair expected[10]; size_t m;
} TestCase;

void run_tests() {
    TestCase cases[] = {
        { .items = {{"a",10}, {"b",5}, {"c",7}}, .n = 3, .k = 2, .expected = {{"a",10}, {"b",5}}, .m = 2 },
        { .items = {}, .n = 0, .k = 0, .expected = {}, .m = 0 }
    };

    size_t num_cases = sizeof(cases) / sizeof(cases[0]);
    for (size_t i = 0; i < num_cases; ++i) {
        size_t out_m = 0;
        Pair *got = solve(cases[i].items, cases[i].n, cases[i].k, &out_m);

        int pass = (out_m == cases[i].m);
        for (size_t j = 0; pass && j < out_m; ++j) {
            if (got[j].score != cases[i].expected[j].score || strcmp(got[j].id, cases[i].expected[j].id) != 0) 
                pass = 0;
        }

        if (pass) printf("✅ Test %zu: OK\n", i + 1);
        else printf("❌ Test %zu: FAIL (Mismatched output)\n", i + 1);

        free(got);
    }
}

// --- 4. Main ---
int main(void) {
    run_tests();
    return 0;
}