#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
namespace pandemic{
  class Medic: public Player{
    public:
      Medic(Board& board_,City city_):Player(board_,city_){}

	  Medic& drive(City c) override;
	  Medic& fly_direct(City c) override;
	  Medic& fly_charter(City c) override;
	  Medic& fly_shuttle(City c) override;
	  Medic& treat(City c) override;

	  string role() override {return "Medic";}

  private:
  	void healIfPossible(City c);
  };
}
