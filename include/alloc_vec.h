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
#include <stdlib.h>
#include <math.h>
#include <assert.h>

//// INPUT
int *input_vector = NULL;
size_t input_vector_size = 0;

int init_input_vector(size_t size)
{
    assert(input_vector == NULL);
    input_vector = (int *)malloc(size * sizeof(int));
    input_vector_size = size;
    for (int i = 0; i < size; ++i)
    {
        input_vector[i] = rand() % (1 << 12);
    }
}

int print_input_vector()
{
    assert(input_vector != NULL);
    printf("input_vector:");
    for (int i = 0; i < input_vector_size; ++i)
    {
        printf(" %d", input_vector[i]);
    }
    printf("\n");
}

int free_input_vector()
{
    assert(input_vector != NULL);
    free(input_vector);
}

/// BUFFER
int *buffer_vector = NULL;
size_t buffer_vector_size = 0;

int init_buffer_vector(size_t size)
{
    buffer_vector = (int *)calloc(size, sizeof(int));
    buffer_vector_size = size;
}

int print_buffer_vector()
{
    assert(buffer_vector != NULL);
    printf("buffer_vector:");
    for (int i = 0; i < buffer_vector_size; ++i)
    {
        printf(" %d", buffer_vector[i]);
    }
    printf("\n");
}

int free_buffer_vector()
{
    assert(buffer_vector != NULL);
    free(buffer_vector);
}