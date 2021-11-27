#include <iostream>
#include <fstream>
#include <string>

std::string file_in_path;
std::string file_out_path;
std::string output;
std::string name;
std::string buff_pin;
std::string buff_x;
std::string buff_y;
std::string size;								// in mm - pin diameter
std::string drill;								// in mm
std::string sheel_diameter;						// in mm

std::fstream file_in;
std::fstream file_out;

int main()
{
	std::getline(std::cin, file_in_path);		// CSV FORMAT!!!!!!
	std::getline(std::cin, file_out_path);		// Will output *.kicad_mod

	file_in.open(file_in_path.c_str(), std::ios_base::in);
	file_out.open(file_out_path.c_str(), std::ios_base::out);

	//get some params:
	std::cin >> sheel_diameter;
	std::cin >> name;
	std::cin >> drill;
	std::cin >> size;

	output = "(module " + name + " (layer F.Cu) (tedit 61A2704C)\n  (fp_text reference REF** (at -24.71166 -17.9578) (layer F.SilkS)\n    (effects(font(size 1 1) (thickness 0.15)))\n  )\n  (fp_text value " + name + " (at -26.88844 -12.10056) (layer F.Fab)\n    (effects(font(size 1 1) (thickness 0.15)))\n  )\n";

	output += "  (fp_circle (center 0 0) (end " + sheel_diameter + " 0) (layer F.SilkS) (width 0.12))\n";

	while (!file_in.eof())
	{
		std::getline(file_in, buff_pin, ';');
		std::getline(file_in, buff_x, ';');
		std::getline(file_in, buff_y);

		output += "  (pad " + buff_pin + " thru_hole circle (at " + std::to_string(std::stod(buff_x) * 25.4) + " " + std::to_string(std::stod(buff_y) * -025.4) + ") (size " + size + " " + size + ") (drill " + drill + ") (layers *.Cu *.Mask))\n";
	}

	output += ")\n";

	file_out << output;

	file_in.close();
	file_out.close();

	return 0;
}
