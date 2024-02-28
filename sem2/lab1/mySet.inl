#include <iostream>
#include <cmath>


template <typename T>
mySet<T>::mySet() {
    size = 0;
    set = new T[size];
}

template <typename T>
mySet<T>::mySet(const mySet<T>& other): set(new T[other.size]), size(other.size) {
    for (int i = 0; i < other.size; i += 1) {
        set[i] = other.set[i];
    }
}

template <typename T>
mySet<T>& mySet<T>::operator=(const mySet<T> &other) {
    if (this == &other) return *this;            // проверка равен ли объект сам себе (other = other)

    delete[] set;
    set = new T[other.size];
    size = other.size;
    for (int i = 0; i < other.size; i += 1) {
        set[i] = other.set[i];
    }
    return *this;
}

template <typename T>
mySet<T>::~mySet() {
    delete[] set;
}

template <typename T>
void mySet<T>::add(T value) {
    int index = index_to_insert(value);
    if (index >= 0) {
        T *temp = new T[size + 1];

        for (int i = 0; i < index; ++i) {
            temp[i] = set[i];
        }

        temp[index] = value;

        for (int i = index; i < size; ++i) {
            temp[i + 1] = set[i];
        }

        size += 1;
        delete[] set;
        set = temp;
    }
}

template <typename T>
void mySet<T>::del(T value) {
    int index = index_to_delete(value);
    if (index >= 0) {
        for (int i = index; i < size - 1; ++i) {
            set[i] = set[i + 1];
        }

        size -= 1;
        T* temp = new T[size];

        for (int i = 0; i < size; ++i) {
            temp[i] = set[i];
        }

        delete[] set;
        set = temp;
    }
}


template<typename T>
void mySet<T>::clear() {
    delete[] set;
    size = 0;
    set = new T[size];
}


template <typename T>
int mySet<T>::getSize() const {
    const int result = size;
    return result;
//    return size;
}

template <typename T>
bool mySet<T>::contain(T value) const {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (set[mid] == value) {
            return true;
        } else if (set[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}


template <typename T>
int mySet<T>::index(T value) const {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (set[mid] == value) {
            return mid;
        } else if (set[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}


template <typename T>
int mySet<T>::index_to_insert(T value) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (set[mid] == value) {
            return -1;  // Элемент уже присутствует в массиве, возвращаем -1
        } else if (set[mid] < value) {
            left = mid + 1;  // Искомый элемент находится в правой половине
        } else {
            right = mid - 1;  // Искомый элемент находится в левой половине
        }
    }

    return left;  // Возвращаем индекс для вставки элемента
}

template <typename T>
int mySet<T>::index_to_delete(T value) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (set[mid] == value) {
            return mid;
        } else if (set[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}



template <typename T>
mySet<T> mySet<T>::operator+(const mySet<T> other) {
    mySet<T> result;
    result = combining(*this, other);
    return result;
}


template <typename T>
void mySet<T>::operator+=(const mySet<T> other) {
    *this = *this + other;
}



template <typename T>
mySet<T> mySet<T>::operator+(const T value) {
    mySet<T> result = *this;
    result.add(value);
    return result;
}


template <typename T>
void mySet<T>::operator+=(const T value) {
    this -> add(value);
}

template <typename T>
mySet<T> mySet<T>::operator-(const T value) {
    mySet<T> result = *this;
    result.del(value);
    return result;
}


template <typename T>
void mySet<T>::operator-=(const T value) {
    *this = *this - value;
}



template <typename T>
T& mySet<T>::operator[](const int i) const {
    if (i >= size or i < 0) {
        throw std::out_of_range("Set index out of range: i = " + std::to_string(i) + ", size = " + std::to_string(size));
    }
    return set[i];
}

template<typename T>
bool mySet<T>::operator<(const mySet<T> &other) {
    if (size < other.size) {
        return true;
    } else if (size > other.size) {
        return false;
    } else {
        for (int i = 0; i < size; i += 1) {
            if (set[i] < other.set[i]) {
                return true;
            }
            if (set[i] > other.set[i]) {
                return false;
            }
        }
    }
    return false;
}

template<typename T>
bool mySet<T>::operator>(const mySet<T> &other) {
    if (size > other.size) {
        return true;
    } else if (size < other.size) {
        return false;
    } else {
        for (int i = 0; i < size; i += 1) {
            if (set[i] > other.set[i]) {
                return true;
            }
            if (set[i] < other.set[i]) {
                return false;
            }
        }
    }
    return false;
}

template<typename T>
bool mySet<T>::operator<=(const mySet<T> &other) {
    return (*this == other) or (*this < other);
}

template<typename T>
bool mySet<T>::operator>=(const mySet<T> &other) {
    return (*this == other) or (*this > other);
}

template<typename T>
bool mySet<T>::operator==(const mySet<T> &other) {
    if (size != other.size) {
        return false;
    } else {
        for (int i = 0; i < size; i += 1) {
            if (set[i] != other.set[i]) {
                return false;
            }
        }
    }
    return true;
}

template<typename T>
bool mySet<T>::operator!=(const mySet<T> &other) {
    if (size != other.size) {
        return true;
    } else {
        for (int i = 0; i < size; i += 1) {
            if (set[i] != other.set[i]) {
                return true;
            }
        }
    }
    return false;
}

template <typename T>
mySet<T> combining(const mySet<T> set1, const mySet<T> set2) {
    mySet<T> result;
    for (int i = 0; i < set1.getSize(); i += 1) {
        result.add(set1[i]);
    }

    for (int i = 0; i < set2.getSize(); i += 1) {
        result.add(set2[i]);
    }

    return result;
}

template <typename T>
mySet<T> intersection(const mySet<T> set1, const mySet<T> set2) {
    mySet<T> result;
    for (int i = 0; i < set1.getSize(); i += 1) {
        if (set2.contain(set1[i])) {
            result.add(set1[i]);
        }
    }

    return result;
}


template<typename T>
mySet<mySet<T>> boolean(const mySet<T> set) {
    mySet<mySet<T>> result;
    mySet<T> tmp;

    for (int i = 0; i < pow(2, set.getSize()); i += 1) {
        int t1 = i;
        for (int j = 0; j < set.getSize(); j += 1) {
            int t2 = t1 % 2;
            t1 = t1 / 2;
            if (t2) {
                tmp.add(set[j]);
            }
        }

        result.add(tmp);
        tmp.clear();
    }
    return result;
}


template <typename T>
std::ostream &operator<<(std::ostream &os, const mySet<T> set) {
    os << "{";
    if (set.getSize() > 0) {
        for (int i = 0; i < set.getSize() - 1; i += 1) {
            os << set[i] << ", ";
        }
        os << set[set.getSize() - 1];
    }
    os << "}";
    return os;
}

template <typename T>
void printSet(const mySet<T> set, char end){
    std::cout << "{";
    if (set.getSize() > 0) {
        for (int i = 0; i < set.getSize() - 1; i += 1) {
            std::cout << set[i] << ", ";
        }
        std::cout << set[set.getSize() - 1];
    }
    std::cout << "}" << end;
}