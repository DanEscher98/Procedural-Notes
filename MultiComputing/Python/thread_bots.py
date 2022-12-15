""" Let's summarize the situation:
- The ThreadBot code is very simple and easy to read. The
logic is fine.
- There's a working test (with 100 tables) that reproducibly
passes.
- There's a longer test (with 20,000 tables) that
reproducibly fails.
- The longer test fails in different, nonreproducible ways.
- Probably, there's a race condition bug. """

import threading
from queue import Queue
from attr import attrs, attrib
import sys


class ThreadBot(threading.Thread):
    """ The bot is going to be waiting tables and will need
    to be responsible for some cutlery. Each bot keeps track
    of the cutlery that it took from the kitchen here """
    def __init__(self):
        super().__init__(target=self.manage_table)
        self.cutlery = Cutlery(knives=0, forks=0)
        self.tasks = Queue()

    def manage_table(self):
        while True:
            task = self.tasks.get()
            if task == 'prepare table':
                kitchen.give(
                    to=self.cutlery, knives=4, forks=4)
            elif task == 'clear table':
                self.cutlery.give(
                    to=kitchen, knives=4, forks=4)
            elif task == 'shutdown':
                return


@attrs  # Alternative to dataclasses
class Cutlery:
    knives = attrib(default=0)
    forks = attrib(default=0)

    def give(self, to: 'Cutlery', knives=0, forks=0):
        self.change(-knives, -forks)
        to.change(knives, forks)

    def change(self, knives, forks):
        """ Here's the bug. The inline summation `+=` is
        implemented internally (inside the C code for the
        Python interpreter itself) as a few separate steps:
        1. Read the current value, self.knives, into
        temporary location.
        2. Add the new value, knives, to the value in that
        temporary location.
        3. Copy the new total from the temporary location
        back into the original location.
        The problem with preemptive multitasking is that any
        thread busy with these steps can be interrupted at
        any time, and a different thread can be gien the
        opportunity to work thorugh the same steps. """
        # with self.lock():     # This line, fix the bug
        self.knives += knives
        self.forks += forks


kitchen = Cutlery(knives=100, forks=100)
bots = [ThreadBot() for _ in range(10)]

if __name__ == '__main__':
    for bot in bots:
        for i in range(int(sys.argv[1])):
            bot.tasks.put('prepare table')
            bot.tasks.put('clear table')
        bot.tasks.put('shutdown')

    print('Kitchen inventory before service: ', kitchen)
    for bot in bots:
        bot.start()

    for bot in bots:
        bot.join()
    print('Kitchen inventory after service: ', kitchen)
