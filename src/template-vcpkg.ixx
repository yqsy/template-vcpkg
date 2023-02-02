import <iostream>;

export int add(int a, int b)
{
	return a + b;
}

export class Person
{
public:
	Person(const std::string& name, int age) : name_(name), age_(age)
	{

	}

	void print()
	{
		std::cout << "name: " << name_ << " age: " << age_;
	}

private:
	std::string name_;
	int age_;
};
