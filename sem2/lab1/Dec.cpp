void addFront(int*& arr, int& size, int& capacity, int element) {
    if (size == capacity) {
        int newCapacity = capacity * 2;
        int* newArr = new int[newCapacity];
        newArr[0] = element;
        for (int i = 0; i < size; i++) {
            newArr[i + 1] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }
    else {
        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = element;
    }
    size++;
}

void addBack(int*& arr, int& size, int& capacity, int element) {
    if (size == capacity) {
        int newCapacity = capacity * 2;
        int* newArr = new int[newCapacity];
        newArr[size] = element;
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }
    else {
        arr[size] = element;
    }
    size++;
}

void delfront(int*& arr, int& size) {
    if (size <= 0) {
   
        return;
    }

    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
}

void delback(int*& arr, int& size) {
    if (size <= 0) {

        return;
    }

    size--;
}
