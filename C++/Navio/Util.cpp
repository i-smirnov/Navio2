#include <cstdio>
#include <stdarg.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#include "Util.h"

int write_file(const char *path, const char *fmt, ...)
{
    errno = 0;

    int fd = ::open(path, O_WRONLY | O_CLOEXEC);
    if (fd == -1) {
        return -errno;
    }

    va_list args;
    va_start(args, fmt);

    int ret = ::vdprintf(fd, fmt, args);
    int errno_bkp = errno;
    ::close(fd);

    va_end(args);

    if (ret < 1) {
        return -errno_bkp;
    }

    return ret;
}

int read_file(const char *path, const char *fmt, ...)
{
    errno = 0;

    FILE *file = ::fopen(path, "re");
    if (!file)
        return -errno;

    va_list args;
    va_start(args, fmt);

    int ret = ::vfscanf(file, fmt, args);
    int errno_bkp = errno;
    ::fclose(file);

    va_end(args);

    if (ret < 1)
        return -errno_bkp;

    return ret;
}
