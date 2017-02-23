#ifndef CRYPTO_FIELD_H
#define CRYPTO_FIELD_H
class Field
{
	private:
		Rule rule;
		unsigned short lenght;
		std::vector<unsigned short> currentField;
		std::vector<unsigned short> nextField;
	public:
		Field(unsigned char letter, const Rule& rule):rule(rule);
		unsigned char operator ();
		Rule getRule() const;
		void setRule(const Rule& newRule);
		unsigned short getLenght() const;
}
#endif