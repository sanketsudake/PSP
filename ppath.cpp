using namespace std;
#include <iostream>
#include <algorithm>
int prime[1000];
void pinit(int prime[], int n){
  for(int i=0; i< 1000; i++)
    prime[i] = i;
}
void pprint(int prime[], int n){
  for(int i=0; i<1000; i++)
    {
      cout << prime[i] << "\t";
    }
}
int main(){
  pinit(p, 1000);
  pprint(p, 1000);
  return 0;
}
