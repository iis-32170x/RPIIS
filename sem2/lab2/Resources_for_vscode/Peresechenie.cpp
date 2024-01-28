#include <iostream>
#include <vector>
#include <fstream>
#include "peresechenie.h"
#include <algorithm>
using namespace std;

Set intersection(vector<Set>& all,int size)
{
    Set result;
    Set new_result;
    for (Set& set : all) result=all[0];
    for (Set& set : all)
    {
        for (int& el : set.getElements())
        {
            if (result.contains(el))
            {
                result.add(el);
            }
        }
    }
    int flag = 0;
    for (int el : result.getElements())
    {
        for (int le : result.getElements())
        {
            if (el == le)
            {
                flag++; 
               
            }
        }
        if (flag == size + 1)
        { 
            if(!new_result.contains(el))
            new_result.add(el);
            
        }
       
        flag = 0;
    }
    
  /*  for (int i = 0; i < all.size(); i++)
    {
        
        for(int j=0;j<)
    }*/
    return new_result;
}

int main()
{
    int count = 0;
    int size = 0;
    vector<Set> all;
    ifstream input("input.txt");
    input >> count;
    for (int i = 0; i < count; i++)
    {
        input >> size;
        vector<int> arr;
        for (int el = 0; el < size; el++)
        {
            int temp;
            input >> temp;
            arr.push_back(temp);
        }
        Set array(arr);
        all.push_back(array);
    }
    Set intersection_mnogestvo = intersection(all,count);
    cout << "Your intersection: " << intersection_mnogestvo << '\n';
    return 0;
}