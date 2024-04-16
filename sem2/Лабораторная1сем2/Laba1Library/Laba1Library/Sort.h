#pragma once
namespace MassiveLibrary
{
	class Massive
	{
	private:
		double** m_mass;
		int m_index1;
		int* m_index2mass;
	public:
		Massive(int index1);
		~Massive();
		void Sortirovka();
		void Output();
		void New_element();
		void Association(Massive& a);
		void Search();
		void Intersection(Massive& a);
	};
}