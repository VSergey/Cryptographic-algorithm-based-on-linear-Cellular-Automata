#ifndef CRYPTO_RULE_H
#define CRYPTO_RULE_H
class Rule
{
	private:
		unsigned short state[8];
	public:
		Rule(const unsigned short ruleNumber);
		unsigned short getState(const unsigned short neighborhood) const;
};
#endif