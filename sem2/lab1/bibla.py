class _set(object):

    system =[]


    def _init_ (self, element):
        index = True
        mnozh =[]
        mnozh.append(element)
        if len(_set.system) == 0:
           _set.system.append(mnozh)
        for i in range(len(_set.system)):
            if element  in _set.system[i]:
                index = False
                break
        if index:
            _set.system.append(mnozh)
        return _set.system
    def unite(self, x, y):
        if len(_set.system) < 2:
            return 0
        firstT = False
        secondT = False

        for i in range(len(_set.system)):

                if x in _set.system[i]:
                    mnozh1 = _set.system[i]
                    firstT = True
                    firstIndex = i
                elif y in _set.system[i]:
                    mnozh2 = _set.system[i]
                    secondT = True
                    secondIndex = i
        if (firstT == True) and (secondT == True):
            _set.system.pop(firstIndex)

            _set.system.pop(secondIndex-1)
            mnozh = mnozh1 + mnozh2
            _set.system.append(mnozh)

        return _set.system
    def is_in(self,element):
       if len(_set.system) == 0:
           return 0
       for i in range(len(_set.system)):
           if element in _set.system[i]:
               return _set.system[i]






