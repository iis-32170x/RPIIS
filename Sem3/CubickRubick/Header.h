/// @file
/// @brief ����������� ������� Face � Cube ��� ������ � �������.

#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <map>
#include <ctime>
#include <sstream>
#include <fstream>

using namespace std;

/**
    \brief ������ Face ������������ ���� ������� ������.

    *����� �������� � ���� ������� ����� ������, ������� ��� ����������� ������ ����� � �������� ��� ������ � �������.
*/
class Face
{
public:
    /// @brief �������, �������������� ������� ������.
    vector<vector<char>> Matrix;
    /**
    \brief ����� ��� ������� ������������ ������.

    *����� ������ � ���� ��� ��������� �������� ��������� ������ ��� �������������� �������� �� ������ ���.
*/
    map<vector<int>,bool> RandomCounter;
    /// @brief ����������� � ����������.
    /// @param Color ���� �����
    Face(char);
    /// @brief ����� ���������.
    /// @param DisplayedFaces ������ ������ ������.
    void OutPutHeader(vector<Face>);
    /// @brief ����� ���������.
    /// @param DisplayedFaces ������ ������ ������.
    void OutPutBody(vector<Face>);
    /// @brief ����� ���������.
    /// @param DisplayedFaces ������ ������ ������.
    void OutPutFooter(vector<Face>);
    /**
    \brief ��������������� ����� ������ �����.

    *������� ����������� ��������� �������� ����� ����� � �������� ��� ������������ ������� ������.
*/
    /// @param MatrixMember ������ �����.
    /// @return ������ �������� ��������.
    string SquareOutPut(char);

    /// @brief �������� ������������.
    /// @param other ������ ������� ������.
    /// @return ������� �������.
    Face& operator=(const Face& other);
    /// @brief �������� �����������.
    /// @param other ������ ������� ������.
    /// @return true, ���� ������� �� �����.
    bool operator!=(const Face& other) const;
    /// @brief �������� ���������.
    /// @param other ������ ������� ������.
    /// @return true, ���� ������� �����.
    bool operator==(const Face& other) const;

private:
    /// @brief ������� ������� ��� ������������.
    const string RedSquare = "\033[31m#\033[0m";
    /// @brief ����� ������� ��� ������������.
    const string BlueSquare = "\033[34m#\033[0m";
    /// @brief ��������� ������� ��� ������������.
    const string OrangeSquare = "\033[38;5;208m#\033[0m";
    /// @brief Ƹ���� ������� ��� ������������.
    const string YellowSquare = "\033[33m#\033[0m";
    /// @brief ������ ������� ��� ������������.
    const string GreenSquare = "\033[32m#\033[0m";
    /// @brief ����� ������� ��� ������������.
    const string WhiteSquare = "\033[37m#\033[0m";
};

/**
    \brief  ����� Cube ������������ ���� �����.

    *����� �������� ������ ��� ���������� � ����������� ������� ������.
*/
class Cube
{
public:
    Face Front /** @brief �������� ����� ������. */, Top /** @brief ������� ����� ������. */, Back/** @brief ������ ����� ������. */, 
        Bottom /** @brief ������ ����� ������. */, Left /**  @brief����� ����� ������. */, Right /**  @brief ������ ����� ������. */, 
        BufferFace /** @brief �������� ����� ������.
                   
                   ����� ��� ������ ������� �������� ������ ������
                   */;
    /**
    \brief ����������� ������.

    *��� �������� ������� ������� ������ �������� ������, �������� ����� � ���������� �������, ���������� ��� ���������� �������� � ������ ������ ������.
*/
    Cube();
    /// @brief ������ ��� �������� ������ ������.
    vector<char> ColorsList;
    /**
    \brief ����� ��� ������� ������������ ������.

    *����� ������ � ���� ���������� � ���, ������� ��� ������������� ����������� ���� ��� ������� ������������ ������.
*/
    map<char, int> ColorsCounter;
    /// @brief ����������, �������� ���������� ��� ��������������� ��������� ����� ������.
    int FullRandomCounter;
    /// @brief ������� �������� ������� ������ ��� ������������ ��������.
    vector<Face> GetDisplayedFace() const;
    /// @brief ������ ��� ������ ������ �� �����.
    void FaceOutPut(Face, vector<Face>);
    /// @brief ������� �������� ����� ����� �� 90 ��������.
    /// @param SelectionFace ������� ��� ��������.
    /// @param clockwise ����������� ��������.
    Face FaceCoup(Face, bool);
    /// @brief ������� ��������� ��������� ������ � �������.
    /// @param PrintedFace ������ ��������� ������.
    void FaceSynchron(vector<Face>);
    /// @brief ������������ ������.
    /// @param DisplayedFaces ������ ������ ������.
    void Randomize(vector<Face>);
    /// @brief ������� ������ ������ ������ �� �����.
    /// @param PrintedFace ������ ������.
    void CubeReading(vector<Face>);
    /**
    \brief ������ ������������� �������� ������� �����.

    *������� ������� ������� ����� ����� ������ � �����������, 
    ��������� �������������, ������ � �������� �� 90 �������� ������� �����, ��������� �� �������� �����.
*/
    /// @param DisplayedFaces ������ ������.
    /// @param SeriesNumber ����� ������� ��� ��������.
    /// @param Up ����������� ��������.
    void VerticalFaceTurn(vector<Face>, int, bool);
    /**
   \brief ������ ��������������� �������� ������� �����.

   *������� ������� ������ ����� ����� ������ � �����������,
   ��������� �������������, ������ � �������� �� 90 �������� ������� ��� ������ �����, ��������� �� �������� �����.
*/
/// @param DisplayedFaces ������ ������.
/// @param SeriesNumber ����� ������ ��� ��������.
/// @param LeftRotatin ����������� ��������.
    void HorisontalFaceTurn(vector<Face>, int, bool);
    /**
   \brief ������ ������� �������� ����� �� 90 ��������.

   *������� ������� �������� ����� �� 90 �������� ������ � ��������� ����������� ����� ������ ������.
*/
/// @param DisplayedFaces ������ ������.
/// @param clockwise ����������� ��������.
    void FaceTurn(vector <Face>, bool);
    /**
   \brief ������ ������ � �������� �����.

   *������� ��������� ������� ������� � ������� ��������� � ���� �������� �����/�������/������.
*/
/// @param ch ������� ������.
    void FaceTorsion(char);
    /**
   \brief ������� �������� ������ � ������������.

   *������� ��������� ������� ������� � ������� ����� � ������������ ��� ��� ������� �� ������������, ������
   �� ����� � �������� �����������. ����� ������� ������� ������� � ������� �������� ������.
*/
/// @param ch ������� ������.
    void FaceChoosing(char);
    /// @brief �������� ����������� ������.
    /// @param DisplayedFaces ������ ������ ������.
    int Examination(vector<Face>);
    /// @brief ������� ������ ����������� � �������� �������� ������������.
    void Game();

private:
    /// @brief ������, �������� � ���������� ������� ����� ������.
    vector<Face> DisplayedFace;
    int CellsNumbers /** @brief ����������, �������� ���������� ����� � ������. */, 
        ColorsNumbers/** @brief ����������, �������� ���������� ������. */,
        SideCellsNumbers/** @brief ����������, �������� ���������� ����� � �����. */,
        LineCellsNumbers/** @brief ����������, �������� ���������� ����� � �����/�������. */,
        SideNumbers/** @brief ����������, �������� ���������� ������. */;
};