#pragma once

#define ANSWER_00 <functional>

#define ANSWER_10 std::function
#define ANSWER_11 bool
#define ANSWER_12 T&
#define ANSWER_13 T
#define ANSWER_14 void

#define ANSWER_20 [&value](int nb) { return nb < value; }
#define ANSWER_21 [](std::string& s) { s += " " + s; }
#define ANSWER_22 []() { static unsigned int nb = 0; return nb++; }