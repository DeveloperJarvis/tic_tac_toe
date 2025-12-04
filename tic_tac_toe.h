// --------------------------------------------------
// -*- C -*- Compatibility Header
//
// Copyright (C) 2023 Developer Jarvis (Pen Name)
//
// This file is part of the tic_tac_toe Library. This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
//
// SPDX-License-Identifier: GPL-3.0-or-later
//
// tic_tac_toe - Simple console game using 3 x 3 array
// 		Concepts: 2D arrays, game logic, input handling
//
// Author: Developer Jarvis (Pen Name)
// Contact: https://github.com/DeveloperJarvis
//
// --------------------------------------------------

#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#ifdef _WIN32
// Code for Windows
#define CLEAR_SCREEN system("cls")
#elif defined(__linux__)
// Code for Linux
#define CLEAR_SCREEN system("clear")
#elif defined(__APPLE__) && defined(__MACH__)
// Code for MacOS
#define CLEAR_SCREEN system("clear")
#else
// Code for other platform
#error "Unknown platform"
#endif

int game[3][3];

// --------------------------------------------------
// Forward function declaration/ prototype
// --------------------------------------------------

void display_help(const char *s);
void display_version(const char *s);

void game_logic();
void game_init();
void game_start();
const char *game_state();
void game_end();
void display_game();
void player_move(int player);
void clear_screen();
#endif
