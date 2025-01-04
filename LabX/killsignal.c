#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handle_signal(int sig) {
    printf("Child received signal %d\n", sig);
}

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        signal(SIGUSR1, handle_signal);
        while (1) {
            pause(); 
        }
    } else if (pid > 0) {
        // Parent process
        sleep(1); 
        printf(" sending signal \n");
        kill(pid, SIGUSR1);
    } else {
        perror("Fork failed");
    }

    return 0;
}
