# 🧩 **Low-Level Design (LLD) — Tic Tac Toe in C**

## 1. **Module Overview**

The program is divided into the following modules:

1. **Game Board Module**

   - Manages internal board representation and board operations.

2. **Game Engine Module**

   - Handles turns, move validation, win checking, draw checking.

3. **Player Interaction Module**

   - Handles input/output: displays the board, asks players for moves.

4. **Main Controller Module**

   - Coordinates game flow (initialization → loop → end result).

---

# 2. **Data Structures**

## 2.1 Board Representation

- **2D array** of size 3×3 storing characters:

  - `'X'` for Player 1
  - `'O'` for Player 2
  - `' '` (space) for empty

### Structure:

```
board[3][3]
```

## 2.2 Game State Enum

Represents the result of a game check:

```
GAME_ONGOING
GAME_WIN
GAME_DRAW
INVALID_MOVE
```

## 2.3 Player Indicator

Stores whose turn it is:

```
current_player  →  'X' or 'O'
```

---

# 3. **Function-Level Design (No Code)**

---

# 3.1 **Board Module**

### `initialize_board(board)`

- Sets all 3×3 board cells to `' '`.

### `display_board(board)`

- Prints the board in a grid format:

  ```
   X | O | X
  ---+---+---
     | X |
  ```

### `is_cell_empty(board, row, col)`

- Returns **true** if the cell is `' '`.

---

# 3.2 **Game Engine Module**

### `make_move(board, row, col, player)`

- Checks if the coordinates are within bounds.
- Checks if the target cell is empty.
- If OK → places `'X'` or `'O'`.
- Returns:

  - `VALID_MOVE`
  - `INVALID_MOVE`

### `check_winner(board, player)`

- Checks all possible win patterns:

  - Rows
  - Columns
  - Diagonals

- Returns **true** if the player has 3 aligned marks.

### `check_draw(board)`

- Returns **true** if:

  - All cells filled
  - No winner

### `switch_player(player)`

- Turns `'X'` into `'O'`
- Turns `'O'` into `'X'`

---

# 3.3 **Player Input Module**

### `get_player_input(&row, &col)`

- Reads row and column from the user.
- Validates numeric input.
- Validates if the values fall within 0–2.

### `print_invalid_move_message()`

- Displays an error message for invalid or occupied moves.

### `print_winner(player)`

- Prints: `"Player X wins!"` or `"Player O wins!"`

### `print_draw()`

- Prints: `"Game ended in a draw."`

---

# 4. **Main Controller Module**

### `main()`

Responsible for complete program execution.

### Responsibilities:

1. Initialize the board.
2. Set starting player to `'X'`.
3. Repeat:

   - Display board.
   - Ask current player for input.
   - Make move.
   - If invalid → ask again.
   - Check for winner.
   - Check for draw.
   - Switch player.

4. On exit:

   - Display final board.
   - Print result.

---

# 5. **Game Flow Sequence**

```
main()
 ├── initialize_board()
 ├── current_player = 'X'
 ├── LOOP:
 │     ├── display_board()
 │     ├── get_player_input()
 │     ├── result = make_move()
 │     ├── if INVALID → print_invalid → continue
 │     ├── if check_winner() → display_board → print_winner → end
 │     ├── if check_draw() → display_board → print_draw → end
 │     ├── switch_player()
 └── END
```

---

# 6. **Error Handling**

### User input errors:

- Non-numeric input
- Out-of-range (not 0–2)
- Cell already used
  → Display error and reprompt.

### Game integrity:

- Functions return status codes rather than crashing.
- No move modifies board until validated.

---

# 7. **Extensibility Considerations**

The LLD can be extended to:

- AI opponent (Minimax module)
- 4×4 or NxN board support
- Score tracking system
- GUI version (SDL/OpenGL)
