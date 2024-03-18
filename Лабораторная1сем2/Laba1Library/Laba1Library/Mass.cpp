#include "Sort.h"
#include <iostream>
using namespace std;
namespace MassiveLibrary
{
	Massive::Massive(int index1) : m_index1(index1)
	{
		if (m_index1 < 0)
		{
			cout << "Incorrect data type";
			exit(0);
		}
		m_mass = new double* [m_index1];
		m_index2mass = new int[m_index1];
		for (int i = 0; i < m_index1; ++i)
		{
			std::cout << "Enter the number of elements in the " << i + 1 << "- th line\n";
			while (!(std::cin >> m_index2mass[i]) || (std::cin.peek() != '\n')||(m_index2mass[i]<0))
			{
				std::cin.clear();
				std::cin.ignore(99999, '\n');
				std::cout << "Incorrect data type" << std::endl;
			}
			m_mass[i] = new double[m_index2mass[i]];
			for (int j = 0; j < m_index2mass[i]; ++j)
			{
				std::cout << "Enter the " << j + 1 << "- th element in the " << i + 1 << "- th line\n";
				while (!(std::cin >> m_mass[i][j]) || (std::cin.peek() != '\n'))
				{
					std::cin.clear();
					std::cin.ignore(99999, '\n');
					std::cout << "Incorrect data type" << std::endl;
				}
			}
		}
		Sortirovka();
	}
	Massive::~Massive()
	{
		for (int count = 0; count < m_index1; ++count)
			delete[] m_mass[count];
		delete[] m_mass;
	}
	void Massive::Sortirovka()
	{
		for (int i = 0; i < m_index1; ++i)
			for (int j = 0; j < m_index2mass[i]; ++j)
			{
				int kod = 0;
				for (int a = i; a < m_index1; ++a)
				{
					int b;
					if (kod == 0) b = j;
					else b = 0;
					for (; b < m_index2mass[a]; ++b)
						if (m_mass[i][j] > m_mass[a][b]) std::swap(m_mass[i][j], m_mass[a][b]);
					++kod;
				}
			}
	}
	void Massive::Output()
	{
		for (int i = 0; i < m_index1; ++i)
		{
			std::cout << "{";
			for (int j = 0; j < m_index2mass[i]; ++j)
				std::cout << m_mass[i][j] << " ";
			std::cout << "}\n";
		}
	}
	void Massive::New_element()
	{
		int press_key;
		std::cout << "If you want to add a new element to the last existing row press 1" << std::endl << "If you want to add a new element to a new row press 2\n";
		while (!(std::cin >> press_key) || (std::cin.peek() != '\n') || (press_key != 1 && press_key != 2))
		{
			std::cin.clear();
			std::cin.ignore(99999, '\n');
			std::cout << "Incorrect data type" << std::endl;
		}
		if (press_key == 1)
		{
			if (m_index1 == 0)
			{
				cout << "There are no rows in the array\n";
				return;
			}
			double* aux_mass = new double[++m_index2mass[m_index1 - 1]];
			for (int j = 0; j < m_index2mass[m_index1 - 1] - 1; ++j)
				aux_mass[j] = m_mass[m_index1 - 1][j];
			delete[] m_mass[m_index1 - 1];
			m_mass[m_index1 - 1] = aux_mass;
			std::cout << "Enter a new element\n";
			while (!(std::cin >> m_mass[m_index1 - 1][m_index2mass[m_index1 - 1] - 1]) || (std::cin.peek() != '\n'))
			{
				std::cin.clear();
				std::cin.ignore(99999, '\n');
				std::cout << "Incorrect data type" << std::endl;
			}
			cout << "Do you want to sort:" << endl << "y=yes\n" << "n=no\n";
			char sorttype;
			while (!(std::cin >> sorttype) || (std::cin.peek() != '\n') || (sorttype != 'y' && sorttype != 'n'))
			{
				std::cin.clear();
				std::cin.ignore(99999, '\n');
				std::cout << "Incorrect data type" << std::endl;
			}
			if (sorttype == 'y')
				Sortirovka();
		}
		else
		{
			double** aux_mass = new double* [++m_index1];
			for (int i = 0; i < m_index1 - 1; ++i)
			{
				aux_mass[i] = new double[m_index2mass[i]];
				for (int j = 0; j < m_index2mass[i]; ++j)
					aux_mass[i][j] = m_mass[i][j];
			}
			for (int i = 0; i < m_index1 - 1; ++i)
				delete[] m_mass[i];
			delete[] m_mass;
			m_mass = aux_mass;
			int* aux_massindex = new int[m_index1];
			for (int i = 0; i < m_index1 - 1; ++i)
				aux_massindex[i] = m_index2mass[i];
			delete[] m_index2mass;
			m_index2mass = aux_massindex;
			m_index2mass[m_index1 - 1] = 1;
			aux_mass[m_index1 - 1] = new double[m_index2mass[m_index1 - 1]];
			std::cout << "Enter a new element\n";
			while (!(std::cin >> m_mass[m_index1 - 1][m_index2mass[m_index1 - 1] - 1]) || (std::cin.peek() != '\n'))
			{
				std::cin.clear();
				std::cin.ignore(99999, '\n');
				std::cout << "Incorrect data type" << std::endl;
			}
			cout << "Do you want to sort:" << endl << "y=yes\n" << "n=no\n";
			char sorttype;
			while (!(std::cin >> sorttype) || (std::cin.peek() != '\n') || (sorttype != 'y' && sorttype != 'n'))
			{
				std::cin.clear();
				std::cin.ignore(99999, '\n');
				std::cout << "Incorrect data type" << std::endl;
			}
			if (sorttype == 'y')
				Sortirovka();
		}
	}
	void Massive::Association(Massive& a)
	{
		double** aux_mass = new double* [m_index1 + a.m_index1];
		for (int i = 0; i < m_index1; ++i)
		{
			aux_mass[i] = new double[m_index2mass[i]];
			for (int j = 0; j < m_index2mass[i]; ++j)
				aux_mass[i][j] = m_mass[i][j];
		}
		for (int i = m_index1; i < (a.m_index1 + m_index1); ++i)
		{
			aux_mass[i] = new double[a.m_index2mass[i - m_index1]];
			for (int j = 0; j < a.m_index2mass[i - m_index1]; ++j)
				aux_mass[i][j] = a.m_mass[i - m_index1][j];
		}
		for (int i = 0; i < m_index1; ++i)
			delete[] m_mass[i];
		delete[] m_mass;
		m_mass = aux_mass;
		int* aux_index2 = new int[m_index1 + a.m_index1];
		for (int i = 0; i < m_index1; ++i)
		{
			aux_index2[i] = m_index2mass[i];
		}
		for (int i = m_index1; i < m_index1 + a.m_index1; ++i)
		{
			aux_index2[i] = a.m_index2mass[i - m_index1];
		}
		delete[] m_index2mass;
		m_index2mass = aux_index2;
		m_index1 = m_index1 + a.m_index1;
		cout << "Do you want to sort:" << endl << "y=yes\n" << "n=no\n";
		char sorttype;
		while (!(std::cin >> sorttype) || (std::cin.peek() != '\n') || (sorttype != 'y' && sorttype != 'n'))
		{
			std::cin.clear();
			std::cin.ignore(99999, '\n');
			std::cout << "Incorrect data type" << std::endl;
		}
		if (sorttype == 'y')
			Sortirovka();
	}
	void Massive::Search()
	{
		cout << "Enter the item you are looking for\n";
		int ser_el, kod = 0;
		while (!(std::cin >> ser_el) || (std::cin.peek() != '\n'))
		{
			std::cin.clear();
			std::cin.ignore(99999, '\n');
			std::cout << "Incorrect data type" << std::endl;
		}
		int** aux = new int* [m_index1];
		for (int i = 0; i < m_index1; ++i)
		{
			aux[i] = new int[m_index2mass[i]];
			for (int j = 0; j < m_index2mass[i]; ++j)
				aux[i][j] = -1;
		}
		for (int i = 0; i < m_index1; ++i)
			for (int j = 0; j < m_index2mass[i]; ++j)
				if (m_mass[i][j] == ser_el)
					aux[i][j] = 1;
		for (int i = 0; i < m_index1; ++i)
			for (int j = 0; j < m_index2mass[i]; ++j)
				if (aux[i][j] == 1)
				{
					++kod;
					cout << "The element you are looking for is in the " << i + 1 << "-th row," << j + 1 << "-th column\n";
				}
		if (kod == 0)
			cout << "The element you are looking for is not in the array\n";
		for (int i = 0; i < m_index1; ++i)
			delete[] aux[i];
		delete aux;
	}
	void Massive::Intersection(Massive& a)
	{
		int min_ind1;
		double** aux_intersec;
		if (m_index1 < a.m_index1)
		{
			aux_intersec = new double* [m_index1];
			min_ind1 = m_index1;
		}
		else
		{
			aux_intersec = new double* [a.m_index1];
			min_ind1 = a.m_index1;
		}
		int* min_ind2 = new int[min_ind1];
		for (int i = 0; i < min_ind1; ++i)
		{
			if (m_index2mass[i] < a.m_index2mass[i])
			{
				min_ind2[i] = m_index2mass[i];
				aux_intersec[i] = new double[min_ind2[i]];
			}
			else
			{
				min_ind2[i] = a.m_index2mass[i];
				aux_intersec[i] = new double[min_ind2[i]];
			}
		}
		for (int i = 0; i < min_ind1; ++i)
		{
			for (int j = 0; j < min_ind2[i]; ++j)
			{
				if (m_mass[i][j] < a.m_mass[i][j])
					aux_intersec[i][j] = m_mass[i][j];
				else aux_intersec[i][j] = a.m_mass[i][j];
			}
			delete[] m_mass[i];
		}
		delete[] m_mass;
		delete[] m_index2mass;
		m_mass = aux_intersec;
		m_index1 = min_ind1;
		m_index2mass = min_ind2;
	}
}