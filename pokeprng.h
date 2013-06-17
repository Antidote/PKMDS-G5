/*
***********************************************
PKMDS Code Library - Gen V

Created by Michael Bond (aka Codemonkey85)
https://plus.google.com/116414067936940758871/

Feel free to use and reuse this code as you see fit, but I
implore you to always link back to me as the original creator.
***********************************************

Thanks to Alex "eevee" Munroe at http://veekun.com/
for his SQLite Pokedex database, which powers this software.

Thanks to the fine folks at SQLite.org for making it possible
to use the Pokedex database... the source files "sqlite3.c"
and "sqlite3.h" came from these people.

Thanks to those of Project Pokemon (http://projectpokemon.org/)
who have helped research and document the underlying structure
of Pokemon game save files.

Special thanks to SCV, Sabresite, loadingNOW, Poryhack,
GatorShark, Jiggy-Ninja, Codr, Bond697, mingot, Guested,
coolbho3000 and of course, COM.

Some documentation available at: http://www.projectpokemon.org/wiki/
*/
#pragma once
#include "stdafx.h"
struct pkmprng
{
	uint32 mseed;
	uint32 previous()
	{
		return 0xeeb9eb65 * mseed + 0xa3561a1;
	}
	uint32 previousnum()
	{
		mseed = previous();
		return mseed;
	}
	uint32 next()
	{
		return (0x41c64e6d * mseed) + 0x6073;
	}
	uint32 nextnum()
	{
		mseed = next();
		return mseed;
	}
};
