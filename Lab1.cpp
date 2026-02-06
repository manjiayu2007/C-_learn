#include <iostream>
#include <string>
#include <limits>
#define Max 100

using namespace std;

// 菜单界面
void showMenu()
{
    cout << "-----1.添加联系人-----" << endl;
    cout << "-----2.显示联系人-----" << endl;
    cout << "-----3.删除联系人-----" << endl;
    cout << "-----4.查找联系人-----" << endl;
    cout << "-----5.修改联系人-----" << endl;
    cout << "-----6.清空联系人-----" << endl;
    cout << "-----0.退出通讯录-----" << endl;
}

// 联系人结构体
struct Person
{
    string m_Name;
    int m_Sex;
    int m_Age;
    string m_Phone;
    string m_Addr;
};

// 通讯录结构体
struct Addressbooks
{
    struct Person personArray[Max];
    int m_Size;
};

// 添加联系人
void addPerson(Addressbooks *abs)
{
    // 判断通讯录是否已满
    if (abs->m_Size == Max)
    {
        cout << "通讯录已满" << endl;
        return;
    }
    else
    {
        // 姓名（允许空格）
        string name;
        cout << "请输入姓名" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);
        abs->personArray[abs->m_Size].m_Name = name;
        // 性别
        cout << "请输入性别" << endl;
        cout << "1------男" << endl;
        cout << "2------女" << endl;
        int sex = 0;

        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            else
            {
                cout << "输入有误，请重新输入" << endl;
            }
        }
        // 年龄
        cout << "请输入年龄" << endl;
        int age = 0;
        while (true)
        {
            cin >> age;
            if (age > 0 && age <= 100)
            {
                abs->personArray[abs->m_Size].m_Age = age;
                break;
            }
            else
            {
                cout << "输入错误，请重新输入" << endl;
            }
        }
        // 电话（允许空格）
        cout << "请输入电话" << endl;
        string phone;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, phone);
        abs->personArray[abs->m_Size].m_Phone = phone;

        // 住址（允许空格）
        cout << "请输入住址" << endl;
        string addr;
        getline(cin, addr);
        abs->personArray[abs->m_Size].m_Addr = addr;

        abs->m_Size++;
        cout << "输入成功" << endl;

        system("pause"); // 按任意键继续
        system("cls");   // 清屏
    }
}

// 显示联系人
void showPerson(Addressbooks *abs)
{
    if (abs->m_Size == 0)
    {
        cout << "当前列表为空" << endl;
        system("pause");
        system("cls");
        return;
    }
    else
    {
        for (int i = 0; i < abs->m_Size; i++)
        {
            cout << "姓名：" << abs->personArray[i].m_Name << "\t";
            cout << "年龄：" << abs->personArray[i].m_Age << "\t";
            cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
            cout << "电话：" << abs->personArray[i].m_Phone << "\t";
            cout << "地址：" << abs->personArray[i].m_Addr << endl;
        }
        system("pause");
        system("cls");
    }
}

// 删除联系人
void deletePerson(Addressbooks *abs)
{
    if (abs->m_Size == 0)
    {
        cout << "当前列表为空，无法删除" << endl;
        system("pause");
        system("cls");
        return;
    }
    cout << "请输入要删除的人的姓名" << endl;
    string proname;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, proname);

    for (int i = 0; i < abs->m_Size; i++)
    {
        if (abs->personArray[i].m_Name == proname)
        {
            for (int j = i; j < abs->m_Size - 1; j++)
            {
                abs->personArray[j] = abs->personArray[j + 1];
            }
            abs->m_Size--;
            cout << "删除成功" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
    cout << "未找到该联系人！" << endl;
    system("pause");
    system("cls");
    return;
}

// 查找联系人
void findPerson(Addressbooks *abs)
{
    if (abs->m_Size == 0)
    {
        cout << "当前列表为空" << endl;
        system("pause");
        system("cls");
        return;
    }
    cout << "请输入要查找的人的姓名" << endl;
    string proname;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, proname);

    for (int i = 0; i < abs->m_Size; i++)
    {
        if (abs->personArray[i].m_Name == proname)
        {
            cout << "姓名：" << abs->personArray[i].m_Name << "\t";
            cout << "年龄：" << abs->personArray[i].m_Age << "\t";
            cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
            cout << "电话：" << abs->personArray[i].m_Phone << "\t";
            cout << "地址：" << abs->personArray[i].m_Addr << endl;
            system("pause");
            system("cls");
            return;
        }
    }
    cout << "未找到该联系人！" << endl;
    system("pause");
    system("cls");
    return;
}

