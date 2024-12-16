#include <iostream>
#include <cstdlib> // ��� srand � rand
#include <ctime>   // ��� time
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    int row, col, m = 0, n, x;
    srand(static_cast<unsigned int>(time(0)));//�������������� ��������� ��������� �����
    cout << "�������� ��������: 1 - �������� �������� � ��������� ��������. 2 - �������� �������� � ���������� ��������. 3 - �������� �������� � 3-� ������ ��������";
    cout << endl << "�� ������� �������: ";
    cin >> x;
    switch (x) {
    case(1):
    {
        cout << "������� ���������� ����� ����������� �������: ";
        cin >> row;
        cout << "������� ���������� �������� ����������� �������: ";
        cin >> col;
        cout << endl;
        //������ ��� ����������� �������
        int* d1 = new int[row * col];

        // ������� ������ ����������
        int** d2 = new int* [row];
        for (int i = 0; i < row; ++i) {
            d2[i] = new int[col]; // �������� ������ ��� ������� ����
        }

        //��������� ������ ���������� �������
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                d2[i][j] = rand() % 100;
            }
        }

        //����� ����������� �������
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                cout << d2[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        int zz;
        cout << "��������: 1 - ������� ���������� ������� � ����������. 2 - ������� ���������� ������� � ����������." << endl;
        cout << "�� ������� �������: ";
        cin >> zz;
        switch (zz) {
        case(1): {
            m = 0;
            //������� ���������� ������� � ����������
            for (int i = 0; i < row; i++) {
                for (int k = 0; k < col; k++) {
                    d1[m] = d2[i][k];
                    m++;
                }
            }
            cout << "���������� ������: " << endl;
            //����� ����������� �������
            for (int i = 0; i < row * col; i++) {
                cout << d1[i] << " ";
            }

            // ����������� ������
            for (int i = 0; i < row; ++i) {
                delete[] d2[i]; // ����������� ������ ��� ������� ����
            }
            delete[] d2; //������������ ������ ��� ������� ����������

            return 0;
            break;
        }
        case(2): {
            m = 0;
            //������� ���������� ������� � ����������
            for (int i = 0; i < row; i++) {
                for (int k = 0; k < col; k++) {
                    d1[m] = d2[i][k];
                    m++;
                }
            }
            cout << endl;
            int depth3, row3, col3, n;
            m = 0;
            n = row * col;
            cout << "������� ���������� ����� (�������) ����������� �������: ";
            cin >> depth3;
            cout << "������� ���������� �����: ";
            cin >> row3;
            cout << "������� ���������� ��������: ";
            cin >> col3;
            if (col3 * row3 * depth3 < n) {
                cout << "�������� ����������. ��������� ���������� ������� ������, ��� �����������.";
            }
            else {
                // ������� ������ ���������� ��� �������
                int*** d3 = new int** [depth3];
                for (int i = 0; i < depth3; ++i) {
                    d3[i] = new int* [row3]; // �������� ������ ��� ����� � ������ ����
                    for (int j = 0; j < row3; ++j) {
                        d3[i][j] = new int[col3]; // �������� ������ ��� �������� � ������ ������
                    }
                }
                for (int j = 0; j < depth3; j++) {

                    for (int k = 0; k < row3; k++) {
                        for (int i = 0; i < col3; i++) {
                            if (m >= n) {
                                d3[j][k][i] = 0;
                            }
                            else {
                                d3[j][k][i] = d1[m];
                            }
                            m++;
                        }
                    }
                }
                for (int i = 0; i < depth3; ++i) {
                    cout << "���� " << i + 1 << ":" << endl;
                    for (int j = 0; j < row3; ++j) {
                        for (int k = 0; k < col3; ++k) {
                            cout << d3[i][j][k] << " ";
                        }
                        cout << endl;
                    }
                    cout << endl;
                }

                for (int i = 0; i < depth3; ++i) {
                    for (int j = 0; j < row3; ++j) {
                        delete[] d3[i][j];
                    }
                    delete[] d3[i];
                }
                delete[] d3;

                delete[] d1;


                for (int i = 0; i < row; ++i) {
                    delete[] d2[i];
                }
                delete[] d2;

                return 0;
            }
            break;
        default: {
            cout << "������������ ��������.";
            break;
        }

               break;
        }
               
        }


        break;
    }
    case(2): {
        m = 0;
        int z;
        cout << "�������� �������: 1 - ������� ����������� ������� � ��������� ������. 2 - ������� ����������� ������� � ���������� ������.";
        cout << endl << "�� ������� �������: ";
        cin >> z;
        switch (z) {
        case(1): {
            m = 0;
            cout << "������� ���������� ��������� ����������� �������: ";
            cin >> n;
            int* d1 = new int[n];
                cout << "������� ���������� ����� ����������� �������: ";
                cin >> row;
                cout << "������� ���������� �������� ����������� �������: ";
                cin >> col;
            if (row * col < n) {
                cout << "��������� ������, ��� �������� ����� � ���������. �������� ����������.";
            }
            else {
                // ������� ������ ����������
                int** d2 = new int* [row];
                for (int i = 0; i < row; ++i) {
                    d2[i] = new int[col]; // �������� ������ ��� ������� ����
                }

                //��������� ��������� ������� ���������� �������
                for (int i = 0; i < n; i++) {
                    d1[i] = rand() % 100;
                }
                cout << "���������� ������: " << endl;
                //������� ���������� ������ ()
                for (int i = 0; i < n; i++) {
                    cout << d1[i] << " ";
                }
                cout << endl;
                //��������� ��������� ������
                for (int i = 0; i < row; i++) {
                    for (int k = 0; k < col; k++) {
                        //���� �� ��������� ���������� ������� ������, ��� �����������, �� ��������� �� ������
                        if (m >= n) {
                            d2[i][k] = 0;
                        }
                        else {
                            d2[i][k] = d1[m];
                        }
                        m++;
                    }
                }
                cout << "��������� ������: " << endl;
                //����� ����������� �������
                for (int i = 0; i < row; ++i) {
                    for (int j = 0; j < col; ++j) {
                        cout << d2[i][j] << " ";
                    }
                    cout << endl;
                }

                // ����������� ������
                for (int i = 0; i < row; ++i) {
                    delete[] d2[i];
                }
                delete[] d2;
                delete[] d1;

                return 0;
            }
            break;
        }
        case(2): {
            cout << "������� ���������� ��������� ����������� �������: ";
            cin >> n;
            int* d1 = new int[n];
            //��������� ��������� ������� ���������� �������
            for (int i = 0; i < n; i++) {
                d1[i] = rand() % 100;
            }

            //������� ���������� ������ ()
            for (int i = 0; i < n; i++) {
                cout << d1[i] << " ";
            }
            cout << endl;
            int depth;
            m = 0;
            cout << "������� ���������� ����� (�������) ����������� �������: ";
            cin >> depth;
            cout << "������� ���������� �����: ";
            cin >> row;
            cout << "������� ���������� ��������: ";
            cin >> col;
            if (col * row * depth < n) {
                cout << "��������� ������, ��� �������� ����� � ����������. �������� ����������.";
            }
            else {
                // ������� ������ ���������� ��� �������
                int*** d3 = new int** [depth];
                for (int i = 0; i < depth; ++i) {
                    d3[i] = new int* [row]; // �������� ������ ��� ����� � ������ ����
                    for (int j = 0; j < row; ++j) {
                        d3[i][j] = new int[col]; // �������� ������ ��� �������� � ������ ������
                    }
                }
                for (int j = 0; j < depth; j++) {

                    for (int k = 0; k < row; k++) {
                        for (int i = 0; i < col; i++) {
                            if (m >= n) {
                                d3[j][k][i] = 0;
                            }
                            else {
                                d3[j][k][i] = d1[m];
                            }
                            m++;
                        }
                    }
                }
                //����� 3-� ������� �������
                for (int i = 0; i < depth; ++i) {
                    cout << "���� " << i + 1 << ":" << endl;
                    for (int j = 0; j < row; ++j) {
                        for (int k = 0; k < col; ++k) {
                            cout << d3[i][j][k] << " ";
                        }
                        cout << endl;
                    }
                    cout << endl;
                }
                for (int i = 0; i < depth; ++i) {
                    for (int j = 0; j < row; ++j) {
                        delete[] d3[i][j];
                    }
                    delete[] d3[i];
                }
                delete[] d3;
            }
            delete[] d1;
            return 0;
            break;
        }
        default: {
            cout << "������������ ��������.";
            break;
        }
        }
        break;
    }
    case(3): {
        //������� �������
        int depth;
        m = 0;
        cout << "������� ���������� ����� (�������) ����������� �������: ";
        cin >> depth;
        cout << "������� ���������� �����: ";
        cin >> row;
        cout << "������� ���������� ��������: ";
        cin >> col;

        // ������� ������ ���������� ��� �������
        int*** d3 = new int** [depth];
        for (int i = 0; i < depth; ++i) {
            d3[i] = new int* [row]; // �������� ������ ��� ����� � ������ ����
            for (int j = 0; j < row; ++j) {
                d3[i][j] = new int[col]; // �������� ������ ��� �������� � ������ ������
            }
        }
        //��������� ������ ���������� �������
        for (int i = 0; i < depth; ++i) {
            for (int j = 0; j < row; ++j) {
                for (int k = 0; k < col; ++k) {
                    d3[i][j][k] = rand() % 100;
                }
            }
        }

        //����� 3-� ������� �������
        for (int i = 0; i < depth; ++i) {
            cout << "���� " << i << ":" << endl;
            for (int j = 0; j < row; ++j) {
                for (int k = 0; k < col; ++k) {
                    cout << d3[i][j][k] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
        int y;
        cout << "�������� �������: 1 - ������� ����������� ������� � ���������� ������. 2 - ������� ����������� ������� � ��������� ������.";
        cout << endl << "�� ������� �������: ";
        cin >> y;
        switch (y) {
        case(1): { //������� 3 � 1 +
            int* d1 = new int[row * col * depth];
            for (int i = 0; i < depth; ++i) {
                for (int j = 0; j < row; ++j) {
                    for (int k = 0; k < col; ++k) {
                        d1[m] = d3[i][j][k];
                        m++;
                    }
                }
            }
            for (int i = 0; i < row * depth * col; i++) {
                cout << d1[i] << " ";
            }
            break;
            delete[] d1;
            for (int i = 0; i < depth; ++i) {
                for (int j = 0; j < row; ++j) {
                    delete[] d3[i][j];
                }
                delete[] d3[i];
            }
            delete[] d3;
        }
        case(2): { // 3 � 2
            //������� ���-�� ��������� ����������� �������
            int el, row2, col2, p = 0, pp = 0, ppp = 0;
            el = row * col * depth;
            cout << "������� ���������� �����, �� ������, ��� ���������, ������� ����� ��� ��������� = " << el << " :";
            cin >> row2;
            cout << "������� ���������� ��������, �� ������, ��� ���������, ������� ����� ��� ��������� = " << el << " :";
            cin >> col2;
            if (col * row * depth > col2 * row2) {
                cout << "�������� ����������, ��� ��� ���������� ��������� ����������� ��������� ���������� ����� ����������";
            }
            else {
                // ������� ������ ���������� 
                int** d2 = new int* [row2];
                for (int i = 0; i < row2; ++i) {
                    d2[i] = new int[col2]; // �������� ������ ��� ������� ����
                }

                //��������� 3-� ������ � ����������
                int* d1 = new int[row * col * depth];
                for (int i = 0; i < depth; ++i) {
                    for (int j = 0; j < row; ++j) {
                        for (int k = 0; k < col; ++k) {
                            d1[m] = d3[i][j][k];
                            m++;
                        }
                    }
                }

                //���������� � ���������
                m = 0;
                for (int i = 0; i < row2; i++) {
                    for (int k = 0; k < col2; k++) {
                        //���� �� ��������� ���������� ������� ������, ��� �����������, �� ��������� �� ������
                        if (m >= row * col * depth) {
                            d2[i][k] = 0;
                        }
                        else {
                            d2[i][k] = d1[m];
                        }
                        m++;
                    }
                }

                //�����
                for (int i = 0; i < row2; ++i) {
                    for (int j = 0; j < col2; ++j) {
                        cout << d2[i][j] << " ";
                    }
                    cout << endl;
                }
                break;
            }
            break;
        }
        default: {
            cout << "������������ ��������.";
            break;
        }
        }
        for (int i = 0; i < depth; ++i) {
            for (int j = 0; j < row; ++j) {
                delete[] d3[i][j];
            }
            delete[] d3[i];
        }
        delete[] d3;
        return 0;
    }
    default: {
        cout << "������������ ��������.";
        break;
    }
    }

}
