using namespace std;

#include <iostream>
#include <string>

string sudoku;
int grid[3][3][9], rows[9][9], columns[9][9], change[9][9];
int puzzle[9][9];
void init();

int main(){
    int T = 0;
    cin >> T;
    for(int i = 0; i<T; i++){
        cin >> sudoku;
        cout << sudoku << endl;
        init();
        //        scanpuzzle();
        //        solve();
        //        printpuzzle();
    }
    return 0;
}
void init(){
    memset((void*)grid,0,sizeof(int)*3*3*9);
    /*    grid[3][3][9] = {{{0}}};
    rows[9][9] = {{0}};
    columns[9][9] = {{0}};
    change = {{0}};
    puzzle[9][9] = {{0}};*/
}
