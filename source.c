#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


char convert_case(char c, size_t i) {
    if ((c >= 'a') && (c <= 'z')) {
        if (i % 2) {
            return c;
        } else {
            return c - 32;
        }
    } else if ((c >= 'A') && (c <= 'Z')) {
        if (i % 2) {
            return c + 32;
        } else {
            return c;
        }
    } else {
        return c;
    }
}

void do_stuff() {
    char buf[100];
    size_t length = 0;
    char nl;

    scanf("%[^\n]", buf);
    scanf("%c", &nl);
    for (size_t i = 0; i < 100; i++) {
        buf[i] = convert_case(buf[i], i);
    }
    printf("%s\n", buf);
}

int main(int argc, char **argv) {
    setbuf(stdout, NULL);
    // Set the gid to the effective gid
    // this prevents /bin/sh from dropping the privileges
    gid_t gid = getegid();
    setresgid(gid, gid, gid);

    size_t welcome_len = 27;
    char welcome[] = "Welcome to my echo server!";
    char pwelcome[welcome_len];
    for (size_t i = 0; i < welcome_len; i++) {
        pwelcome[i] = convert_case(welcome[i], i);
    }
    puts(pwelcome);

    while (1) {
        do_stuff();
    }
}

