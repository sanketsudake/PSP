#include <iostream>
#include <stack>
using namespace std;
int main()
{
  while(true){
    int truck, required=1;
    cin >> truck;
    if (truck == 0)
      break;
    int trucks[truck];
    stack<int> track;
    for(int j = 0; j < truck; j++)
      cin >> trucks[j];
    for(int i = 0; i < truck; i++)
      {
        if ( required == trucks[i] )
          required++;
        else
          track.push(trucks[i]);
        while(!track.empty() && required == track.top())
          {
            track.pop();
            required++;
          }
      }
    while(!track.empty() && required == track.top())
      {
        track.pop();
        required++;
      }
    if(track.empty())
      cout << "yes\n";
    else
      cout << "no\n";
  }
  return 0;
  }
