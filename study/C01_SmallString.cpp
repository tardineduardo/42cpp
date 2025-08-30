
#include <string>

int main(void) {

	// Default constructor
	std::string imBlank;

	// Direct initialization constructor
	std::string heyMom("Where are my socks?");

	// Copy initialization - Here, the operator '=' does not mean assignment.
	// The string classes defines that '=' will actually use the constructor.
	std::string standardReply = "Beamed into deep space on wide angle dispersion?";

	//Copy constructor
	std::string useThisOneAgain(standardReply);
} 