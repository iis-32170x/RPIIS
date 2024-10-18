#include "Header.h"

Face::Face(char Сolor) {
    Matrix = vector<vector<char>>(3, vector<char>(3, Сolor));
}

Cube::Cube() : Front('W'), Back('Y'), Left('G'), Right('B'), Top('O'), Bottom('R'), BufferFace(Front) {
    DisplayedFace = { Front, Right, Top, Back, Left, Bottom };
    FullRandomCounter = 0;
    ColorsList = { 'W', 'G', 'Y', 'B', 'R', 'O' };
    CellsNumbers = 54; ColorsNumbers = 6; SideCellsNumbers = 9; LineCellsNumbers = 3; SideNumbers = 6;
};


Face& Face::operator=(const Face& other) {
    if (this != &other) {
        this->Matrix = other.Matrix;
    }
    return *this;
}

bool Face::operator!=(const Face& other) const {
    return this->Matrix != other.Matrix;
}

bool Face::operator==(const Face& other) const {
    return this->Matrix == other.Matrix;
}

string Face::SquareOutPut(char MatrixMember) {
    if (MatrixMember == 'W') return WhiteSquare;
    else if (MatrixMember == 'R') return RedSquare;
    else if (MatrixMember == 'B') return BlueSquare;
    else if (MatrixMember == 'O') return OrangeSquare;
    else if (MatrixMember == 'Y') return YellowSquare;
    else if (MatrixMember == 'G') return GreenSquare;
    else return "ERROR";
}


void Face::OutPutHeader(vector<Face> DisplayedFaces) {
        cout << "  " << SquareOutPut(DisplayedFaces[2].Matrix[0][0]) << SquareOutPut(DisplayedFaces[2].Matrix[0][1]);
        cout << SquareOutPut(DisplayedFaces[2].Matrix[0][2]) << "/" << SquareOutPut(DisplayedFaces[1].Matrix[0][2]) << endl;
        cout << " " << SquareOutPut(DisplayedFaces[2].Matrix[1][0]) << SquareOutPut(DisplayedFaces[2].Matrix[1][1]);
        cout << SquareOutPut(DisplayedFaces[2].Matrix[1][2]) << "/";
        cout << SquareOutPut(DisplayedFaces[1].Matrix[0][1]) << SquareOutPut(DisplayedFaces[1].Matrix[1][2]) << endl;
}

void Face::OutPutBody(vector<Face> DisplayedFaces) {
    cout << "" << SquareOutPut(DisplayedFaces[2].Matrix[2][0]) << SquareOutPut(DisplayedFaces[2].Matrix[2][1]);
    cout << SquareOutPut(DisplayedFaces[2].Matrix[2][2]) << "/" << SquareOutPut(DisplayedFaces[1].Matrix[0][0]);
    cout << SquareOutPut(DisplayedFaces[1].Matrix[1][1]) << SquareOutPut(DisplayedFaces[1].Matrix[2][2]) << endl;
    cout << SquareOutPut(DisplayedFaces[0].Matrix[0][0]) << SquareOutPut(DisplayedFaces[0].Matrix[0][1]);
    cout << SquareOutPut(DisplayedFaces[0].Matrix[0][2]) << "|" << SquareOutPut(DisplayedFaces[1].Matrix[1][0]) << SquareOutPut(DisplayedFaces[1].Matrix[2][1]) << endl;
}

void Face::OutPutFooter(vector<Face> DisplayedFaces) {
    cout << SquareOutPut(DisplayedFaces[0].Matrix[1][0]) << SquareOutPut(DisplayedFaces[0].Matrix[1][1]);
    cout << SquareOutPut(DisplayedFaces[0].Matrix[1][2]);
    cout << "|" << SquareOutPut(DisplayedFaces[1].Matrix[2][0]) << endl;
    cout << SquareOutPut(DisplayedFaces[0].Matrix[2][0]) << SquareOutPut(DisplayedFaces[0].Matrix[2][1]);
    cout << SquareOutPut(DisplayedFaces[0].Matrix[2][2]) << "|" << endl;
}


void Cube::FaceOutPut(Face PrintedFace, vector<Face>PrintFaces) {
    PrintedFace.OutPutHeader(PrintFaces);
    PrintedFace.OutPutBody(PrintFaces);
    PrintedFace.OutPutFooter(PrintFaces);
}

