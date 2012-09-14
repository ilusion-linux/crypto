#include <iostream>

using std::cout;
using std::endl;

int main(int argC, char * argV[])
{
  cout<<argC<<endl<<endl;
  for(int x=0; x<argC; x++)
  {
     cout<<argV[x]<<endl;
  }
  cout<<endl<<endl;
  cout<<"Hola mundo"<<endl;
  return 0;
}
