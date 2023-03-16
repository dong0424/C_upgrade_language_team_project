#include<iostream>
#include <string>
using namespace std;

#define NAME_SIZE 32
#define STUDENT_MAX 10
#define ADDRESS_SIZE 128
#define SUBJECT_SIZE 20

struct _tagStudent
{
    int iNumber;
    char strName[NAME_SIZE];
    char strSubject[SUBJECT_SIZE];
    char strAddress[ADDRESS_SIZE];
    int imonth;
    int idate;
    int iTime;
    int iClock;
};

enum MENU
{
    MENU_NONE,
    MENU_INSERT,
    MENU_DELETE,
    MENU_SEARCH,
    MENU_OUTPUT,
    MENU_EXIT
};


void main()
{

    _tagStudent tStudentArr[STUDENT_MAX] = {};
    char strName[NAME_SIZE] = {};
    int iStudentCount = 0;
    int iStdNumber = 1;


    while (true)
    {

        cout << "   --------<  �ڰ��� ���� ���� ���α׷� >--------- " << endl;
        cout << "  |                                               |" << endl;
        cout << "  |  1. �ڰ��� ���� �����ϱ�                      |" << endl;
        cout << "  |  2. �ڰ��� ���� ����ϱ�                      |" << endl;
        cout << "  |  3. �ڰ��� ���� ����� Ž���ϱ�               |" << endl;
        cout << "  |  4. �ڰ��� ���� ����� ����ϱ�               |" << endl;
        cout << "  |  5. �����ϱ�                                  |" << endl;
        cout << "   ----------------------------------------------- " << endl;
        cout << "   �޴��� �Է��ϼ��� :    ";


        int iMenu;
        cin >> iMenu;

        if (cin.fail())
        {
            cin.clear();

            continue;
        }




        if (iMenu == MENU_EXIT)
            break;

        switch (iMenu)
        {
        case MENU_INSERT:


            cout << " ==========�ڰ��� ���� ���� �Է� �ϼ���.=============" << endl;

            if (iStudentCount == STUDENT_MAX)
                break;

            cout << "�̸��� �Է��ϼ��� :";
            cin >> tStudentArr[iStudentCount].strName, NAME_SIZE;

            cin.ignore(1024, '\n');

            cout << "���� ������ �Է��ϼ��� :";
            cin.getline(tStudentArr[iStudentCount].strSubject, SUBJECT_SIZE);

            cout << "��Ҹ� �Է��ϼ��� : ";
            cin.getline(tStudentArr[iStudentCount].strAddress, ADDRESS_SIZE);

            cout << "����� �Է����ϼ��� : ";
            cin >> tStudentArr[iStudentCount].imonth;

            cout << "������ �Է����ϼ��� : ";
            cin >> tStudentArr[iStudentCount].idate;

            cout << "�ð��� �Է��ϼ��� : ";
            cin >> tStudentArr[iStudentCount].iTime;

            cout << "����� �Է��ϼ��� : ";
            cin >> tStudentArr[iStudentCount].iClock;

            tStudentArr[iStudentCount].iNumber = iStdNumber;

            ++iStdNumber;
            ++iStudentCount;



            break;
        case MENU_DELETE:



            cout << "=======================������ ����� ==================" << endl;



            cin.ignore(1024, '\n');
            cout << "������ ������� �Է��ϼ��� : ";
            cin.getline(strName, NAME_SIZE);

            for (int i = 0; i < iStudentCount; ++i)
            {
                if (strcmp(tStudentArr[i].strName, strName) == 0)
                {
                    for (int j = i; j < iStudentCount - 1; ++j)
                    {
                        tStudentArr[i] = tStudentArr[i + 1];
                    }
                    --iStudentCount;

                    cout << "������ �Ϸ� �Ǿ����ϴ�." << endl;
                    break;
                }
            }


            break;
        case MENU_SEARCH:


            cout << "=======================����� Ž�� ==================" << endl;



            cin.ignore(1024, '\n');
            cout << "Ž���� ������� �Է��ϼ��� : ";
            cin.getline(strName, NAME_SIZE);

            for (int i = 0; i < iStudentCount; ++i)
            {
                if (strcmp(tStudentArr[i].strName, strName) == 0)
                {
                    cout << tStudentArr[i].iNumber << "��° " << endl;
                    cout << "�̸� : " << tStudentArr[i].strName << endl;
                    cout << "���� ���� : " << tStudentArr[i].strSubject << endl;
                    cout << "2020�� " << tStudentArr[i].imonth << "�� " << tStudentArr[i].idate << "�� " << endl;
                    cout << tStudentArr[i].iTime << "�� " << tStudentArr[i].iClock << "��" << endl;
                    break;
                }
            }





            break;
        case MENU_OUTPUT:



            cout << "=============�������� ============" << endl;

            for (int i = 0; i < iStudentCount; ++i)
            {
                cout << tStudentArr[i].iNumber << "��° " << endl;
                cout << "�̸� : " << tStudentArr[i].strName << endl;
                cout << "���� ���� : " << tStudentArr[i].strSubject << endl;
                cout << "2020�� " << tStudentArr[i].imonth << "�� " << tStudentArr[i].idate << "�� " << endl;
                cout << tStudentArr[i].iTime << "�� " << tStudentArr[i].iClock << "��" << endl;
            }



            break;
        default:
            cout << "�޴��� �߸� �����߽��ϴ�. " << endl;
            break;
        }


    }
}