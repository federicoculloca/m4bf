/* 
 * m4bf - macro brainfuck
 * Copyright (C) 2011  Federico Culloca <federicoculloca@gmail.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#include <stdlib.h>

#include "bf_stack.h"

/*
 * bf_stack_init(bf_stack*, unsigned int)
 * allocates memory for the stack and initializes struct's members.
 * Returns non-zero on success.
 */
int
bf_stack_init (bf_stack * s, unsigned int size)
{
  s->ptr = 0;
  s->content = (unsigned int *) calloc (size, sizeof (unsigned int));
  s->size = size;
  return s->content != NULL;
}

/*
 * bf_stack_push(bf_stack*, unsigned int)
 * Pushes an element on top of the stack. If the stack is full it does nothing.
 */
void
bf_stack_push (bf_stack * s, unsigned int elm)
{
  if (s->ptr < s->size)
    s->content[s->ptr++] = elm;
}

/*
 * bf_stack_pop(bf_stack*)
 * Removes the element on top of the stack and removes it from the stack.
 * If the stack is empty, returns a negative value.
 */
int
bf_stack_pop (bf_stack * s)
{
  if (!bf_stack_is_empty (s))
    return s->content[--s->ptr];
  return -1;
}

/*
 * bf_stack_peek(bf_stack*)
 * Returns the element on top of the stack.
 */
int
bf_stack_peek (bf_stack * s)
{
  return s->content[s->ptr - 1];
}

/*
 * bf_stack_is_empty(bf_stack*)
 * returns non-zero if the stack is empty.
 */
int
bf_stack_is_empty (bf_stack * s)
{
  return s->ptr == 0;
}

/*
 * bf_stack_destroy(bf_stack*)
 * Frees the area pointed to by the stack content.
 */
void
bf_stack_destroy (bf_stack * s)
{
  if (s->content)
    free (s->content);
}
