#pragma once

using namespace std;

#include <iostream>
#include <deque>
#include <iterator>

struct deqqqq
{
    std::deque<char> deq;
        
    void addElfront(deque<char>& deq);
    void DelElfront(deque<char>& deq);
    void addElback(deque<char>& deq);
    void DelElback(deque<char>& deq);
};

