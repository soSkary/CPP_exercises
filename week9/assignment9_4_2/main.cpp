#include <expected>
#include <iostream>
#include <optional>
#include <random>


//This is silly, but only for getting random numbers
static std::mt19937 mt{ std::random_device{}() };
std::uniform_int_distribution random_nr_between_1_and_10{ 1, 10 };

enum class error_type
{
    wrong_input_value,
    random_error
};

class optional_class
{
public:
    //Factory construction, instantiate and return class if input over five, else return nullopt
    static std::optional<optional_class> create(int input)
    {
        if (input > 5)
        {
            return std::optional<optional_class>{optional_class{}};
        }
        else return std::nullopt;
    }

private:
    optional_class() = default;
};

class expected_class
{
public:
    //Factory construction, instantiate and return class if input over five and random check succeeds
    //Else return error_type
    static std::expected<expected_class, error_type> create(int input)
    {
        if (input > 5)
        {
            if (random_nr_between_1_and_10(mt) > 5)
            {
                return std::expected<expected_class, error_type>{expected_class{}};
            }
            return std::unexpected{ error_type::random_error };
        }
        return std::unexpected{ error_type::wrong_input_value };
    }
private:
    expected_class() = default;
};

int main()
{
    std::cout << std::boolalpha;
    //Exercise 1
    std::cout << "Exercise 1\n\n";

    auto opt1{ optional_class::create(7) };

    auto opt2{ optional_class::create(4) };

    std::cout << "opt1 has value: " << opt1.has_value()
        << "\nopt2 has value: " << opt2.has_value() << '\n';


    //Exercise 2
    std::cout << "\nExercise 2\n\n";

    auto exp1{ expected_class::create(7) };
    auto exp2{ expected_class::create(7) };
    auto exp3{ expected_class::create(7) };
    auto exp4{ expected_class::create(7) };
    auto exp5{ expected_class::create(7) };
    auto exp6{ expected_class::create(4) };

    std::vector<std::expected<expected_class, error_type>> exp_vec{ exp1, exp2, exp3, exp4, exp5, exp6 };

    for (auto& exp : exp_vec)
    {
        static int counter{ 1 };
        //Check if exp has a value
        if (exp)
        {
            std::cout << "exp" << counter << " has value!\n";
            ++counter;
        }
        //if not, check which kind of error
        else
        {

            switch (exp.error())
            {
            case error_type::wrong_input_value:
                std::cout << "exp" << counter << " error_type::wrong_input_value\n";
                ++counter;
                break;
            case error_type::random_error:
                std::cout << "exp" << counter << " error_type::random_error\n";
                ++counter;
                break;
            }
        }
    }

    return 0;
}
