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

#ifndef BF_MEM_H
#define BF_MEM_H

#define MAX_MEMORY_SIZE 512

int bf_init_memory (void);
void bf_clean_memory (void);

void bf_inc_mem_cell (int);
void bf_move_mem_ptr (int);

unsigned char bf_get_mem_content (void);
void bf_set_mem_val (unsigned char);

unsigned int get_cur_mem_ptr (void);
void set_cur_mem_ptr (unsigned int);

#endif //BF_MEM_H
