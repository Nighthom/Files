#pragma once

#include "tree.h"
#include <stdlib.h>

#define SIZEOF_MENU 4


void print_screen();

Node* insert_data(Node* tree);
Node* delete_data(Node* tree);
Node* lookup_data(Node* tree);
Node* search_data(Node* tree);

void print_lable();

void clear_buffer();
