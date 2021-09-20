#include <pybind11/pybind11.h>
#include <iostream>

using namespace std;

    class Pet {
    public:
        Pet() : m_name("class 1: "), m_species("blah 1")
	{

		cout  << endl <<  "Basic constructor: "  ;
		Pet("class 2: " , "blah 2");
	}

        Pet(const std::string &name, const std::string &species) : m_name(name), m_species(species)
	{
		cout << endl <<  "Advanced constructor: "  ;
		cout << m_name << m_species ;

	} 

	~Pet()
	{
		cout << endl << "Destructor: "  << m_name << m_species   ;
	}

        std::string name() const { return m_name; }
        std::string species() const { return m_species; }
    private:
        std::string m_name;
        std::string m_species;
    };

namespace py = pybind11;

PYBIND11_MODULE(cmake_example, m) {
py::class_<Pet>(m, "Pet")
	.def(py::init<std::string, std::string>())
	.def(py::init<>())
	.def("name", &Pet::name)
	.def("species", &Pet::species);

}


