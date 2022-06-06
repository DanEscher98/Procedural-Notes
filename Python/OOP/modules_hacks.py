#!/usr/bin/python3


import importlib
import runpy
from types import ModuleType

# In IPython
# %load_ext autoreload
# %autoreload 2


def walk_reload(module: ModuleType):
    if hasattr(module, "__all__"):
        for submodule in module.__all__:
            walk_reload(getattr(module, submodule))
    importlib.reload(module)


# importlib.import_module(name: str)
# importlib.reload(module: ModuleType)

# runpy.run_module


def name_value():
    print(__name__)
