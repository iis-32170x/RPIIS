import imp_lexer
import mySet

dataset: dict[mySet.mySet] = dict()

def interpreter(inp: str):
    out = None

    lex, err = imp_lexer.imp_lex(inp)

    if err is not None:
        return out, err

    if len(lex) == 1:
        if lex[0][1] == imp_lexer.ID:
            if lex[0][0] not in dataset:
                return None, f'name "{lex[0][0]}" is not defined'
            else:
                return dataset[lex[0][0]], None
        elif lex[0][1] == imp_lexer.SET:
            return mySet.mySet(eval(lex[0][0].replace('{', '[').replace('}', ']').replace('<', '(').replace('>', ')'))), None
        else:
            return None, f'expected SET or ID'

    elif len(lex) == 2:
        if lex[0][1] == imp_lexer.BOOLEAN:
            if lex[1][1] == imp_lexer.ID:  # первое это сущ. ID
                if lex[1][0] not in dataset:
                    return None, f'name "{lex[1][0]}" is not defined'  # первое ID не определено
                else:
                    lex[1] = (dataset[lex[1][0]], imp_lexer.SET)
            else:
                lex[1] = (mySet.mySet(eval(lex[1][0].replace('{', '[').replace('}', ']').replace('<', '(').replace('>', ')'))), imp_lexer.SET)

            if lex[1][1] != imp_lexer.SET:
                return None, f'met "{lex[1][0]}", expected SET or ID'

            return mySet.boolean(lex[1][0]), None

        else:
            return None, f'met "{lex[0][0]}", expected "~"'

    elif len(lex) == 3:
        if lex[1][1] == imp_lexer.ASSIGNMENT:                                  # если будем присваивать
            if lex[0][1] == imp_lexer.ID:                                      # первое значение это - ID
                if lex[2][1] == imp_lexer.SET:                                 # второе это SET
                    dataset[lex[0][0]] = mySet.mySet(eval(lex[2][0].replace('{', '[').replace('}', ']').replace('<', '(').replace('>', ')')))
                    return None, None

                elif lex[2][1] == imp_lexer.ID:                                # или второе это сущ. ID
                    if lex[2][0] not in dataset:
                        return None, f'name "{lex[2][0]}" is not defined'               # второе ID не определено
                    else:
                        dataset[lex[0][0]] = dataset[lex[2][0]].copy()
                        return None, None
                else:
                    return None, f'met "{lex[2][0]}", expected SET or ID'
            else:                                                              # первое может быть только ID
                return None, f'met "{lex[0][0]}", expected ID'
        elif lex[1][1] in (imp_lexer.COMBINING, imp_lexer.INTERSECTION):       # в другом случае
            if lex[0][1] == imp_lexer.ID:  # первое это сущ. ID
                if lex[0][0] not in dataset:
                    return None, f'name "{lex[0][0]}" is not defined'  # первое ID не определено
                else:
                    lex[0] = (dataset[lex[0][0]], imp_lexer.SET)
            else:
                lex[0] = (mySet.mySet(eval(lex[0][0].replace('{', '[').replace('}', ']').replace('<', '(').replace('>', ')'))), imp_lexer.SET)
            if lex[2][1] == imp_lexer.ID:  # второе это сущ. ID
                if lex[2][0] not in dataset:
                    return None, f'name "{lex[2][0]}" is not defined'  # второе ID не определено
                else:
                    lex[2] = (dataset[lex[2][0]], imp_lexer.SET)
            else:
                 lex[2] = (mySet.mySet(eval(lex[2][0].replace('{', '[').replace('}', ']').replace('<', '(').replace('>', ')'))), imp_lexer.SET)

            if lex[0][1] != imp_lexer.SET:
                return None, f'met "{lex[0][0]}", expected SET or ID'
            if lex[2][1] != imp_lexer.SET:
                return None, f'met "{lex[2][0]}", expected SET or ID'

            # теперь первое и второе это SET

            if lex[1][1] == imp_lexer.COMBINING:
                return mySet.combining(lex[0][0], lex[2][0]), None
            if lex[1][1] == imp_lexer.INTERSECTION:
                return mySet.intersection(lex[0][0], lex[2][0]), None
        else:
            return None, f'met "{lex[1][0]}", expected "+" or "|" or "="'

    elif len(lex) == 4:
        if lex[0][1] == imp_lexer.ID:
            if lex[1][1] == imp_lexer.ASSIGNMENT:
                if lex[2][1] == imp_lexer.BOOLEAN:
                    if lex[3][1] == imp_lexer.ID:  # первое это сущ. ID
                        if lex[3][0] not in dataset:
                            return None, f'name "{lex[3][0]}" is not defined'  # первое ID не определено
                        else:
                            lex[3] = (dataset[lex[3][0]], imp_lexer.SET)
                    else:
                        lex[3] = (mySet.mySet(
                            eval(lex[3][0].replace('{', '[').replace('}', ']').replace('<', '(').replace('>', ')'))),
                                  imp_lexer.SET)

                    if lex[3][1] != imp_lexer.SET:
                        return None, f'met "{lex[3][0]}", expected SET or ID'

                    # return mySet.boolean(lex[3][0]), None
                    dataset[lex[0][0]] = mySet.boolean(lex[3][0])
                    return None, None

                else:
                    return None, f'met "{lex[2][0]}", expected "~"'

            else:
                return None, f'met "{lex[1][0]}", expected "="'
        else:
            return None, f'met "{lex[0][0]}", expected ID'

    elif len(lex) == 5:
        if lex[0][1] == imp_lexer.ID:
            if lex[1][1] == imp_lexer.ASSIGNMENT:

                if lex[3][1] in (imp_lexer.COMBINING, imp_lexer.INTERSECTION):  # в другом случае
                    if lex[4][1] == imp_lexer.ID:  # первое это сущ. ID
                        if lex[4][0] not in dataset:
                            return None, f'name "{lex[4][0]}" is not defined'  # первое ID не определено
                        else:
                            lex[4] = (dataset[lex[4][0]], imp_lexer.SET)
                    else:
                        lex[4] = (mySet.mySet(
                            eval(lex[4][0].replace('{', '[').replace('}', ']').replace('<', '(').replace('>', ')'))),
                                  imp_lexer.SET)

                    if lex[2][1] == imp_lexer.ID:  # второе это сущ. ID
                        if lex[2][0] not in dataset:
                            return None, f'name "{lex[2][0]}" is not defined'  # второе ID не определено
                        else:
                            lex[2] = (dataset[lex[2][0]], imp_lexer.SET)
                    else:
                        lex[2] = (mySet.mySet(
                            eval(lex[2][0].replace('{', '[').replace('}', ']').replace('<', '(').replace('>', ')'))),
                                  imp_lexer.SET)

                    if lex[4][1] != imp_lexer.SET:
                        return None, f'met "{lex[4][0]}", expected SET or ID'
                    if lex[2][1] != imp_lexer.SET:
                        return None, f'met "{lex[2][0]}", expected SET or ID'

                    # теперь первое и второе это SET

                    if lex[3][1] == imp_lexer.COMBINING:
                        dataset[lex[0][0]] = mySet.combining(lex[2][0], lex[4][0])
                        return None, None
                    if lex[3][1] == imp_lexer.INTERSECTION:
                        dataset[lex[0][0]] = mySet.intersection(lex[2][0], lex[4][0])
                        return None, None
                else:
                    return None, f'met "{lex[3][0]}", expected "+" or "|"'


            else:
                return None, f'met "{lex[1][0]}", expected "="'
        else:
            return None, f'met "{lex[0][0]}", expected ID'

    else:
        return None, "Incorrect input format"



