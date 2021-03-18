#include<iostream>
#include <malloc.h>

using namespace std;

struct LinkedList {
	int value;
	struct LinkedList* next;
};
//��������
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
//�������
void Show(struct LinkedList* L) {
	cout << "���������";
	while (L->next) {
		cout << L->next->value << " ";
		L = L->next;
	}
	cout << endl;
}
//��������
int length(struct LinkedList* L) {
	int length = 0;
	while (L->next) {
		length++;
		L = L->next;
	}
	return length;
}
//����
void addNode(struct LinkedList* L,int index,int data) {
	struct LinkedList* temp = NULL;
	struct LinkedList* ptr = (struct LinkedList*)malloc(sizeof(struct LinkedList));
	ptr->value = data;
	ptr->next = NULL;
	
	while (index && L->next) {
		temp = L;      //��ŵ�k-1��Ԫ�ص�ֵ
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
//ɾ����x��λ�õĽڵ㣬
void DeleteList(struct LinkedList* L, int x) {
	if (length <= 0) {
		cout << "�ձ��޿�ɾ��Ԫ��..." << endl;
		return;
	}
	x = x - 1;//�±��һ
	struct LinkedList* ptr = L->next;
	struct LinkedList* pre = L;//ptrǰһ��λ��
	
	while (x-- && ptr) {
		pre = ptr;
		ptr = pre->next;
	}
	if (ptr == NULL || x > 0) {
		cout << "Ҫɾ����λ�ò�����" << endl;
	}
	else {
		pre->next = ptr->next;//ɾ��ptr�ڵ�
		free(ptr);
	}
}
//�ĵ�i��λ�õ�ֵ
int ChangeElement(struct LinkedList* L, int i,int v) {
	struct LinkedList* ptr = L;
	int k = i;
	while (i > 0 && ptr->next) {
		ptr = ptr->next;
		i--;
	}
	if (i == 0 && ptr != NULL) { //�ҵ��˵�i��λ�õ�Ԫ��
		ptr->value = v;
		return ptr->value;
	}
	else {
		cout << "��" << k << "��λ�õ�ֵ������" << endl;
		return -1;
	}
}

//���ҵ�i��λ��Ԫ�ص�ֵ
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
		cout << "��" << k << "��λ�õ�ֵ������" << endl;
		return -1;
	}
}

//�������
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
		cout << "*1.����������-1������            *2.��ӡ������" << endl;
		cout << "*3.���뵥����                     *4.������ɾ��" << endl;
		cout << "*5.�������ֵ                           *6.����" << endl;
		cout << "                   *7.�˳�                    " << endl;
		
		int k;
		cout << "����������ѡ��";
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
			cout << "������Ҫ�����λ�ú�ֵ��";
			cin >> i;
			cin >> data;
			addNode(head, i, data);
			Show(head);
			system("pause");
			continue;

		case 4:
			int x;
			cout << "������Ҫɾ����λ�ã�";
			cin >> x;
			DeleteList(head, x);
			system("pause");
			continue;

		case 5:
			int j,k;
			cout << "������Ҫ�ı��λ�ú͸ı��ֵ��";
			cin >> j;
			cin >> k;
			if (ChangeElement(head,j,k) != -1)
				cout << "��" << j << "��λ�õ�ֵΪ��" << ChangeElement(head,j,k) << endl;
			system("pause");
			continue;

		case 6:
			int n;
			cout << "������Ҫ���ҵ�λ�ã�";
			cin >> n;
			if (FindElement(head, n) != -1)
				cout << "��" << n << "��λ�õ�ֵΪ��" << FindElement(head, n) << endl;
			system("pause");
			continue;

		case 7:
			break;

		default:
			cout << "��������ȷ��ѡ�" << endl;
			system("pause");
			continue;

		}
		break;
	}
	return 0;
}
