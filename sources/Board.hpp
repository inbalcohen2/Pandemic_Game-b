#pragma once
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <utility>

#include "City.hpp"
#include "Color.hpp"

namespace pandemic{

class Board{

public:
	Board();
	bool is_clean() const;
	void remove_cures();
	int & operator[](City city);
	friend std::ostream& operator<<(std::ostream& os,const Board& board);

	void buildResearchStation(City c);
	bool isResearchStation(City c) const;
	void cureFound(Color diseaseColor);
	bool isCureFound(Color diseaseColor) const;
	Color getCityColor(City c) const;
	bool areConnected(City first, City second) const;

private:
	std::unordered_map<City, int> _diseases;
	std::unordered_map<City, bool> _researchStations;
	std::unordered_map<Color, bool> _cures;
	std::unordered_map<City, std::pair<Color, std::unordered_set<City>>> _citiesInformation;
};
}
