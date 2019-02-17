/*
Minetest
Copyright (C) 2019 paramat

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/


#pragma once

#include "mapgen.h"

#define MGWATERSHED_VENTS 0x01

class BiomeManager;

extern FlagDesc flagdesc_mapgen_watershed[];


struct MapgenWatershedParams : public MapgenParams {
	u32 spflags;

	float map_scale;
	float sea_y;
	float flat_y;
	float continent_area;
	float river_width;
	float river_depth;
	float river_bank;
	s16 big_dungeon_ymin;
	s16 big_dungeon_ymax;

	float cave_width;
	s16 large_cave_depth;
	s16 lava_depth;
	s16 cavern_limit;
	s16 cavern_taper;
	float cavern_threshold;
	s16 dungeon_ymin;
	s16 dungeon_ymax;

	NoiseParams np_vent;
	NoiseParams np_continent;
	NoiseParams np_base;
	NoiseParams np_flat;
	NoiseParams np_river1;
	NoiseParams np_river2;
	NoiseParams np_mountain;
	NoiseParams np_plateau;
	NoiseParams np_plat_select;
	NoiseParams np_3d;
	NoiseParams np_big_dungeon;

	NoiseParams np_filler_depth;
	NoiseParams np_cave1;
	NoiseParams np_cave2;
	NoiseParams np_cavern;

	MapgenWatershedParams();
	~MapgenWatershedParams() {}

	void readParams(const Settings *settings);
	void writeParams(Settings *settings) const;
};


class MapgenWatershed : public MapgenBasic {
public:
	MapgenWatershed(int mapgenid, MapgenWatershedParams *params,
		EmergeManager *emerge);
	~MapgenWatershed();

	virtual MapgenType getType() const { return MAPGEN_WATERSHED; }

	virtual void makeChunk(BlockMakeData *data);
	int getSpawnLevelAtPoint(v2s16 p);
	int generateTerrain();

private:
	float div;
	float sea_y;
	float flat_y;
	float continent_area;
	float river_width;
	float river_depth;
	float river_bank;
	s16 big_dungeon_ymin;
	s16 big_dungeon_ymax;

	s16 large_cave_depth;
	s16 dungeon_ymin;
	s16 dungeon_ymax;

	float vertical_scale;
	float base_flat;

	NoiseParams np_vent_div;
	NoiseParams np_continent_div;
	NoiseParams np_base_div;
	NoiseParams np_flat_div;
	NoiseParams np_river1_div;
	NoiseParams np_river2_div;
	NoiseParams np_mountain_div;
	NoiseParams np_plateau_div;
	NoiseParams np_plat_select_div;
	NoiseParams np_3d_div;
	NoiseParams np_big_dungeon;

	Noise *noise_vent;
	Noise *noise_continent;
	Noise *noise_base;
	Noise *noise_flat;
	Noise *noise_river1;
	Noise *noise_river2;
	Noise *noise_mountain;
	Noise *noise_plateau;
	Noise *noise_plat_select;
	Noise *noise_3d;

	NoiseParams np_dungeon;

	content_t c_volcanic_rock;
};
