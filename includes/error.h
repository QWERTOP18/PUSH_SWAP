
#ifndef ERROR_H
#define ERROR_H

typedef enum s_err
{
    E_NONE=0,
    E_OPERATION=1,
    E_ALLOCATE,
    E_INT_OVERFLOW,
    E_INVALID_INPUT,
    E_DUPLICATE_VALUE,
    // E_LIST_EMPTY,
    // E_LIST_FULL,
} t_err;

#endif