using namespace std;
#include <iostream>
#include <algorithm>
#include <cassert>
#include <queue>
#include <set>

bool arr[10000];
void primegen(bool arr[], int n);
inline int isprime(int no);
int bitset(int curnode,int pos, int digit);
int ppath(int source, int destination);
int main(int argc, char *argv[])
{
    primegen(arr,10000);
    int testcase;
    cin >> testcase;
    for(int i=0; i < testcase; i++)
        {
            int source, destination;
            cin >> source >> destination;
            int value = ppath(source, destination) ;
            if(value == -1)
                cout << "Impossible" << endl;
            else
                cout << value << endl;
        }

    return 0;
}
/* Genearate prime nos upto 10000 */
void primegen(bool arr[], int n)
{
    fill_n(arr, n, 1);
    arr[0] = 0;
    arr[1] = 0;
    for (int i=2; i < n; i++)
        {
            if ((i*i) > n)
                break;
            if (arr[i])
                {
                    int j = 2;
                    while (i*j < n)
                        {
                            arr[i*j] = 0;
                            j = j + 1;
                        }
                }
        }
}
/* no prime or not
   function not much of use
*/
inline int isprime(int no)
{
    if(arr[no])
        return true;
    return false;
}
/*  set particular bit to some digit
    position indexed from left to right
    [ 0, 1, 2, 3]
    bitset(1234, 0, 5) => 5234
    bitset(1234, 1, 5) => 1534
    bitset(0001, 0, 5) => 5001
    bitset(0011, 3, 0) => 10
*/
int bitset(int curnode,int pos, int digit)
{
    int no = 1;
    int temp = curnode;
    int bit;
    for(int i = 4 - pos ; i > 0; i--)
        {
            bit = temp % 10;
            temp = temp / 10;
            no = 10 * no;
        }
    no = no /10;
    int newnode = curnode - (bit * no);
    newnode = newnode + (digit * no);
    return newnode;
}

int ppath(int source, int destination)
{
    int dist[10000];
    int visited[10000];
    fill_n(dist, 10000, 0);
    fill_n(visited, 10000, 1);
    queue<int> q;
    q.push(source);
    visited[source] = 0;
    dist[source] = 0;
    while(!q.empty())
        {
            int curnode = q.front();
            int d = dist[curnode];
            q.pop();
            if(curnode == destination)
                return dist[curnode];
            for (int i = 0; i < 4; i++)
                {
                    for(int j = 0; j < 10; j++)
                        {
                            if (j%2 == 0 && i == 3) continue;
                            int newnode = bitset(curnode, i, j);
                            if(arr[newnode] && visited[newnode])
                                {
                                    visited[newnode] = 0;
                                    dist[newnode] = d + 1;
                                    q.push(newnode);
                                }
                        }
                }
        }

    return -1;
}
