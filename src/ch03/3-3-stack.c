#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef int ElementType; /* 假设结点数据是整数 */
typedef int Position;
typedef struct SNode *PtrToSNode;

struct SNode {
  ElementType *Data; /* 存储元素的数组 */
  Position Top;      /* 栈顶指针 */
  int MaxSize;       /* 堆栈最大容量 */
};

typedef PtrToSNode Stack;

Stack CreateStack(int MaxSize) {
  Stack S = (Stack)malloc(sizeof(struct SNode));
  S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
  S->Top = -1;
  S->MaxSize = MaxSize;
  return S;
}

bool IsFull(Stack S) { return (S->Top == S->MaxSize - 1); }

bool Push(Stack S, ElementType X) {
  if (IsFull(S)) {
    printf("堆栈满\n");
    return false;
  } else {
    S->Data[++(S->Top)] = X;
    return true;
  }
}

bool IsEmpty(Stack S) { return (S->Top == -1); }

ElementType Pop(Stack S) {
  if (IsEmpty(S)) {
    printf("堆栈空\n");
    return ERROR; /* ERROR 是 ElementType 的特殊值，标志错误 */
  } else
    return (S->Data[(S->Top)--]);
}

int main() {
  int maxSize = 10;               // 定义栈的最大容量
  Stack S = CreateStack(maxSize); // 创建一个栈

  // 测试入栈操作
  printf("开始入栈操作...\n");
  for (int i = 1; i <= maxSize; i++) {
    if (Push(S, i)) {
      printf("入栈元素: %d\n", i);
    } else {
      printf("入栈失败，栈已满\n");
    }
  }

  // 测试栈满情况
  printf("尝试在栈满时入栈...\n");
  if (!Push(S, 11)) {
    printf("入栈失败，栈已满\n");
  }

  // 测试出栈操作
  printf("开始出栈操作...\n");
  while (!IsEmpty(S)) {
    ElementType element = Pop(S);
    if (element != ERROR) {
      printf("出栈元素: %d\n", element);
    } else {
      printf("出栈失败，栈已空\n");
    }
  }

  // 测试栈空情况
  printf("尝试在栈空时出栈...\n");
  ElementType element = Pop(S);
  if (element == ERROR) {
    printf("出栈失败，栈已空\n");
  }

  // 释放栈的内存
  free(S->Data);
  free(S);

  return 0;
}