void Cube::Randomize(vector<Face> DisplayedFace) {
    while (FullRandomCounter < CellsNumbers) {
        char Color = ColorsList[rand() % ColorsNumbers];
        int RandomSide = rand() % SideNumbers, RandomLine = rand() % LineCellsNumbers, RandomColumn = rand() % LineCellsNumbers;
        while (1) {
            if (DisplayedFace[RandomSide].RandomCounter.find({ RandomLine, RandomColumn }) == DisplayedFace[RandomSide].RandomCounter.end()) {
                DisplayedFace[RandomSide].RandomCounter[{RandomLine, RandomColumn}] = true;
                FullRandomCounter++;
                while (1) {
                    if (ColorsCounter[Color] < SideCellsNumbers) {
                        DisplayedFace[RandomSide].Matrix[RandomLine][RandomColumn] = Color;
                        ColorsCounter[Color]++;
                        break;
                    }
                    else Color = ColorsList[rand() % ColorsNumbers];
                }
                break;
            }
            else RandomSide = rand() % SideNumbers, RandomLine = rand() % LineCellsNumbers, RandomColumn = rand() % LineCellsNumbers;
        }
    }
    FullRandomCounter = 0;
    for (int i = 0; i < SideNumbers; i++)  DisplayedFace[i].RandomCounter.clear();
    ColorsCounter.clear();
    FaceSynchron(DisplayedFace);
}

void Cube::CubeReading(vector<Face> DisplayedFace) {
    ifstream File("D:/Проекты Visual Studio/Laba1PPOIS/Laba1PPOIS/Cube.txt");
    string Line;
    if (File.is_open()) {
        int FaceIndex = 0;
        int RowIndex = 0;
        while (getline(File, Line)) {
            stringstream iss(Line);
            char ch;
            int ColIndex = 0;
            while (iss >> ch) {
                DisplayedFace[FaceIndex].Matrix[RowIndex][ColIndex] = ch;
                ColIndex++;
            }
            RowIndex++;
            if (RowIndex == 3) {
                RowIndex = 0;
                FaceIndex++;
            }
        }
        File.close();
    }
    else {
        cout << "Не удалось открыть файл." << endl;
    }
    FaceSynchron(DisplayedFace);
}

int Cube::Examination(vector<Face> DisplayedFace) {
    int ExaminationCounter = 0;
    for (int i = 0; i < SideNumbers; i++) {
        for (int j = 0; j < LineCellsNumbers; j++) {
            for (int k = 0; k < LineCellsNumbers; k++) {
                if (DisplayedFace[i].Matrix[0][0] == DisplayedFace[i].Matrix[j][k]) ExaminationCounter++;
            }
        }
    }
    if (ExaminationCounter == CellsNumbers) {
        cout << "Кубик собран" << endl;
        ExaminationCounter = 0;
        return 1;
    }
    else {
        cout << "Кубик не собран" << endl;
        ExaminationCounter = 0;
        return 0;
    }
}

vector<Face> Cube::GetDisplayedFace() const {
    return DisplayedFace;
}

Face Cube::FaceCoup(Face SelectionFace, bool clockwise) {
    vector<vector<char>> BufferMatrix(3, vector<char>(3));

    if (clockwise == true) {
        for (int i = 0; i < LineCellsNumbers; ++i) {
            for (int j = 0; j < LineCellsNumbers; ++j) {
                BufferMatrix[j][2 - i] = SelectionFace.Matrix[i][j];
            }
        }
    }
    else {
        for (int i = 0; i < LineCellsNumbers; ++i) {
            for (int j = 0; j < LineCellsNumbers; ++j) {
                BufferMatrix[2 - j][i] = SelectionFace.Matrix[i][j];
            }
        }
    }

    SelectionFace.Matrix = BufferMatrix;
    return SelectionFace;
}

void Cube::FaceSynchron(vector<Face> PrintedFace) {

    DisplayedFace[0] = PrintedFace[0]; DisplayedFace[1] = PrintedFace[1]; DisplayedFace[2] = PrintedFace[2];
    DisplayedFace[3] = PrintedFace[3]; DisplayedFace[4] = PrintedFace[4]; DisplayedFace[5] = PrintedFace[5];
}

