import asyncio
import time


async def main():
    print(f"{time.ctime()} Hello!")
    await asyncio.sleep(1.0)
    print(f"{time.ctime()} Goodbye!")


# asyncio proves a `run()` function to execute an async def
# function and all other coroutines called from there.
# asyncio.run(main())

# Almost equivalent to the meaning of `run()`
def blocking():
    time.sleep(0.5)
    print(f"{time.ctime()} Hello from a thread!")


loop = asyncio.get_event_loop()
task = loop.create_task(main())

loop.run_in_executor(None, blocking)
loop.run_until_complete(task)

pending = asyncio.all_tasks(loop=loop)
for task in pending:
    task.cancel()
group = asyncio.gather(*pending, return_exceptions=True)
loop.run_until_complete(group)
loop.close()
