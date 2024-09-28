#include<iostream>

int main(){
    std::string previous;
    std::string current;
    // std::cin>>current>>previous;
    // std::cout<<current<<previous;
    while(std::cin>>current){
        if(previous == current)
            std::cout<<"repeated "<<current<<"\n";
        previous = current;
        std::cout<<current;
    }
    std::cout<<current;
}