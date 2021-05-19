#include "OperationsExpert.hpp"
namespace pandemic{
	OperationsExpert& OperationsExpert::build()
    {
	    if(!_board.isResearchStation(_currentCity))
	    {
		    _board.buildResearchStation(_currentCity);
		}
		return *this;
    }
}
