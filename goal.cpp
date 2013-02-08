#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

inline int compare(pair<int,bool> entry1, pair<int, bool> entry2)
{
  return entry1.first < entry2.first;
}

int main(int argc, char *argv[])
{
  int testcases, N;
  cin >> testcases;
  for(int i = 0; i < testcases; i++)
    {
      cin >> N;
      vector< pair <int, bool> > entries; // Contains all entry log
      for(int j = 0; j < N; j++)
        {
          /*
            For entry 4, 5
            it pushes 4,true and 5, false at back of the stack
          */
          int value1, value2;
          pair<int, bool> entry;
          cin >> value1 >> value2;
          entry = make_pair(value1, 1);
          entries.push_back(entry);
          entry = make_pair(value2, 0);
          entries.push_back(entry);
        }
      sort(entries.begin(), entries.end(), compare); // Sort entries
      int count = 0, max = 0;               // Stores no people in a room
      for(unsigned int k = 0; k < entries.size(); k++)
        {
          if( entries[k].second == 1)
              count++;
          else
              count--;
          if(max < count)
            max = count;       // Compare count with max
        }
      // Print maximum value
       if( max < count)
         max = count;
       cout << max << endl;
    }
   return 0;
}
