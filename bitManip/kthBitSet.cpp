#include <iostream>
#include <vector>
using namespace std;

class solution{
  public:
   bool checkKthBit(int n, int k){
    return (n & (1 << k));
   }
};

int main(){
    solution s;
    cout<<s.checkKthBit(5,1);
    return 0;
}