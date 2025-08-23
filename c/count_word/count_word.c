// Compilar y correr (test): gcc -std=c11 -O2 template.c && ./a.out
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*
Problem: Count the number of words in a given sentence.

Specs:
- Inputs: A String
- Output: an int representing the number of words in the string
- Rules: Words are separated by spaces or punctuation
- Edge cases: Empty string, multiple spaces, punctuation
*/

// Define data structures here
typedef struct {
    int numWords;
    char* sentence;
} WordCounter;

// --- mini harness ---
typedef struct {
    WordCounter* (*solution)(const char*);
    int expected;
} TestCase;

// Solution function
WordCounter* word_counter(const char* sentence) {
    WordCounter* wc = malloc(sizeof(WordCounter));
    wc->sentence = strdup(sentence);
    wc->numWords = 0;

    char* copy = strdup(sentence);  // Duplicate string for tokenization
    char* token = strtok(copy, " ,.!?;:\n\t");
    while (token) {
        wc->numWords++;
        token = strtok(NULL, " ,.!?;:\n\t");
    }
    free(copy);
    return wc;
}

void free_wc(WordCounter* wc) {
    if (wc) {
        free(wc->sentence);
        free(wc);
    }
}

int main(void) {
    TestCase testCases[] = {
        {word_counter, 5}, // "Hello, world! This is C." -> 5 words
        {word_counter, 0}, // "" -> 0 words
        {word_counter, 4}, // "   Leading and trailing spaces   " -> 4 words
        {word_counter, 4}, // "Punctuation! Should; not: affect?" -> 4 words
        {word_counter, 1}, // "SingleWord" -> 1 word
    };
    const char* inputs[] = {
        "Hello, world! This is C.",
        "",
        "   Leading and trailing spaces   ",
        "Punctuation! Should; not: affect?",
        "SingleWord"
    };
    int numTests = sizeof(testCases) / sizeof(TestCase);
    for (int i = 0; i < numTests; i++) {
        WordCounter* result = testCases[i].solution(inputs[i]);
        assert(result->numWords == testCases[i].expected);
        printf("✅ Test %d passed! -> ", i + 1);
        printf("Input: \"%s\" | Expected: %d | Got: %d\n", inputs[i], testCases[i].expected, result->numWords);
        free_wc(result);
    }
    printf("All tests passed! 👍🏽\n");
    return 0;
}
