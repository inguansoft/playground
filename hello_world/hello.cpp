#include <iostream>
using namespace std;

// class Animal {
//  	      int speed;
//  	      Animal Animal() {
//  	      }
//  };

struct Taxonomist
// class Taxonomist
{
private:
	int part_0;

public:
	void set_part(int value)
	{
		part_0 = value;
	}

	int give_me_my_part()
	{
		return part_0;
	}

	Taxonomist()
	{
		printf("(no argument)\n");
	}
	Taxonomist(char x)
	{
		printf("char: %c\n", x);
	}
	Taxonomist(int x)
	{
		part_0 = x;
		printf("int: %d\n", x);
	}
	Taxonomist(float x)
	{
		printf("float: %f\n", x);
	}
};

struct ClockOfTheLongNow
{
private:
	int year;

	bool check_year()
	{
		return check_year(year);
	}
	bool check_year(int this_year)
	{
		return this_year > 1000 && this_year < 4000;
	}

public:
	void add_year()
	{
		year++;
	}
	bool set_year(int new_year)
	{
		if (check_year(new_year))
		{
			year = new_year;
			return true;
		}
		return false;
	}
	int get_year()
	{
		if (!check_year())
		{
			printf("Year is invalid");
		}
		return year;
	}

	ClockOfTheLongNow(int year_in)
	{
		if (!set_year(year_in))
		{
			year = 2019;
		}
	}
};

int step_function(int x)
{
	return (x + 1) * 23;
}

void sample_function(Taxonomist *taxo_instance)
{
	printf("------- this is %d\n", taxo_instance->give_me_my_part());
}

int main()
{
	ClockOfTheLongNow venga = {1995};
	enum class Race
	{
		Dinan,
		Teklan,
		Ivyn,
		Moiran,
		Camite,
		Julian,
		Aidan
	};
	Race this_race = Race::Dinan;
	int t = 0b010101, xx{0x03f}, aaa(9), bb = {33};
	float float_variable = 1.3F;
	double d_variable = 1.3L;
	double plancks_constant = 6.62607004e-34;
	wchar_t char_wch = L'马';
	bool mybool = false;
	// wchar_t sample = U'\U0001F37A';  how to declare this kind of unicode?
	// char char_0 = "马";

	int my_array[100];
	int array[] = {1, 2, 3, 4};
	unsigned long maximum, values[] = {10, 50, 20, 40, 0};
	int value2 = step_function(010);
	int myNumbers[5] = {10, 20, 30, 40, 50};
	int getArrayLength = sizeof(myNumbers) / sizeof(int);
	char english[] = "A book holds a house of gold.";
	char sample_string[] = "sample 1"
						   " sample 2"
						   " and sample 3\n";
	char16_t chinese[] = u"\u4e66\u4e2d\u81ea\u6709\u9ec4\u91d1\u5c4b";

	union Var_dd
	{
		char string[10];
		int integer;
		double floating_point;
	};

	Var_dd v;
	Taxonomist taxo = Taxonomist(3);
	Taxonomist taxoo[] = {99,
						  2,
						  3};
	Taxonomist *tax_ptr = &taxoo[0];

	sample_function(tax_ptr);
	sample_function(taxoo); // same as previous call, lets try the ++ concept
	tax_ptr++;
	sample_function(tax_ptr);
	tax_ptr++;
	sample_function(tax_ptr);
	tax_ptr++; // can I?  Yes I can, nad it is garbage   ooopps  Never do this
	sample_function(tax_ptr);
	tax_ptr->set_part(444); // Lets set that memory that was not explicitly created
	sample_function(tax_ptr);// Yes I can   TODO: This modt be lazy instantiation or a DONT DO it thing, lets research

	int *my_ptr;
	int numero = 9;
	my_ptr = &numero;
	v.integer = 42;
	printf("Year: %d\n", venga.get_year());
	printf("The ultimate answer: %d\n", v.integer);
	printf("The value of my_ptr on %d (%p) is %p as %d.\n", numero, &numero, my_ptr, *my_ptr);
	// v.floating_point = 2.7182818284;
	v.floating_point = 0;
	printf("Euler's number e:    %f\n", v.floating_point);
	printf("A dumpster fire:     %d\n", v.integer); // Why a  union breaks

	cout << english << "\n";
	cout << chinese << "\n";
	cout << sample_string;
	cout << "length:" << getArrayLength << "\n";
	while (getArrayLength--)
	{
		cout << "array[" << getArrayLength << "]=" << myNumbers[getArrayLength] << " ";
	}

	cin >> t;
	cout << t << "\n";
	cout << (mybool ? "true" : "false") << '\n';
	cout << char_wch << " hello world " << value2 << "\n";
	printf("Windows binaries start with %c%lc.\n", char_wch, char_wch);

	for (unsigned long value : values)
	{
		if (value > maximum)
			maximum = value;
	}
	printf("--The maximum value is %lu.", maximum);

	return 0;
}
