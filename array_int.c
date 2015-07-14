/* Commentary soon  */

#include "stdio.h"
#include "stdlib.h"
#include "array_int.h"
 
void Array_expand(struct DynIntArray * self, int *error){
	int *old = self->values;
	self->values = (int*) realloc(self->values, sizeof(int)*(self->capacity*=2));
	if (self->values != old)
	{
		free(self);
	}
	else
	{
		free(old);
	}
}

struct DynIntArray * Array_new(int *error)
{
	struct DynIntArray * new;
	new = (struct DynIntArray*) malloc(sizeof(struct DynIntArray));
	int * a;
	*error = 0;
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
			*error = 5;
			free(new);
			new = NULL;
		}
	}
	else
	{
		*error = 5;
	}
	return new;
}

void Array_setAt(struct DynIntArray * self, int value, int index, int *error)
{
	*error = 0;
	if (self == NULL)
	{
		*error = 1;
	}
	else
	{
		if (index >= 0 && index < self->used)
		{
			self->values[index] = value;
		}
		else
		{
			*error = 2;
		}
	}
}

void Array_insertLast(struct DynIntArray * self, int value, int *error)
{
	*error = 0;
	if (self == NULL)
	{
		*error = 1;
	}
	else
	{
		if (self->used >= self->capacity)
		{
			Array_expand(self,error);
		}
		if (self->values == NULL)
		{
			*error = 5;
		}
		if (*error == 0)
		{
			self->values[self->used++] = value;
		}
	}
}

void Array_insertFirst(struct DynIntArray * self, int value, int *error){
  *error = 0;
  int aux = 0;
  if (self == NULL)
  	{
  		*error = 1;
  	}
  else
  	{
  		if (self->used >= self->capacity)
  		{
  			Array_expand(self, error);
  		}
		if (self->values == NULL)
		{
			*error = 5;
		}
  		if (*error == 0)
  		{
  			for (int i = 0; i < self->used; i++)
  			{
  				aux = values[i];
  				values[i+1] = aux; 
  			}
  			values[0] = value;
  		}
  	}
}

int Array_removeAt(struct DynIntArray * self, int index, int *error){ 
	int removedElem = 0;
	if (self == NULL)
	{
		*error = 1;
	}
	else
	{
		if (index < self->used)
		{
			removedElem = self->values[index];
			for (i = index; i < self->used; i++)
			{
				values[i] = values[i+1] /* Substitui o valor do índice informado pelo seguinte*/
			}
			self->values[self->used--] = NULL; /* Decresce o último elemento */
		}
		else
		{
			*error = 2;
		}
	}
	return removedElem;
}

int Array_removeLast(struct DynIntArray * self,  int *error){ 
	*error = 0;
	int removedElem;
	if (self == NULL)
	{
		*error = 1;
	}
	else
	{
		if (self->used != 0])
		{
			removedElem = self->values[used-1];
			self->values[self->used--] = NULL;
		}
		else
		{
			*error = 3;
		}
	}
	return removedElem;
}

int Array_getAtIndex(struct DynIntArray * self, int index, int *error)
{
	int value = 0;
	*error = 0;
	if (self == NULL)
	{
		*error = 1;
	}
	else
	{
		if (index < 0 || index >= self->used)
		{
			*error = 2;
		}
		else
		{
			value = self->values[index];
		}
	}
	return value;
}

int Array_getIndexFor(struct DynIntArray * self, int value, int *error){ 
	int index = 0;
	*error = 0;

	if(self == NULL){
		*error = 1;
	}
	else{
		for (int index, index < self-> used, index++)
		{
			if (self->values[index] == value)
			{
				return index;	
			}
			else
			{
				*error = 2;
			}
		}
	}
}

int Array_size(struct DynIntArray * self, int *error)
{
	int size = -1;
	*error = 0;
	if (self == NULL)
	{
		*error = 1;
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
	*error = 0; 
	if (self == NULL){
		*error = 1;
	}
	else {
		size = self->capacity;
	}
	return size;
}
