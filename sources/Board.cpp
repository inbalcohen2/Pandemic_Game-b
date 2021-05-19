#include <algorithm>
#include "Board.hpp"

namespace pandemic{

	Board::Board()
	{
		/* initialize neighbors graph per city */
		_citiesInformation[Algiers] = {Black, {Madrid, Paris, Istanbul, Cairo}};
		_citiesInformation[Atlanta] = {Blue, {Chicago, Miami, Washington}};
		_citiesInformation[Baghdad] = {Black, {Tehran, Istanbul, Cairo, Riyadh, Karachi}};
		_citiesInformation[Bangkok] = {Red, {Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong}};
		_citiesInformation[Beijing] = {Red, {Shanghai, Seoul}};
		_citiesInformation[Bogota] = {Yellow, {MexicoCity, Lima, Miami, SaoPaulo, BuenosAires}};
		_citiesInformation[BuenosAires] = {Yellow, {Bogota, SaoPaulo}};
		_citiesInformation[Cairo] = {Black, {Algiers, Istanbul, Baghdad, Khartoum, Riyadh}};
		_citiesInformation[Chennai] = {Black, {Mumbai, Delhi, Kolkata, Bangkok, Jakarta}};
		_citiesInformation[Chicago] = {Blue, {SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal}};
		_citiesInformation[Delhi] = {Black, {Tehran, Karachi, Mumbai, Chennai, Kolkata}};
		_citiesInformation[Essen] = {Blue, {London, Paris, Milan, StPetersburg}};
		_citiesInformation[HoChiMinhCity] = {Red, {Jakarta, Bangkok, HongKong, Manila}};
		_citiesInformation[HongKong] = {Red, {Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei}};
		_citiesInformation[Istanbul] = {Black, {Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow}};
		_citiesInformation[Jakarta] = {Red, {Chennai, Bangkok, HoChiMinhCity, Sydney}};
		_citiesInformation[Johannesburg] = {Yellow, {Kinshasa, Khartoum}};
		_citiesInformation[Karachi] = {Black, {Tehran, Baghdad, Riyadh, Mumbai, Delhi}};
		_citiesInformation[Khartoum] = {Yellow, {Cairo, Lagos, Kinshasa, Johannesburg}};
		_citiesInformation[Kinshasa] = {Yellow, {Lagos, Khartoum, Johannesburg}};
		_citiesInformation[Kolkata] = {Black, {Delhi, Chennai, Bangkok, HongKong}};
		_citiesInformation[Lagos] = {Yellow, {SaoPaulo, Khartoum, Kinshasa}};
		_citiesInformation[Lima] = {Yellow, {MexicoCity, Bogota, Santiago}};
		_citiesInformation[London] = {Blue, {NewYork, Madrid, Essen, Paris}};
		_citiesInformation[LosAngeles] = {Yellow, {SanFrancisco, Chicago, MexicoCity, Sydney}};
		_citiesInformation[Madrid] = {Blue, {London, NewYork, Paris, SaoPaulo, Algiers}};
		_citiesInformation[Manila] = {Red, {Taipei, HongKong, SanFrancisco, HoChiMinhCity, Sydney}};
		_citiesInformation[MexicoCity] = {Yellow, {LosAngeles, Chicago, Miami, Lima, Bogota}};
		_citiesInformation[Miami] = {Yellow, {Atlanta, MexicoCity, Washington, Bogota}};
		_citiesInformation[Milan] = {Blue, {Essen, Paris, Istanbul}};
		_citiesInformation[Montreal] = {Blue, {Chicago, Washington, NewYork}};
		_citiesInformation[Moscow] = {Black, {StPetersburg, Istanbul, Tehran}};
		_citiesInformation[Mumbai] = {Black, {Karachi, Delhi, Chennai}};
		_citiesInformation[NewYork] = {Blue, {Montreal, Washington, London, Madrid}};
		_citiesInformation[Osaka] = {Red, {Taipei, Tokyo}};
		_citiesInformation[Paris] = {Blue, {Algiers, Essen, Madrid, Milan, London}};
		_citiesInformation[Riyadh] = {Black, {Baghdad, Cairo, Karachi}};
		_citiesInformation[SanFrancisco] = {Blue, {LosAngeles, Chicago, Tokyo, Manila}};
		_citiesInformation[Santiago] = {Yellow, {Lima}};
		_citiesInformation[SaoPaulo] = {Yellow, {Bogota, BuenosAires, Lagos, Madrid}};
		_citiesInformation[Seoul] = {Red, {Beijing, Shanghai, Tokyo}};
		_citiesInformation[Shanghai] = {Red, {Beijing, HongKong, Taipei, Seoul, Tokyo}};
		_citiesInformation[StPetersburg] = {Blue, {Essen, Istanbul, Moscow}};
		_citiesInformation[Sydney] = {Red, {Jakarta, Manila, LosAngeles}};
		_citiesInformation[Taipei] = {Red, {Shanghai, HongKong, Osaka, Manila}};
		_citiesInformation[Tehran] = {Black, {Baghdad, Moscow, Karachi, Delhi}};
		_citiesInformation[Tokyo] = {Red, {Seoul, Shanghai, Osaka, SanFrancisco}};
		_citiesInformation[Washington] = {Blue, {Atlanta, NewYork, Montreal, Miami}};

		/* initialize diseases number per city */
		_diseases[Algiers] = 0;
		_diseases[Atlanta] = 0;
		_diseases[Baghdad] = 0;
		_diseases[Bangkok] = 0;
		_diseases[Beijing] = 0;
		_diseases[Bogota] = 0;
		_diseases[BuenosAires] = 0;
		_diseases[Cairo] = 0;
		_diseases[Chennai] = 0;
		_diseases[Chicago] = 0;
		_diseases[Delhi] = 0;
		_diseases[Essen] = 0;
		_diseases[HoChiMinhCity] = 0;
		_diseases[HongKong] = 0;
		_diseases[Istanbul] = 0;
		_diseases[Jakarta] = 0;
		_diseases[Johannesburg] = 0;
		_diseases[Karachi] = 0;
		_diseases[Khartoum] = 0;
		_diseases[Kinshasa] = 0;
		_diseases[Kolkata] = 0;
		_diseases[Lagos] = 0;
		_diseases[Lima] = 0;
		_diseases[London] = 0;
		_diseases[LosAngeles] = 0;
		_diseases[Madrid] = 0;
		_diseases[Manila] = 0;
		_diseases[MexicoCity] = 0;
		_diseases[Miami] = 0;
		_diseases[Milan] = 0;
		_diseases[Montreal] = 0;
		_diseases[Moscow] = 0;
		_diseases[Mumbai] = 0;
		_diseases[NewYork] = 0;
		_diseases[Osaka] = 0;
		_diseases[Paris] = 0;
		_diseases[Riyadh] = 0;
		_diseases[SanFrancisco] = 0;
		_diseases[Santiago] = 0;
		_diseases[SaoPaulo] = 0;
		_diseases[Seoul] = 0;
		_diseases[Shanghai] = 0;
		_diseases[StPetersburg] = 0;
		_diseases[Sydney] = 0;
		_diseases[Taipei] = 0;
		_diseases[Tehran] = 0;
		_diseases[Tokyo] = 0;
		_diseases[Washington] = 0;

		/* initialize research station per city */
		_researchStations[Algiers] = false;
		_researchStations[Atlanta] = false;
		_researchStations[Baghdad] = false;
		_researchStations[Bangkok] = false;
		_researchStations[Beijing] = false;
		_researchStations[Bogota] = false;
		_researchStations[BuenosAires] = false;
		_researchStations[Cairo] = false;
		_researchStations[Chennai] = false;
		_researchStations[Chicago] = false;
		_researchStations[Delhi] = false;
		_researchStations[Essen] = false;
		_researchStations[HoChiMinhCity] = false;
		_researchStations[HongKong] = false;
		_researchStations[Istanbul] = false;
		_researchStations[Jakarta] = false;
		_researchStations[Johannesburg] = false;
		_researchStations[Karachi] = false;
		_researchStations[Khartoum] = false;
		_researchStations[Kinshasa] = false;
		_researchStations[Kolkata] = false;
		_researchStations[Lagos] = false;
		_researchStations[Lima] = false;
		_researchStations[London] = false;
		_researchStations[LosAngeles] = false;
		_researchStations[Madrid] = false;
		_researchStations[Manila] = false;
		_researchStations[MexicoCity] = false;
		_researchStations[Miami] = false;
		_researchStations[Milan] = false;
		_researchStations[Montreal] = false;
		_researchStations[Moscow] = false;
		_researchStations[Mumbai] = false;
		_researchStations[NewYork] = false;
		_researchStations[Osaka] = false;
		_researchStations[Paris] = false;
		_researchStations[Riyadh] = false;
		_researchStations[SanFrancisco] = false;
		_researchStations[Santiago] = false;
		_researchStations[SaoPaulo] = false;
		_researchStations[Seoul] = false;
		_researchStations[Shanghai] = false;
		_researchStations[StPetersburg] = false;
		_researchStations[Sydney] = false;
		_researchStations[Taipei] = false;
		_researchStations[Tehran] = false;
		_researchStations[Tokyo] = false;
		_researchStations[Washington] = false;

		/* initialize cures according to color disease */
		_cures[Black] = false;
		_cures[Red] = false;
		_cures[Blue] = false;
		_cures[Yellow] = false;
	}


bool Board::is_clean() const
{
	for(const auto& [city, diseasesNum] : _diseases)
	{
	  if (diseasesNum > 0)
	  {
		  return false;
	  }
	}
	return true;
}

