#include <iostream>
#include <stdexcept>

struct SimStr
{
public:
	
	/// @brief Display message with a TAG when passed by
	/// @param tag can be null, or a specific string
	void print(const char *tag) const
	{
		if (tag)
		{
			printf("[%s] %s", tag, buffer);
		}
		else
		{
			printf("NOTAG %s", buffer);
		}
	}

    /**
     * Constructor with size
     * @param max_size value needs to be > 0
     */
	SimStr(size_t max_size) : max_size{max_size},
							  length{}
	{
		if (max_size == 0)
		{
			throw std::runtime_error{"Max size must be at least 1."};
		}
		buffer = new char[max_size];
		buffer[0] = 0;
	}


	/**
	 * Constructor taking a deep copy
	 * @param other SimStr instance to deep copy from into the new obkect
	 */
	SimStr(const SimStr &other) : max_size{other.max_size},
								  buffer{new char[other.max_size]},
								  length{other.length}
	{
		std::strncpy(buffer, other.buffer, max_size);
	}

	/**
	 * Destructor
	 */
	~SimStr()
	{
		delete[] buffer;
	}

private:
	size_t max_size;
	char *buffer;
	size_t length;
};

int main()
{
	SimStr* simstr_instance = new SimStr(5);

	return 0;
}
