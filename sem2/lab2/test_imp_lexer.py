import sys
from imp_lexer import *

if __name__ == '__main__':

    while True:
        tmp = input()
        if tmp == "EXIT":
            break
        else:
            tokens = imp_lex(tmp)
            print(tokens)

