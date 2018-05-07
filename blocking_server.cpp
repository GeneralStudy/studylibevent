#include <netinet/in.h>

#include <sys/socket.h>

#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(int c, char **v) 
{
    const char query[] = 
        "GET / HTTP/1.0\r\n"
        "Host: www.baidu.com\r\n"
        "\r\n";

    const char hostname[] = "www.baidu.com";
    struct sockaddr_in sin;
    struct hostent *h;
    const char *cp;
    int fd;

    ssize_t n_written, remaining;
    char buf[1024];

    h = gethostbyname(hostname);
    if (!h) {
        fprintf(stderr, "Couldn't loopup %s: %s", hostname, hstrerror(h_errno));
        return 1;
    }

    if (h->h_addrtype != AF_INET) {
        fprintf(stderr, "No ipv6 support, sorry");
        return 1;
    }

    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) {
        perror("socket");
        return 1;
    }

    sin.sin_family = AF_INET;
    sin.sin_port = htons(80);

}

