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

#ifndef BF_INTERPRETER_H
#define BF_INTERPRETER_H

char *bf_read_source_file (char *);
int bf_interpreter (void);

void bf_init_interpreter (void);
void bf_clean_interpreter ();

#endif //BF_INTERPRETER_H
