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

#include <stdio.h>
#include <stdlib.h>

#include "bf_interpreter.h"

#define ERR_NO_SOURCE_CODE  0
#define HLP_USAGE           1
#define ERR_RUNTIME_ERROR   2

/*utilities*/
char *help_message (unsigned int);

/*initialization and finalization*/
void init (void);
void clean (void);

int
main (int argc, char **argv)
{
  atexit (clean);		/*clean interpreter on exit */

  /*check command line arguments */
  if (argc < 2)
    {
      printf ("%s", help_message (HLP_USAGE));
      return 1;
    }

  /*TODO: think of other ways to call the interpeter (e.g. without args) */

  /*read source file and check if it exists */
  if (!bf_read_source_file (argv[1]))
    {
      printf ("%s", help_message (ERR_NO_SOURCE_CODE));
      return 1;
    }

  init ();

  /*call the interpreter and check if something went wrong */
  if (!bf_interpreter ())
    {
      printf ("%s", help_message (ERR_RUNTIME_ERROR));
      return 1;
    }
  printf ("\n");		//flush buffer
  return 0;
}

/*
 * help_message(unsigned int)
 * Returns a help/error message depending on the argument.
 */
char *
help_message (unsigned int msg)
{
  switch (msg)
    {
    case HLP_USAGE:
      return "usage: bf <infile>\n";
    case ERR_NO_SOURCE_CODE:
      return "the specified file is non-existent or empty\n";
    case ERR_RUNTIME_ERROR:
      return "runtime error. aborting\n";
    }
  return "";
}

/*
 * init()
 * Calls the interpreter's initializers.
 */
void
init ()
{
  bf_init_interpreter ();
}

/*
 * clean()
 * Calls the interpreter's clean routines.
 */
void
clean ()
{
  bf_clean_interpreter ();
}
