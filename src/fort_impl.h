#ifndef FORT_IMPL_H
#define FORT_IMPL_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define FORT_COL_SEPARATOR '|'

#define FORT_UNUSED  __attribute__((unused))

#define F_CALLOC calloc
#define F_MALLOC malloc
#define F_REALLOC realloc
#define F_FREE free
#define F_STRDUP fort_strdup

#define F_CREATE(type) ((type *)F_CALLOC(sizeof(type), 1))

#define MAX(a,b) ((a) > (b) ? (a) : b)
#define MIN(a,b) ((a) < (b) ? (a) : b)


enum PolicyOnNull
{
    Create,
    DoNotCreate
};


enum F_BOOL
{
    F_FALSE = 0,
    F_TRUE = 1
};


#define STR_2_CAT_(arg1, arg2) \
    arg1##arg2
#define STR_2_CAT(arg1, arg2) \
    STR_2_CAT_(arg1, arg2)

#define UNIQUE_NAME_(prefix) \
    STR_2_CAT(prefix,__COUNTER__)
#define UNIQUE_NAME(prefix) \
    UNIQUE_NAME_(prefix)



/*****************************************************************************
 *               LOGGER
 *****************************************************************************/
#define SYS_LOG_ERROR(...)


/*****************************************************************************
 *               RETURN CODES
 * ***************************************************************************/
typedef int fort_status_t;
#define F_SUCCESS        0
#define F_MEMORY_ERROR   1
#define F_ERROR          2
#define IS_SUCCESS(arg) ((arg) == F_SUCCESS)
#define IS_ERROR(arg) (!IS_SUCCESS(arg))

/*****************************************************************************
 *               DEFAULT_SIZES
 * ***************************************************************************/
#define DEFAULT_STR_BUF_SIZE 1024
#define DEFAULT_VECTOR_CAPACITY 10



struct fort_table_options;
struct fort_column_options;
struct fort_row;
struct vector;
struct fort_cell;
struct string_buffer;


typedef struct fort_table_options fort_table_options_t;
typedef fort_table_options_t context_t;
typedef struct fort_column_options fort_column_options_t;
typedef struct vector vector_t;
typedef struct fort_cell fort_cell_t;
typedef struct string_buffer string_buffer_t;
typedef struct fort_row fort_row_t;
typedef struct fort_table FTABLE;





/*****************************************************************************
 *               LIBFORT helpers
 *****************************************************************************/
char *fort_strdup(const char* str);
size_t number_of_columns_in_format_string(const char *fmt);
int snprint_n_chars(char *buf, size_t length, size_t n, char ch);

#endif // FORT_IMPL_H