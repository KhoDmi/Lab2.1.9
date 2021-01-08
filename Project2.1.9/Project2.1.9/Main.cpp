#include<stdlib.h>;     
#include<iostream>;
#include <fstream>;
#include <limits>;
#include"cmath";
#include <cassert>;
#include <typeinfo>;
#include"forward_list"

using namespace std;


int intInpCheck()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string num;
	cin >> num;
	int i = 0, finalnum = 0, negativCheck = 0, doubleCheck = 0, point = 0;
	double finalnumd = 0.0;
	if (num[0] == '-')
	{
		negativCheck = 1;
		i++;
	}
	while (num[i])
	{
		if (int(num[i]) >= 48 && int(num[i]) <= 57)
			finalnum = finalnum * 10 + int(num[i] - 48);
		if ((num[i] == '.') && (doubleCheck == 0) && (i > 0))
		{
			finalnumd = finalnum;
			point = i;
			doubleCheck = 1;
		}
		if (!(int(num[i]) >= 48 && int(num[i]) <= 57) && !((num[i] == '.') && ((doubleCheck == 0) || (doubleCheck == 1)) && (i > 0)))
		{
			cout << "Wrong input, try again\n";
			return intInpCheck();
		}
		i++;
	}
	if (doubleCheck == 1)
	{
		cout << "Wrong input, try again\n";
		return intInpCheck();
	}
	if (doubleCheck == 0)
	{
		if (negativCheck == 1)
			return -finalnum;
		return finalnum;
	}
}
double doubleInpCheck()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string num;
	cin >> num;
	int i = 0, finalnum = 0, negativCheck = 0, doubleCheck = 0, point = 0;
	double finalnumd = 0.0;
	if (num[0] == '-')
	{
		negativCheck = 1;
		i++;
	}
	while (num[i])
	{
		if (int(num[i]) >= 48 && int(num[i]) <= 57)
			finalnum = finalnum * 10 + int(num[i] - 48);
		if ((num[i] == '.') && (doubleCheck == 0) && (i > 0))
		{
			point = i;
			doubleCheck = 1;
		}
		if (!(int(num[i]) >= 48 && int(num[i]) <= 57) && !((num[i] == '.') && ((doubleCheck == 0) || (doubleCheck == 1)) && (i > 0)))
		{
			cout << "Wrong input, try again\n";
			return doubleInpCheck();
		}
		i++;
	}
	if (doubleCheck == 1)
	{
		finalnumd = finalnum / pow(10, (i - point - 1));
		if (negativCheck == 1)
			return -finalnumd;
		return finalnumd;
	}
	if (doubleCheck == 0)
	{
		finalnumd = finalnum;
		if (negativCheck == 1)
			return -finalnumd;
		return finalnumd;
	}
}
int answerCheck()
{
	int check = -1;
	do
	{
		cout << "Input your answer (y or n)" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		char answer = cin.get();
		if (answer == 'y') check = 1;
		if (answer == 'n') check = 0;
	} while (check == -1);
	return check;
}




namespace stuff
{
	class MyException
	{

	public:

		MyException(string err)
		{
			ex_mes = err;
		}

		const char* getErr()
		{

			return ex_mes.c_str();
		}

	private:
		string ex_mes;
	};

	template <typename T>
	class Exam
	{
	public:
		class MyException
		{

		public:

			MyException(string err)
			{
				ex_mes = err;
			}

			const char* getErr()
			{

				return ex_mes.c_str();
			}

		private:
			string ex_mes;
		};


	public:
		Exam()
		{
			setMark();
			setId();
			setName();
		}

		Exam(T a) :val(a)
		{
			setId();
			setName();
		}

		Exam(T a, string c, int b) :val(a), id(b), name(c)
		{
		}


		void setName()
		{
			cout << "Input name" << endl;
			cin >> name;
		}

		void setId()
		{

			do
			{
				cout << "Input id" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> id;
			} while (cin.fail());
		}

