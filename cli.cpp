#include <iostream>

//My modules
#include "animus_cli/main.h"

int main() {
    ANIMUS_CLI a_cli(3);

    //Initailize actual interface
    a_cli.init();
}