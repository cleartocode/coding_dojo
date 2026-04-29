// Compilar y correr: gcc -std=c11 -O2 template.c && ./a.out
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

// --- 1. Definiciones de Problema ---
/* 
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
 

Constraints:

0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.
*/

typedef struct { const char *s; const char *t; } Input;

/*
SPEC:
- Entradas: 
  - s: cadena de caracteres a verificar como subsecuencia
  - t: cadena de caracteres en la que se busca la subsecuencia
- Salidas: 
  - true si s es una subsecuencia de t, false en caso contrario
*/

// --- 2. Función a Testear ---
bool isSubsequence(const char *s, const char *t) {
    while (*s && *t) {
        if (*s == *t) {
            s++;
        }
        t++;
    }
    return *s == '\0';
}

// --- 3. Harness de Tests ---
typedef struct {
    Input items[2]; 
    bool expected[2]; 
} TestCase;

void run_tests() {
    TestCase cases[] = {
        { .items = {{"abc", "ahbgdc"}, {"axc", "ahbgdc"}}, .expected = {true, false}},
    };

    size_t num_cases = sizeof(cases) / sizeof(cases[0]);
    for (size_t i = 0; i < num_cases; ++i) {
        int pass = 1;
        for (size_t j = 0; j < 2; ++j) {
            if (isSubsequence(cases[i].items[j].s, cases[i].items[j].t) != cases[i].expected[j]) {
                pass = 0;
            }
            if (pass) printf("✅ Test %zu: OK\n", i + 1);
            else printf("❌ Test %zu: FAIL (Mismatched output)\n", i + 1);
        }
    }
}

// --- 4. Main ---
int main() {
    run_tests();
    return 0;
}