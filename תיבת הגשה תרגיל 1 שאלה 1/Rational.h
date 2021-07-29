
class Rational
{
public:
	int numerator;
	int	denominator;
	void setNumerator(int x);
	void setDenominator(int y);
	int getNumerator();
	int getDenominator();
	void print();
	bool equal(Rational a);
	Rational add(Rational a);
private:
	void RationalReduction();
};