void moveCursorRightBy(int numChars) { printf("\x1B[%dC", numChars); }
void moveCursorDownBy(int numChars) { printf("\x1B[%dB", numChars); }
void moveCursorUpBy(int numChars) { printf("\x1B[%dA", numChars); }
void moveCursorLeftBy(int numChars) { printf("\x1B[%dD", numChars); }
void moveCursorToLineStart() { printf("\x1B[0G"); }
void useBoldConsoleText() { printf("\x1B[1m"); }
void useFaintConsoleText() { printf("\x1B[2m"); }
void useItalicConsoleText() { printf("\x1B[3m"); }
void useUnderlineConsoleText() { printf("\x1B[4m"); }
void useInverseConsoleText() { printf("\x1B[7m"); }
void useStrikeThroughConsoleText() { printf("\x1B[9m"); }
void restoreConsoleText() { printf("\x1B[0m"); }

void clearConsoleScreen() 
{
#ifdef __linux__
    system("clear");

#if defined(TIOCGWINSZ)
    struct winsize ws;

    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) != 0) {
        printf("Could not get window size...");
        exit(1);
    }
    // Center the window vertically
    if(ws.ws_row > 56)
        moveCursorDownBy(ws.ws_row / 2 - 28);
#endif // TIOCGWINSZ
#elif _WIN32
    system("cls");

    // TODO: Vertical window centering
#endif
}

void printCenteredScreen(int indent, const char *msg) {
    if (indent == 0)
    {
#if defined(TIOCGWINSZ)
        struct winsize ws;

        if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) != 0) {
            printf("Could not get window size...");
            exit(1);
        }
        // Center the window horizontally
        if(ws.ws_row > 127)
            indent = (ws.ws_row / 2) - 64;
#endif // TIOCGWINSZ
    }
    for (int i = 0; i < indent; i++) {
        putchar(' ');
    }
    printf("%s", msg);
}