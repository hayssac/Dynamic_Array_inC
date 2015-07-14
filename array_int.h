/* Long story short: all I want to do is a dynamic array program, using structs and memory management. It's an array list */
/* There are 5 possible errors */

#ifndef ERROR_LIST
#define NO_ERROR 0      /* No error HUE  */
#define EMPTY_ERROR 1   /* The memory ptr gives you an empty space on your memory  */
#define INDEX_ERROR 2   /* The index you informed is invalid to current array */
#define ARRAY_ERROR 3   /* There are no items in this current array   */
#define ALLOC_ERROR 5   /* It wasnt possible do allocate memory for our modifications on our struct  */
#endif

#ifndef __DYN_INT_ARRAY__
#define __DYN_INT_ARRAY__

struct DynIntArray * Array_new(int *error);

void Array_setAt(struct DynIntArray * self, int value, int index, int *error);

void Array_insertLast(struct DynIntArray * self, int value, int *error);

void Array_insertFirst(struct DynIntArray * self, int value, int *error);

int Array_removeAt(struct DynIntArray * self, int index, int *error);

int Array_removeLast(struct DynIntArray * self,  int *error);

int Array_getAtIndex(struct DynIntArray * self, int index, int *error);

int Array_getIndexFor(struct DynIntArray * self, int value, int *error);

int Array_size(struct DynIntArray * self, int *error);

int Array_capacity(struct DynIntArray * self, int *error);

#endif /* __DYN_INT_ARRAY__ */
