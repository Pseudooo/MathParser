#ifndef OPERATORS_H
#define OPERATORS_H

int is_operator(char* str);

int ADD(int x1, int x2);
int SUB(int x1, int x2);
int MUL(int x1, int x2);
int DIV(int x1, int x2);

extern const int OPERATOR_COUNT;
extern const char* OPERATOR_STR[];
extern const int (*ops[]) (int x1, int x2);

#endif
