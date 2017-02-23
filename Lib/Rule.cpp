#include <Rule.h>
Rule::Rule(const unsigned short ruleNumber)
{
	for (unsigned short i = 0, unsigned short divider = 128; i<8; ++i, divider /= 2)
	{
		state[i] = ruleNumber%divider;
	}
}
unsigned short Rule::getState(const unsigned short neighborhood) const
{
	return state[neighborhood];
}