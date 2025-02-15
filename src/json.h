#ifndef _JSON
#define _JSON

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct json {
  char *content;
  char *headers;
} json;

json string_to_json(char *s);

char *json_to_string(json *j);

#endif
