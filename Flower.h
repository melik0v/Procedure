#pragma once


namespace Melikov 
{
	// Flower
	struct Flower 
	{
		enum Type 
		{
			HOME = 1,
			GARDEN,
			WILD,
		};
		Type _tof; // type of flower
	};

}