void Cube::VerticalFaceTurn(vector<Face> DisplayedFace, int SeriesNumber, bool Up) {
    SeriesNumber--;
    DisplayedFace[3] = FaceCoup(FaceCoup(DisplayedFace[3], true), true);
    BufferFace = DisplayedFace[5];
    if (Up == true) {
        for (int k = 0; k < 3; k++) {
            DisplayedFace[5].Matrix[k][SeriesNumber] = DisplayedFace[3].Matrix[k][SeriesNumber];
            DisplayedFace[3].Matrix[k][SeriesNumber] = DisplayedFace[2].Matrix[k][SeriesNumber];
            DisplayedFace[2].Matrix[k][SeriesNumber] = DisplayedFace[0].Matrix[k][SeriesNumber];
            DisplayedFace[0].Matrix[k][SeriesNumber] = BufferFace.Matrix[k][SeriesNumber];
        }
    }
    else {
        BufferFace = DisplayedFace[0];
        for (int k = 0, j = 2; k < 3; k++, j--) {
            DisplayedFace[0].Matrix[k][SeriesNumber] = DisplayedFace[2].Matrix[k][SeriesNumber];
            DisplayedFace[2].Matrix[k][SeriesNumber] = DisplayedFace[3].Matrix[k][SeriesNumber];
            DisplayedFace[3].Matrix[k][SeriesNumber] = DisplayedFace[5].Matrix[k][SeriesNumber];
            DisplayedFace[5].Matrix[k][SeriesNumber] = BufferFace.Matrix[k][SeriesNumber];
        }
    }
    DisplayedFace[3] = FaceCoup(FaceCoup(DisplayedFace[3], true), true);
    if (SeriesNumber == 2 && Up == true) DisplayedFace[1] = FaceCoup(DisplayedFace[1], true);
    else if (SeriesNumber == 2 && Up == false) DisplayedFace[1] = FaceCoup(DisplayedFace[1], false);
    if (SeriesNumber == 0 && Up == true) DisplayedFace[4] = FaceCoup(DisplayedFace[4], true);
    else if (SeriesNumber == 0 && Up == false) DisplayedFace[4] = FaceCoup(DisplayedFace[4], false);
    FaceSynchron(DisplayedFace);
    FaceChoosing('P');
}

void Cube::HorisontalFaceTurn(vector<Face> DisplayedFace, int SeriesNumber, bool LeftRotation) {
    SeriesNumber--;
    BufferFace = DisplayedFace[1];
    if (LeftRotation == true) {
        for (int k = 0, j = 2; k < 3; k++, j--) {
            DisplayedFace[1].Matrix[SeriesNumber][k] = DisplayedFace[3].Matrix[SeriesNumber][k];
            DisplayedFace[3].Matrix[SeriesNumber][k] = DisplayedFace[4].Matrix[SeriesNumber][k];
            DisplayedFace[4].Matrix[SeriesNumber][k] = DisplayedFace[0].Matrix[SeriesNumber][k];
            DisplayedFace[0].Matrix[SeriesNumber][k] = BufferFace.Matrix[SeriesNumber][k];
        }
    }
    else {
        BufferFace = DisplayedFace[4];
        for (int k = 0; k < 3; k++) {
            DisplayedFace[4].Matrix[SeriesNumber][k] = DisplayedFace[3].Matrix[SeriesNumber][k];
            DisplayedFace[3].Matrix[SeriesNumber][k] = DisplayedFace[1].Matrix[SeriesNumber][k];
            DisplayedFace[1].Matrix[SeriesNumber][k] = DisplayedFace[0].Matrix[SeriesNumber][k];
            DisplayedFace[0].Matrix[SeriesNumber][k] = BufferFace.Matrix[SeriesNumber][k];
        }
    }
    if (SeriesNumber == 0 && LeftRotation == true) DisplayedFace[2] = FaceCoup(DisplayedFace[2], true);
    else if (SeriesNumber == 0 && LeftRotation == false) DisplayedFace[2] = FaceCoup(DisplayedFace[2], false);
    if (SeriesNumber == 2 && LeftRotation == true) DisplayedFace[5] = FaceCoup(DisplayedFace[5], true);
    else if (SeriesNumber == 2 && LeftRotation == false) DisplayedFace[5] = FaceCoup(DisplayedFace[5], false);
    
    FaceSynchron(DisplayedFace);
    FaceChoosing('P');
}

