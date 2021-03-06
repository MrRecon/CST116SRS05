#include "stdafx.h"
#include <iostream>
#include "iomanip"

int main()
{
	const int JAN{ 1 }, FEB{ 2 }, MAR{ 3 }, APR{ 4 }, MAY{ 5 }, JUN{ 6 }, JUL{ 7 }, AUG{ 8 }, SEP{ 9 }, OCT{ 10 }, NOV{ 11 }, DEC{ 12 };
	int firstYear{}, firstMonth{}, firstDay{}, secondYear{}, secondMonth{}, secondDay{}, dayCeil{};
	char a{}, b{}, c{}, d{};
	int valid_1{}, valid_2{}, valid_3{};

	do
	{
		std::cin >> firstYear >> a >> firstMonth >> b >> firstDay >> secondYear >> c >> secondMonth >> d >> secondDay;
		std::cout << std::endl;

		if ((firstMonth >= 12) || (firstMonth <= 0) || (firstYear > 2099) || (firstYear < 1901))
		{
			valid_1 = 3;
		}

		if ((secondMonth >= 12) || (secondMonth <= 0) || (secondYear > 2099) || (secondYear < 1901))
		{
			valid_2 = 3;
		}

		if (a != '-' || b != '-' || c != '-' || d != '-')
		{
			valid_3 = 3;
		}

		switch (firstMonth)
		{
		case JAN:
		case MAR:
		case MAY:
		case JUL:
		case AUG:
		case OCT:
		case DEC:
			if (firstDay <= 0 || firstDay > 31)
			{
				valid_1 = 3;
			}
			break;
		case APR:
		case JUN:
		case SEP:
		case NOV:
			if (firstDay <= 0 || firstDay > 30)
			{
				valid_1 = 3;
			}
			break;
		case FEB:
			(firstYear % 4 == 0) ? (firstDay > 29 ? valid_1 = 3 : valid_1) : (firstDay > 28 ? valid_1 = 3 : valid_1);
			break;
		default:
			valid_1 = 3;
			valid_2 = 3;
			break;
		}

		switch (secondMonth)
		{
		case JAN:
		case MAR:
		case MAY:
		case JUL:
		case AUG:
		case OCT:
		case DEC:
			if (secondDay <= 0 || secondDay > 31)
			{
				valid_2 = 3;
			}
			break;
		case APR:
		case JUN:
		case SEP:
		case NOV:
			if (secondDay <= 0 || secondDay > 30)
			{
				valid_2 = 3;
			}
			break;
		case FEB:
			(secondYear % 4 == 0) ? (secondDay > 29 ? valid_2 = 3 : valid_2 = 2) : (secondDay > 28 ? valid_2 = 3 : valid_2 = 2);
			break;
		default:
			valid_1 = 3;
			valid_2 = 3;
			break;
		}

		if (valid_1 == 3 || valid_2 == 3 || valid_3 == 3)
		{
			return 0;
		}

	} while (valid_1 == 3 || valid_2 == 3 || valid_3 == 3);


	const int holdOneYear = firstYear, holdOneMonth = firstMonth, holdOneDay = firstDay;
	const int holdTwoYear = secondYear, holdTwoMonth = secondMonth, holdTwoDay = secondDay;


	if (firstYear > secondYear)
	{
		firstYear = holdTwoYear;
		firstMonth = holdTwoMonth;
		firstDay = holdTwoDay;
		secondYear = holdOneYear;
		secondMonth = holdOneMonth;
		secondDay = holdOneDay;
	}
	else if ((firstMonth > secondMonth) && (firstYear == secondYear))
	{
		firstMonth = holdTwoMonth;
		firstDay = holdTwoDay;
		secondMonth = holdOneMonth;
		secondDay = holdOneDay;
	}
	else if ((firstDay > secondDay) && (firstMonth == secondMonth) && (firstYear == secondYear))
	{
		firstDay = holdTwoDay;
		secondDay = holdOneDay;
	}



	while (firstYear <= secondYear)
	{
		if (firstYear == secondYear)
		{
			while (firstMonth < secondMonth)
			{
				switch (firstMonth)
				{
				case JAN:
				case MAR:
				case MAY:
				case JUL:
				case AUG:
				case OCT:
				case DEC:
				{
					dayCeil = 31;
				}
				break;
				case APR:
				case JUN:
				case SEP:
				case NOV:
				{
					dayCeil = 30;
				}
				break;
				case FEB:
				{
					firstYear % 4 == 0 ? dayCeil = 29 : dayCeil = 28;
				}
				break;
				default:
					break;
				}

				while (firstDay <= dayCeil)
				{
					std::cout << firstYear << "-" << std::setfill('0') << std::setw(2) << firstMonth << "-" << std::setw(2) << std::setfill('0') << firstDay << std::endl;
					++firstDay;
				}

				firstDay = 1;
				++firstMonth;
			}

			if (firstMonth == secondMonth)
			{
				while (firstDay < secondDay)
				{
					std::cout << firstYear << "-" << std::setw(2) << std::setfill('0') << firstMonth << "-" << std::setw(2) << std::setfill('0') << firstDay << std::endl;
					++firstDay;
				}
			}
		}
		if (firstYear < secondYear)
		{
			while (firstMonth <= 12)
			{
				switch (firstMonth)
				{
				case JAN:
				case MAR:
				case MAY:
				case JUL:
				case AUG:
				case OCT:
				case DEC:
				{
					dayCeil = 31;
				}
				break;
				case APR:
				case JUN:
				case SEP:
				case NOV:
				{
					dayCeil = 30;
				}
				break;
				case FEB:
				{
					firstYear % 4 == 0 ? dayCeil = 29 : dayCeil = 28;
				}
				break;
				default:
					break;
				}

				while (firstDay <= dayCeil)
				{
					std::cout << firstYear << "-" << std::setw(2) << std::setfill('0') << firstMonth << "-" << std::setw(2) << std::setfill('0') << firstDay << std::endl;
					++firstDay;
				}

				firstDay = 1;
				++firstMonth;
			}
		}

		firstMonth = 1;
		++firstYear;
	}


	return 0;
}