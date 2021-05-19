#include "Scientist.hpp"
namespace pandemic{

	Scientist& Scientist::discover_cure(Color c)
    {
		return dynamic_cast<Scientist&> (internalDiscover_cure(c, _n));
    }
}
