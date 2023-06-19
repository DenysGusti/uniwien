#include <iostream>
#include <random>

using namespace std;

/*
(*) Implement the game Minesweeper using arrays (i.e. without classes from libraries).
*/

struct Cell {
public:
    bool mine = false;
    bool opened = false;
    bool marked = false;
    bool chosen_mine = false;
    size_t mines_nearby = 0;

    friend ostream &operator<<(ostream &os, const Cell &cell) {
        if (!cell.opened) {
            if (cell.marked)
                os << '^';
            else
                os << '#';
        } else {
            if (cell.marked) {
                if (cell.mine)
                    os << '^';
                else
                    os << 'X';
            } else {
                if (cell.mine) {
                    if (cell.chosen_mine)
                        os << '@';
                    else
                        os << '*';
                } else {
                    if (cell.mines_nearby == 0)
                        os << '-';
                    else
                        os << cell.mines_nearby;
                }
            }
        }
        return os;
    }
};

class Minesweeper {
private:
    size_t rows{};
    size_t columns{};
    size_t mines{};
    int mines_left{};

    Cell **field{};

    random_device rd;
    mt19937_64 gen{rd()};
    uniform_int_distribution<size_t> dist_rows;
    uniform_int_distribution<size_t> dist_columns;

    char getCommand(size_t &row_idx, size_t &column_idx) const {
        char mode{};
        cout << "Print command [l - left mouse button (click), r - right mouse button (mark/unmark)], "
             << "and row and column coordinate from 0.\nExample: l 0 0\n";
        while (true) {
            cin >> mode >> row_idx >> column_idx;
            if ((mode == 'l' || mode == 'r') && row_idx < rows && column_idx < columns)
                break;
            cout << "Wrong command.\n";
        }
        return mode;
    }

    void createField() {
        field = new Cell *[rows];
        for (size_t i = 0; i < rows; ++i)
            field[i] = new Cell[columns];
    }

    void drawField() {
        cout << "   ";
        for (size_t j = 0; j < columns; ++j)
            cout << j << (j < 10 ? " " : "");
        cout << '\n';
        for (size_t i = 0; i < rows; ++i) {
            cout << (i < 10 ? " " : "") << i << ' ';
            for (size_t j = 0; j < columns; ++j)
                cout << field[i][j] << ' ';
            cout << '\n';
        }
        cout << "Mines left: " << mines_left << '\n';
    }

    size_t countMinesNearby(const size_t row, const size_t column) {
        size_t counter = 0;
        if (row > 0) {
            counter += field[row - 1][column].mine;
            if (column > 0)
                counter += field[row - 1][column - 1].mine;
            if (column < columns - 1)
                counter += field[row - 1][column + 1].mine;
        }
        if (row < rows - 1) {
            counter += field[row + 1][column].mine;
            if (column > 0)
                counter += field[row + 1][column - 1].mine;
            if (column < columns - 1)
                counter += field[row + 1][column + 1].mine;
        }
        if (column > 0)
            counter += field[row][column - 1].mine;
        if (column < columns - 1)
            counter += field[row][column + 1].mine;
        return counter;
    }

