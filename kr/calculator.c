/*
Reverse Polish Calculator

The C Programming Language
Pages before 79
Exercises 4-3 ...

*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
void put(double);
double pop(void);
double get(void);
void clear(void);
void swap(void);
void show(void);
void duplicate_last(void);
int getop(char []);

int main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
	switch (type) {
	case NUMBER:
	    put(atof(s));
	    break;
	case '+':
	    put(pop() + pop());
	    break;
	case '*':
	    put(pop() * pop());
	    break;
	case '-':
	    op2 = pop();
	    put(pop() - op2);
	    break;
	case '/':
	    op2 = pop();
	    if (op2 != 0.0)
		put(pop() / op2);
	    else
		printf("Error: zero divisor.\n");
	    break;
	case '%':
	    op2 = pop();
	    put((int) pop() % (int) op2);
	    break;
	case '\n':
	    printf("\t%.8g\n", get());
	    break;
	case 'h':
	    printf("Help - available commands:\n");
	    printf("\tOperators:      + - * / %%\n");
	    printf("\tClear stack:    c\n");
	    printf("\tShow stack:     s\n");
	    printf("\tSwap last 2:    w\n");
	    printf("\tDuplicate last: d\n");
	    printf("\tShow help:   h\n");
	    break;
	case 'c':
	    clear();
	    break;
	case 's':
	    show();
	    break;
	case 'w':
	    swap();
	    break;
	case 'd':
	    duplicate_last();
	    break;
	default:
	    printf("Error: unknown command %s.\n", s);
	    break;
	}
    }
    return 0;
}



int getop(char s[]) {
    int getch(void);
    void ungetch(int);
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t');

    s[1] = '\0';

    if (!isdigit(c) && c != '.')
	return c;

    i = 0;
    if (isdigit(c))
	while (isdigit(s[++i] = c = getch()));

    if (c == '.')
	while (isdigit(s[++i] = c = getch()));

    s[i] = '\0';

    if (c != EOF)
	ungetch(c);

    return NUMBER;

}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) {
    if (bufp >= BUFSIZE)
	printf("Error: nuffer to small\n");
    else
	buf[bufp++] = c;
}

/**********************************************
*************** Stack Handling ***************
************************************************/

#define STACK_SIZE 100
double stack[STACK_SIZE];
int stack_ct = 0;
void put(double x) {
    if (stack_ct >= STACK_SIZE)
	printf("Error: stack full.\n");
    else
	stack[stack_ct++] = x;
}
double pop(void) {
    if (stack_ct == 0) {
	printf("Error: Stack empty.\n");
	return 0.0;
    }
    return stack[--stack_ct];
}
double get(void) {
    return stack[stack_ct-1];
}
void clear(void) {
    stack_ct = 0;
}
void show(void) {
    printf("Stack size: %d\n    ", stack_ct);
    for (int i=0; i < stack_ct; i++)
        printf("%.2g  ", stack[i]);
    printf("\n");
}
void swap(void) {
    if (stack_ct >= 2) {
        double tmp = stack[stack_ct-1];
        stack[stack_ct-1] = stack[stack_ct-2];
        stack[stack_ct-2] = tmp;
    } else
	printf("Stack has less than 2 elements.\n");
}
void duplicate_last(void) {
    put(stack[stack_ct-1]);
}
