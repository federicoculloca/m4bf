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
#include <stdio.h>
#include <string.h>

#include "bf_interpreter.h"
#include "bf_mem.h"
#include "bf_stack.h"

/*TODO: allow user defined size for stacks, maybe with a command-line switch?*/
#define MAX_NESTED_LOOPS 100	/*The maximum allowed number of nested loops */
#define U_STACK_SIZE	 100	/*The size of the user's stack */

/*stacks*/
static bf_stack l_stack;	/*loop bf_stack */
static bf_stack u_stack;	/*user's bf_stack */

/*interpreter stuff*/
static int pc;			/*program counter */
static char *source_code = NULL;

/*
 * bf_read_source_file(char*)
 * Loads the source file into memory.
 * Returns non-zero on success.
 */
char *
bf_read_source_file (char *file_name)
{
#define BLOCKSIZE 56
  FILE *source_file = fopen (file_name, "r");
  int offset = 0;
  int last_read = 0;
  if (!source_file)
    return NULL;
  while (!feof (source_file))
    {
      source_code = (char *) realloc (source_code, BLOCKSIZE * ++offset);
      last_read +=
	fread (source_code + BLOCKSIZE * (offset - 1), sizeof (char),
	       BLOCKSIZE, source_file);
    }
  fclose (source_file);
  source_code[last_read + 1] = '\0';
  return source_code;
}

/*
 * bf_interpret()
 * Runs the program stored in memory.
 * Retruns non-zero if there was no runtime error.
 * TODO: implement some sort of batching for groups of identical instructions?
 */
int
bf_interpreter ()
{
  int prog_size = strlen (source_code) - 1;
  do
    {
      /*TODO: this big switch sucks: find a better way */
      switch (source_code[pc])
	{
	case '+':
	  bf_inc_mem_cell (1);
	  break;
	case '-':
	  bf_inc_mem_cell (-1);
	  break;
	case '<':
	  bf_move_mem_ptr (-1);
	  break;
	case '>':
	  bf_move_mem_ptr (1);
	  break;
	case '.':
	  fputc (bf_get_mem_content (), stdout);
	  break;
	case ',':
	  bf_set_mem_val (getchar ());
	  break;
	case '[':
	  bf_stack_push (&l_stack, pc);
	  break;
	case ']':
	  if (bf_get_mem_content () == 0)
	    bf_stack_pop (&l_stack);
	  else
	    pc = bf_stack_peek (&l_stack);
	  break;
	case '^':
	  bf_stack_push (&u_stack, bf_get_mem_content ());
	  break;
	case 'v':
	case 'V':
	  bf_set_mem_val (bf_stack_pop (&u_stack));
	  break;
	case 'P':
	case 'p':
	  bf_set_mem_val (bf_stack_peek (&u_stack));
	  break;
	case 'A':
	case 'a':
	  bf_stack_push(&u_stack, bf_get_cur_mem_ptr());
	  break;
	case 'U':
	case 'u':
	  bf_set_cur_mem_ptr(bf_stack_pop(&u_stack));
	  break;
	}
      if (pc == -1)
	return 0;
      pc++;
    }
  while (pc <= prog_size);
  return 1;
}

/*
 * bf_init_interpreter()
 * Initialiazes the program counter and the stacks.
 */
void
bf_init_interpreter ()
{
  bf_init_memory ();
  pc = 0;
  bf_stack_init (&l_stack, MAX_NESTED_LOOPS);
  bf_stack_init (&u_stack, U_STACK_SIZE);
}

/*
 * bf_clean_interpreter()
 * Frees the memory allocated by the interpreter.
 */
void
bf_clean_interpreter ()
{
  bf_stack_destroy (&l_stack);
  bf_stack_destroy (&u_stack);
  if (source_code)
    free (source_code);
  bf_clean_memory ();
}
