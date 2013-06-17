#pragma once

#include "AbstractCelestialBody.h"

//! @brief Implementation of the Earth.
class Earth : public AbstractCelestialBody
{
public:

   Earth();

   ~Earth();

   void doRender();

};
