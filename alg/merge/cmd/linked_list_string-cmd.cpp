/* R. Fabbri, 2024 */
#include <linked_list_string.h> // Keep this if you use it elsewhere
#include <iostream>
#include <cstdlib>  // Required for malloc() and free()
#include <cstring>  // Required for strncpy()
#include <cstdio>   // Required for printf()

#define MAX 64

struct No {
    char name[MAX];
    No *next;
};

typedef No *Lista;

void lista2() {
    std::cout << "teste" << std::endl;

    // ERROR: The line "Lista2;" was here and has been removed.

    No *l;
    // In C++, it's more common to use: l = new No;
    l = (No *) malloc(sizeof(No));

    // It's good practice to check if malloc succeeded
    if (l == NULL) {
        return; // Exit if memory allocation failed
    }

    l->name[0] = '\0'; // Initialize the string
    l->next = NULL;    // Always initialize pointers

    // CORRECTION: Replaced std::end with std::endl
    std::cout << "String vazia: [" << std::string(l->name) << "]" << std::endl;
    // CORRECTION: Replaced std::end with std::endl
    std::cout << "teste" << std::endl;

    printf("Nome antes da copia: [%s]\n", l->name);
    
    // Copy the string into the allocated space
    strncpy(l->name, "joao", MAX - 1);
    l->name[MAX - 1] = '\0'; // Ensure the string is null-terminated

    printf("Nome depois da copia: [%s]\n", l->name);

    // FIX: Free the memory allocated by malloc to prevent a memory leak.
    // If you had used 'new', you would use 'delete l;' here.
    free(l);

    // ERROR: The line "return 0;" was here and has been removed because the function is void.
}

// You can add a main function like this to test your code
int main() {
    lista2();
    return 0;
}
