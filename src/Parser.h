#include "util/LinkedList.h"
#ifndef PARSER_H
#define PARSER_H

int parse_infix_postfix(char* expr, char* dest);
void tokenize(const char* str, LinkedList* dest);

#endif