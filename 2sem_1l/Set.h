#pragma once

class MySet {
public:
    MySet();
    ~MySet();

    void insert(int element);
    void remove(int element);
    bool contains(int element) const ;
    int contains2(int element) const;

    MySet intersection(const MySet& other) const;
    MySet unionWith(const MySet& other);

    void clear();
    int size();
    void print();

    MySet(const MySet& other);
    MySet& operator=(const MySet& other);
 
private:
    int* elements;
    int capacity;
    int count;

    void resize(int newCapacity);
    bool isFull();
};

MySet::MySet() : capacity(10), count(0) {
    elements = new int[capacity];
}

MySet::~MySet() {
    delete[] elements;
}

void MySet::insert(int element) {
    if (contains(element)) {
        return;
    }

    if (isFull()) {
        resize(capacity * 2);
    }

    elements[count] = element;
    count++;
}

void MySet::remove(int element) {
    int index = -1;

    for (int i = 0; i < count; i++) {
        if (elements[i] == element) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < count - 1; i++) {
            elements[i] = elements[i + 1];
        }
        count--;
    }
}

bool MySet::contains(int element) const {
    for (int i = 0; i < count; i++) {
        if (elements[i] == element) {
            return true;
        }
    }
    return false;
}

int MySet::contains2(int element) const {
    for (int i = 0; i < count; i++) {
        if (elements[i] == element) {
            return i;
        }
    }
    return 0;
}

MySet MySet::intersection(const MySet& other) const {
    MySet result;

    for (int i = 0; i < count; i++) {
        if (other.contains(elements[i])) {
            result.insert(elements[i]);
        }
    }

    return result;
} 

MySet MySet::unionWith(const MySet& other) {
    MySet result = *this;

    for (int i = 0; i < other.count; i++) {
        result.insert(other.elements[i]);
    }

    return result;
}

void MySet::clear() {
    count = 0;
}

int MySet::size() {
    return count;
}

void MySet::print() {
    std::cout << "{ ";
    for (int i = 0; i < count; i++) {
        std::cout << elements[i] << " ";
    } 
    std::cout << "}" << std::endl;
}

void MySet::resize(int newCapacity) {

    int* newElements = new int[newCapacity];

    for (int i = 0; i < count; i++) {
        newElements[i] = elements[i];
    }

    delete[] elements;

    elements = newElements;
    capacity = newCapacity;
}

bool MySet::isFull() {
    return count == capacity;
}



MySet::MySet(const MySet& other) : capacity(other.capacity), count(other.count) {
    elements = new int[capacity];

    for (int i = 0; i < count; i++) {
        elements[i] = other.elements[i];
    }
}

MySet& MySet::operator=(const MySet& other) {
    if (this != &other) {
        delete[] elements;
        capacity = other.capacity;
        count = other.count;

        elements = new int[capacity];

        for (int i = 0; i < count; i++) {
            elements[i] = other.elements[i];
        }
    }

    return *this;
}