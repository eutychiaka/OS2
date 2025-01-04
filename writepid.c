#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("pids.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1) {
        perror("File open failed");
        return 1;
    }

    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        dprintf(fd, "Child PID: %d\n", getpid());
    } else if (pid > 0) {
        // Parent process
        dprintf(fd, "Parent PID: %d\n", getpid());
    } else {
        perror("Fork failed");
    }

    close(fd);
    return 0;
}
