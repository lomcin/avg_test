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
#include <stdio.h>
#include <defines.h>
#include <avg_methods.h>
#include <time.h>

int main()
{
    printf("Hello World!\n");

#ifdef BENCHMARK
    // check the defines.h file to see what is the allocation size
    // note: this will allocate the BENCHMARK_SIZE*sizeof(int) in memory
    init_input_vector(BENCHMARK_SIZE);
#else
    init_input_vector(BSZM * 4);
    print_input_vector();
#endif

    time_t t_begin;
    time_t t_end;
    double secs_iterative, secs_vector;

    time(&t_begin);
    main_iterative();
    time(&t_end);
    secs_iterative = difftime(t_end, t_begin);
    printf("iterative averaging: %.3lf\n", secs_iterative);

    puts("\n");

    time(&t_begin);
    main_vector();
    time(&t_end);
    secs_vector = difftime(t_end, t_begin);
    printf("vector averaging: %.3lf\n", secs_vector);

    free_input_vector();

    return 0;
}