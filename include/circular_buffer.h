#pragma once
#include <stdlib.h>

typedef struct bufferi_st
{
    int *data;       // buffer data pointer
    size_t max_size; // maximum circular buffer size
    size_t size;     // circular buffer size
    size_t cur;      // cursor position
} bufferi_t;

// If you want a memory deallocation look for bufferi_free(bufferi_t *b).
// This is just a quick clear, without writing zeros, the data is still available.
void bufferi_clear(bufferi_t *b)
{
    // check if buffer is not null
    assert(b != NULL);

    // initializing size as 0
    b->size = 0;

    // initializing cursor as 0
    b->cur = 0;
}

void bufferi_init(bufferi_t *b, size_t max_size)
{
    // check if buffer is not null
    assert(b != NULL);

    // allocate the requested size
    b->data = (int *)malloc(max_size * sizeof(int));

    // check if data allocation was successful
    if (b->data != NULL)
    {
        // setting up a valid max_size after checking allocation
        b->max_size = max_size;
    }
    else
    {
        // setting up a valid max_size after failing allocation
        b->max_size = 0;
    }

    // initializing size and cur as 0
    bufferi_clear(b);
}

void bufferi_free(bufferi_t *b)
{
    // check if buffer is not null
    assert(b != NULL);

    // check if data is allocated before trying to deallocate
    assert(b->data != NULL);

    // free data
    free(b->data);

    // just making sure the previous pointer is invalid
    b->data = NULL;

    // making sure the max_size verifications will be coherent
    b->max_size = 0;

    // making sure the size and cur verifications will be coherent
    bufferi_clear(b);
}

int *bufferi_at(bufferi_t *b, size_t pos)
{
    // check if buffer is not null
    assert(b != NULL);

    // check if buffer has data
    assert(b->data != NULL);

    size_t circular_pos = (pos + b->cur) % b->max_size;

    // check if position is valid in buffer data
    // assert(circular_pos > -1 && circular_pos < b->max_size);

    // return pointer to circular position in buffer data
    return &(b->data[circular_pos]);
}

int bufferi_get(bufferi_t *b, size_t pos)
{
    // check if buffer is not null
    assert(b != NULL);

    // check if buffer has data
    assert(b->data != NULL);

    // check if position is valid
    assert((pos >= 0) && (pos < b->size));

    // return value from circular position in buffer data
    return *bufferi_at(b, pos);
}

void bufferi_push_back(bufferi_t *b, int value)
{
    // check if buffer is not null
    assert(b != NULL);

    // check if circular buffer is not full
    assert(b->size < b->max_size);

    // get possible position for new value
    int *data = bufferi_at(b, b->size);

    // set data with value
    *data = value;

    // increment the circular buffer size
    b->size++;
}

void bufferi_pop_front(bufferi_t *b, int *value)
{
    // check if buffer is not null
    assert(b != NULL);

    // check if circular buffer is not empty
    assert(b->size > 0);

    // get possible position for first value
    int *data = bufferi_at(b, 0);

    // sets value from first element in the circular buffer
    if (value != NULL)
    {
        *value = *data;
    }

    // decrement the circular buffer size
    b->size--;

    // move buffer cursor
    b->cur = (b->cur + 1) % b->max_size;
}

void bufferi_print(bufferi_t *b)
{
    // check if buffer is not null
    assert(b != NULL);

    printf("bufferi:");
    for (size_t p = 0; p < b->size; ++p)
    {
        printf(" %d", bufferi_get(b, p));
    }
    printf("\n");
}

void bufferi_push_and_pop(bufferi_t *b, int push_value, int *pop_value)
{
    // check if buffer is not null
    assert(b != NULL);

    // pop front before overflowing
    bufferi_pop_front(b, pop_value);

    // push back after removing first element
    bufferi_push_back(b, push_value);
}

void bufferi_avgi(bufferi_t *b, int *avg)
{
    // check if buffer is not null
    assert(b != NULL);

    int acc = 0;
    for (size_t p = 0; p < b->size; ++p)
    {
        acc += bufferi_get(b, p);
    }
    *avg = acc / b->size;
}

void bufferi_avgd(bufferi_t *b, double *avg)
{
    // check if buffer is not null
    assert(b != NULL);

    double acc = 0.0;
    for (size_t p = 0; p < b->size; ++p)
    {
        acc += (double)bufferi_get(b, p);
    }
    *avg = acc / ((double)b->size);
}

void bufferi_avgf(bufferi_t *b, float *avg)
{
    // check if buffer is not null
    assert(b != NULL);

    float acc = 0.0f;
    for (size_t p = 0; p < b->size; ++p)
    {
        acc += (float)bufferi_get(b, p);
    }
    *avg = acc / ((float)b->size);
}