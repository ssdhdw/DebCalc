#include <unistd.h>
#include <termios.h>

auto getch(bool echo = false){
    termios oldattr;
    tcgetattr(STDIN_FILENO, &oldattr);
    auto newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | (ECHO * !echo));
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    auto ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return ch;
}