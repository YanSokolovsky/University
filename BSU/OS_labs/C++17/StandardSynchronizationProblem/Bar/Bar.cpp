#include <boost/thread.hpp>
#include <iostream>
#include <string>
#include <time.h>
#include <boost/process.hpp>
#include <fstream>
std::ofstream out("logfile.txt");
bool EmptyTable = true;
boost::mutex CheckingTable;
std::string KeepWorking;
boost::mutex chenginui;
struct UI
{
	int PaperSmoker;
	bool PaperSmoking;
	int MatchesSmoker;
	bool MatchesSmoking;
	int TobaccoSmoker;
	bool TobaccoSmoking;
} ui;
struct Table
{
	bool paper;
	bool tobacco;
	bool matches;
} table;
std::string AnimatedSigaret(int i)
{
	std::string sig = " ";
	switch (i)
	{
	case 9: sig = " ____________________\n(__(_________________@~~~"; break;  //0 
	case 8: sig = " __________________\n(__(_______________@~"; break;  //2 
	case 7: sig = " ________________\n(__(_____________@~~"; break;  //4 
	case 6: sig = " ______________\n(__(___________@~~~~"; break;  //6
	case 5: sig = " ____________\n(__(_________@~";  break; //8 
	case 4: sig = " __________\n(__(_______@~"; break;  //10 
	case 3: sig = " ________\n(__(_____@~~~";  break; //12 
	case 2: sig = " ______\n(__(___@~~~~~";  break; //14 
	case 1: sig = " ____\n(__(_@~~~"; break;  //16 
	case 0: sig = " __\n(__()";  break; //18
	}
	return sig;
}
void DrawingUI(UI ui)
{
	system("cls");
	if (ui.PaperSmoking)
	{
		std::cout << "Smoker with paper is smoking" << std::endl << AnimatedSigaret(ui.PaperSmoker % 10) << std::endl << std::endl;
	}
	else
	{
		std::cout << "Smoker with paper is`t smoking... He is waiting for ingredients..." << std::endl << std::endl << std::endl << std::endl;
	}

	if (ui.MatchesSmoking)
	{
		std::cout << "Smoker with matches is smoking" << std::endl << AnimatedSigaret(ui.MatchesSmoker % 10) << std::endl << std::endl;
	}
	else
	{
		std::cout << "Smoker with matches is`t smoking... He is waiting for ingredients..." << std::endl << std::endl << std::endl << std::endl;
	}

	if (ui.TobaccoSmoking)
	{
		std::cout << "Smoker with tobacco is smoking" << std::endl << AnimatedSigaret(ui.TobaccoSmoker % 10) << std::endl << std::endl;
	}
	else
	{
		std::cout << "Smoker with tobacco is`t smoking... He is waiting for ingredients..." << std::endl << std::endl << std::endl << std::endl;
	}
}
void diller()
{
	srand(time(NULL));
	while (true)
	{
		if (!table.matches && !table.paper && !table.tobacco)
		{
			int a = rand() % 100;
			CheckingTable.lock();
			boost::this_thread::sleep_for(boost::chrono::milliseconds(300));
			if (a > 66)
			{
				table.tobacco = false;
				table.matches = true;
				table.paper = true;
				out << "|||||||Matches and paper were putted on the table." << std::endl;
			}
			if (a <= 66 && a >= 33)
			{
				table.tobacco = true;
				table.matches = false;
				table.paper = true;
				out << "|||||||Paper and tobacco were putted on the table." << std::endl;
			}
			if (a < 33)
			{
				table.tobacco = true;
				table.matches = true;
				table.paper = false;
				out << "|||||||Tobacco and matches were putted on the table." << std::endl;
			}
			CheckingTable.unlock();
		}
	}
}
void SmokerWithPaper()
{
	while (true)
	{
		CheckingTable.lock();
		if (table.matches && table.tobacco)
		{
				int i = 9;
				ui.PaperSmoking = true;
				table.tobacco = false;
				table.matches = false;
				out << "Stuf were piked up by smoker with paper" << std::endl;
				CheckingTable.unlock();
				while (i != -1)
				{
					ui.PaperSmoker = i;
					boost::this_thread::sleep_for(boost::chrono::milliseconds(300));
					i--;
				}
				ui.PaperSmoking = false;
		}
		else
		{
			CheckingTable.unlock();
		}
	}
}
void SmokerWithTobacco()
{
	while (true)
	{
		CheckingTable.lock();
		if (table.matches && table.paper)
		{
			int i = 9;
			ui.TobaccoSmoking = true;
			table.matches = false;
			table.paper = false;
			out << "Stuf were piked up by smoker with tobacco" << std::endl;
			CheckingTable.unlock();
			while (i != -1)
			{
				ui.TobaccoSmoker = i;
				boost::this_thread::sleep_for(boost::chrono::milliseconds(300));
				i--;
			}
			ui.TobaccoSmoking = false;
		}
		else
		{
			CheckingTable.unlock();
		}
	}
}
void SmokerWithMatches()
{
	while (true)
	{
		CheckingTable.lock();
		if (table.paper && table.tobacco)
		{
			int i = 9;
			ui.MatchesSmoking = true;
			table.paper = false;
			table.tobacco = false;
			out << "Stuf were piked up by smoker with matches" << std::endl;
			CheckingTable.unlock();
			while (i != -1)
			{
				ui.MatchesSmoker = i;
				boost::this_thread::sleep_for(boost::chrono::milliseconds(300));
				i--;
			}
			ui.MatchesSmoking = false;
		}
		else
		{
			CheckingTable.unlock();
		}
	}
}
int main()
{
	ui.MatchesSmoking = false;
	ui.PaperSmoking = false;
	ui.TobaccoSmoking = false;
	table.matches = false;
	table.paper = false;
	table.tobacco = false;
	ui.MatchesSmoking = false;
	ui.TobaccoSmoking = false;
	ui.PaperSmoking = false;
	boost::thread dil(diller);
	boost::thread smok1(SmokerWithPaper);
	boost::thread smok2(SmokerWithMatches);
	boost::thread smok3(SmokerWithTobacco);
	while (true)
	{
		DrawingUI(ui);
		boost::this_thread::sleep_for(boost::chrono::milliseconds(150));
	}
	out.close();
	dil.join();
	smok1.join();
	smok2.join();
	smok3.join();
}
