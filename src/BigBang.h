#ifndef BIGBANG_H_
#define BIGBANG_H_

#include "ISolarSystem.h"

//! @brief The big bang.
class BigBang
{
public:

   //! Creates the solar system and returns a pointer to it.
   static ISolarSystemSP bang();

private:

   BigBang();

};

#endif /* BIGBANG_H_ */
