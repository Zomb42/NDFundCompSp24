// ex107.cpp
// intro to vectors
#include <iostream>
using namespace std;
#include <vector>

int main()
{
  vector<int> vec = {13, 45, 23, 87, 46, 59};

  cout << vec.size() << endl;

  for (int i = 0; i < vec.size(); i++)
    cout << vec[i] << " ";
  cout << endl;

  for (int n: vec)
    cout << n << " ";
  cout << endl;
  
// (added post-class)
//  using the push_back method
//   (to showcase the dynamic nature of vectors)

  vec.push_back(77);
  cout << vec.size() << endl;
  for (int n: vec)
    cout << n << " ";
  cout << endl;

  return 0;
}

