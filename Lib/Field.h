#ifndef CRYPTO_FIELD_H
#define CRYPTO_FIELD_H

#include <Rule.h>
#include <vector>

class Field
{
	private:
		Rule rule;
		unsigned short lenght;
		std::vector<unsigned short> currentField;
		std::vector<unsigned short> nextField;
	public:
		Field(unsigned char letter, Rule rule):rule(rule)
		{
			
		}
		unsigned char operator () ();
		inline Rule getRule() const;
		void setRule(Rule newRule);
		inline unsigned short getLenght() const;
};
#endif