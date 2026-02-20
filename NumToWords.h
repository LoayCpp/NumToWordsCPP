
#pragma once

#include <iostream>
#include<string>
using namespace std;
class NumToWords
{
private:
	static string DeleteZeroInTheEnd(string Word)
	{

		while (!Word.empty() && Word.back() == '0')
		{
			Word.pop_back();
		}

		return Word;
	}
	static int  ConvertingDecimal(string Number)
	{

		short pos = 0;
		pos = Number.find(".");
		string NewNumber = Number.substr(pos + 1, Number.length());
		return stoi(NewNumber);
	}

public:
	static string NumberToText(int   Number)
	{

		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
		"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
		  "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return  arr[Number] + " ";

		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return  arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return  "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return  "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return  "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return  "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}


	}
	static string NumberToText(double Number)
{
	int IntegarNumber = (int)Number;
	double Decimal = Number - IntegarNumber;

	string WordOfNumber = to_string(Decimal);
	
	if (Decimal > 0) {
	WordOfNumber = DeleteZeroInTheEnd(WordOfNumber);
		return NumberToText(IntegarNumber) +
			ColorText(" Point ") +
			NumberToText(ConvertingDecimal(WordOfNumber));
	}
	return NumberToText(IntegarNumber);
}
	enum encolor { Red = 1, Green = 2, Yellow = 3, Blue = 4, Cyan = 5, BRed = 6, BGreen = 7, BYellow = 8, BBlue = 9, BCyan = 10 };
	static string ColorText(string text, encolor color = encolor::Red) {
#define RESET       "\033[0m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define CYAN        "\033[36m"

#define BRIGHT_RED     "\033[91m"
#define BRIGHT_GREEN   "\033[92m"
#define BRIGHT_YELLOW  "\033[93m"
#define BRIGHT_BLUE    "\033[94m"
#define BRIGHT_CYAN    "\033[96m"

		switch (color)
		{
		case NumToWords::Red:
			text = RED + text + RESET;
			break;
		case NumToWords::Green:
			text = GREEN + text + RESET;
			break;
		case NumToWords::Yellow:
			text = YELLOW + text + RESET;
			break;
		case NumToWords::Blue:
			text = BLUE + text + RESET;
			break;
		case NumToWords::Cyan:
			text = CYAN + text + RESET;
			break;
		case NumToWords::BRed:
			text = BRIGHT_RED + text + RESET;
			break;
		case NumToWords::BGreen:
			text = BRIGHT_GREEN + text + RESET;
			break;
		case NumToWords::BYellow:
			text = BRIGHT_YELLOW + text + RESET;
			break;
		case NumToWords::BBlue:
			text = BRIGHT_BLUE + text + RESET;
			break;
		case NumToWords::BCyan:
			text = BRIGHT_CYAN + text + RESET;
			break;
		}


		return text;

	}
};
