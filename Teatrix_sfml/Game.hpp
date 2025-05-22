#include <iostream>
#include <vector>

using namespace std;

class Estados
{
private:
	std::vector<unsigned char> forma;
public:
	Estados(unsigned char forma);
	vector<vector<bool>> ConsultPart(int ind);
	void RotatePart(int ind);
	void DerotatePart(int ind);
};

