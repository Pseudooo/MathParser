#ifndef TEST_H
#define TEST_H

void init_test_suite(int total_cases, char* name, char* desc);

void assert_eq_int(int exp, int act);
void assert_eq_str(char* exp, char* act);

void terminate_test_suite();

#endif