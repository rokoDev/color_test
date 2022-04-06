#include <errno.h>
#include <stdio.h>
#include <unistd.h>

#include <cstdlib>
#include <iostream>

void handleError(const bool aIsError)
{
    if (!aIsError)
    {
        return;
    }
    const std::error_code errCode(errno, std::system_category());
    std::cerr << errCode.message() << '\n';
    std::exit(errCode.value());
}

int main(int argc, const char* argv[])
{
    // Get stdout file descriptor.
    const int kStdoutFD = fileno(stdout);
    handleError(kStdoutFD == -1);

    // Check if kStdoutFD is an open file descriptor referring to a terminal.
    const int kTerminalFlag = isatty(kStdoutFD);
    handleError(kTerminalFlag == 0);

    if (kTerminalFlag == 1)
    {
        // kStdoutFD is an open file descriptor referring to a terminal.
        // Get TERM environment variable to check if terminal support colors.
        char const* const kTerm = std::getenv("TERM");
        if (kTerm)
        {
            std::cout
                << "TERM = \"" << kTerm
                << "\" and therefore terminal does support colour text.\n";
            // Setup green color for forground
            std::cout << "\033[0;32m";

            std::cout << "Green text example.\n";

            // Resets the terminal to default.
            std::cout << "\033[m";
        }
        else
        {
            std::cout << "TERM environment variable is not found and therefore "
                         "terminal does not support colour text.\n";
        }
    }
    else
    {
        std::cerr << "Error: <int isatty(int)> returned unexcpected value: "
                  << kTerminalFlag << '\n';
        std::exit(-1);
    }
    return 0;
}