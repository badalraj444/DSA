#include <iostream>
#include <vector>
using namespace std;

class solution{
  public:
   bool isOdd(int n){
    return (n & 1);
   }
};

int main(){
    solution s;
    cout<<s.isOdd(5);
    return 0;
}