// 修改联系人
void changePerson(Addressbooks *abs)
{
    if (abs->m_Size == 0)
    {
        cout << "当前列表为空，无法修改" << endl;
        system("pause");
        system("cls");
        return;
    }
    cout << "请输入要修改的联系人的姓名" << endl;
    string name;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    for (int i = 0; i < abs->m_Size; i++)
    {
        if (abs->personArray[i].m_Name == name)
        {
            cout << "找到联系人：" << name << "，请选择要修改的信息" << endl;
            cout << "1.姓名" << endl;
            cout << "2.性别" << endl;
            cout << "3.年龄" << endl;
            cout << "4.电话" << endl;
            cout << "5.地址" << endl;
            int choice = 0;
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                cout << "请输入新的姓名：" << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                string newname;
                getline(cin, newname);
                abs->personArray[i].m_Name = newname;
                break;
            }
            case 2:
            {
                cout << "请输入新的性别（1男 2女）：" << endl;
                int sex = 0;
                while (true)
                {
                    cin >> sex;
                    if (sex == 1 || sex == 2)
                    {
                        abs->personArray[i].m_Sex = sex;
                        break;
                    }
                    else
                        cout << "输入错误，请重新输入：" << endl;
                }
                break;
            }
            case 3:
            {
                cout << "请输入新的年龄：" << endl;
                int age = 0;
                while (true)
                {
                    cin >> age;
                    if (age > 0 && age <= 100)
                    {
                        abs->personArray[i].m_Age = age;
                        break;
                    }
                    else
                        cout << "输入错误，请重新输入：" << endl;
                }
                break;
            }
            case 4:
            {
                cout << "请输入新的电话：" << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                string phone;
                getline(cin, phone);
                abs->personArray[i].m_Phone = phone;
                break;
            }
            case 5:
            {
                cout << "请输入新的住址：" << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                string addr;
                getline(cin, addr);
                abs->personArray[i].m_Addr = addr;
                break;
            }
            default:
                cout << "无效选择" << endl;
                break;
            }
            cout << "修改完成" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
    cout << "未找到该联系人，无法修改" << endl;
    system("pause");
    system("cls");
}
int main()
{
    // 创建通讯录的结构体变量
    Addressbooks abs;
    // 初始化通讯录当前人数为 0，避免未定义行为
    abs.m_Size = 0;

    int select = 0;

    while (true)
    {
        // 菜单调用
        showMenu();

        cin >> select;

        switch (select)
        {
        case 1: // 添加联系人
            addPerson(&abs);
            break;
        case 2: // 显示联系人
            showPerson(&abs);
            break;
        case 3: // 删除联系人
            deletePerson(&abs);
            break;
        case 4: // 查找联系人
            findPerson(&abs);
            break;
        case 5: // 修改
            changePerson(&abs);
            break;
        case 6: // 清空联系人
            // 清空通讯录
            if (abs.m_Size == 0)
            {
                cout << "通讯录已为空" << endl;
            }
            else
            {
                abs.m_Size = 0;
                cout << "已清空通讯录" << endl;
            }
            system("pause");
            system("cls");
            break;
        case 0: // 退出通讯录
            cout << "欢迎下次使用" << endl;
            system("pause");
            return 0;
        default:
            cout << "输入错误，请选择0-6的数字！" << endl;
            system("pause");
            system("cls"); // 清屏，优化体验
            break;
        }
    }
    system("pause");
    return 0;
}