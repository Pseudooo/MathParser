#ifndef OPERATORS_H
#define OPERATORS_H

int is_operator(const char* str);
int operator_prec(const char* str);
int evaluate_operator(const char* op, int x1, int x2);

extern const int OPERATOR_COUNT;
extern const char* OPERATOR_STR[];
extern const int OPERATOR_PREC[];

#endif
