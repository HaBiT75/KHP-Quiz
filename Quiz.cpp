// Quiz program
// Written by Shadle 483

#include <iostream> // To print to screen
#include <string> // To use std::string
#include <ctime> // To use std::time
#include <cstdlib> // To use std::rand

enum QuestionTypes // Types of quizzes
{
	STATUTE,
	WEATHER,
	SIGNAL,
	TEN_CODE,
};

unsigned int RandomNumber(int min, int max) // Gets a random number for the list shuffle
{
		static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) };
		return min + static_cast<int>(((max - 1) - min + 1) * (std::rand() * fraction));
}

struct Questions // Hold the test questions
{
	std::string number;
	std::string text;
};


void ShuffleList(Questions* questions, int length) // Shuffles the list into a random order
{
	int start = 0;
	Questions temp;
	int tempN;
	for (int index{ 0 }; index <= (length - 1); ++index)
	{
		tempN = RandomNumber(start, length);
		temp = questions[index];
		questions[index] = questions[tempN];
		questions[tempN] = temp;
	}
}

void CreateList(Questions* questions, int length, std::string* text, std::string* number) // Combines the anwsers and questions into one list
{
	for (int index{ 0 }; index <= (length - 1); ++index)
	{
		questions[index].text = text[index];
		questions[index].number = number[index];
	}
}

int Quiz(Questions* questions, int length, std::string type, bool multi) // Function that holds the quiz and outputs correct answers inputted
{
	int start = 0;

	int correct{ 0 };

	int numberOfQuestions{ 4 };

	std::string temp;

	for (int index{ 0 }; index <= (length - 1); ++index)
	{
		std::cout << "What is the " << type << " for " << questions[index].text << ": ";

		if (multi);
		{
			Questions* multi = new Questions[numberOfQuestions];
			multi[0] = questions[index]
			for (int Index{ 1 }; Index <= (numberOfQuestions - 1); ++Index)
			{
				multi[Index] = questions[RandomNumber(start, length)];
			}
			ShuffleList(multi, length);
			for (int I{ 0 }; I <= (numberOfQuestions - 1); ++I)
				std::cout << multi[I] << '\n' << ;
		}

		std::cin >> temp;
		std::cout << std::endl;
		if (temp == questions[index].number)
		{
			++correct;
			std::cout << "Correct, " << questions[index].number << " is the right " << type << " for " << questions[index].text << std::endl;
			std::cout << std::endl;
			continue;
		}
		else
			std::cout << "incorrect, " << questions[index].number << " is the " << type << " for " << questions[index].text << std::endl;
		std::cout << std::endl;
	}
	return correct;
}

int main()	// Main function is the actual program

