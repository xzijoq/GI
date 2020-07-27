#include <iostream>
template<typename T>
void DisplayBits(const T &a){
  //  std::cout<<"\nSize IS: "<<a.size()<<"\n";
    for(int i=a.size();i>=0;i--){

        std::cout<<a[i];
    }
    std::cout<<"\n";


}