  int & Board::operator[](City city){
    return this->_diseases[city];
  }

  void Board::remove_cures(){
		for(auto& [color, isCure] : _cures)
		{
			isCure = false;
		}
  }

  std::ostream& operator<<(std::ostream& os,const Board& board)
  {

	  // disease level in each city, and research lab if exist
	  for (const auto& [city, diseasesNum] : board._diseases)
	  {
		  os << "[" << city << ',' << diseasesNum << "]\n";
		  if (board._researchStations.at(city)){
			  os << "has research station\n";
		  }
	  }

	  // cures found so far
	  for (const auto&[color, isCure] : board._cures)
	  {
		  os << color << ":" << isCure;
	  }

	  return os;
  }

	void Board::cureFound(Color diseaseColor)
	{
		_cures[diseaseColor] = true;
	}

	bool Board::isCureFound(Color diseaseColor) const
	{
		return _cures.at(diseaseColor);
	}

	void Board::buildResearchStation(City c)
	{
		_researchStations.at(c) = true;
	}

	bool Board::isResearchStation(City c) const
	{
		return _researchStations.at(c);
	}

	Color Board::getCityColor(City c) const
	{
		return _citiesInformation.at(c).first;
	}

	bool Board::areConnected(City firstCity, City secondCity) const
	{
		return _citiesInformation.at(firstCity).second.find(secondCity) != _citiesInformation.at(firstCity).second.end();
	}
}
