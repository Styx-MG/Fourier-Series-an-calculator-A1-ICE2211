#include <iostream>
#include <vector>
#include <cmath>
#include <format>
#include <cstdio>
#include <fstream>
#include <string>

//Sould have used double instead of float, for more precision, but alas


# define M_PI           3.14159265358979323846

std::vector<float> anS1{};
std::vector<float> anS2{};
std::vector<float> anS3{};
std::vector<float> anS4{};

std::vector<float> pi_anS1{};
std::vector<float> pi_anS2{};
std::vector<float> pi_anS3{};
std::vector<float> pi_anS4{};

std::vector<float> an_total{  };
std::vector<float> pi_an_total{};

float CalcCos(double theta) {

	if (std::abs(cos(theta)) < 0.00001) theta = 0 ;

	else {

		theta = cos(theta);

	}
	return theta;
}

float CalcSin(double theta) {

	if (std::abs(sin(theta)) < 0.00001) theta = 0;

	else {

		theta = sin(theta);

	}
	return theta;
}

float EvaluateAtTS1(int n, float t) {

	float r =  (2 * CalcCos(n * t)) / (pow(n, 2) * M_PI)   ;
	
	float s = CalcSin(n*t) * ( (8*n*M_PI + 2*n*t) / (pow(n,2)*M_PI ) ) ;
	
	float y =  (r + s);

	return y;
}

float EvaluateAtTS2(int n, float t) {

	float p = (-4 * CalcCos(n * t)) / (pow(n, 2) * M_PI);
	
	float q = CalcSin(n * t) * ((5 * n * M_PI - 4 * n * t) / (pow(n, 2) * M_PI));
	
	float y = p + q;

	return y;
}

float EvaluateAtTS3(int n, float t) {

	float y = (4 * CalcCos(n * t)) / (pow(n, 2) * M_PI);

	float x = CalcSin(n * t) * ((5 * n * M_PI + 4 * n * t) / (pow(n, 2) * M_PI));

	float z = x + y;

	return z;
}

float EvaluateAtTS4(int n, float t) {

	float r = (-2 * CalcCos(n * t)) / (pow(n, 2) * M_PI);

	float s = CalcSin(n * t) * ((8 * n * M_PI - 2 * n * t) / (pow(n, 2) * M_PI));

	float y = (r + s);

	return y;
}


void PrintAll(int n, float p, float q ) {

	std::cout << "a";
	std::cout << n;
	std::cout << " at -pi: ";
	std::cout << p << std::endl;

	std::cout << "a";
	std::cout << n;
	std::cout << " at -pi/2: ";
	std::cout << q << std::endl;

	std::cout << q - p << std::endl;

}

int main() {

	//std::cout << std::sin(M_PI/2);//std::sin is in radians
	
	std::cout << (EvaluateAtTS3(1, M_PI/2)- EvaluateAtTS3(1,0)) <<std::endl;

	for (int n = 1; n <= 15; n++) {

		float p = EvaluateAtTS1(n,-M_PI);
		float q = EvaluateAtTS1(n, -(M_PI / 2));
	
		anS1.push_back(q - p);
		pi_anS1.push_back((1 / M_PI) * (q - p));

		float r = EvaluateAtTS2(n, -(M_PI / 2));
		float s = EvaluateAtTS2(n, 0);

		anS2.push_back(s - r);
		pi_anS2.push_back((1 / M_PI) * (s - r));

		float t = EvaluateAtTS3(n, 0);
		float x = EvaluateAtTS3(n, M_PI/2);

		anS3.push_back(x - t);
		pi_anS3.push_back((1 / M_PI) * (x - t));

		float p2 = EvaluateAtTS4(n, M_PI / 2);
		float q2 = EvaluateAtTS4(n, M_PI );
		
		anS4.push_back(q2-p2);
		pi_anS4.push_back((1 / M_PI) * ( q2 - p2 ));

		an_total.push_back( ((2 * (q - p)) + (2 * (s - r))) );
		pi_an_total.push_back((1 / M_PI)*((2 * (q - p)) + (2 * (s - r))));
	}
	/*
	std::cout << "an = { ";
	for (double n : anS1) {
		std::cout << n << ", ";
	}
	std::cout << "}; \n";

	std::cout << "}\n";

	std::cout << "anS2 = { ";
	for (double n : anS2) {
		std::cout << n << ", ";
	}
	std::cout << "}; \n";

	std::cout << "}\n";

	std::cout << "anS3 = { ";
	for (double n : anS3) {
		std::cout << n << ", ";
	}
	std::cout << "}; \n";
	*/

	std::cout << "an_total = { ";
	for (double n : an_total) {
		std::cout << n << ", ";
	}
	std::cout << "}; \n";
	

	std::ofstream fw("C:\\Users\\micha\\Documents\\Bangor Uni modules\\ICE2211\\DumpA.txt", std::ofstream::out);

	std::ofstream fs("C:\\Users\\micha\\Documents\\Bangor Uni modules\\ICE2211\\Final_DumpA.txt", std::ofstream::out);

	if (fw.is_open())
	{
		//store array contents to text file
		for (int i = 0; i < 14; i++) {
			fw << std::format("a{} s1= {}  \t 1/pi*an{}s1 = {} a{} s1= {}  \t 1/pi*an{}s1 = {} a{} s1= {}  \t 1/pi*an{}s1 = {} a{} s1= {}  \t 1/pi*an{}s1 = {}",i ,anS1[i], i,pi_anS1[i], i, anS2[i], i, pi_anS2[i], i, anS3[i], i, pi_anS3[i], i, anS4[i], i, pi_anS4[i]) << "\n";
		}
		fw.close();
	}
	else std::cout << "Problem with opening file";

	if (fs.is_open())
	{
		//store array contents to text file
		for (int i = 0; i < 14; i++) {
			fs << std::format("a{}_total = {} \t 1/pi*an_total{}= {} ", i, an_total[i], i, pi_an_total[i]) << "\n";
		}
		fw.close();
	}
	else std::cout << "Problem with opening file";

	return 0;
}