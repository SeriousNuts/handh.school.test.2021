#include <iostream>
#include<vector>
#include<cstdlib>
#include <algorithm>
using namespace std;
struct lower
{
    template<class T>
    bool operator()(T const &a, T const &b) const { return a < b; }
};
struct greaterr
{
    template<class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};

unsigned int PRNG()
{
    static unsigned int seed = 3214;
 
    seed = (8253729 * seed + 2396403);

    return seed % 32768;
}
vector<vector<int>> sorter(int n)
{
    
    vector<int>first_layer;
    vector<vector<int>>second_layer;
    for (int i = 0; i<n; i++)
    {
        for(int j = 0; j<PRNG(); j++)
        {
            first_layer.push_back(PRNG());
        }
        second_layer.push_back(first_layer);
    }
    for (int iter = 0; iter < second_layer.size(); iter++)
    {
        if ((iter+1) % 2 == 0 )
        {
            sort(second_layer[iter].begin(), second_layer[iter].end(), greaterr());
        }
        else
        {
           sort(second_layer[iter].begin(), second_layer[iter].end(), lower()); 
        }
    }
    return second_layer;
}

int main()
{
    cout<<"Hello World";
    return 0;
}