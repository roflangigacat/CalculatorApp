#ifndef SRC_SMARTCALC_H_
#define SRC_SMARTCALC_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIGNS const char ops[] = "+-*/%^sScCtTlLq~_()";
#define PRIORITY const char pri[] = "1122223333333332299";

typedef union {
  double number;
  char op;
} Data;

typedef struct stack {
  Data data;
  struct stack *next;
} Stack;

void Push(Stack **s, Data data);
Data Pop(Stack **s);
void DeleteStack(Stack **s);
Data FindTopElement(Stack **s);
int IsBinary(char op);
int IsUnary(char op);
int FindSignPriority(char op);
void SkipNum(char **str);
int IsNum(char c);
void SwapNames(char *str, char *res);
int ApplyBinaryOperator(Stack **nums, Stack **ops);
int ApplyUnaryOperator(Stack **nums, Stack **ops);
double calculate(char *str, double x);

#endif // SRC_SMARTCALC_H_