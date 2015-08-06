#ifndef PREPROCESS_FOR_HUMANS
#include <iostream>
#include <cstdlib>
#endif

#define FOREACH_ROW(X)                 \
  X(enu_jd, "John", "Doe",        23)  \
  X(enu_mm, "Max",  "Mustermann", 24)



#define GEN_ENUM(ENUM_ID, ...) ENUM_ID,

enum Enu {
  FOREACH_ROW(GEN_ENUM)
};




#define GEN_NAMES(ENUM_ID, FIRSTNAMES, SURNAME, ...) {FIRSTNAMES, SURNAME},

struct NameData {
  const char *names;
  const char *surname;
};

const NameData arr[] =
  {FOREACH_ROW(GEN_NAMES)}
  ;



#define GEN_AGE(ENUM_ID, FIRSTNAMES, SURNAME, AGE) AGE,

unsigned age[] =
  {FOREACH_ROW(GEN_AGE)}
  ;




#define GEN_CNT(...) 1U +
constexpr size_t num_rows =
  FOREACH_ROW(GEN_CNT)  0;



int main()
{
  for (size_t i = 0; i < num_rows; ++i) {
    std::cout << i << ") " << arr[i].names << ' ' << arr[i].surname << "     \t(age: " << age[i] << ')' << std::endl;
  }
}
