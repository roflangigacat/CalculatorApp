#include "SmartCalc.h"

void Push(Stack **s, Data data) {
  Stack *new_node = malloc(sizeof(Stack));
  new_node->data = data;
  if (!(*s)) {
    *s = new_node;
    (*s)->next = NULL;
  } else {
    new_node->next = *s;
    *s = new_node;
  }
}

Data Pop(Stack **s) {
  Data result;
  if (*s) {
    result = (*s)->data;
    Stack *delete = *s;
    *s = (*s)->next;
    free(delete);
  } else {
    result.op = '\0';
  }
  return result;
}

void DeleteStack(Stack **s) {
  while (*s) {
    Pop(s);
  }
}

Data FindTopElement(Stack **s) {
  Data result = {0};
  if (*s) {
    result = (*s)->data;
  }
  return result;
}

int IsBinary(char op) {
  SIGNS;
  int result;
  if (strchr(ops, op) - ops < 6) {
    result = 1;
  } else {
    result = 0;
  }
  return result;
}

int IsUnary(char op) {
  SIGNS;
  int result;
  if (strchr(ops, op) - ops > 6 && strchr(ops, op) - ops < 17) {
    result = 1;
  } else {
    result = 0;
  }
  return result;
}

int FindSignPriority(char op) {
  SIGNS;
  PRIORITY;
  char *pos = strchr(ops, op);
  int result = -1;
  if (pos)
    result = pri[pos - ops] - '0';
  return result;
}

void SkipNum(char **str) {
  int dots = 0;
  while (**str && dots < 2 &&
         ((**str >= '0' && **str <= '9') || **str == '.')) {
    if (**str == '.')
      ++dots;
    ++(*str);
  }
}

int IsNum(char c) {
  int result;
  if (c >= '0' && c <= '9') {
    result = 1;
  } else {
    result = 0;
  }
  return result;
}

void SwapNames(char *str, char *res) {
  char *c = str;
  char *new_c = res;
  for (size_t i = 0; i < strlen(str); i++) {
    if (*c == ' ') {
      c++;
      continue;
    } else if (c[0] == 'a' && c[1] == 'c' && c[2] == 'o' && c[3] == 's') {
      *new_c = 'C';
      c += 3;
    } else if (c[0] == 'a' && c[1] == 's' && c[2] == 'i' && c[3] == 'n') {
      *new_c = 'S';
      c += 3;
    } else if (c[0] == 'a' && c[1] == 't' && c[2] == 'a' && c[3] == 'n') {
      *new_c = 'T';
      c += 3;
    } else if (c[0] == 's' && c[1] == 'i' && c[2] == 'n') {
      *new_c = 's';
      c += 2;
    } else if (c[0] == 'c' && c[1] == 'o' && c[2] == 's') {
      *new_c = 'c';
      c += 2;
    } else if (c[0] == 't' && c[1] == 'a' && c[2] == 'n') {
      *new_c = 't';
      c += 2;
    } else if (c[0] == 'l' && c[1] == 'n') {
      *new_c = 'l';
      c += 1;
    } else if (c[0] == 'l' && c[1] == 'o' && c[2] == 'g') {
      *new_c = 'L';
      c += 2;
    } else if (c[0] == 's' && c[1] == 'q' && c[2] == 'r' && c[3] == 't') {
      *new_c = 'q';
      c += 3;
    } else if (c[0] == 'm' && c[1] == 'o' && c[2] == 'd') {
      *new_c = '%';
      c += 2;
    } else if ((c[0] == '-' &&
                (IsNum(c[1]) || c[1] == 'X' || c[1] == 'x' || c[1] == '(' ||
                 strchr("CSTsctlLq%", c[1])) &&
                *(c - 1) != ')' && !IsNum(*(c - 1)))) {
      *new_c = '~';
    } else if ((c[0] == '+' &&
                (IsNum(c[1]) || c[1] == 'X' || c[1] == 'x' || c[1] == '(' ||
                 strchr("CSTsctlLq%", c[1])) &&
                *(c - 1) != ')' && !IsNum(*(c - 1)))) {
      *new_c = '_';
    } else {
      *new_c = *c;
    }
    ++c;
    ++new_c;
  }
}

