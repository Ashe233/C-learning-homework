// 前插链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;


class Datanode {
public:
    int data = 0;
    Datanode* head = NULL;
    Datanode* next = NULL;
};

int main()
{
    int n = 0;
    cin >> n;
    Datanode *last,*head;
    last = new Datanode;
    head = new Datanode;
    while (n != -1) {
        last->data = n;
        Datanode* p = NULL;
        p = new Datanode;
        p->next = last;
        last = p;
        cin >> n;
    }
    head = last->next;

    //遍历
    int i = 1;
    while (head->next != NULL) {
        cout << head->data << " ";
        head = head->next;
        i++;
    }
    int m = i;
    cout << head->data << " ";
    head = last->next;
    cout << "sum" << i << endl;


    //查找
    int searchn = 0;
    cout << "Serch For:";
    cin >> searchn;
    while (head->next != NULL) {
        if (head->data == searchn) {
            cout << head->data << " num:" << i << endl;
        }
        head = head->next;
        i--;
    }
    if (head->data == searchn) {
        cout << head->data << " num:1" << endl;
    }

    head = last->next;

    //排序
    int dec = 0;
    cin >> dec;
    if (dec != 0) {
        for (int z = 0; z < m; z++) {
            for (int k = 0; k < m - z - 1; k++) {
                if (head->data > head->next->data) {
                    Datanode *temp = NULL;
                    temp = head;
                    head = head->next;
                    head->next = head;
                }
                head = head->next;
            }
        }
        head = last->next;
        while (head->next != NULL) {
            cout << head->data << " ";
            head = head->next;
        }
    }

    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
