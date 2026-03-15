#include <iostream>
#include <windows.h>
using namespace std;

//定义联系人结构体
struct Person {
    string m_Name;//姓名
    int m_Age;//年龄
    int m_Sex;//性别
    string m_Address;//地址
    string m_Phone;//电话
};

//定义最大通讯录能存储的最大人数
#define MAX 1000

struct addressBooks {
    Person personArray[MAX];
    int m_size;//通讯录中的人员个数
};


//菜单界面
void showMenu() {
    cout << "**********************" << endl;
    cout << "***** 1.添加联系人 *****"<<endl;
    cout << "***** 2.显示联系人 *****"<<endl;
    cout << "***** 3.删除联系人 *****"<<endl;
    cout << "***** 4.查找联系人 *****"<<endl;
    cout << "***** 5.修改联系人 *****"<<endl;
    cout << "***** 6.清空联系人 *****"<<endl;
    cout << "***** 0.退出通讯录 *****"<<endl;
    cout << "**********************" << endl;
}

//添加联系人
void addPerson(addressBooks *abs) {
    //判断人是否已满
    if (abs->m_size==MAX) {
        cout << "通讯录人数已达上限";
        return;
    }
    else {
        //开始添加具体联系人

        //姓名
        cout << "请输入姓名：";
        string name;
        cin >> name;
        abs->personArray[abs->m_size].m_Name = name;
        //性别
        int sex = 0;
        cout << "请输入性别（1代表男，2代表女）";
        while (true) {
            cin >> sex;
            if (sex==1 || sex==2) {
                abs->personArray[abs->m_size].m_Sex=sex;
                break;
            }
            cout << "请重新输入：";
        }
        //年龄
        int age = 0;
        cout << "请输入年龄：";
        cin >> age;
        abs->personArray[abs->m_size].m_Age=age;
        //电话
        string phoneNum;
        cout << "请输入电话：";
        cin >> phoneNum;
        abs->personArray[abs->m_size].m_Phone=phoneNum;
        //住址
        cout << "请输入住址：";
        string address;
        cin >> address;
        abs->personArray[abs->m_size].m_Address=address;
        //更新通讯录
        abs->m_size++;

        cout << "添加成功！" <<endl;
        system("pause");

    }
}

//展示联系人
void showPerson(addressBooks * abs) {
    if (abs->m_size==0) {
        cout << "通讯录为空" << endl;
    }
    else {
        for (int i=0;i<abs->m_size;i++) {
            cout << "姓名：" << abs->personArray[i].m_Name << "\t";
            cout << "性别：" << (abs->personArray[i].m_Sex==1 ? "男" : "女") << "\t";
            cout << "年龄：" << abs->personArray[i].m_Age << "\t";
            cout << "电话：" << abs->personArray[i].m_Phone << "\t";
            cout << "住址：" << abs->personArray[i].m_Address << endl;
        }
        system("pause");
    }
}

//通过姓名判断联系人是否存在
int isExsit(addressBooks * abs,string name) {
    for (int i=0;i<abs->m_size;i++) {
        if (abs->personArray[i].m_Name==name) return i;
    }
    return -1;
}


//删除的实现
void deletePerson(addressBooks * abs) {
    string name;
    cout << "请输入要删除的联系人的姓名：";
    cin >> name;

    //检测是否存在此人
    if (isExsit(abs,name)!=-1) {
        int index = isExsit(abs,name);
        for (int i=index;i<abs->m_size;i++) {
            abs->personArray[i]=abs->personArray[i+1];
        }
        cout << "删除成功！";
        abs->m_size--;
        system("pause");
    }
    else {
        cout << "查无此人";
        system("pause");
    }
}


//查找联系人
void findPerson(addressBooks * abs) {
    string name;
    cout << "请输入您要查找的联系人的姓名：" << endl;
    cin >> name;
    if (isExsit(abs,name)!=-1) {
        int res = isExsit(abs,name);
        cout << "姓名：" << abs->personArray[res].m_Name << "\t";
        cout << "性别：" << (abs->personArray[res].m_Sex==1 ? "男" : "女") << "\t";
        cout << "年龄：" << abs->personArray[res].m_Age << "\t";
        cout << "电话：" << abs->personArray[res].m_Phone << "\t";
        cout << "住址：" << abs->personArray[res].m_Address << endl;
        system("pause");
    }
    else {
        cout << "查无此人" << endl;
        system("pause");
    }
}

//修改联系人
void modifyPerson(addressBooks * abs) {
    cout << "请输入要修改联系人的姓名：" << endl;
    string name;
    cin >> name;
    int res = isExsit(abs,name);
    if (res!=-1) {
        //修改姓名
        cout << "请输入新姓名：" << endl;
        string name;
        cin >> name;
        abs->personArray[res].m_Name=name;
        //修改性别
        cout << "请输入新性别，1代表男，2代表女：" << endl;
        while (true) {
            int sex;
            cin >> sex;
            if (sex==1 || sex==2) {
                abs->personArray[res].m_Sex=sex;
                break;
            }
            else cout << "请重新输入性别：" << endl;
        }
        //修改年龄
        cout << "请输入新年龄：" << endl;
        int age;
        cin >> age;
        abs->personArray[res].m_Age=age;
        //修改号码
        cout << "请输入新号码：" << endl;
        string phoneNum;
        cin >> phoneNum;
        abs->personArray[res].m_Phone=phoneNum;
        //修改地址
        cout << "请输入新地址：" << endl;
        string address;
        cin >> address;
        abs->personArray[res].m_Address=address;

        cout << "修改完成！" << endl;
        system("pause");
    }
    else {
        cout << "查无此人" << endl;
        system("pause");
    }
}

void cleanPerson(addressBooks * abs) {
    cout << "你确定要清空所有联系人吗？该操作不可撤销！" << endl;
    cout << "输入1以继续，输入2退出" << endl;
    while (true) {
        int choice;
        cin >> choice;
        if (choice==1) {
            abs->m_size=0;
            cout << "已清除全部联系人！" << endl;
            break;
        }
        else if (choice==2) {
            break;
        }
        else {
            cout << "数字越界，重新输入：" << endl;
        }
    }
}


int main() {
    //设置控制台编码方式
    SetConsoleOutputCP(65001);
    //创建通讯录结构体变量
    addressBooks abs;
    //初始化
    abs.m_size = 0;

    int select = 0;
    while (true) {
        //调用菜单
        showMenu();
        cin >> select;
        switch (select) {
            case 1:     //添加联系人
                addPerson(&abs);
                break;
            case 2:     //显示联系人
                showPerson(&abs);
                break;
            case 3:     //删除联系人
                deletePerson(&abs);
                break;
            case 4:     //查找联系人
                findPerson(&abs);
                break;
            case 5:     //修改联系人
                modifyPerson(&abs);
                break;
            case 6:     //清空联系人
                cleanPerson(&abs);
                break;
            case 0:     //退出通讯录
                cout << "欢迎下次使用！" << endl;
                return 0;
                break;
            default:
                break;
        }
    }
    return 0;
}