int ApplyBinaryOperator(Stack **nums, Stack **ops) {
  Data pop1, pop2, oper;
  int res = 0;
  if (*nums && *ops) {
    pop1 = Pop(nums);
  } else {
    res = 1;
  }
  if (*nums) {
    pop2 = Pop(nums);
  } else {
    res = 1;
  }
  oper = Pop(ops);
  double result;
  switch (oper.op) {
  case '+':
    result = pop2.number + pop1.number;
    break;
  case '-':
    result = pop2.number - pop1.number;
    break;
  case '*':
    result = pop2.number * pop1.number;
    break;
  case '/':
    result = pop2.number / pop1.number;
    break;
  case '^':
    result = pow(pop2.number, pop1.number);
    break;
  case '%':
    result = fmod(pop2.number, pop1.number);
    break;
  }
  Data to_push;
  to_push.number = result;
  Push(nums, to_push);
  return res;
}

int ApplyUnaryOperator(Stack **nums, Stack **ops) {
  int res = 0;
  if (*nums != NULL && *ops != NULL) {
    double num = Pop(nums).number;
    char oper = Pop(ops).op;
    double result;
    switch (oper) {
    case 's':
      result = sin(num);
      break;
    case 'c':
      result = cos(num);
      break;
    case 't':
      result = tan(num);
      break;
    case 'C':
      result = acos(num);
      break;
    case 'S':
      result = asin(num);
      break;
    case 'T':
      result = atan(num);
      break;
    case 'q':
      result = sqrt(num);
      break;
    case 'l':
      result = log(num);
      break;
    case 'L':
      result = log10(num);
      break;
    }
    Data to_push;
    to_push.number = result;
    Push(nums, to_push);
  } else {
    res = 1;
  }
  return res;
}

double calculate(char *str, double x) {
  int is_error = 0;
  char sstr[1024] = {0};
  SwapNames(str, sstr);
  char *strptr = sstr;
  Stack *nums = NULL;
  Stack *ops = NULL;
  while (*strptr) {
    if (IsNum(*strptr)) {
      double num;
      sscanf(strptr, "%lf", &num);
      SkipNum(&strptr);
      Data to_push;
      to_push.number = num;
      Push(&nums, to_push);
    } else {
      if (*strptr == '(') {
        Data to_push;
        to_push.op = *strptr;
        Push(&ops, to_push);
        ++strptr;
      } else if (*strptr == 'X' || *strptr == 'x') {
        Data pushX;
        pushX.number = x;
        Push(&nums, pushX);
        ++strptr;
      } else if (*strptr == '~') {
        Data PushBinaryMinus;
        Data Minis;
        Minis.op = '-';
        PushBinaryMinus.number = 0;
        Push(&nums, PushBinaryMinus);
        Push(&ops, Minis);
        ++strptr;
      } else if (*strptr == '_') {
        ++strptr;
      } else if (*strptr == ')') {
        while (ops && FindTopElement(&ops).op != '(') {
          if (IsBinary(FindTopElement(&ops).op))
            is_error = ApplyBinaryOperator(&nums, &ops);
          else
            is_error = ApplyUnaryOperator(&nums, &ops);
        }
        if (ops)
          Pop(&ops);
        ++strptr;
      } else if (ops && FindTopElement(&ops).op != '(' &&
                 FindSignPriority(FindTopElement(&ops).op) >=
                     FindSignPriority(*strptr)) {
        while (ops && nums && FindTopElement(&ops).op != '(' &&
               FindSignPriority(FindTopElement(&ops).op) >=
                   FindSignPriority(*strptr))
          if (IsBinary(FindTopElement(&ops).op))
            is_error = ApplyBinaryOperator(&nums, &ops);
          else
            is_error = ApplyUnaryOperator(&nums, &ops);
        Data yo;
        yo.op = *strptr;
        ++strptr;
        Push(&ops, yo);
      } else {
        Data to_push;
        to_push.op = *strptr;
        ++strptr;
        Push(&ops, to_push);
      }
    }
  }
  while (ops && nums)
    if (IsBinary(FindTopElement(&ops).op))
      is_error = ApplyBinaryOperator(&nums, &ops);
    else
      is_error = ApplyUnaryOperator(&nums, &ops);
  Data result = Pop(&nums);
  DeleteStack(&nums);
  DeleteStack(&ops);
  if (is_error) {
    result.number = NAN;
  }
  return result.number;
}