    void generateMines(const size_t start_row, const size_t start_column) {
        for (size_t i = 0; i < mines;) {
            size_t row = dist_rows(gen);
            size_t column = dist_columns(gen);
            if (!(row == start_row && column == start_column) && !field[row][column].mine) {
                field[row][column].mine = true;
                ++i;
            }
        }
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < columns; ++j)
                field[i][j].mines_nearby = countMinesNearby(i, j);
    }

    void openAllMinesAndMarks() {
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < columns; ++j)
                if (field[i][j].mine || field[i][j].marked)
                    field[i][j].opened = true;
    }

    bool allMinesMarkedAndAllOtherOpened() {
        if (mines_left != 0)
            return false;
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < columns; ++j)
                if ((field[i][j].mine && !field[i][j].marked) || (!field[i][j].mine && !field[i][j].opened))
                    return false;
        return true;
    }

    size_t countMarkedNearby(const size_t row, const size_t column) {
        size_t counter = 0;
        if (row > 0) {
            counter += field[row - 1][column].marked;
            if (column > 0)
                counter += field[row - 1][column - 1].marked;
            if (column < columns - 1)
                counter += field[row - 1][column + 1].marked;
        }
        if (row < rows - 1) {
            counter += field[row + 1][column].marked;
            if (column > 0)
                counter += field[row + 1][column - 1].marked;
            if (column < columns - 1)
                counter += field[row + 1][column + 1].marked;
        }
        if (column > 0)
            counter += field[row][column - 1].marked;
        if (column < columns - 1)
            counter += field[row][column + 1].marked;
        return counter;
    }

    bool markedRightNearby(const size_t row, const size_t column) {
        if (row > 0) {
            if (field[row - 1][column].marked ^ field[row - 1][column].mine)
                return false;
            if (column > 0)
                if (field[row - 1][column - 1].marked ^ field[row - 1][column - 1].mine)
                    return false;
            if (column < columns - 1)
                if (field[row - 1][column + 1].marked ^ field[row - 1][column + 1].mine)
                    return false;
        }
        if (row < rows - 1) {
            if (field[row + 1][column].marked ^ field[row + 1][column].mine)
                return false;
            if (column > 0)
                if (field[row + 1][column - 1].marked ^ field[row + 1][column - 1].mine)
                    return false;
            if (column < columns - 1)
                if (field[row + 1][column + 1].marked ^ field[row + 1][column + 1].mine)
                    return false;
        }
        if (column > 0)
            if (field[row][column - 1].marked ^ field[row][column - 1].mine)
                return false;
        if (column < columns - 1)
            if (field[row][column + 1].marked ^ field[row][column + 1].mine)
                return false;
        return true;
    }

    void recursiveOpening(const size_t row, const size_t column, bool first_opening = false) {
        field[row][column].opened = true;
        if (field[row][column].mines_nearby > 0 && !first_opening)
            return;

        if (row > 0) {
            if (!field[row - 1][column].opened && !field[row - 1][column].marked && !field[row - 1][column].mine)
                recursiveOpening(row - 1, column);
            if (column > 0)
                if (!field[row - 1][column - 1].opened && !field[row - 1][column - 1].marked &&
                    !field[row - 1][column - 1].mine)
                    recursiveOpening(row - 1, column - 1);
            if (column < columns - 1)
                if (!field[row - 1][column + 1].opened && !field[row - 1][column + 1].marked &&
                    !field[row - 1][column + 1].mine)
                    recursiveOpening(row - 1, column + 1);
        }
        if (row < rows - 1) {
            if (!field[row + 1][column].opened && !field[row + 1][column].marked && !field[row + 1][column].mine)
                recursiveOpening(row + 1, column);
            if (column > 0)
                if (!field[row + 1][column - 1].opened && !field[row + 1][column - 1].marked &&
                    !field[row + 1][column - 1].mine)
                    recursiveOpening(row + 1, column - 1);
            if (column < columns - 1)
                if (!field[row + 1][column + 1].opened && !field[row + 1][column + 1].marked &&
                    !field[row + 1][column + 1].mine)
                    recursiveOpening(row + 1, column + 1);
        }
        if (column > 0)
            if (!field[row][column - 1].opened && !field[row][column - 1].marked && !field[row][column - 1].mine)
                recursiveOpening(row, column - 1);
        if (column < columns - 1)
            if (!field[row][column + 1].opened && !field[row][column + 1].marked && !field[row][column + 1].mine)
                recursiveOpening(row, column + 1);
    }

    bool startGame() {
        for (bool first_click = true; true;) {
            size_t row_idx{};
            size_t column_idx{};
            char mode = getCommand(row_idx, column_idx);

            if (field[row_idx][column_idx].opened && field[row_idx][column_idx].mines_nearby == 0)
                continue;

            if (mode == 'r' && !field[row_idx][column_idx].opened) {
                field[row_idx][column_idx].marked = !field[row_idx][column_idx].marked;
                mines_left += (field[row_idx][column_idx].marked ? -1 : 1);
            } else if (mode == 'l' && !field[row_idx][column_idx].marked) {
                if (first_click) {
                    first_click = false;
                    field[row_idx][column_idx].opened = true;
                    generateMines(row_idx, column_idx);
                    recursiveOpening(row_idx, column_idx);
                } else {
                    if (field[row_idx][column_idx].mine) {
                        field[row_idx][column_idx].opened = true;
                        field[row_idx][column_idx].chosen_mine = true;
                        openAllMinesAndMarks();
                        drawField();
                        return false;
                    }
                    if (field[row_idx][column_idx].opened && field[row_idx][column_idx].mines_nearby > 0) {
                        field[row_idx][column_idx].opened = true;
                        if (countMarkedNearby(row_idx, column_idx) == field[row_idx][column_idx].mines_nearby) {
                            if (!markedRightNearby(row_idx, column_idx)) {
                                openAllMinesAndMarks();
                                drawField();
                                return false;
                            }
                        }
                    }
                    recursiveOpening(row_idx, column_idx, true);
                }
            }
            drawField();
            if (allMinesMarkedAndAllOtherOpened())
                return true;
        }
    }

public:
    explicit Minesweeper(const int difficulty) {
        if (difficulty == 0) {
            rows = 3;
            columns = 3;
            mines = 1;
        }
        if (difficulty == 1) {
            rows = 9;
            columns = 9;
            mines = 10;
        } else if (difficulty == 2) {
            rows = 16;
            columns = 16;
            mines = 40;
        } else if (difficulty == 3) {
            rows = 16;
            columns = 30;
            mines = 99;
        }
        mines_left = static_cast<int>(mines);
        dist_columns = uniform_int_distribution<size_t>{0, columns - 1};
        dist_rows = uniform_int_distribution<size_t>{0, rows - 1};
    }

    void play() {
        cout << "Game started!\n";
        createField();
        drawField();
        cout << (startGame() ? "You won!\n" : "You lost!\n");
        cout << "Game ended!\n" << endl;
    }

    ~Minesweeper() {
        for (size_t i = 0; i < rows; ++i)
            delete[] field[i];
        delete[] field;
    }
};

int main() {
    for (char again = 'y'; again == 'y' || again == 'Y';) {
        int difficulty = -1;
        while (!(0 <= difficulty && difficulty <= 3)) {
            cout << "Choose difficulty:\n";
            cin >> difficulty;
        }
        Minesweeper minesweeper{difficulty};
        minesweeper.play();
        cout << "Do you want to play again? y/n\n";
        cin >> again;
    }
    return 0;
}

/*
Input:
0
l 0 0
r 2 0
n

Output:
Choose difficulty:
Game started!
   0 1 2
 0 # # #
 1 # # #
 2 # # #
Mines left: 1
Print command [l - left mouse button (click), r - right mouse button (mark/unmark)], and row and column coordinate from 0.
Example: l 0 0
   0 1 2
 0 - - -
 1 1 1 -
 2 # 1 -
Mines left: 1
Print command [l - left mouse button (click), r - right mouse button (mark/unmark)], and row and column coordinate from 0.
Example: l 0 0
   0 1 2
 0 - - -
 1 1 1 -
 2 ^ 1 -
Mines left: 0
You won!
Game ended!

Do you want to play again? y/n
*/