{
	std::srand(static_cast<unsigned int>(std::time(nullptr))); // Sets the seed for std::rand()

	const int FullLength{ 60 };	// Holds the length of the full statute lists

	std::string FullStatutes[FullLength] // List of Full Statutes
	{
		"improper display of license plate", "tag missing expiration month decal", "unreg veh, expired tag/no tag, incl > 2m trailer",
		"valid license required (expired)", "driving w/o license in possession (delivered)", "fail provide dmv w/ change of address within 10 days",
		"unlawful use of license (fake id)", "license suspended/cancelled/revoked", "permitting unauthorized minor to drive", "habitual violator",
		"violation of restrictions (permit, interlock, etc)",  "refuse to comply w/ lawful order of leo or fireman",
		"police veh need not display red light visible from front",
		"disobey traffic control signal (light)", "flashing traffic signal", "driving on right side of roadway required", "shall pass on the left",
		"vehicle being passed shall not speed up", "shall not pass withing 100 ft of intersection", "driving on left in no pass zone",
		"driving on laned roadway (fail to maintain)(left of center)", "follow too closely (not reasonable or prudent)",
		"driving limitations on divided highways & cont. access (u-turns, stop, park)", "pedestrian/bicyclce on interstate (misdemeanor)",
		"right of way (approaching intersection)", "fail to yield at stop or yield sign", "duty of driver upon approach of authorized emergency vehicle",
		"pedestrians under the influence of alcohol or drugs (misdemeanor)", "improper turn or approach (closest lane)", "u turns",
		"unsafe turning or stopping; fail to give proper signal", "vehicle emerging from alley, building, private road, or driveway",
		"operate vehicle in excess of maximum speed", "minimum speed (impeding flow)", "racing on highways (drag racing); misdemeanor", "reckless driving", "dui",
		"flee and elude", "riding in house trailer or mobile home", "riding on vehicle prohibited", "operate vehicle without lights when required",
		"defective head lamps (headlight out)", "defective tail lamps (taillight out) 2 required (white light to rear)", "stop lamps or turn signals",
		"high beam indicator burned out", "fail to dim headlamps (500 ft front, 300 ft rear)", "mirrors (driver side required)+ center or right",
		"windshield damaged/obstructed, defective wipers", "restrictions to tire equipment", "tint (35%), one way glass, headlamps", "headlamps", "tail lamps",
		"reflectors", "stop lamps and turn signals", "loads extending to either side (nothing to left, 6in to right)",
		"projecting loads to front and rear (4 to front, 6 to rear)", "child seat belt", "seatbelt 18+ yoa", "seatbelt 14-18 yoa",
		"fail to display/provide proof of liability insurance"
	};

	std::string FullStatuteNumbers[FullLength] // Full Statutes numbers
	{
		"08-0133", "08-0134", "08-0142", "08-0235", "08-0244", "08-0248", "08-0260", "08-0262", "08-0263", "08-0287", "08-0291", "08-1503", "08-1506", "08-1508",
		"08-1510", "08-1514", "08-1516", "08-1517", "08-1519", "08-1520", "08-1522", "08-1523", "08-1524", "08-1525", "08-1526", "08-1528", "08-1530", "08-1543",
		"08-1545", "08-1546", "08-1548", "08-1555", "08-1558", "08-1561", "08-1565", "08-1566", "08-1567", "08-1568", "08-1578", "08-1578", "08-1703", "08-1705",
		"08-1706", "08-1708", "08-1724", "08-1725", "08-1740", "08-1741", "08-1742", "08-1749", "08-1801", "08-1802", "08-1803", "08-1804", "08-1903", "08-1905",
		"08-1344", "08-2503", "08-2503", "40-3104"
	};


	const int DigiLength = 25; // Holds the length of the digiticket statutes list

	std::string DigiStatutes[DigiLength]	// List of digiticket Statutes
	{ "improper display of license plate", "unreg veh, expired tag/no tag, incl > 2m trailer", "driving w/o license in possession (delivered)",
	"fail provide dmv w/ change of address within 10 days", "refuse to comply w/ lawful order of leo or fireman", "disobey traffic control signal (light)",
	"driving on right side of roadway required", "driving on left in no pass zone", "driving on laned roadway (fail to maintain)(left of center)",
	"follow too closely (not reasonable or prudent)", "fail to yield at stop or yield sign", "improper turn or approach (closest lane)",
	"unsafe turning or stopping; fail to give proper signal", "operate vehicle in excess of maximum speed", "operate vehicle without lights when required",
	"defective head lamps (headlight out)", "defective tail lamps (taillight out) 2 required (white light to rear)", "stop lamps or turn signals",
	"mirrors (driver side required)+ center or right", "windshield damaged/obstructed, defective wipers", "tint (35%), one way glass", "child seat belt",
	"seatbelt 18+ yoa", "seatbelt 14-18 yoa", "fail to display/provide proof of liability insurance" };

	std::string DigiStatuteNumber[DigiLength] // List of digiticket Statutes numbers
	{
		"08-0133", "08-0142", "08-0244", "08-0248", "08-1503", "08-1508", "08-1514", "08-1520", "08-1522", "08-1523", "08-1528", "08-1545", "08-1548", "08-1558", "08-1703",
		"08-1705", "08-1706", "08-1708", "08-1740", "08-1741", "08-1749", "08-1344", "08-2503", "08-2503", "40-3104"
	};

	const int TenLength = 53; // Holds the length of the ten code list

	std::string TenCodes[TenLength] // List of ten code text
	{
		"Receiving poorly (move to better location)", "Receiving good", "Stand-by until no interference", "Acknowledgment", "Relay", "Busy, stand-by", "Out of service",
		"In service", "Repeat", "Out of service, subject to call", "Stay in service", "Visitors, press or officials present", "Weather and road conditions",
		"Convoy or escort", "We have prisoner in custody", "Pick up prisoner at ____, or papers at ___", "Nothing for you", "Anything for us", "Return to your station",
		"Location", "Call ___ by phone", "Disregard", "Arrived at scene", "Finished with last assignment", "Do you have contact with ____?", "Holding subject, rush reply",
		"Request drivers license information", "Request full registration information", "Check record for wanted or stolen", "Does not conform to rules and regulations",
		"Emergency basis, all troopers 10-11", "Chase, all units stand by", "Emergency traffic, station or unit", "Trouble at ___, all units respond",
		"Major crime, blockade", "No further assistance needed", "No rush", "Urgent (silent run)", "Emergency (lights & sirens)", "Fatality report",
		"Send wrecker to ___", "Officer ___ now at home", "Meet ___ at ___", "Investigate vehicle", "Investigate occupants of vehicle", "Investigate drunken driver",
		"Auto accident, property damage", "Auto accident, personal injury", "Send ambulance to ___", "Item number for assignment", "No contact at all",
		"Pick up your partner", "Investigate pedestrian or hitchhiker"
	};

	std::string TenCodeNumber[TenLength] // Ten code numbers
	{
		"10-1", "10-2", "10-3", "10-4", "10-5", "10-6", "10-7", "10-8", "10-9", "10-10", "10-11", "10-12", "10-13", "10-14", "10-15", "10-16", "10-17", "10-18",
		"10-19", "10-20", "10-21", "10-22", "10-23", "10-24", "10-25", "10-26", "10-27", "10-28", "10-29", "10-30", "10-31", "10-32", "10-33", "10-34", "10-35",
		"10-36", "10-37", "10-38", "10-39", "10-40", "10-41", "10-42", "10-43", "10-44", "10-45", "10-46", "10-47", "10-48", "10-49", "10-52", "10-77", "10-80",
		"11-44"
	};

	const int WeatherLength = 25; // Holds the length of the Weather code list

	std::string WeatherCodes[WeatherLength] // List of weather codes
	{
		"Weather Clear", "Overcast", "Roads Dry", "Roads Wet", "Raining", "Mist", "Light Snow", "Heavy Snow", "Heavy Snow with Drifting", "Fog", "Windy (over 20 mph)",
		"Blowing Dust", "Roads Snow Packed", "Roads Snow Packed in Spots", "Roads Icy", "Roads Icy in Spots", "Roads Slushy", "Treated and Sanded",
		"Blizzard Conditions Existing", "Roads Closed", "One Lane Traffic", "Hail", "Sleet", "Rain Mixed with Snow", "Flooding"
	};

	std::string WeatherCodeNumbers[WeatherLength] // Weather code numbers
	{
		"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25"
	};

	const int SignalLength = 36; // Holds the length of the Signal codes

	std::string SignalCodes[SignalLength] // List of signal codes
	{
		"Armed-dangerous", "Resists arrest", "Mental", "Suicidal", "Known offender felony", "Known offender misdemeanor", "Known offender traffic",
		"Drugs, narcotics, drug equipment, drug paraphernalia", "Drugs - Intent", "Drugs - Possession", "Explosives-Bombs (or making of)", "Fraud",
		"Gang activity/affiliation", "HIV, AIDS, Hepatitis B", "Illegal alien", "Juvenile runaway", "Kidnapping suspect/subject", "Larceny", "Murder/homicide",
		"Other-call dispatch", "Parole, probation, papis", "Robbery/burglary",
		"Sex offender (rape incest, sodomy, indecent exposure/exhibitionist, pedophile, prostitution, etc.)", "Terrorist activity/affiliation",
		"Identity Theft Victim or Suspect", "Intelligence subject", "Snipers in area", "Arsonist in area", "Wanted-felony", "Wanted-misdemeanor",
		"Property or vehicle reported stolen", "Bomb explosion at ___", "Officer needs assistance ___", "Valid concealed carry permit.",
		"Suspended concealed carry permit", "Revoked concealed carry permit"
	};

	std::string SignalCodeNumber[SignalLength] // signal code numbers
	{
		"1", "2", "3", "4", "5a", "5b", "5c", "5d", "5d-i", "5d-p", "5e", "5f", "5g", "5h", "5i", "5j", "5k", "5l", "5m", "5o", "5p", "5r", "5s", "5t", "5v",
		"6", "7", "8", "9", "10", "11", "12", "13", "45", "45-s", "45-r"
	};

	const int NumberofTypes{ 4 };  // Holds the length for the different types of test

	std::string TestTypes[NumberofTypes] // Test type list
	{
		"statute number", "weather code", "singal code", "ten code"
	};

	int Correct{ 0 }; // Holds the number of correct inputs

	int TestLength; // Holds how many questions are in the quiz

	int input; // holds the input that chooses the test

	bool Checkinput(true); // Sets the while loop to infinite until a correct selection is made

	while (Checkinput) // Loop that checks user input
	{
		std::cout << "Which quiz do you want to start on? \n 1. Full statute list \n 2. Digiticket statute list \n 3. Ten codes \n 4. Signal codes \n 5. Weather Codes" << "\n" << 
		"Enter a number 1 - 5 to choose your quiz: ";
		
		std::cin >> input;

		if (std::cin.fail()) // error check to see if an invalid input was entered 
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}

		std::cout << '\n';
		
		std::string multiChoicetemp;
		bool multichoice{ false;
		std::cout << "Enter 1 for multiple choice or 2 for fill in the blank : ";
		std::cin >> multiChoicetemp;
		if {multiChoice == 1}
		{
			multichoice = true;
		}

		switch (input) // Selects which test the user takes
		{
			case 1:
			{
				Questions *FullTest = new Questions[FullLength];
				CreateList(FullTest, FullLength, FullStatutes, FullStatuteNumbers);
				ShuffleList(FullTest, FullLength);
				Correct = Quiz(FullTest, FullLength, TestTypes[STATUTE], multichoice);
				TestLength = FullLength;
				Checkinput = false;
				delete[] FullTest;
				break;
			}
			
			case 2:
			{
				Questions *DigiTest = new Questions[DigiLength];
				CreateList(DigiTest, DigiLength, DigiStatutes, DigiStatuteNumber);
				ShuffleList(DigiTest, DigiLength);
				Correct = Quiz(DigiTest, DigiLength, TestTypes[STATUTE], multichoice);
				TestLength = DigiLength;
				Checkinput = false;
				delete[] DigiTest;
				break;
			}
			
			case 3:
			{
				Questions *TenTest = new Questions[TenLength];
				CreateList(TenTest, TenLength, TenCodes, TenCodeNumber);
				ShuffleList(TenTest, TenLength, TenCodes, TenCodeNumber);
				Correct = Quiz(TenTest, TenLength, TestTypes[TEN_CODE], multichoice);
				TestLength = TenLength;
				Checkinput = false;
				delete[] TenTest;
				break;
			}
			
			case 4:
			{
				Questions *SignalTest = new Questions[SignalLength];
				CreateList(SignalTest, SignalLength, SignalCodes, SignalCodeNumber);
				ShuffleList(SignalTest, SignalLength, SignalCodes, SignalCodeNumber);
				Correct = Quiz(SignalTest, SignalLength, TestTypes[SIGNAL], multichoice);
				TestLength = SignalLength;
				Checkinput = false;
				delete[] SignalTest;
				break;
			}
			
			case 5:
			{
				Questions *WeatherTest = new Questions[WeatherLength];
				CreateList(WeatherTest, WeatherLength, WeatherCodes, WeatherCodeNumbers);
				ShuffleList(WeatherTest, WeatherLength, WeatherCodes, WeatherCodeNumbers);
				Correct = Quiz(WeatherTest, WeatherLength, TestTypes[WEATHER], multichoice);
				TestLength = WeatherLength;
				Checkinput = false;
				delete[] WeatherTest;
				break;
			}
			
			default:
				std::cout << "Please enter a number 1-5" << std::endl;
			
		}
		
	}
	
	
	std::cout << "You got " << Correct << " questions right out of " << TestLength << "." << "\n" << "\n"; // Prints the correct answer 

	std::cout << "Made by Shadle - 483," << "\n" << "Enter any key to exit the window...";
	int exit;
	std::cin >> exit;
	return 0;

};