void Cube::FaceTurn(vector<Face> DisplayedFace, bool clockwise) {
    if (clockwise == true) {
        BufferFace = DisplayedFace[2];
        DisplayedFace[0] = FaceCoup(DisplayedFace[0], true);
            for (int k = 0, j = 2; k < 3; k++, j--) {
                DisplayedFace[2].Matrix[2][k] = DisplayedFace[4].Matrix[j][2];
                DisplayedFace[4].Matrix[j][2] = DisplayedFace[5].Matrix[0][j];
                DisplayedFace[5].Matrix[0][j] = DisplayedFace[1].Matrix[k][0];
                DisplayedFace[1].Matrix[k][0] = BufferFace.Matrix[2][k];
        }
    }
    else {
        BufferFace = DisplayedFace[2];
        DisplayedFace[0] = FaceCoup(DisplayedFace[0], false);
        for (int k = 0, j = 2; k < 3; k++, j--) {
            DisplayedFace[2].Matrix[2][j] = DisplayedFace[1].Matrix[j][0];
            DisplayedFace[1].Matrix[j][0] = DisplayedFace[5].Matrix[0][k];
            DisplayedFace[5].Matrix[0][k] = DisplayedFace[4].Matrix[k][2];
            DisplayedFace[4].Matrix[k][2] = BufferFace.Matrix[2][j];
        }
    }
    FaceSynchron(DisplayedFace);
}


void Cube::FaceChoosing(char Last) {
    char ch;
    vector<Face> BufDpFace = DisplayedFace;
    if (Last != 'P') {
        ch = _getch();
        ch = toupper(ch);
    }
    else {
        ch = 'P';
    }
    system("cls");
    switch (ch) {
    case 'Q':
        DisplayedFace = { BufDpFace[2], FaceCoup(BufDpFace[1],false), FaceCoup(FaceCoup(BufDpFace[3],true),true),
           FaceCoup(FaceCoup(BufDpFace[5],true),true), FaceCoup(BufDpFace[4],true), BufDpFace[0] };
        break;
    case 'A':
        DisplayedFace = { BufDpFace[4], BufDpFace[0], FaceCoup(BufDpFace[2],false), BufDpFace[1], BufDpFace[3], FaceCoup(BufDpFace[5],true) };
        break;
    case 'Z':
        DisplayedFace = { BufDpFace[5], FaceCoup(BufDpFace[1],true), BufDpFace[0],
           FaceCoup(FaceCoup(BufDpFace[2],true),true), FaceCoup(BufDpFace[4],false), FaceCoup(FaceCoup(BufDpFace[3], true),true) };
        break;
    case 'S':
        DisplayedFace = { BufDpFace[1], BufDpFace[3], FaceCoup(BufDpFace[2],true), BufDpFace[4], BufDpFace[0], FaceCoup(BufDpFace[5], false) };
        break;
    case 'L':
        Randomize(DisplayedFace);
        break;
    case 'K':
        Examination(DisplayedFace);
        break;
    case 'J':
        CubeReading(DisplayedFace);
        break;
    default:
        FaceTorsion(ch);
        break;
    }
}

void Cube::FaceTorsion(char ch) {
    ch = toupper(ch);
    switch (ch) {
    case 'E':
        HorisontalFaceTurn(DisplayedFace, 1, true);
        break;
    case 'R':
        VerticalFaceTurn(DisplayedFace, 1, true);
        break;
    case 'F':
        HorisontalFaceTurn(DisplayedFace, 2, true);
        break;
    case 'V':
        VerticalFaceTurn(DisplayedFace, 1, false);
        break;
    case 'C':
        HorisontalFaceTurn(DisplayedFace, 3, true);
        break;
    case 'B':
        VerticalFaceTurn(DisplayedFace, 2, false);
        break;
    case 'N':
        VerticalFaceTurn(DisplayedFace, 3, false);
        break;
    case 'M':
        HorisontalFaceTurn(DisplayedFace, 3, false);
        break;
    case 'H':
        HorisontalFaceTurn(DisplayedFace, 2, false);
        break;
    case 'U':
        HorisontalFaceTurn(DisplayedFace, 1, false);
        break;
    case 'Y':
        VerticalFaceTurn(DisplayedFace, 3, true);
        break;
    case 'T':
        VerticalFaceTurn(DisplayedFace, 2, true);
        break;
    case 'D':
        FaceTurn(DisplayedFace, false);
        break;
    case 'G':
        FaceTurn(DisplayedFace, true);
        break;
    default:
        system("cls");
        break;
    }
}

void Cube::Game() {

    while (true) {
        FaceOutPut(Front, DisplayedFace);
        FaceChoosing('O');
    }
}