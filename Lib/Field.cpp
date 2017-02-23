#include <Field.h>
#include <algorithm>

unsigned char Field::operator () ()
{
	for (unsigned short i = 1; i<lenght-1; ++i)
	{
		nextField[i] = rule.getState(currentField[i-1]+currentField[i]*2+currentField[i+1]*4);
	}
	nextField[0] = rule.getState(currentField[lenght-1]+currentField[0]*2+currentField[1]*4);
	nextField[lenght-1] = rule.getState(currentField[lenght-2]+currentField[lenght-1]*2+currentField[0]*4);
	copy(nextField.begin(), nextField.end(), currentField.begin());
	char letter = 0;
	unsigned short divider = 1<<lenght;
  for (unsigned short &i : currentField)
	{
		letter += i*divider;
		divider /= 2;
	}
	return letter;
}

Rule Field::getRule() const
{
	return rule;
}
void Field::setRule(Rule newRule)
{
	rule = newRule;
}
unsigned short Field::getLenght() const
{
	return lenght;
}