// MIT License

// Copyright (c) 2023 Lucas Oliveira Maggi

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
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
    bufferi_t b;                   // buffer struct
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
            avg_acc -= last_element;                                  // O(1)
            // printf("subtract %d == %d\n", last_element, avg_acc);
        }
        avg_acc += input_vector[i];
        // printf("add %d == %d\n", input_vector[i], avg_acc);
        avg_qnt = b.size;
#ifndef BENCHMARK
        bufferi_print(&b);
        printf("avg: %d\n", avg_acc / avg_qnt); // O(1)
#endif
    }

    bufferi_free(&b);

    return 0;
}