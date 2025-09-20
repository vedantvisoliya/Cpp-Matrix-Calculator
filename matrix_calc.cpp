#include <iostream>
#include <vector>
using namespace std;

class Matrix
{
public:
    int rows;
    int columns;
    vector<vector<int>> mat;

    Matrix(int rows, int columns)
    {
        this->rows = rows;
        this->columns = columns;
        mat.resize(rows, vector<int>(columns, 0));
    }

    void showMatrix()
    {
        for (int i = 0; i < rows; i++)
        {
            cout << "[";
            for (int j = 0; j < columns; j++)
            {
                cout << mat[i][j] << ",";
            }
            cout << "]";
            cout << endl;
        }
    }

    void showMatrix(Matrix matX)
    {
        for (int i = 0; i < matX.rows; i++)
        {
            cout << "[";
            for (int j = 0; j < matX.columns; j++)
            {
                cout << mat[i][j] << ",";
            }
            cout << "]";
            cout << endl;
        }
    }

    void addElements()
    {
        int elem;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                try
                {
                    cout << "Enter the element " << "(" << i+1 << "," << j+1 << ")" << ": ";
                    cin >> elem;
                    mat[i][j] = elem;
                }
                catch (exception e)
                {
                    cout << e.what() << endl;
                }
            }
        }
        cout << "Elements added" << endl;
    }

    void addMatrix(Matrix matX)
    {
        if (rows == matX.rows && columns == matX.columns)
        {
            showMatrix();
            cout << "   +" << endl;
            matX.showMatrix();
            cout << "  ||" << endl;

            for (int i = 0; i < rows; i++)
            {
                cout << "[";
                for (int j = 0; j < columns; j++)
                {
                    cout << mat[i][j] + matX.mat[i][j] << ",";
                }
                cout << "]" << endl;
            }
        }
        else
        {
            cout << "Error: Row and Columns mismateched." << endl;
        }
    }

    void subtractMatrix(Matrix matX)
    {
        if (rows == matX.rows && columns == matX.columns)
        {
            showMatrix();
            cout << "   -" << endl;
            matX.showMatrix();
            cout << "  ||" << endl;

            for (int i = 0; i < rows; i++)
            {
                cout << "[";
                for (int j = 0; j < columns; j++)
                {
                    cout << mat[i][j] - matX.mat[i][j] << ",";
                }
                cout << "]" << endl;
            }
        }
        else
        {
            cout << "Error: Row and Columns mismateched." << endl;
        }
    }
};

int askMatrixCode() {
    int inputMatrixCode;
    while (true)
    {
        try
        {
            cout << "[1]Matrix A\n[2]Matrix B\n[3]Matrix C\n[4]Matrix D\n   Enter the number of the matrix: ";
            cin >> inputMatrixCode;
            if (inputMatrixCode != 1 && inputMatrixCode != 2 && inputMatrixCode != 3 && inputMatrixCode != 4) {
                cout << "Input Error: matrix code didn't match." << endl;
                continue;
            }
            return inputMatrixCode;
        }
        catch (exception e)
        {
            cout << e.what() << endl;
            return 0;
        }
    }
}

vector<int> size_of_matrix()
{
    int rows;
    int columns;
    while (true)
    {
        cout << "Enter the number of the rows: ";
        cin >> rows;
        cout << "Enter the numbers of the column: ";
        cin >> columns;
        if (rows != 0 && columns != 0)
        {
            return {rows, columns};
        }
        else
        {
            continue;
        }
    }
}

void createMatrix(Matrix &a, Matrix &b, Matrix &c, Matrix &d)
{
    int inputMatrixCode = askMatrixCode();
    vector<int> dimen;

    switch (inputMatrixCode)
    {
    case 0:
        return;
    case 1:
        dimen = size_of_matrix();
        a = Matrix(dimen[0], dimen[1]);
        a.addElements();
        break;
    case 2:
        dimen = size_of_matrix();
        b = Matrix(dimen[0], dimen[1]);
        b.addElements();
        break;
    case 3:
        dimen = size_of_matrix();
        c = Matrix(dimen[0], dimen[1]);
        c.addElements();
        break;
    case 4:
        dimen = size_of_matrix();
        d = Matrix(dimen[0], dimen[1]);
        d.addElements();
        break;

    default:
        cout << "Error: Invalid Input." << endl;
        return;
    }
}

void showStoredMatrices(Matrix a, Matrix b, Matrix c, Matrix d)
{
    int inputMatrixCode = askMatrixCode();

    switch (inputMatrixCode)
    {
    case 0:
        return;
    case 1:
        a.showMatrix();
        break;
    case 2:
        b.showMatrix();
        break;
    case 3:
        c.showMatrix();
        break;
    case 4:
        d.showMatrix();
        break;
    default:
        cout << "Error: Invalid Input." << endl;
        return;
    }
}


