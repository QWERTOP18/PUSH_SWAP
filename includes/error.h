
#ifndef ERROR_H
#define ERROR_H

typedef enum s_err
{
    E_NONE=0,
    E_OPERATION=1,
    E_ALLOCATE=2,
    E_INVALID_INPUT=4,
    E_DUPLICATE_VALUE=8,
    // E_LIST_EMPTY,
    // E_LIST_FULL,
} t_err;

#endif