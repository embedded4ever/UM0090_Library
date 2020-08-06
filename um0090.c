#include "um0090.h"
#include "stdlib.h"
#include "string.h"

//Do cast, get parsed value

void get_measurement(const char* data, int* val)
{
    ultrasonic_parser_t *parse = (ultrasonic_parser_t*)data;
    char calculated_arr[3] = {0};
    memcpy(calculated_arr, &parse -> look_data[0], 3);
    //ultrasonic.debug(data);
    *val = atoi(calculated_arr);
}
