#pragma once
#include <defines.h>
#include <alloc_vec.h>
#include <data_structures.h>

int main_iterative()
{
    printf("%s\n", __func__);
    int last_element = 0;
    int avg_acc = 0;
    int avg_qnt = 0;
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
            bufferi_push_and_pop(&b, input_vector[i], &last_element); // O(1)
            avg_acc -= last_element; // O(1)
            // printf("subtract %d == %d\n", last_element, avg_acc);
        }
        avg_acc += input_vector[i];
        // printf("add %d == %d\n", input_vector[i], avg_acc);
        avg_qnt = b.size;
        bufferi_print(&b);
        printf("avg: %d\n", avg_acc/avg_qnt); // O(1)
    }

    bufferi_free(&b);

    return 0;
}