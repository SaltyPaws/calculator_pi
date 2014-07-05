#include "VariableFactory.h"

//---------------------------------------------------------------------------
// Factory function for creating new parser variables
// This could as well be a function performing database queries.
value_type* AddVariable(const char *a_szName, void *pUserData)
{
  static double afValBuf[100];
  static int iVal = -1;

  iVal++;
  if (iVal>=99) {iVal =0;} //Start recycling variables after 100 have been entered

  /*std::cout << "Generating new variable \""
            << a_szName << "\" (slots left: "
            << 99-iVal << ")" << endl;
*/
  // You can also use custom factory classes like for instance:
  // MyFactory *pFactory = (MyFactory*)pUserData;
  // pFactory->CreateNewVariable(a_szName);

  afValBuf[iVal] = 0;
/*
  if (iVal>=99)
    throw mu::ParserError("Variable buffer overflow.");
  else*/
    return &afValBuf[iVal];
}

