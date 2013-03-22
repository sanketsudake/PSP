using namespace std;

#include <iostream>
#include <cstring>
#include <cassert>
#include <cctype>
#include <utility>
#include <algorithm>

string sudoku;
int grid[3][3][9], rows[9][9], columns[9][9], change[9][9];
int puzzle[9][9];
pair<int, int> start = make_pair(0, 0); // Starting point

void init();
int readpuzzle();
void printpuzzle();
int solve(pair<int,int> position);
inline pair<int, int> next(pair<int, int> position);
inline int match(pair<int, int> position,int digit);
void pset(pair<int, int> position,int digit);
void punset(pair<int, int> position);

int main()
{
    int T = 0;
    cin >> T;
    for(int i = 0; i<T; i++){
        init();
        cin >> sudoku;
        if(readpuzzle()){
            if(not solve(start))
                cout << "N" << endl;
        }
        else
            cout << "N" << endl;
    }
    return 0;
}
// put zero in all arrays
void init()
{
    memset((void*)grid, 0, sizeof(int)*3*3*9);
    memset((void*)rows, 0, sizeof(int)*9*9);
    memset((void*)columns, 0, sizeof(int)*9*9);
    memset((void*)change, 0, sizeof(int)*9*9);
    memset((void*)puzzle, 0, sizeof(int)*9*9);
}
// reads puzzle and sets all appropriate bit
int readpuzzle()
{
    int row=0, col=0, digit=0 ;
    //    assert(sudoku.size() == 81);
    for(int i=0; i<81; i++){
        if(isdigit(sudoku[i])){
            digit = sudoku[i] - 48;
            row = i / 9;
            col = i % 9;
            puzzle[row][col] = digit;
            change[row][col] = 1;
            digit = digit - 1;  // Array index start from 0 ;and digit from 1
            if((rows[row][digit] > 0) || (columns[col][digit] > 0) || (grid[row/3][col/3][digit] > 0))
                return false;
            rows[row][digit] = 1;
            columns[col][digit] = 1;
            grid[row/3][col/3][digit] = 1;
        }
    }
    return true;
}
// print puzzle at that instance
void printpuzzle()
{
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(puzzle[i][j])
                cout << puzzle[i][j];// << " ";
            else
                cout << "-";
        }
    }
    cout << endl;
}
// Find next position from current position
inline pair<int, int> next(pair<int, int> position)
{
    if(position.second >= 8){
        position.first += 1;
        position.second = 0;
    }
    else{
        position.second += 1;
    }
    return position;
}
// Checks whether particular digit fits that place or not
inline int match(pair<int, int> position,int digit)
{
    //    assert(digit != 0);
    int row= position.first;
    int col = position.second;
    digit = digit - 1;
    if((rows[row][digit] > 0) || (columns[col][digit] > 0) || (grid[row/3][col/3][digit] > 0))
        return false;
    return true;
}
// Set digit at that position
void pset(pair<int, int> position,int digit)
{
    int row = position.first ;
    int col = position.second;
    //    assert(digit != 0);
    //    assert(change[row][col] != 1);
    puzzle[row][col] = digit;
    digit = digit - 1;
    change[row][col] = 2;
    rows[row][digit] += 1;
    columns[col][digit] += 1;
    grid[row/3][col/3][digit] += 1;
}
// unset digit at that position after wrong choice
void punset(pair<int, int> position)
{
    int row = position.first;
    int col = position.second;
    //    assert(change[position.first][position.second] != 1);
    //    assert(change[position.first][position.second] == 2);
    int digit = puzzle[row][col] - 1;
    rows[row][digit] -= 1;
    columns[col][digit] -= 1;
    grid[row/3][col/3][digit] -= 1;
    //    assert(rows[row][digit] >= 0);
    //    assert(columns[row][digit] >= 0);
    //    assert(grid[row/3][col/3][digit] >= 0);
}
// starting point to solve puzzle
int solve(pair<int,int> position)
{
    int row = position.first;
    int col = position.second;
    if( row == 9){
        cout << "Y" << endl;
        printpuzzle();
        return true;
    }
    if(change[row][col] == 1){
        if(solve(next(position)))
            return true;
    }
    else{
        for(int i=9; i>0; i--){
            if(match(position, i)){
                pset(position, i);
                if(solve(next(position)))
                    return true;
                punset(position);
            }
        }
    }
    return false;
}
