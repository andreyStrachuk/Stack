#ifndef VERIFICATOR_H_INCLUDED
#define VERIFICATOR_H_INCLUDED

#include <stdio.h>
#include <assert.h>
#include "stack.h"

#define NDEBUG


#define ASSERTION_CHECK(st)          checkIfStackIsValid (st); \
                                     ASSERT_OK(st->err != OK_WITH_STACK, st, st->err, return;)



#define Dump(st, DATA, ERROR)        FILE *dump = fopen ("dump.txt", "w"); \
                                     PrintError (ERROR); \
                                     FPrintError (dump, ERROR); \
                                     fprintf (dump, "Stack  <%s>  [%p]  \"%s\"  %s  at  %s(%d)\n", typeid(DATA).name(), st, #st, __PRETTY_FUNCTION__, __FILE__, __LINE__); \
                                     if (st != nullptr) { \
                                        if (st->err != STACK_DESTRUCTED)\
                                        DumpStack (st, dump); \
                                     } \
                                     fclose (dump); \
                                     exit (0);


#ifdef NDEBUG
    #define ASSERT_OK(smth, st, ERROR, todo) if (smth) { st->err = ERROR; Dump(st, DATA, ERROR); todo }
#endif // NDEBUG

#ifndef NDEBUG
    #define ASSERT_OK(smth, st, ERROR, todo) if (smth) { st->err = ERROR; PrintError (ERROR); todo }
#endif


void PrintError (int error);

void PrintElem (DATA value);

void FPrintElem (FILE *file, DATA value);

void FPrintError (FILE *file, int error);

void PrintStack (Stack *st);

void checkIfStackIsValid (Stack *st);

unsigned int MurmurHash2 (Stack *st);

void DumpStack (Stack *st, FILE *dump);

void ALLOCATION_ASSERT (Stack *st);

#endif // VERIFICATOR_H_INCLUDED
