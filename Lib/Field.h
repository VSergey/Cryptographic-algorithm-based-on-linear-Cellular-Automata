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
		Field(const unsigned char letter, Rule rule):rule(rule), lenght(sizeof(unsigned char)*8)
		{
			currentField.resize(lenght);
			nextField.resize(lenght);
			unsigned short bit = 1<<lenght;
			for (unsigned short& i : currentField)
			{
				i = letter&bit;
				bit/=2;
			}
		}
		unsigned char operator () ();
		inline Rule getRule() const;
		void setRule(Rule newRule);
		inline unsigned short getLenght() const;
};
#endif