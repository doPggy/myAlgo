#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct array {
    int used_elem_size;      // 已经使用的空间个数
    int array_size;          // 数组长度
    int elem_type_byte_size; // 存储的字节长度
    void * data;                // 开辟空间
}Array;

Array * array_create()
{
    Array * array = (Array *)malloc(sizeof(Array));
    if(array == NULL)
    {
        return NULL;
    }

    array->data                 = NULL;
    array->used_elem_size       = 0;
    array->elem_type_byte_size  = 0;

    return array;
}

void * array_call(Array * array, size_t array_size, size_t elem_type_byte_size)
{

}

void array_init(Array * array, size_t array_size, size_t elem_type_byte_size)
{
    if(array == NULL)
    {
        return;
    }

    array->data = malloc(array_size * elem_type_byte_size);
    if(array->data == NULL)
    {
        return;
    }

    array->elem_type_byte_size = elem_type_byte_size;
    array->array_size          = array_size;
}

bool array_is_full(Array *array)
{
    return array->used_elem_size >= array->array_size;
}

bool array_is_empty(Array *array)
{
    return array->used_elem_size == 0;
}

int array_del_by_index(Array *array, int index)
{
    if(array == NULL)
    {
        return -1;
    }
    if(array->data == NULL)
    {
        return -2;
    }
    if(index > array->used_elem_size || index < 0)
    {
        return -3;
    }

    if(array_is_empty(array))
    {
        return -4;
    }

    char *data = (char *)(array->data);
    for (int i = index - 1; i < array->used_elem_size - 1; i++)
    {
        void *p_new = data + i * array->elem_type_byte_size;
        void *p_old = data + (i + 1) * array->elem_type_byte_size;
        memcpy(p_new, p_old, array->elem_type_byte_size);
    }

    array->used_elem_size--;
}

int array_insert_by_index(Array *array, int index, void *value)
{
    if(array == NULL)
    {
        return -1;
    }
    if(array->data == NULL)
    {
        return -2;
    }
    if(index > array->array_size)
    {
        return -3;
    }
    // 数组中部和尾巴和头可以插入
    if(index > array->used_elem_size + 1 || index < 0)
    {
        return -4;
    }

    // 支持动态扩容
    if(array_is_full(array))
    {
        printf("full and expand!\n");
        void * new_address = malloc((array->used_elem_size + array->elem_type_byte_size) * 10);
        memcpy(new_address, array->data, array->used_elem_size * array->elem_type_byte_size);
        free(array->data);
        array->data = new_address;
        array->array_size = array->array_size + 10;
    }

    // 3 4 5 6 
    for(int i = array->used_elem_size; i >= index; i--)
    {
        void * p_new = (char *)array->data + i * array->elem_type_byte_size;
        void * p_old = (char *)array->data + (i - 1) * array->elem_type_byte_size;
        memcpy(p_new, p_old, array->elem_type_byte_size * 1);
    }

    memcpy((char *)array->data + (index - 1) * array->elem_type_byte_size, value, array->elem_type_byte_size);
    array->used_elem_size++;
}

void array_destory(Array *array)
{
    // delete [] array->data;
    free(array->data);
    free(array);
}

void array_dump(Array *array)
{
    printf("-----------------\n");
    for(size_t i = 0; i < array->used_elem_size; i++)
    {
        printf("[%02d]=%08d\n", i + 1, *((char *)array->data + i * array->elem_type_byte_size));
    }
    printf("-----------------\n");
}


int main()
{
    int values[9] = {1, 2, 3, 4, 5, 6, 7};
    Array *array = array_create();
    array_init(array, 4, sizeof(int));
    for(int i = 0; i < 7; i++)
    {
        array_insert_by_index(array, 1, values + i);
        array_dump(array);
    }
    array_insert_by_index(array, 2, values + 1);
    array_dump(array);
    array_del_by_index(array, 4);
    array_dump(array);
    array_del_by_index(array, 4);
    array_dump(array);
    array_del_by_index(array, 4);
    array_dump(array);
    array_del_by_index(array, 4);
    array_dump(array);
    array_del_by_index(array, 4);
    array_dump(array);
    array_del_by_index(array, 4);
    array_dump(array);
    array_del_by_index(array, 1);
    array_dump(array);
    array_del_by_index(array, 1);
    array_dump(array);
    array_del_by_index(array, 1);
    array_dump(array);

    array_destory(array);
    return 0;
}
