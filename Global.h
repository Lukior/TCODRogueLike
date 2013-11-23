#pragma once

#define WIN32_LEAN_AND_MEAN

#include <list>
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <assert.h>

#include <windows.h>

#include "include\TCOD\libtcod.hpp"

using namespace std;

namespace RogueEngine
{
/*** Kernels  ***************************/
	class ComponentKernel;
	class RenderKernel;

	typedef stringstream StringBuilder;
}

#include "Kernels\ComponentKernel.h"
#include "Kernels\RenderKernel.h"

#define OUTPUT_MSG(level, msg) cout << level << " : " << msg << endl;