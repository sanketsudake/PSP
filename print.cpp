#include <iostream>
using namespace std;
void printno(int n){
  if (n){
    cout << n;
    printno(n-1);
  }
  else{

  }
 }

void jprintno(int i, int n){
  if ( i != n){
    cout << i;
    jprintno(i+1, n);
  }
}


int main(){
  int a;
  cin >> a;
  printno(a);
  cout << endl;
  return 0;
}
