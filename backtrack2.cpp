using namespace std;
#include <iostream>
#include <queue>
#include <stack>
int row, column, puzzle[10][10],visited[10][10],traverse[10][10];
int dr[] = {0, 0, -1, 1, 1, -1, 1, -1};
int dc[] = {1, -1, 0, 0, 1, -1, -1, 1};
queue< pair<int, int> > q;
pair<int, int> start;           // Start position
pair<int, int> end;             // Final Position to reach
int printnodes(pair<int, int> start, pair<int,int> final);
int  solvemaze(pair<int, int> position, pair<int,int> final);
void getpuzzle();
void printpuzzle();
int valid(pair<int, int> position);
int isvisited(pair<int, int> position);

int main(int argc, char *argv[]){
    getpuzzle();
    printpuzzle();
    if(!solvemaze(start , end))
        cout << "NO" << endl;
    return 0;
}

// Accepts all input values
void getpuzzle(){
    cin >> row >> column;
    cin >> start.first >> start.second;
    cin >> end.first >> end.second;
    for(int i=0; i<row; i++)
        for(int j=0; j< column; j++)
            cin >> puzzle[i][j];
}
// Prints puzzle at a one instance
void printpuzzle(){
    for(int i=0; i<row; i++){
        for(int j=0; j< column; j++){
            cout << puzzle[i][j];
            cout << "\t";
        }
        cout << endl;
    }
    cout << "\n";
}
// Check next position to be travelled valid or not
int valid(pair<int, int> position){
    if(position.first >= 0 && position.first < row &&
       position.second >= 0 && position.second < column)
        if(puzzle[position.first][position.second])
            return true;
    return false;
}
// Check next position already visited or not
int isvisited(pair<int, int> position){
    if(visited[position.first][position.second] == 1)
        return true;
    return false;
}
// Print path traversed using finding parent of each position
int printnodes(pair<int, int> start, pair<int,int> final){
    stack< pair<int, int> > s;
    pair<int, int> curpos;
    int value;
    curpos = final;
    while(curpos != start ){
        s.push(curpos);
        value = traverse[curpos.first][curpos.second];
        curpos.first = value/10;
        curpos.second = value%10;
    }
    cout << "YES" << endl;
    cout << "0 0" << endl;
    while(!s.empty()){
        curpos = s.top();
        cout << curpos.first << " " << curpos.second << endl;
        s.pop();
    }
    return true;
}
// solve maze
int  solvemaze(pair<int, int> position, pair<int,int> final){
    pair<int, int> curpos, nextpos;
    traverse[curpos.first][curpos.second] = -1;
    q.push(position);
    while(!q.empty()){
        curpos = q.front();
        visited[curpos.first][curpos.second] = 1;
        q.pop();
        if(curpos.first == final.first && curpos.second == final.second){
            return printnodes(position, final);
        }
        for(int i=0; i < 8;i++){
            nextpos.first = curpos.first + dr[i];
            nextpos.second = curpos.second + dc[i];
            if(valid(nextpos) && !isvisited(nextpos)){
                traverse[nextpos.first][nextpos.second] = curpos.first * 10\
                    + curpos.second;
                q.push(nextpos);
            }
        }
    }
    return false;
}
