// usage of execl

// #include <stdio.h>
// #include <unistd.h>
// int main()
// {
//     printf("Before execl\n");
//     execl("/binj/ls", "ls", "-l", ".", NULL);
//     perror("execl failed");
//     return 1;
// }

// usage of execv

// #include <stdio.h>
// #include <unistd.h>
// int main() {
//     printf("Before execv\n");
//     char *args[] = {"ls", "-l", "/", NULL};
//     execv("/bin/ls", args);
//     perror("execv failed");
//     return 1;
// }

// usage of execlp

// #include <stdio.h>
// #include <unistd.h>

// int main()
// {
//     printf("Before execlp\n");
//     execlp("ls", "ls", NULL);
//     perror("execlp failed");
//     return 1;
// }

// usage of execvp

// #include <stdio.h>
// #include <unistd.h>

// int main()
// {
//     printf("Before execvp\n");
//     char *args[] = {"ls", "-la", NULL};
//     execvp("ls", args);
//     perror("execvp failed\n");
//     return 1;
// }