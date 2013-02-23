using namespace std;

#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
int row = 0, column = 0, puzzle[10][10];
pair<int, int> start;           // Start position
pair<int, int> end;             // Final Position to reach
string node = "";
int  backtrack(pair<int, int> position, pair<int,int> final);
void getpuzzle();
void printpuzzle();
void printnodes();


int main(int argc, char *argv[]){
    getpuzzle();
    //    cout << "Before" << endl;
    printpuzzle();
    if(backtrack(start , end) == true){
        cout << "YES" << endl;
        cout << "Travelled Nodes" << endl;
        printnodes();
    }
    else
        cout << "NO" << endl;
    //    cout << "After" << endl;
    //    printpuzzle();
    return 0;
}

int backtrack(pair<int,int> position,pair<int,int> final){
    ostringstream convert;
    convert << position.first << position.second << "\t";
    node = node + convert.str();
    if(position.first == final.first && position.second == final.second){
        // cout << "Final Destination" << endl;
        puzzle[position.first][position.second] = 5;
        return true;
    }
    if(puzzle[position.first][position.second] == 9)
        return false;
    if(position.second < column){
        if(puzzle[position.first][position.second + 1] == 1){
            int result;
            puzzle[position.first][position.second + 1] = 4;
            result = backtrack(make_pair(position.first, position.second + 1), final);
            if(result)
                return true;
        }
        else{
            puzzle[position.first][position.second + 1] = 9;
        }
    }
    if(position.first < row){
        if(puzzle[position.first + 1][position.second] == 1){
            int result;
            puzzle[position.first + 1][position.second] = 4;
            result = backtrack(make_pair(position.first + 1, position.second), final);
            if(result)
                return true;
        }
        else{
            puzzle[position.first + 1][position.second] = 9;
        }
    }
    if(position.first > 0){
        if(puzzle[position.first - 1][position.second] == 1){
            int result;
            puzzle[position.first - 1][position.second] = 4;
            result = backtrack(make_pair(position.first - 1, position.second), final);
            if(result)
                return true;
        }
        else{
            puzzle[position.first - 1][position.second] = 9;
        }
    }
    if(position.second > 0){
        if(puzzle[position.first][position.second - 1] == 1){
            int result;
            puzzle[position.first][position.second - 1] = 4;
            result = backtrack(make_pair(position.first, position.second - 1), final);
            if(result)
                return true;
        }
        else{
            puzzle[position.first][position.second - 1] = 9;
        }
    }
    puzzle[position.first][position.second] = 9;
    node = node +  "\t\t";
    return false;
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

void printnodes(){
    while(1){
        int temp = node.find("\t\t");
        if(temp == -1)
            break;
        else
            node.erase(0, temp + 2);
    }
    if(node.find("\t") == 0)
        node.erase(0,1);
    //    cout << node << endl;
    int flag = 1;
    for(unsigned int i = 0; i < node.length(); i++)
        if(node[i] != '\t'){
            if(flag){
                cout << node.at(i);
                flag = 0;
            }
            else{
                cout << "\t" << node.at(i);
                flag = 1;
            }
        }
        else
            cout << "\n";
}
