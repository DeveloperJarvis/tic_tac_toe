# 📘 Tic Tac Toe — C Console Game

A simple and classic **Tic Tac Toe** game implemented in C, using a **3×3 board**, console interaction, and structured game logic. This project demonstrates essential C concepts such as **2D arrays**, **conditional logic**, **input validation**, and **modular program design**.

---

## 📝 Features

- 3×3 Tic-Tac-Toe board
- Two-player (Player X vs Player O) mode
- Input validation for safe and clean interaction
- Win detection (rows, columns, diagonals)
- Draw detection
- Clean modular structure
- Clear console UI
- Fully open-source under **GPL-3.0-or-later**

---

## 📂 Project Structure

```
tic_tac_toe/
├── src/
│   ├── main.c
│   ├── tic_tac_toe.c
│   └── tic_tac_toe.h
├── LICENSE
└── README.md
```

---

## 🧱 Core Concepts Demonstrated

- 2D arrays in C
- Separation of logic (input, game loop, win logic, display)
- Clean function-based organization
- Defensive programming (invalid input handling)

---

## ▶ How to Build & Run

### **Compile**

```sh
gcc -o tic_tac_toe src/main.c src/tic_tac_toe.c
```

### **Run**

```sh
./tic_tac_toe
```

---

## 🎮 Game Rules

- Player **X** starts first
- Players alternate turns by choosing a row and column (0–2)
- A player wins by placing 3 marks in:

  - a row
  - a column
  - a diagonal

- If the board fills without a winner → **Draw**

---

## 📖 Example Gameplay

```
   Tic Tac Toe
   Player X starts

       0   1   2
     -------------
  0 |   |   |   |
     -------------
  1 |   |   |   |
     -------------
  2 |   |   |   |
     -------------

Player X, enter row and column: 0 2
```

---

## 🔧 Future Enhancements

- Add AI using Minimax
- Add scoring system
- Online multiplayer
- GUI version using SDL or ncurses

---

## 🧑💻 Author

**Developer Jarvis (Pen Name)**
GitHub: [https://github.com/DeveloperJarvis](https://github.com/DeveloperJarvis)

---

## 📜 License

This project is licensed under the
**GNU General Public License v3.0 or later**
See the full license text in:
`LICENSE` or [https://www.gnu.org/licenses/](https://www.gnu.org/licenses/)
