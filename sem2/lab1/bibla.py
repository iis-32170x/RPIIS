class _set(object):
    def _init_from_one_number_to_your_second_number(self,first_number, number_of_elements):
        mnozh =[]
        for i in range(first_number, number_of_elements+1):

            mnozh.append(i)
        return mnozh
    def _init_ (self, number_of_elements):
        mnozh =[]
        for i in range(number_of_elements):
            element = int(input())
            mnozh.append(element)
        return mnozh
    def unite(self, mnozh1, mnozh2):
        mnozh=mnozh1
        for i in range(len(mnozh2)):
                if mnozh2[i] not in mnozh1:
                    mnozh.append(mnozh2[i])

        return mnozh
    def is_in(self, *args):
        element = args[-1]
        for i in range(len(args)-1):
            if element in args[i]:
                print("В множестве ", args[i], " присутсвует элемент", element)