void addTwoMatrix(Matrix a, Matrix b, Matrix c, Matrix d) {
    cout << "Enter the first matrix code:" << endl;
    int firstMatrixCode = askMatrixCode();

    cout << "Enter the second matrix code:" << endl;
    int secondMatrixCode = askMatrixCode();

    if (firstMatrixCode == 0 || secondMatrixCode == 0) {
        return;
    }
    else if (firstMatrixCode == 1 && secondMatrixCode == 1) {
        a.addMatrix(a);
    }
    else if (firstMatrixCode == 1 && secondMatrixCode == 2) {
        a.addMatrix(b);
    }
    else if (firstMatrixCode == 1 && secondMatrixCode == 3) {
        a.addMatrix(c);
    }
    else if (firstMatrixCode == 1 && secondMatrixCode == 4) {
        a.addMatrix(d);
    }
    else if (firstMatrixCode == 2 && secondMatrixCode == 1) {
        b.addMatrix(a);
    }
    else if (firstMatrixCode == 2 && secondMatrixCode == 2) {
        b.addMatrix(b);
    }
    else if (firstMatrixCode == 2 && secondMatrixCode == 3) {
        b.addMatrix(c);
    }
    else if (firstMatrixCode == 2 && secondMatrixCode == 4) {
        b.addMatrix(d);
    }
    else if (firstMatrixCode == 3 && secondMatrixCode == 1) {
        c.addMatrix(a);
    }
    else if (firstMatrixCode == 3 && secondMatrixCode == 2) {
        c.addMatrix(b);
    }
    else if (firstMatrixCode == 3 && secondMatrixCode == 3) {
        c.addMatrix(c);
    }
    else if (firstMatrixCode == 3 && secondMatrixCode == 4) {
        c.addMatrix(d);
    }
    else if (firstMatrixCode == 4 && secondMatrixCode == 1) {
        d.addMatrix(a);
    }
    else if (firstMatrixCode == 4 && secondMatrixCode == 2) {
        d.addMatrix(b);
    }
    else if (firstMatrixCode == 4 && secondMatrixCode == 3) {
        d.addMatrix(c);
    }
    else if (firstMatrixCode == 4 && secondMatrixCode == 4) {
        d.addMatrix(d);
    }
}

void subtractTwoMatrix(Matrix a, Matrix b, Matrix c, Matrix d) {
    cout << "Enter the first matrix code:" << endl;
    int firstMatrixCode = askMatrixCode();

    cout << "Enter the second matrix code:" << endl;
    int secondMatrixCode = askMatrixCode();

    if (firstMatrixCode == 0 || secondMatrixCode == 0) {
        return;
    }
    else if (firstMatrixCode == 1 && secondMatrixCode == 1) {
        a.subtractMatrix(a);
    }
    else if (firstMatrixCode == 1 && secondMatrixCode == 2) {
        a.subtractMatrix(b);
    }
    else if (firstMatrixCode == 1 && secondMatrixCode == 3) {
        a.subtractMatrix(c);
    }
    else if (firstMatrixCode == 1 && secondMatrixCode == 4) {
        a.subtractMatrix(d);
    }
    else if (firstMatrixCode == 2 && secondMatrixCode == 1) {
        b.subtractMatrix(a);
    }
    else if (firstMatrixCode == 2 && secondMatrixCode == 2) {
        b.subtractMatrix(b);
    }
    else if (firstMatrixCode == 2 && secondMatrixCode == 3) {
        b.subtractMatrix(c);
    }
    else if (firstMatrixCode == 2 && secondMatrixCode == 4) {
        b.subtractMatrix(d);
    }
    else if (firstMatrixCode == 3 && secondMatrixCode == 1) {
        c.subtractMatrix(a);
    }
    else if (firstMatrixCode == 3 && secondMatrixCode == 2) {
        c.subtractMatrix(b);
    }
    else if (firstMatrixCode == 3 && secondMatrixCode == 3) {
        c.subtractMatrix(c);
    }
    else if (firstMatrixCode == 3 && secondMatrixCode == 4) {
        c.subtractMatrix(d);
    }
    else if (firstMatrixCode == 4 && secondMatrixCode == 1) {
        d.subtractMatrix(a);
    }
    else if (firstMatrixCode == 4 && secondMatrixCode == 2) {
        d.subtractMatrix(b);
    }
    else if (firstMatrixCode == 4 && secondMatrixCode == 3) {
        d.subtractMatrix(c);
    }
    else if (firstMatrixCode == 4 && secondMatrixCode == 4) {
        d.subtractMatrix(d);
    }
}

void intro()
{
    cout << "__________________________________________" << endl;
    cout << "|----Welcome to the Matrix Calculator----|" << endl;
    cout << "|                       by- VedantKumar  |" << endl;
    cout << "|________________________________________|" << endl;
    cout << endl;
}

void operations(Matrix &a, Matrix &b, Matrix &c, Matrix &d)
{
    int oper_num;
    try {
        cout << "What operation do you want to perform?" << endl;
        cout << "operations:\n    [1]Add\n    [2]Subtract\n    [3]Multiply\n    [4]Power\n    [5]Inverse\n    [6]Determinant\n    [7]Store Matrix\n    [8]Show Stored Matrix\n  :";
        cin >> oper_num;
    }
    catch (exception e) {
        cout << e.what() << endl; 
        return;
    }

    switch (oper_num)
    {
    case 1:
        addTwoMatrix(a, b, c, d);
        break;
    case 2:
        subtractTwoMatrix(a, b, c, d);
        break;
    case 3:
        cout << "Multiply";
        break;
    case 4:
        cout << "Power";
        break;
    case 5:
        cout << "Inverse";
        break;
    case 6:
        cout << "Determinant";
        break;
    case 7:
        createMatrix(a, b, c, d);
        break;
    case 8:
        showStoredMatrices(a, b, c, d);
        break;
    default:
        cout << "Error: Invalid Input " << oper_num << endl;
        return;
    }
}

int main()
{
    // matrices a, b, c, d
    Matrix matA = Matrix(0, 0);
    Matrix matB = Matrix(0, 0);
    Matrix matC = Matrix(0, 0);
    Matrix matD = Matrix(0, 0);

    // exit variable
    bool exit = false;
    char exitChoice = 'n';

    // welcome message for the user
    intro();

    while (!exit)
    {
        operations(matA, matB, matC, matD);
        cout << "Do you want to exit, type y: ";
        cin >> exitChoice;

        if (exitChoice == 'y' || exitChoice == 'Y') {
            exit = !exit;
        }
        else {
            continue;
        }
    }

    return 0;
}