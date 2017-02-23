#ifndef CRYPTO_RULE_H
#define CRYPTO_RULE_H
class Rule
{
	private:
		int state[8];
	public:
		Rule(const unsigned short ruleNumber);
		int getState(const unsigned neighborhood) const;
};
#endif