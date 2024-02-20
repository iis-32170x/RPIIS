#pragma once



class MyQueue {
public:
    MyQueue();
    virtual ~MyQueue();

    void    Push(int value);
    int     Pop();
    void    View();
    bool    Check();
    void    HeadElemenetToTail();

private:
    typedef struct QueueElement {
        int             el;
        QueueElement* prev;
    } QueueElement;

    QueueElement* last;
    QueueElement* begin;
};
