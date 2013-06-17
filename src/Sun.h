#pragma once

#include "AbstractCelestialBody.h"

//! @brief Implementation of the Sun
class Sun : public AbstractCelestialBody
{
public:

   Sun();

   ~Sun();

   void doRender();

};
