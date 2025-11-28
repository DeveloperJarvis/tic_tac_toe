// --------------------------------------------------
// -*- C -*- Compatibility Header
//
// Copyright (C) 2023 Developer Jarvis (Pen Name)
//
// This file is part of the [Project Name] Library. This library is free
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

// --------------------------------------------------
// Header files
// --------------------------------------------------
#include <stdio.h>
#include <stdbool.h> // for bool datatype
#include <string.h>
#include <stdlib.h> // for system()

#include "tic_tac_toe.h"

// --------------------------------------------------
// Main function
// --------------------------------------------------
int main(int argc, char *argv[])
{
	if (argc == 1)
		game_logic();
	else if (argc == 2)
	{
		if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
			display_help(argv[0]);
		else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0)
			display_version(argv[0]);
	}
	return 0;
}

// --------------------------------------------------
// Helper functions
// --------------------------------------------------
void display_help(const char *s)
{
	printf("Usage: %s\n", s);
	printf(" -h --help		display help\n");
	printf(" -v --version	display version\n");
	printf("Happy playing!!.\n");
}

void display_version(const char *s)
{
	printf("%s version: 1.0.0\n", s);
}
// --------------------------------------------------
// Game Logic
// --------------------------------------------------

void game_logic()
{
	int i = 0;
	game_init();
	game_start();
	while (1)
	{
		printf("game logic: %d\n", i);
		display_game();
		player_move(i); // Player 1 or Player 2 makes a move

		const char *state = game_state();
		if (strcmp(state, "1wins") == 0)
		{
			printf("Player 1 wins!\n");
			game_end();
		}
		else if (strcmp(state, "2wins") == 0)
		{
			printf("Player 2 wins!\n");
			game_end();
		}
		else if (strcmp(state, "tie") == 0)
		{
			printf("It's a tie!\n");
			game_end();
		}
		// Switch player after each valid move
		i = 1 - 1; // Switch player between 0 and 1
	}
}

void game_init()
{
	// initial state of game
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			game[i][j] = -1; // -1 indicates empty cell
		}
	}
}

void game_start()
{
	clear_screen();
	printf("Tic Tac Toe Game Started!\n");
}

const char *game_state()
{
	// Check for winner (rows, columns, diagonals)
	// Check diagonals
	printf("game state");
	if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && game[0][0] != -1)
		return (game[0][0] == 1) ? "1wins" : "2wins"; // Player 1 or Player 2 wins
	else if (game[0][2] == game[1][1] && game[1][1] == game[2][0] && game[0][2] != -1)
		return (game[0][2] == 1) ? "1wins" : "2wins"; // Player 1 or Player 2 wins
	else
	{
		// Check rows and columns
		for (int i = 0; i < 3; i++)
		{
			if (game[i][0] == game[i][1] && game[i][1] == game[i][2] && game[i][0] != -1)
				return (game[i][0] == 1) ? "1wins" : "2wins"; // Player 1 or Player 2 wins
			else if (game[0][i] == game[1][i] && game[1][i] == game[2][i] && game[0][i] != -1)
				return (game[0][i] == 1) ? "1wins" : "2wins"; // Player 1 or Player 2 wins
		}
	}

	// Check for tie
	int empty_cells = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			if (game[i][j] == -1)
				empty_cells++;
	}
	if (empty_cells == 0)
		return "tie";
	return "ongoing";
}

void display_game()
{
	clear_screen();
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (game[i][j] == -1)
				printf("_ ");
			else if (game[i][j] == 1)
				printf("X ");
			else
				printf("O ");
		}
		printf("\n");
	}
}

void game_end()
{
	char choice;
	printf("Do you want to play again? (y/n): ");

	while (1)
	{
		choice = getchar(); // Get user input
		while (getchar() != '\n')
			; // Clear imput buffer
		if (choice == 'y' || choice == 'Y')
		{
			game_init(); // Reset the game board
			printf("Restarting the game...\n");
			game_start();
			break;
		}
		else if (choice == 'n' || choice == 'N')
		{
			/* code */
			printf("Thanks for playing! Exiting...\n");
			exit(0);
		}
		else
		{
			printf("Invalid input. Please enter 'y' to restart or 'n' to quit: ");
		}
	}
}
// --------------------------------------------------
// Game helper functions
// --------------------------------------------------
void player_move(int player)
{
	int row, col;
	while (1)
	{
		printf("Player %d, enter your move (row and column)(e.g., 0 0): ", player);
		if (scanf("%d %d", &row, &col) != 2)
		{
			printf("1debug: '%d' '%d'\n", row, col);
			printf("Invalid Input. Please enter two integers between 0 and 2.\n");
			continue;
		}
		else if (row < 0 || row >= 3 || col < 0 || col >= 3 || game[row][col] == -1)
		{
			printf("2debug: '%d' '%d'\n", row, col);
			printf("Invalid move. Try again.\n");
			player_move(player);
		}
		else
		{
			game[row][col] = player;
			break;
		}
	}
}

void clear_screen()
{
	CLEAR_SCREEN;
}