		void setMark()
		{

			do
			{
				do
				{
					cout << "Input mark" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cin >> val;
				} while (cin.fail());
			} while (val < 0);

		}

		void getMark()
		{
			cout << "Mark is:" << val << endl;
		}

		void get()
		{
			cout << "Mark is:" << val << endl;
			cout << "Id is:" << id << endl;
			cout << "Name is:" << name << endl;
		}

		~Exam()
		{

		}

		int id;
		string name;
		T val;
	};

	template <typename T>
	void Shell	(forward_list<Exam<int>>::iterator list, int size)
	{
		try
		{
			T count = 0;
			string counts;
			int countd;
			int i = 0;
			int d = size;
			int n = d;
			d = d / 2;
			while (d > 0)
			{
				auto cur = list;
				auto last = list;
				for (i = 0; i < d; i++)
				{
					last++;
				}
				for (i = 0; i < n - d; i++)
				{
					int j = i;
					while (j >= 0 && cur->val > last->val)
					{
						count = cur->val;
						cur->val = last->val;
						last->val = count;

						countd = cur->id;
						cur->id = last->id;
						last->id = countd;

						counts = cur->name;
						cur->name = last->name;
						last->name = counts;

						j--;
					}
					cur++;
					last++;
				}
				d = d / 2;

				if (d == 0)
				{
					d = 1;
					auto cur = list;
					auto last = list;
					for (i = 0; i < d; i++)
					{
						last++;
					}
					for (i = 0; i < n - d; i++)
					{
						int j = i;
						while (j >= 0 && cur->val > last->val)
						{
							count = cur->val;
							cur->val = last->val;
							last->val = count;

							countd = cur->id;
							cur->id = last->id;
							last->id = countd;

							counts = cur->name;
							cur->name = last->name;
							last->name = counts;

							j--;
						}
						cur++;
						last++;
					}
					d = d / 2;
				}
			}
		}
		catch (MyException exception)
		{
			cerr << exception.getErr();
		}

	}

		template <typename T>
		class Add
		{
		public:
			forward_list<Exam<int>>::iterator list;
			int* i;


			Add(forward_list<Exam<int>>::iterator list, int *i): list(list), i(i) {}

			void add(forward_list<Exam<T>>* list, int* i)
			{
				Exam<T> add;
				list->push_front(add);
			}

		};

	

}

using  stuff::Exam;
using  stuff::Add;
using  stuff::MyException;


int main()
{

	cin.clear();
	cout << "Input anything to start" << endl;
	cin.get();
	system("cls");

	cout << "input first element of int list" << endl;
	forward_list<Exam<int>> listi(1);
	int i = 0;

	//cout << "input first element of double list" << endl;
	//forward_list<Exam<double>> listd(1);
	//int d = 0;

	//cout << "input first element of char list" << endl;
	//forward_list<Exam<char>> listc(1);
	//int c = 0;

	Add<int> lint(listi.begin(), &i);

	cout << "do you want to add any elements to int list?" << endl;
	while (answerCheck())
	{
		listi.resize(++i);
		lint.add(&listi, &i);
		cout << "do you want to add any more elements to this list?" << endl;
	}

	//cout << "do you want to add any elements to double list?" << endl;
	//while (answerCheck())
	//{
	//	listi.resize(++i);
	//	add<double>(&listd, &d);
	//	cout << "do you want to add any more elements to this list?" << endl;
	//}

	//
	//cout << "do you want to add any elements to char list?" << endl;
	//while (answerCheck())
	//{
	//	listi.resize(++i);
	//	add<char>(&listc, &c);
	//	cout << "do you want to add any more elements to this list?" << endl;
	//}


	stuff::Shell<int>(listi.begin(), i+1);

	auto out= listi.begin();
	for (int k = 0; k < i+1; k++)
	{
		out->get();
		cout << endl;
		out++;
	}

	return 0;
}