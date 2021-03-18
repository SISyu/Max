#include<iostream>
#include <malloc.h>

using namespace std;

struct LinkedList {
	int value;
	struct LinkedList* next;
};
//创建链表
void List(struct LinkedList* L) {
	int d;
	cin >> d;
	while (d != -1) {
		struct LinkedList* ptr = (struct LinkedList*)malloc(sizeof(struct LinkedList));
		ptr->value = d;
		ptr->next = NULL;
		L->next = ptr;
		L = L->next;
		cin >> d;
	}
}
//链表遍历
void Show(struct LinkedList* L) {
	cout << "链表遍历：";
	while (L->next) {
		cout << L->next->value << " ";
		L = L->next;
	}
	cout << endl;
}
//求链表长度
int length(struct LinkedList* L) {
	int length = 0;
	while (L->next) {
		length++;
		L = L->next;
	}
	return length;
}
//插入
void addNode(struct LinkedList* L,int index,int data) {
	struct LinkedList* temp = NULL;
	struct LinkedList* ptr = (struct LinkedList*)malloc(sizeof(struct LinkedList));
	ptr->value = data;
	ptr->next = NULL;
	
	while (index && L->next) {
		temp = L;      //存放第k-1个元素的值
		L = L->next;
		index--;
	}
	if (index > 0) {
		L->next = ptr;
		L = L->next;
	}
	else {
		temp->next = ptr;
		ptr->next = L;
	}
}
//删除第x个位置的节点，
void DeleteList(struct LinkedList* L, int x) {
	if (length <= 0) {
		cout << "空表，无可删除元素..." << endl;
		return;
	}
	x = x - 1;//下标减一
	struct LinkedList* ptr = L->next;
	struct LinkedList* pre = L;//ptr前一个位置
	
	while (x-- && ptr) {
		pre = ptr;
		ptr = pre->next;
	}
	if (ptr == NULL || x > 0) {
		cout << "要删除的位置不存在" << endl;
	}
	else {
		pre->next = ptr->next;//删除ptr节点
		free(ptr);
	}
}
//改第i个位置的值
int ChangeElement(struct LinkedList* L, int i,int v) {
	struct LinkedList* ptr = L;
	int k = i;
	while (i > 0 && ptr->next) {
		ptr = ptr->next;
		i--;
	}
	if (i == 0 && ptr != NULL) { //找到了第i个位置的元素
		ptr->value = v;
		return ptr->value;
	}
	else {
		cout << "第" << k << "个位置的值不存在" << endl;
		return -1;
	}
}

//查找第i个位置元素的值
int FindElement(struct LinkedList* L, int i) {
	struct LinkedList* ptr = L;
	int k = i;
	while (i > 0 && ptr->next) {
		ptr = ptr->next;
		i--;
	}
	if (i == 0 && ptr != NULL) {
		return ptr->value;
	}
	else {
		cout << "第" << k << "个位置的值不存在" << endl;
		return -1;
	}
}

//清空链表
void ClearLinkedList(struct LinkedList* L) {
	struct LinkedList* ptr = L;
	if (length(L) > 0) {
		while (ptr->next) {
			struct LinkedList* temp = ptr->next;
			ptr->next = ptr->next->next;
			free(temp);
		}
	}
}
int main() {
	struct LinkedList* head = (struct LinkedList*)malloc(sizeof(struct LinkedList));
	head->next = NULL;
	while (1) {
		cout << "*********************************************" << endl;
		cout << "*1.创建单链表（-1结束）            *2.打印单链表" << endl;
		cout << "*3.插入单链表                     *4.单链表删除" << endl;
		cout << "*5.单链表改值                           *6.查找" << endl;
		cout << "                   *7.退出                    " << endl;
		
		int k;
		cout << "请输入您的选择：";
		cin >> k;
		switch (k) {
		case 1:
			List(head);
			system("pause");
			continue;

		case 2:
			Show(head);
			system("pause");
			continue;

		case 3:
			int i, data;
			cout << "请输入要插入的位置和值：";
			cin >> i;
			cin >> data;
			addNode(head, i, data);
			Show(head);
			system("pause");
			continue;

		case 4:
			int x;
			cout << "请输入要删除的位置：";
			cin >> x;
			DeleteList(head, x);
			system("pause");
			continue;

		case 5:
			int j,k;
			cout << "请输入要改变的位置和改变的值：";
			cin >> j;
			cin >> k;
			if (ChangeElement(head,j,k) != -1)
				cout << "第" << j << "个位置的值为：" << ChangeElement(head,j,k) << endl;
			system("pause");
			continue;

		case 6:
			int n;
			cout << "请输入要查找的位置：";
			cin >> n;
			if (FindElement(head, n) != -1)
				cout << "第" << n << "个位置的值为：" << FindElement(head, n) << endl;
			system("pause");
			continue;

		case 7:
			break;

		default:
			cout << "请输入正确的选项！" << endl;
			system("pause");
			continue;

		}
		break;
	}
	return 0;
}
