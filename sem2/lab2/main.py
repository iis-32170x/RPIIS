import colorama

import interpreter
from colorama import Fore, Style

i = 1

colorama.init()

while True:
    inp = input(f"{Fore.GREEN}In [{i}]: {Style.RESET_ALL}")

    if inp == "EXIT":
        break

    try:
        out, err = interpreter.interpreter(inp)
    except:
        out = None
        err = 'Invalid syntax'

    if out is not None:
        print(f"{Fore.YELLOW}Out[{i}]: {out}")

    if err is not None:
        print(f"{Fore.RED}Err[{i}]: {err}")

    print()
    i += 1

print(end=f'{Style.RESET_ALL}')