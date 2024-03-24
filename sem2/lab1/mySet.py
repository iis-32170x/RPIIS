class mySet:
    def __init__(self, set=None):
        self.set = []
        if set is not None:
            for i in set:
                if isinstance(i, list):
                    tmp = mySet(i)
                else:
                    tmp = i
                self.add(tmp)

    def __str__(self):
        result = ''

        if self.set != []:
            for i in range(len(self.set) - 1):
                result += str(self.set[i])
                result += ', '

            return '{' + result + str(self.set[-1]) + '}'
        else:
            return '{}'

    def __len__(self):
        return len(self.set)

    def __lt__(self, other) -> bool:  # <
        if not (isinstance(other, mySet)):
            return False
        elif len(self.set) < len(other):
            return True
        elif len(self.set) > len(other):
            return False
        else:
            for i in range(len(self.set)):
                if self.set[i] < other.set[i]:
                    return True
                if self.set[i] > other.set[i]:
                    return False
        return False

    def __gt__(self, other) -> bool:  # >
        if not (isinstance(other, mySet)):
            return True
        elif len(self.set) < len(other):
            return False
        elif len(self.set) > len(other):
            return True
        else:
            for i in range(len(self.set)):
                if self.set[i] < other.set[i]:
                    return False
                if self.set[i] > other.set[i]:
                    return True
        return False

    def __eq__(self, other) -> bool:
        if not (isinstance(other, mySet)):
            return False
        elif len(self.set) != len(other):
            return False
        else:
            for i in range(len(self.set)):
                if self.set[i] != other.set[i]:
                    return False
        return True

    def __ne__(self, other):
        return not self.__eq__(other)

    def __le__(self, other):
        return self.__lt__(other) or self.__eq__(other)

    def __ge__(self, other):
        return self.__gt__(other) or self.__eq__(other)

    def __iter__(self) -> iter:
        return mySetIterator(self.set)

    def __contains__(self, item) -> bool:
        return item in self.set

    def __index_to_insert(self, value) -> int:
        left = 0
        right = len(self.set) - 1

        while left <= right:
            mid = int(left + (right - left) / 2)

            if self.set[mid] == value:
                return -1
            elif self.set[mid] < value:
                left = mid + 1
            else:
                right = mid - 1

        return left

    def __index_to_delete(self, value) -> int:
        left = 0
        right = len(self.set) - 1

        while left <= right:
            mid = int(left + (right - left) / 2)

            if self.set[mid] == value:
                return mid
            elif self.set[mid] < value:
                left = mid + 1
            else:
                right = mid - 1

        return -1

    def add(self, value) -> None:
        if isinstance(value, mySet):
            value = value.copy()
        index = self.__index_to_insert(value)
        if index >= 0:
            self.set.insert(index, value)

    def delete(self, value) -> None:
        index = self.__index_to_delete(value)
        if index >= 0:
            del self.set[index]

    def clear(self) -> None:
        self.set = []

    def copy(self):
        set_copy = mySet()
        for i in self.set:
            set_copy.add(i)

        return set_copy


    def contain(self, value) -> bool:
        left = 0
        right = len(self.set) - 1

        while left <= right:
            mid = int(left + (right - left) / 2)

            if self.set[mid] == value:
                return True
            elif self.set[mid] < value:
                left = mid + 1
            else:
                right = mid - 1

        return False




class mySetIterator:
    def __init__(self, set):
        self.set = set
        self.num = 0
        self.size = len(set)

    def __iter__(self) -> iter:
        return self

    def __next__(self):
        if self.num < self.size:
            self.num += 1
            return self.set[self.num - 1]
        raise StopIteration


def combining(first: mySet, second: mySet) -> mySet:
    result = first.copy()

    for i in second:
        result.add(i)

    return result


def intersection(first: mySet, second: mySet) -> mySet:
    result = mySet()

    for i in first:
        if i in second:
            result.add(i)

    return result


def boolean(this: mySet) -> mySet:
    result = mySet()
    tmp = mySet()

    for i in range(2 ** len(this)):
        t1 = i
        for j in this:
            t2 = t1 % 2
            t1 //= 2
            if t2 == 1:
                tmp.add(j)
        result.add(tmp)
        tmp.clear()

    return result
