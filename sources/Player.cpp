#include <vector>
#include "Player.hpp"

constexpr int CARDS_TO_THROW = 5;

namespace pandemic{

	Player& Player::drive(City c)
	{
		if(!_board.areConnected(_currentCity, c))
		{
			throw invalid_argument("cities are not connected\n");
		}
		
		
			_currentCity = c;
		
			return *this;
	}

	Player& Player::fly_direct(City c)
	{
		if(c == _currentCity && _cardsAtHand.find(c) != _cardsAtHand.end())
		{
			throw invalid_argument("cannot fly from city to itself\n");
		}

		if(_cardsAtHand.find(c) == _cardsAtHand.end())
		{
			throw invalid_argument("player has no such a city card at hand\n");
		}
	
			_cardsAtHand.erase(c);
			_currentCity = c;
		
		return *this;
	}

	Player& Player::fly_charter(City c)
	{
		if(c == _currentCity)
		{
			throw invalid_argument("cannot fly from city to itself\n");
		}

		if(_cardsAtHand.find(_currentCity) == _cardsAtHand.end())
		{
			throw invalid_argument("player has no such a city card at hand\n");
		}
		
			_cardsAtHand.erase(_currentCity);
			_currentCity = c;
		
		return *this;
	}

	Player& Player::fly_shuttle(City c)
	{
		if(c == _currentCity)
		{
			throw invalid_argument("cannot fly from city to itself\n");
		}

		if(_board.isResearchStation(_currentCity) && _board.isResearchStation(c))
		{
			_currentCity = c;
		}
		else
		{
			throw invalid_argument("current city or destination city has no research station");
		}
		return *this;
	}

	Player& Player::build()
	{
		if(!_board.isResearchStation(_currentCity))
		{
			if(_cardsAtHand.find(_currentCity) == _cardsAtHand.end())
			{
				throw invalid_argument("cannot build, no suitable card for current city");
			}
			
			
				_cardsAtHand.erase(_currentCity);
				_board.buildResearchStation(_currentCity);
			
		}
		return *this;
	}

	Player& Player::discover_cure(Color c)
	{
		return internalDiscover_cure(c, CARDS_TO_THROW);
	}

	Player& Player::treat(City c)
	{
		if(c != _currentCity)
		{
			throw invalid_argument("the player is not in the currnet city\n");
		}

		if(_board[_currentCity] == 0)
		{
			throw invalid_argument("city has no disease to treat");
		}
		// if found cure to the disease of this city color
		if (_board.isCureFound(_board.getCityColor(_currentCity)))
		{
			_board[_currentCity] = 0;
		}
		else
		{
			_board[_currentCity]--;
		}
		return *this;
	}

	Player& Player::take_card(City c)
	{
		_cardsAtHand.insert(c);
		return *this;
	}

	Player& Player::internalDiscover_cure(Color c, int numOfCardsToThrow)
	{
		if(!_board.isResearchStation(_currentCity))
		{
			throw invalid_argument("current city has no research station\n");
		}

		if(!_board.isCureFound(c))
		{
			std::vector<City> cardsToDrop;
			// find all cards with the specified color
			for(const auto& card : _cardsAtHand)
			{
				if(_board.getCityColor(card) == c)
				{
					cardsToDrop.push_back(card);
				}
			}
			if(cardsToDrop.size() < numOfCardsToThrow)
			{
				throw invalid_argument("not enough cards at player hand for cure\n");
			}

			auto i = 0;
			for(auto iter = cardsToDrop.begin(); i < numOfCardsToThrow ; ++iter, ++i)
			{
				_cardsAtHand.erase(*iter);
			}
			_board.cureFound(c);
		}
		return *this;
	}
}
