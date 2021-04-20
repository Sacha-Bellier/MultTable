
#pragma once
#include <cstdint>

void MultTable(uint32_t m, uint32_t* diff, uint32_t* unit, uint32_t* len, bool print);
void MultTableThread(uint32_t i, uint32_t nb, uint32_t* diff, uint32_t* unit, uint32_t* len);

void Run(uint32_t nbToDo, bool print);