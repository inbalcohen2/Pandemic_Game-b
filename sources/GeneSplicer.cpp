#include "GeneSplicer.hpp"

constexpr int CARDS_TO_THROW = 5;

namespace pandemic
{
GeneSplicer& GeneSplicer::discover_cure(Color c)
{
	{
		if (!_board.isResearchStation(_currentCity))
		{
			throw invalid_argument("current city has no research station\n");
		}

		if (!_board.isCureFound(c))
		{
			if (_cardsAtHand.size() < CARDS_TO_THROW)
			{
				throw invalid_argument("not enough cards at player hand for cure\n");
			}

			auto i = 0;
			for (auto iter = _cardsAtHand.begin(); i < CARDS_TO_THROW; i++)
			{
				_cardsAtHand.erase(iter++);
			}
			_board.cureFound(c);
		}
		return *this;
	}
	}
}
