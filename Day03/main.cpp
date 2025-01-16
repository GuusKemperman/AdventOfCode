#include <fstream>

static int mul_all()
{
	int total{};

	std::ifstream stream{ "input.txt" };

	try
	{
		while (stream)
		{
			if (stream.get() != 'm'
				|| stream.get() != 'u'
				|| stream.get() != 'l'
				|| stream.get() != '('
				)
			{
				continue;
			}

			int num1;
			stream >> num1;

			if (stream.get() != ',')
			{
				continue;
			}

			int num2;
			stream >> num2;

			if (stream.get() != ')')
			{
				continue;
			}

			total += num1 * num2;
		}
	}
	catch (...)
	{
		
	}

	return total;
}

static int mul_all_with_do()
{
	int total{};

	std::ifstream stream{ "input.txt" };

	try
	{
		bool areMulsEnabled = true;
		while (stream)
		{
			if (stream.peek() == 'm')
			{
				if (stream.get() != 'm'
					|| stream.get() != 'u'
					|| stream.get() != 'l'
					|| stream.get() != '('
					)
				{
					continue;
				}

				int num1;
				stream >> num1;

				if (stream.get() != ',')
				{
					continue;
				}

				int num2;
				stream >> num2;

				if (stream.get() != ')')
				{
					continue;
				}

				if (areMulsEnabled)
				{
					total += num1 * num2;
				}
			}
			else if (stream.get() == 'd')
			{
				if (stream.get() != 'o')
				{
					continue;
				}

				bool isNegative{};

				if (stream.peek() == 'n')
				{
					if (stream.get() != 'n'
						|| stream.get() != '\''
						|| stream.get() != 't'
						)
					{
						continue;
					}

					isNegative = true;
				}

				if (stream.get() != '('
					|| stream.get() != ')')
				{
					continue;
				}

				areMulsEnabled = !isNegative;
			}
		}
	}
	catch (...)
	{

	}

	return total;
}

int main()
{
	return mul_all();
}