/* 
 * m4bf - macro brainfuck
 * Copyright (C) 2011  Federico Culloca <djthrottle@gmail.com>
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

#include "bf_mem.h"

static unsigned char *memory;	/*bf program memory */
static unsigned int mem_ptr;	/*points to the current program memory cell */

/*
 * bf_init_memory()
 * Allocates and zeroes the program memory.
 * Returns non-zero on success.
 */
int
bf_init_memory ()
{
  memory = (unsigned char *) calloc (MAX_MEMORY_SIZE, sizeof (unsigned char));
  mem_ptr = 0;
  return memory != NULL;
}

/*
 * bf_free_memory()
 * Frees the memory area containing the program memory.
 */
void
bf_clean_memory ()
{
  if (memory)
    free (memory);
}

/*
 * bf_inc_mem_cell(int)
 * With a non-negative argument, increments by one the program memory cell
 * pointed to by mem_ptr. With a negative arguments decrements it by one.
 */
void
bf_inc_mem_cell (int n)
{
  memory[mem_ptr] += n;
}

/*
 * bf_move_mem_ptr(int)
 * With a non-negative arguments, it moves one step forward the program memory
 * pointer. With a negative argument, it moves it one step backward.
 * If the pointer is already at program memory's boundaries it does nothing.
 */
void
bf_move_mem_ptr (int direction)
{
  if (direction >= 0 && mem_ptr < MAX_MEMORY_SIZE)
    mem_ptr++;
  else if (direction < 0 && mem_ptr > 0)
    mem_ptr--;
}

/*
 * bf_get_mem_content()
 * Returns the content of the program memory cell pointed by mem_ptr .
 */
unsigned char
bf_get_mem_content (void)
{
  return memory[mem_ptr];
}

/*
 * bf_set_mem_val(unsigned char)
 * Sets the value of the program memory cell pointed by mem_ptr to the value
 * of the given argument.
 */
void
bf_set_mem_val (unsigned char n)
{
  memory[mem_ptr] = n;
}

/*
 * bf_get_cur_mem_ptr(void)
 * Returns the value of the current memory pointer.
 */
unsigned int
bf_get_cur_mem_ptr (void)
{
  return mem_ptr;
}

/*
 * bf_set_cur_mem_ptr(unsigned int)
 * Sets the memory pointer to the location given as parameter
 */
void
bf_set_cur_mem_ptr (unsigned int n)
{
  mem_ptr = n;
}
