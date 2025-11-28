#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
using namespace std;

vector<int> num;

void num_aleatorios(){
    num.clear();
    for (int i= 1; i< 100;i++){
        num.push_back(i);
    }
    default_random_engine engine(time(0));
    shuffle(num.begin(), num.end(), engine);
}


int main(){
    num_aleatorios();
    for (int i= 1; i< 100;i++){
       cout << num.at(i)<< endl;
    }

    return 0;
}