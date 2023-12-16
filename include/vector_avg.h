#pragma once
#include <defines.h>
#include <alloc_vec.h>
#include <data_structures.h>

int main_vector()
{
    printf("%s\n", __func__);
    int avg = 0;
    bufferi_t b;            // buffer struct
    bufferi_init(&b, WINDOW_SIZE); // initialize buffer with WINDOW_SIZE as maximum size

    for (int i = 0; i < input_vector_size; ++i)
    {
        if (b.size < b.max_size)
        {
            bufferi_push_back(&b, input_vector[i]); // O(1)
        }
        else
        {
            bufferi_push_and_pop(&b, input_vector[i], NULL); // O(1)
        }
        bufferi_print(&b);
        bufferi_avgi(&b, &avg); // O(n)
        printf("avg: %d\n", avg);
    }

    bufferi_free(&b);

    return 0;
}