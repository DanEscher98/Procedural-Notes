""" Scopness is evaluated at compile time """


def local_or_global(var):
    if var in locals():
        print("Is local")
    elif var in globals():
        print("Is global")
    else:
        print("Is not defined")


def undef_var():
    try:
        print(x)
    except NameError as err:
        print(f"NameError: {err}")


def local_var():
    try:
        print(x)
    except NameError as err:
        print(f"NameError: {err}")
    x = 0


def global_var():
    try:
        print(f"Global var {y=}")
    except NameError as err:
        print(f"NameError: {err}")


def infact_islocal():
    try:
        print(y)
    except NameError as err:
        print(f"NameError: {err}")
    y = 0


if __name__ == "__main__":
    y = 0
    global_var()
    infact_islocal()
    undef_var()
    local_var()
