#include <stdio.h>
#include <defines.h>
#include <avg_methods.h>

int main()
{
    printf("Hello World!\n");

    init_input_vector(BSZM*4);
    print_input_vector();

    main_iterative();
    puts("\n");
    main_vector();

    free_input_vector();

    return 0;
}