#include<iostream>
#include"entity.h"

using std::cin; using std::cout ; using std::endl;

class Int : public SpecificComponent<Int>
{
public:
	int levi, desni;
	Int()
	{
	}
};

class Renderable : public SpecificComponent<Renderable>
{
public:
	Renderable()
	{

	}
	~Renderable()
	{

	}
	std::string duzinaKurcine;
};

class Light : public SpecificComponent<Light>
{
public:
	int a, b;
	mat::vec3 kurac;
	Light()
	{

	}
	~Light()
	{

	}
};

class Float : public SpecificComponent<Float>
{
public:

};

void ispis(Light thing){
	cout << "Svetlo id: " << thing.getId() << " a: " << thing.a << " b: " << thing.b << " vektor: " << thing.kurac.x << " " << thing.kurac.y << " " << thing.kurac.z << endl;
}
void ispis(Renderable thing){
	cout << "Renderable id: " << thing.getId() << " Ime: " << thing.duzinaKurcine << endl;
}
void ispis(Int thing){
	cout << "kaoInt id: " << thing.getId() << " levi: " << thing.levi << " desni: " << thing.desni << endl;
}
int main()
{

	Entity stanic, stojko;

	Int intJedan, intDva, intTri;
	Light lightJedan, lightDva, lightTri;
	Renderable rJedan, rDva, rTri;

	intJedan.levi = 123;
	intJedan.desni = 654;
	//
	lightJedan.a = 11;
	lightJedan.b = 22;
	lightJedan.kurac = mat::vec3(3, 33, 333);
	//
	rJedan.duzinaKurcine = "retardJedan";


	intDva.levi = 999;
	intDva.desni = 888;
	//
	lightDva.a = 101;
	lightDva.b = 202;
	lightDva.kurac = mat::vec3(303, 304, 399);
	//
	rDva.duzinaKurcine = "15.5cm";

	// test - neke komponente point-uju na iste stvari
	// test - nemaju komponente istog tipa

	stanic.addComponent(&intJedan);
	stanic.addComponent(&lightJedan);
	stanic.addComponent(&rJedan);

	stojko.addComponent(&intDva);
	stojko.addComponent(&lightJedan);
	//stojko.addComponent(&rDva);


	cout << "STANIC ISPIS:\n";
	ispis(*stanic.getComponent<Int>());
	ispis(*stanic.getComponent<Light>());
	ispis(*stanic.getComponent<Renderable>());

	cout << "STOJKO ISPIS:\n";
	ispis(*stojko.getComponent<Int>());
	ispis(*stojko.getComponent<Light>());
	//ispis(*stojko.getComponent<Renderable>());

	cout << "HAOS\n";
	ispis(*stanic.getComponent<Light>());
	//ispis(*stojko.getComponent<Renderable>());
	ispis(*stanic.getComponent<Int>());
	ispis(*stojko.getComponent<Light>());

    return 0;
}