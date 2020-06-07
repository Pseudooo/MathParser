#ifndef OPERATORS_H
#define OPERATORS_H

int is_operator(char* str);

int ADD(int x1, int x2);
int SUB(int x1, int x2);
int MUL(int x1, int x2);
int DIV(int x1, int x2);

const int OPERATOR_COUNT = 4;
const char* OPERATOR_STR[] = {"+", "-", "*", "/"};
const (*ops[]) (int x1, int x2) = {ADD, SUB, MUL, DIV};

#endif
