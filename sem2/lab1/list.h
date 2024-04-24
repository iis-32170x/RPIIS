#include <iostream>

using namespace std;
class Quenue
{
public:
    int Data;
    Quenue* Next;
    Quenue* Prev;

    Quenue(Quenue* prev, Quenue* next, int data)
    {
        Data = data;
        Next = next;
        Prev = prev;
    }

    Quenue()
    {
    }
};

Quenue* Join(Quenue* q1, Quenue* q2) 
{
    if (q1 == NULL || q1 == NULL) return NULL;
    Quenue* top = NULL;
    Quenue iterator;
    Quenue* prev = NULL;

    bool isInList = false;
    Quenue* check = top;

    do
    {
        isInList = false;
        check = top;
        while (check)
        {
            if (check->Data == q1->Data)
            {
                isInList = true;
                break;
            }
            check = check->Prev;
        }
        if (!isInList)
        {
            Quenue* q = new Quenue(prev, NULL, q1->Data);
            if (prev != NULL)
            {
                prev->Next = q;
            }
            else
            {
                iterator = *q;
            }
            top = q;
            prev = q;
        }    
        q1 = q1->Prev;
    } while (q1 != NULL);


    do
    {
        do
        {
            if (iterator.Data == q2->Data)
            {
                break;
            }
            if (iterator.Next == NULL)
            {
                isInList = false;
                check = top;
                while (check)
                {
                    if (check->Data == q2->Data)
                    {
                        isInList = true;
                        break;
                    }
                    check = check->Prev;
                }
                if (!isInList)
                {
                    Quenue* q = new Quenue(prev, NULL, q2->Data);
                    prev->Next = q;
                    top = q;
                    prev = q;
                }
            }
            if (iterator.Next == NULL)
            {
                break;
            }
            iterator = *iterator.Next;
        } while (true);
        q2 = q2->Prev;
    } while (q2 != NULL);

    return top;
} 

void ConsoleOutput(Quenue* q)
{
    if (q == NULL) return;
    cout << "Quenue item: " << q->Data << endl;
    ConsoleOutput(q->Prev);
}

Quenue* Intersect(Quenue* q1, Quenue* q2)
{
    if (q1 == NULL || q1 == NULL) return NULL;
    Quenue* top = NULL;
    Quenue* prev = NULL;
    Quenue temp = *q1;
    bool isInList = false;

    Quenue* check = top;

    do
    {
        do
        {
            if (q1->Data == q2->Data)
            {
                
                isInList = false;
                check = top;
                while (check)
                {
                    if (check->Data == q1->Data)
                    {
                        isInList = true;
                        break;
                    }
                    check = check->Prev;
                }
                if (!isInList)
                {
                    Quenue* q = new Quenue(prev, NULL, q2->Data);
                    if (prev != NULL)
                    {
                        prev->Next = q;
                    }
                    top = q;
                    prev = q;
                    break;
                }              
            }
            if (q1->Prev == NULL)
            {
                break;
            }
            q1 = q1->Prev;
        } while (true);
        q1 = &temp;
        q2 = q2->Prev;
    } while (q2 != NULL);

    return top;
}

void SortQuenue(Quenue** q)
{
    Quenue* maxSorted = NULL;
    Quenue* Bottom = *q;
    Quenue* temp = NULL;
    Quenue* prev;
    Quenue* current = NULL;
    Quenue* next;

    while (Bottom->Prev != NULL)
    {
        Bottom = Bottom->Prev;
    }

    while (Bottom != maxSorted)
    {
        temp = Bottom;
        while (temp != maxSorted)
        {
            current = temp;
            next = current->Next;
            prev = current->Prev;
            if (next != NULL && current->Data < next->Data)
            {
                if (prev != NULL) prev->Next = next;
                else Bottom = next;
                next->Prev = prev;
                current->Prev = next;
                current->Next = next->Next;
                if (next->Next != NULL)next->Next->Prev = current;
                next->Next = current;
            }
            else
            {
                temp = temp->Next;
            }
            if (next == NULL) *q = current;
        }
        maxSorted = current;
    }
}

void InsertAt(Quenue** top, int index, int data)
{
    if (*top==NULL) return;
    if (index < 0) return;
    Quenue* q = *top;
    for (int i = 0; i < index; i++)
    {
        if (q->Prev != NULL)
        {
            q = q->Prev;
        }
    }

    Quenue* insertion = new Quenue(q, q->Next, data);
    q->Next->Prev = insertion;
    q->Next = insertion;
    if (index == 0) *top = insertion;
}

void CreateQuenueFromPtr(int* arr, int n, Quenue** top)
{
    for (int i = 0; i < n; i++)
    {
        Quenue* q = new Quenue(*top, NULL, arr[i]);
        if (*top != NULL)
        {
            (*top)->Next = q;
        }
        *top = q;
    }
}


void RemoveQuenue(Quenue** q)
{
    if (*q == NULL) return;
    do {
        Quenue* temp = *q;
        *q = (*q)->Prev;
        delete temp;
    } while ((*q) != NULL);

}

int FindItem(Quenue* q, int value)
{
    if (q == NULL) return -1;
    int index = 0;
    while (q != NULL)
    {
        if (q->Data == value) return index;
        index++;
        q = q->Prev;
    }
    return -1;
}

void RemoveAt(Quenue** Top, int value)
{
    if (*Top == NULL) return;
    if (value < 0) return;
    Quenue* next = NULL;
    Quenue* q = *Top;
    for (int i = 0; i < value; i++)
    {
        if (q->Prev != NULL)
        {
            next = q;
            q = q->Prev;
        }
    }
    if (value == 0)
    {
        *Top = (*Top)->Next;
    }
    if (q->Prev != NULL)
    {
        q->Prev->Next = next;
    }
    if (next != NULL)
    {
        next->Prev = q->Prev;
    }
    delete q;
}



