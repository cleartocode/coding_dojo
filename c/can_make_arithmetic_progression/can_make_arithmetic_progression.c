// Compilar y correr: gcc -std=c11 -O2 template.c && ./a.out
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // IMPORTANTE: LeetCode usa bool en C
#include <string.h>

// --- 1. Función a Testear (Copiada exactamente de LeetCode) ---
int cmp_int(const void *a, const void *b) {
    int ia = *(const int *)a;
    int ib = *(const int *)b;
    return (ia > ib) - (ia < ib);
}

bool canMakeArithmeticProgression(int* arr, int arrSize) {
    // TODO: Tu lógica acá (ordenar el array y chequear las diferencias)
    if (arrSize <= 2) return true; // Cualquier array de 2 o menos elementos es AP
    qsort(arr, arrSize, sizeof(int), cmp_int); // Ordenamos el array
    int diff = arr[1] - arr[0];
    for (int i = 2; i < arrSize; i++) {
        if (arr[i] - arr[i - 1] != diff) return false; // Si la diferencia no es constante, no es AP
    }
    return true; // Si llegamos acá, es AP
}

// --- 2. Harness de Tests ---
// Adaptamos el struct a lo que pide este problema específico
typedef struct {
    int arr[10];      // Input: el array (tamaño fijo pequeño para los tests)
    int arrSize;      // Input: el tamaño real que le pasamos a la función
    bool expected;    // Output: lo que esperamos que devuelva (true o false)
} TestCase;

void run_tests() {
    // Acá definimos los ejemplos que te da LeetCode en la descripción
    TestCase cases[] = {
        // Example 1: arr = [3,5,1], Output: true
        { .arr = {3, 5, 1}, .arrSize = 3, .expected = true },
        
        // Example 2: arr = [1,2,4], Output: false
        { .arr = {1, 2, 4}, .arrSize = 3, .expected = false },

        // Exaxmple 3: arr = [-68,-96,-12,-40,16], expected = true
        { .arr = {-68, -96, -12, -40, 16}, .arrSize = 5, .expected = true }
    };

    size_t num_cases = sizeof(cases) / sizeof(cases[0]);
    for (size_t i = 0; i < num_cases; ++i) {
        // 1. Ejecutamos TU función pasándole los datos del test
        bool got = canMakeArithmeticProgression(cases[i].arr, cases[i].arrSize);

        // 2. Comparamos lo que devolvió (got) con lo que esperábamos (expected)
        if (got == cases[i].expected) {
            printf("✅ Test %zu: OK\n", i + 1);
        } else {
            printf("❌ Test %zu: FAIL (Expected: %s, Got: %s)\n", 
                   i + 1, 
                   cases[i].expected ? "true" : "false", 
                   got ? "true" : "false");
        }
    }
}

// --- 3. Main ---
int main(void) {
    run_tests();
    return 0;
}