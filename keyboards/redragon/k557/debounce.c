/*
Copyright 2017 Alex Ong<the.onga@gmail.com>
Copyright 2021 Simon Arlott
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
Basic global debounce algorithm. Used in 99% of keyboards at time of implementation
When no state changes have occured for DEBOUNCE milliseconds, we push the state.
*/
#include "debounce.h"
#include "timer.h"
#include <string.h>
#ifndef DEBOUNCE
#    define DEBOUNCE 5
#endif

// Maximum debounce: 255ms
#if DEBOUNCE > UINT8_MAX
#    undef DEBOUNCE
#    define DEBOUNCE UINT8_MAX
#endif

#if DEBOUNCE > 0
static bool         debouncing = false;
static fast_timer_t debouncing_time;
static bool matrix_need_update;

void debounce_init(void) {}

bool debounce(matrix_row_t raw[], matrix_row_t cooked[], bool changed) {
    bool cooked_changed = false;
    matrix_need_update = false;

    if (!debouncing){
        matrix_need_update = false;
        for (uint8_t row = 0; row < ROWS_PER_HAND; row++){
            cooked[row] = raw[row];
            cooked_changed = true;
        }
        debouncing = true;
    }

    if (changed) {
    matrix_need_update = false;
    debouncing_time = timer_read_fast();

    } else if (debouncing && timer_elapsed_fast(debouncing_time) >= DEBOUNCE) {
        debouncing = false;
        matrix_need_update = true;
    }

    return cooked_changed;
}

void debounce_free(void) {}
#else // no debouncing.
#    include "none.c"
#endif
