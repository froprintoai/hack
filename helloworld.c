#include <stdio.h>
#include <unistd.h>
int main() {
    printf("Hello, world!\n");
    return 0;
}
// execve("./a.out", ["./a.out"], 0x7fff6da3fb80 /* 59 vars */) = 0
// brk(NULL)                               = 0x56337b3d4000
// arch_prctl(0x3001 /* ARCH_??? */, 0x7ffe9adbdcb0) = -1 EINVAL (Invalid argument)
// access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
// openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 6
// fstat(6, {st_mode=S_IFREG|0644, st_size=94264, ...}) = 0
// mmap(NULL, 94264, PROT_READ, MAP_PRIVATE, 6, 0) = 0x7ff5f2782000
// close(6)                                = 0
// openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 6
// read(6, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\360q\2\0\0\0\0\0"..., 832) = 832
// pread64(6, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
// pread64(6, "\4\0\0\0\20\0\0\0\5\0\0\0GNU\0\2\0\0\300\4\0\0\0\3\0\0\0\0\0\0\0", 32, 848) = 32
// pread64(6, "\4\0\0\0\24\0\0\0\3\0\0\0GNU\0\363\377?\332\200\270\27\304d\245n\355Y\377\t\334"..., 68, 880) = 68
// fstat(6, {st_mode=S_IFREG|0755, st_size=2029224, ...}) = 0
// mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7ff5f2780000
// pread64(6, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
// pread64(6, "\4\0\0\0\20\0\0\0\5\0\0\0GNU\0\2\0\0\300\4\0\0\0\3\0\0\0\0\0\0\0", 32, 848) = 32
// pread64(6, "\4\0\0\0\24\0\0\0\3\0\0\0GNU\0\363\377?\332\200\270\27\304d\245n\355Y\377\t\334"..., 68, 880) = 68
// mmap(NULL, 2036952, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 6, 0) = 0x7ff5f258e000
// mprotect(0x7ff5f25b3000, 1847296, PROT_NONE) = 0
// mmap(0x7ff5f25b3000, 1540096, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 6, 0x25000) = 0x7ff5f25b3000
// mmap(0x7ff5f272b000, 303104, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 6, 0x19d000) = 0x7ff5f272b000
// mmap(0x7ff5f2776000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 6, 0x1e7000) = 0x7ff5f2776000
// mmap(0x7ff5f277c000, 13528, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7ff5f277c000
// close(6)                                = 0
// arch_prctl(ARCH_SET_FS, 0x7ff5f2781540) = 0
// mprotect(0x7ff5f2776000, 12288, PROT_READ) = 0
// mprotect(0x563379b5f000, 4096, PROT_READ) = 0
// mprotect(0x7ff5f27c7000, 4096, PROT_READ) = 0
// munmap(0x7ff5f2782000, 94264)           = 0
// fstat(1, {st_mode=S_IFREG|0664, st_size=78, ...}) = 0
// brk(NULL)                               = 0x56337b3d4000
// brk(0x56337b3f5000)                     = 0x56337b3f5000
// write(1, "Hello, world!\n", 14)         = 14
// exit_group(0)                           = ?
// +++ exited with 0 +++