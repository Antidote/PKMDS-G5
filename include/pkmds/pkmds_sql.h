/*
Copyright (C) 2013  codemonkey85

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/
#pragma once
#ifdef PKMDS_CMAKE_USED
//#ifndef __cplusplus_cli
////#include <sqlite3.h>
//#endif
//#include <pkmds/pkmds_g5.h>
#include <pkmds_g5_sqlite.h>
#else
//#ifndef __cplusplus_cli
////#include "../sqlite3.h"
//#endif
//#include "pkmds_g5.h"
#include "pkmds_g5_sqlite.h"
#endif
//#include "pkmds_g5.h"
//#include "pkmds_g5_sqlite.h"
using namespace std;
//static const int LANG_ID = 9;
//static const int VERSION_GROUP = 11;
//static const int GENERATION = 5;
//static const int BUFF_SIZE = 955;
string DllExport getpkmstatsql(const pokemon_obj &pkm, const Stat_IDs::stat_ids stat_id);
string DllExport getpkmstatsql(const pokemon_obj *pkm, const Stat_IDs::stat_ids stat_id);
void DllExport getspritesql(ostringstream& o, const pokemon_obj & pkm, int langid = LANG_ID);
void DllExport getspritesql(ostringstream& o, const pokemon_obj * pkm, int langid = LANG_ID);
void DllExport geticonsql(ostringstream& o, const pokemon_obj & pkm, int langid = LANG_ID);
void DllExport geticonsql(ostringstream& o, const pokemon_obj * pkm, int langid = LANG_ID);
void DllExport gettypesql(ostringstream& o, const Types::types type);
void DllExport gettypesql(ostringstream& o, const int type);
void DllExport getwallpapersql(ostringstream& o, const int wallpaper);
void DllExport getwallpapersql(ostringstream& o, const Wallpapers::wallpapers wallpaper);
void DllExport getitemsql(ostringstream& itemsql, const uint16 itemid, const int generation = GENERATION);
void DllExport getmarkingsql(ostringstream& o, const Markings::markings mark, const bool marked);
void DllExport getballsql(ostringstream& o, const Balls::balls ball, const int generation = GENERATION);
string DllExport getspeciesnamesql(const int speciesid, const int langid = LANG_ID);
string DllExport getmovenamesql(const int moveid, const int langid = LANG_ID);
string DllExport getmoveflavortextsql(const uint16 moveid, const int langid = LANG_ID, const int versiongroup = VERSION_GROUP);
string DllExport getmovetypenamesql(const uint16 moveid, const int langid = LANG_ID);
string DllExport getmovedamagetypenamesql(const uint16 moveid, const int langid = LANG_ID);
string DllExport getpkmlevelsql(const int id, const int exp);
string DllExport getpkmexptonextsql(const int id, const int exp);
string DllExport getpkmexpatcursql(const int id, const int exp);
string DllExport getpkmexpatlevelsql(const int id, const int level);
string DllExport getpkmexpatlevelsql(const Species::pkmspecies id, const int level);
string DllExport getnaturenamesql(const int natureid, const int langid = LANG_ID);
string DllExport getmoveppsql(const Moves::moves moveid);
string DllExport lookuppkmevolvedspeciessql(int speciesid);
string DllExport getsetlevelsql(pokemon_obj *pkm, int level);
string DllExport getsetlevelsql(pokemon_obj &pkm, int level);
string DllExport getpkmformnamesql(const pokemon_obj *pkm, const int langid = LANG_ID);
string DllExport getpkmformnamesql(const pokemon_obj &pkm, const int langid = LANG_ID);
string DllExport  getnatureincreasesql(const int natureid);
string DllExport  getnaturedecreasesql(const int natureid);
string DllExport  lookupitemnamesql(const int itemid, const int generation = GENERATION, const int langid = LANG_ID);
string DllExport  pkmhasgenddiffsql(const int species);
string DllExport  lookupabilitynamesql(const int abilityid, const int langid = LANG_ID);
string DllExport  lookuplocnamesql(const int locid, const int gen, const int langid = LANG_ID);
string DllExport  lookupitemflavortextsql(const int itemid, const int generation = GENERATION, const int langid = LANG_ID, const int versiongroup = VERSION_GROUP);
string DllExport  lookuppkmcolornamesql(const int species, const int langid = LANG_ID);
string DllExport  lookuppkmcoloridsql(const int species);
string DllExport  lookupabilityflavortextsql(const int abilityid, const int version_group = VERSION_GROUP, const int langid = LANG_ID);
string DllExport  lookupcharacteristicsql(const int statid, const int iv, const int langid = LANG_ID);
string DllExport  lookuptypenamesql(const int type, const int langid = LANG_ID);
void DllExport getmovecatsql(ostringstream& o, const Moves::moves moveid);
