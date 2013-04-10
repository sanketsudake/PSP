#include<iostream>
#include<algorithm>
using namespace std;
int n= 0, total = 0;
int sum(int a[], int visited[])
{
  int sum = 0;
  for(int i = 0; i < n; i++)
    {
      sum = sum + a[i] * visited[i];
    }
  return sum;
}
void printset(int a[], int visited[])
{
  for(int i = 0; i < n; i++)
    if(visited[i])
      cout << a[i] << " ";
  cout << endl;
  for(int j = 0; j < n; j++)
    if(!visited[j])
      cout << a[j] << " ";
  cout << endl;
}
int sol(int h, int a[], int visited[])
{
  //  printset(a, visited);
  if(sum(a, visited) == total / 2)
    {
      printset(a, visited);
      return true;
    }
  if(h > n)
    return false;
  if(sol(h+1, a, visited))
    return true;
  visited[h] = 1;
  if(sol(h+1, a, visited))
    return true;
  return false;
}
int main(void)
{
  int test = 0;
  cin >> test;
  for(int k = 0; k < test; k++ ){
    cout << "case #" << k + 1 << endl;
    n = 0;
    total = 0;
    cin >> n;
    int a[n], visited[n];
    for(int i=0; i < n; i++)
      {
        cin >> a[i];
        total = total + a[i];
        visited[i] = 0;
      }
    cout << "Total " << total << endl;
    if(total % 2 == 0 )
      {
        int flag = 0;
        for(int i = 0; i < n; i++){
          int temp = a[0];
          for(int f = 1; f < n; f++)
            a[f - 1] = a[f];
          a[n - 1] = temp;
          if(sol(1, a, visited))
            {
              flag = 1;
              break;
            }
        }
        if(!flag)
          cout << "Not possible" << endl;
      }
    else
      cout << "Not Possible" << endl;
  }
  return 0;
}
