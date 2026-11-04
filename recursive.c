#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char s[100];
int i = 0;

void E(), Eprime(), T(), Tprime(), F();

void match(char c) {
    if (s[i] == c) {
        printf("Matched: '%c'\n", c);
        i++;
    } else {
        printf("Syntax Error\n");
        exit(0);
    }
}

void F() {
    if (s[i] == '(') {
        printf("Entering F -> (E)\n");
        match('(');
        E();
        match(')');
        printf("Exiting F -> (E)\n");
    } else if (isalpha(s[i])) {
        printf("Entering F -> id\nMatched identifier: '%c'\nExiting F -> id\n", s[i++]);
    } else {
        printf("Syntax Error\n");
        exit(0);
    }
}

void Tprime() {
    if (s[i] == '*') {
        printf("Entering T' -> * F T'\n");
        match('*');
        F();
        Tprime();
        printf("Exiting T' -> * F T'\n");
    } else {
        printf("T' -> ε\n");
    }
}

void T() {
    printf("Entering T -> F T'\n");
    F();
    Tprime();
    printf("Exiting T -> F T'\n");
}

void Eprime() {
    if (s[i] == '+') {
        printf("Entering E' -> + T E'\n");
        match('+');
        T();
        Eprime();
        printf("Exiting E' -> + T E'\n");
    } else {
        printf("E' -> ε\n");
    }
}

void E() {
    printf("Entering E -> T E'\n");
    T();
    Eprime();
    printf("Exiting E -> T E'\n");
}

int main() {
    printf("Enter an expression: ");
    scanf("%s", s);
    E();
    if (s[i] == '\0')
        printf("Parsing successful.\n");
    else
        printf("Syntax Error\n");
    return 0;
}
