/* So, basically, in my home work, I should create functions to provide a dynamic array, where it can grow (if the memory
supports such thing) or simply disappear. It's the concept of arrayList that we all know and love. 
In my graduation, I'm studying now C for Algorithms, C# in objected-oriented programming, Assembly in PC Architecture (rather
die). As a newbie in this area for almost 9 months now, I'm trying to learn the new things and insert myself on the market.

And yes, I prefer back-end because it's so fun and I love to suffer.*/

#include "stdlib.h"
#include "array_int.h"

#ifndef ERROR_LISTA
#define NO_ERROR 0
#define MEMORY_ERROR 1
#define INDEX_ERROR 2
#define EMPTY_ERROR 3
#define ALLOC_ERROR 5
#endif

void Array_expand(struct DynIntArray * self, int *error){
	int *old = self->values;
	self->values = (int*) realloc(self->values, sizeof(int)*(self->capacity*=2));
	if (self->values != old)
	{
		free(old);
	}
	/* Pointless comparison, though I'm working with a condition for it */
}

struct DynIntArray * Array_new(int *error)
{
	struct DynIntArray * new;
	new = (struct DynIntArray*) malloc(sizeof(struct DynIntArray));
	int * a;
	*error = NO_ERROR;
	if (new != NULL)
	{
		a = (int*) malloc(sizeof(int)*8);
		if (a != NULL)
		{
			new->values = a;
			new->used = 0;
			new->capacity = 8;
		}
		else
		{
			*error = ALLOC_ERROR;
			free(new);
			new = NULL;
		}
	}
	else
	{
		*error = ALLOC_ERROR;
	}
	return new;
}

void Array_setAt(struct DynIntArray * self, int value, int index, int *error)
{
	*error = NO_ERROR;
	if (self == NULL)
	{
		*error = MEMORY_ERROR;
	}
	else
	{
		if (index >= 0 && index < self->used)
		{
			self->values[index] = value;
		}
		else
		{
			*error = INDEX_ERROR;
		}
	}
}

void Array_insertLast(struct DynIntArray * self, int value, int *error)
{
	*error = NO_ERROR;
	if (self == NULL)
	{
		*error = MEMORY_ERROR;
	}
	else
	{
		if (self->used >= self->capacity)
		{
			Array_expand(self,error);
		}
		if (self->values == NULL)
		{
			*error = ALLOC_ERROR;
		}
		if (*error == NO_ERROR)
		{
			self->values[self->used++] = value;
		}
	}
}

void Array_insertFirst(struct DynIntArray * self, int value, int *error)
{
	int aux = 0;
	int i;
	*error = NO_ERROR;
	if (self == NULL)
  	{
  		*error = MEMORY_ERROR;
  	}
  	else
  	{
  		if (self->used >= self->capacity)
  		{
  			Array_expand(self, error);
  		}
		if (self->values == NULL)
		{
			*error = ALLOC_ERROR;
		}
  		if (*error == NO_ERROR)
  		{
  			for (i = 0; i < self->used; i++)
  			{
  				aux = self->values[i];
  				self->values[i+1] = aux; 
  			}
  			self->values[0] = value;
  			self->used = self->used+1;
  		}
  	}
}

int Array_removeAt(struct DynIntArray * self, int index, int *error){ 
	int removedElem = 0;
	int i;
	*error = NO_ERROR;
	if (self == NULL)
	{
		*error = MEMORY_ERROR;
	}
	else
	{
		if (index < self->used)
		{
			removedElem = self->values[index];
			for (i = index; i < self->used; i++)
			{
				self->values[i] = self->values[i+1]; 
			}
			self->values[self->used--] = NULL; 
		}
		else
		{
			return *error = INDEX_ERROR;
		}
	}
	return removedElem;
}

int Array_removeLast(struct DynIntArray * self,  int *error){ 
	int aux = -1;
	int removedElem;
	*error = NO_ERROR;
	if (self == NULL)
	{
		*error = MEMORY_ERROR;
	}
	else
	{
		if (self->used != 0)
		{
			aux = self->used;
			removedElem = self->values[aux-1];
			self->values[aux-1] = NULL;
			self->used = aux-1;
			return removedElem;
		}
		else
		{
			*error = EMPTY_ERROR;
		}
	}
}

int Array_getAtIndex(struct DynIntArray * self, int index, int *error)
{
	int value = 0;
	*error = NO_ERROR;
	if (self == NULL)
	{
		*error = MEMORY_ERROR;
	}
	else
	{
		if (index < 0 || index >= self->used)
		{
			*error = INDEX_ERROR;
		}
		else
		{
			value = self->values[index];
		}
	}
	return value;
}

int Array_getIndexFor(struct DynIntArray * self, int value, int *error){ 
	int index;
	int i = -1;
	*error = NO_ERROR;
	if (self == NULL)
	{
		*error = MEMORY_ERROR;
	}
	else
	{
		for (index = 0; index < self->used; index++)
		{
			if (value == self->values[index])
			{
				i = index;
				return i;
			}
		}
		if(i == -1)
		{
			*error = INDEX_ERROR;
		}
	}
}

int Array_size(struct DynIntArray * self, int *error)
{
	int size = -1;
	*error = NO_ERROR;
	if (self == NULL)
	{
		*error = MEMORY_ERROR;
	}
	else
	{
		size = self->used;
	}
	return size;
}

int Array_capacity(struct DynIntArray * self, int *error)
{
	int size = -1; 
	*error = NO_ERROR; 
	if (self == NULL){
		*error = MEMORY_ERROR;
	}
	else {
		size = self->capacity;
	}
	return size;
}
