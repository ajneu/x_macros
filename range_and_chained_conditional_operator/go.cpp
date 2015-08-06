#ifndef PREPROCESS_FOR_HUMANS
#include <iostream>
#endif

#define FOREACH_Limits(X)                 \
  X( 0, 10, enu0)                         \
  X(20, 30, enu20)                        \
  X(40, 50, enu40)




#define GEN_ENUM(START, END, ENUM_ID) ENUM_ID,

enum Enu {
  FOREACH_Limits(GEN_ENUM)
  enu_other
};



#define CMP(           START, END)          (((START) <= (val)) && ((val) < (END)))
#define GEN_SELECTOR(  START, END, ENUM_ID) (CMP(START, END) ? ENUM_ID : 
#define GEN_CLOSEPAREN(...)                 )

Enu get_enum(int val)
{
  return FOREACH_Limits(GEN_SELECTOR)
         enu_other
         FOREACH_Limits(GEN_CLOSEPAREN)
    ;
}


#define GEN_CASE(START, END, ENUM_ID) case ENUM_ID : return #ENUM_ID; break;

const char *get_enu_token(Enu enu)
{
  switch(enu) {
    FOREACH_Limits(GEN_CASE)
  default:
      return "enu_other";
      break;
  }
}


#define GEN_MSG(START, END, ENUM_ID) "[" #START ", " #END ") -- " #ENUM_ID "      , or \n"


int main()
{
  std::cout << "Enter numbers in\n"
                FOREACH_Limits(GEN_MSG)
                "other    -- enu_other:" << std::endl;

  for (int i; std::cin >> i; ) {
    std::cout << "Got " << get_enu_token(get_enum(i)) << std::endl;
  }
}
