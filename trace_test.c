#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>

#define __NR_trace_syscall 463

int main(void)
{
    long ret;

    ret = syscall(__NR_trace_syscall, 1);
    if (ret < 0) {
        perror("trace_syscall");
        return 1;
    }

    write(1, "hello world\n", 12);
    printf("pid %d\n", getpid());

    syscall(__NR_trace_syscall, 0);

    return 0;
}
