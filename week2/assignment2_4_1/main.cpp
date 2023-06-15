#include "get_user_file.h"

int main(int argc, char* argv[])
{
    if (argc == 2)
    print_file_contents(argv[1]);

    return 0;
}
