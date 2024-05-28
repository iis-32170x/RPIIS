import lexer

RESERVED     = 'RESERVED'
ASSIGNMENT   = 'ASSIGNMENT'
COMBINING    = 'COMBINING'
INTERSECTION = 'INTERSECTION'
BOOLEAN      = 'BOOLEAN'
SET          = 'SET'
ID           = 'ID'

token_exprs = [
    (r'[ \n\t]+',              None),       # перенос строки
    (r'#[^\n]*',               None),       # коментарии
    (r'=',                     ASSIGNMENT), # присваивание
    (r'\~',                    BOOLEAN),    # булеан
    # (r'\(',                    RESERVED),   #
    # (r'\)',                    RESERVED),   #
    # (r'\+=',                   RESERVED),   # объединение с присваиванием
    (r'\+',                    COMBINING),   # объединение
    # (r'\|=',                   RESERVED),   # пересечение с присваиванием
    (r'\|',                    INTERSECTION),   # пересечение
    # (r'<=',                    RESERVED),   #
    # (r'<',                     RESERVED),   #
    # (r'>=',                    RESERVED),   #
    # (r'>',                     RESERVED),   #
    # (r'==',                    RESERVED),   #
    # (r'!=',                    RESERVED),   #
    (r'\{(?:[^{}]*|(?R))*\}',  SET),
    # не закончено, исправить   значение переменной

    (r'[A-Za-z][A-Za-z0-9_]*', ID),         # имя переменной
]

def imp_lex(characters):
    out, err = lexer.lex(characters, token_exprs)
    if err is not None:
        return None, ' ' * err + f'^\nIllegal character at pos {err}'
    return out, None
