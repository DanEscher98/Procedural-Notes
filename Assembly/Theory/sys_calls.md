# System Calls

| SysCall | Description | `rax` | `rdi` | `rsi` | `rdx` | `r10` | `r8` | `r9` |
| ------- | ----------- | ----- | ----- | ----- | ----- | ----- | ---- | ---- |
| read | read from a file descriptor | 0 | unsigned int fd | char *buf | size\_t count | | | |
| write | write to a file descriptor | 1 | unsigned int fd | const char *buf | size\_t count | | | |
