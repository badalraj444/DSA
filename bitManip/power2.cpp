#include <iostream>
#include <vector>
using namespace std;

class solution{
  public:
   bool power2(int n){
    return (!(n & (n-1)));
   }
};

int main(){
    solution s;
    cout<<s.power2(15);
    return 0;
}