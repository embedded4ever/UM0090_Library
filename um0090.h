#ifndef UM0090_H
#define UM0090_H

#include "stdbool.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef struct __attribute__((packed)) ultrasonic_parser_t
{
  char discard_data[7];
  char look_data[];
  
}ultrasonic_parser_t;

typedef struct ultrasonic_t
{
  char coming_data[15];
  char data;
  //void (*debug)(const char* str);
  //bool is_completed;
  
}ultrasonic_t;

extern ultrasonic_t ultrasonic;

void get_measurement(const char* data, int* val);

#ifdef __cplusplus
}
#endif

#endif
