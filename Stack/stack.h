#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <typeinfo>

#define Int_type

#ifdef Int_type
    typedef int DATA;
#endif // Int_type

#ifdef Double_type
    typedef double DATA;
#endif // Double_type

#ifdef Char_type
    typedef char DATA;
#endif // Char_type


static long long CANARY_DATA_LEFT = 0xDEDDEADAAADDDD;
static long long CANARY_DATA_RIGHT = 0xDEADDED;
static const int POISON = 1337228;
static const int SIZEOFEL = sizeof(DATA);
static const int NUMBOFCANARIES = 2;
static int INIT_SIZE = 100;


struct Stack {
    DATA *data;

    int sizeOfStack;
    int capacity;
    int err;

    unsigned int hashStack;
};

enum ErrorsStack {
    OK_WITH_STACK = 0,
    CANARY_DATA_LEFT_DAMAGED = 1,
    CANARY_DATA_RIGHT_DAMAGED = 2,
    NULL_PTR_TO_STACK_DATA = 3,
    STACK_SIZE_WRONG = 4,
    RECREATING_STACK = 5,
    HASH_DAMAGED = 6,
    EMPTY_STACK = 7,
    ALLOC_FAULT = 8,
    NULL_PTR_TO_STACK = 9,
    STACK_CAPACITY_WRONG = 10,
    STACK_DESTRUCTED = 11
};

void InitStack (Stack *st);

void PushStack (Stack *st, DATA value);

static void ResizeStackUp (Stack *st);

DATA PopStack (Stack *st);

DATA TopStack (Stack *st);

 void ResizeStackDown (Stack *st);

void DestructStack (Stack *st);

#endif // STACK_H_INCLUDED
