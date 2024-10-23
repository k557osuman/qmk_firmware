/* Copyright 2023 Dimitris Mantzouranis <d3xter93@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#define CH_CFG_OPTIMIZE_SPEED FALSE

#define CH_CFG_USE_CONDVARS_TIMEOUT FALSE

#undef CH_CFG_ST_TIMEDELTA
#define CH_CFG_ST_TIMEDELTA 0
#undef CH_CFG_ST_RESOLUTION
#define CH_CFG_ST_RESOLUTION 32
#undef CH_CFG_ST_FREQUENCY
#define CH_CFG_ST_FREQUENCY 10000

#include_next <chconf.h>
