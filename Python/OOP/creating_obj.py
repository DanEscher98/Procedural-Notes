#!/usr/bin/python3

from typing import Iterable


class Singleton:  # eg. global config object
    _instance = None

    def __new__(cls, *args, **kwargs):
        if cls._instance is None:
            cls._instance = super().__new__(cls, *args, **kwargs)
        return cls._instance


class UpperTuple(tuple):
    def __new__(cls, iterable: Iterable[str]):
        upper_iterable = (s.upper() for s in iterable)
        return super().__new__(cls, upper_iterable)


if __name__ == "__main__":
    print("Hello")
