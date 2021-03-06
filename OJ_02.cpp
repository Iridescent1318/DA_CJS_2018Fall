#include <stdio.h>
#pragma warning(disable:4996)

struct ComplexNode {
	int Value;
	ComplexNode* Next;
	ComplexNode* Random;
};

struct CN_list
{
	ComplexNode* front;
	int length;
	CN_list(int len, int* val_list) {
		front = new ComplexNode();
		front->Value = -1;
		length = len;
		ComplexNode* tmp = front;
		for (int i = 0; i < length; i++) {
			ComplexNode* cur = new ComplexNode();
			tmp->Next = cur;
			tmp = tmp->Next;
			tmp->Value = val_list[i];
			tmp->Random = NULL;
		}
		tmp->Next = NULL;
	}
	ComplexNode* CN_search(int index) {
		ComplexNode* tmp = front;
		for (int i = -1; i < index; i++) {
			tmp = tmp->Next;
		}
		return tmp;
	}
	void CN_Rand_init(int* rand_list) {
		for (int i = 0; i < length; i++) {
			if (rand_list[i] >= 0)
				this->CN_search(i)->Random = this->CN_search(rand_list[i]);
		}
	}
	void CN_insert(int index, int value, int rand) {
		ComplexNode* tmp = this->CN_search(index - 1);
		ComplexNode* cur = new ComplexNode();
		cur->Next = tmp->Next;
		cur->Value = value;
		tmp->Next = cur;
		length++;
		this->CN_search(index)->Random = rand >= 0 ? this->CN_search(rand) : NULL;
	}
	void CN_delete(int index) {
		ComplexNode* tmp = this->CN_search(index - 1), *tar = tmp->Next;
		tmp->Next = tar->Next;
		length--;
		ComplexNode* check_tmp = front->Next;
		for (int i = 0; i < length; i++) {
			if (check_tmp->Random == tar) check_tmp->Random = NULL;
			check_tmp = check_tmp->Next;
		}
	}
};

int main() {
	int n, m, k, t;
	scanf("%d%d%d%d", &n, &m, &k, &t);
	int* IniNodeValue = new int[n], *IniNodeRand = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &IniNodeValue[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &IniNodeRand[i]);
	}
	CN_list* list = new CN_list(n, IniNodeValue);
	list->CN_Rand_init(IniNodeRand);
	//Delete
	int* DelNode = new int[m];
	for (int i = 0; i < m; i++) {
		scanf("%d", &DelNode[i]);
	}
	for (int i = 0; i < m; i++) {
		list->CN_delete(DelNode[i]);
	}
	//Insert
	int* InsNodeVal = new int[k], *InsNodeIndex = new int[k], *InsNodeRand = new int[k];
	for (int i = 0; i < k; i++) {
		scanf("%d%d%d", &InsNodeVal[i], &InsNodeIndex[i], &InsNodeRand[i]);
	}
	for (int i = 0; i < k; i++) {
		list->CN_insert(InsNodeIndex[i], InsNodeVal[i], InsNodeRand[i]);
	}
	ComplexNode* out_next = list->CN_search(t), *out_rand = out_next;
	while (out_next != NULL) {
		printf("%d ", out_next->Value);
		out_next = out_next->Next;
	}
	printf("-1\n");
	while (out_rand != NULL) {
		printf("%d ", out_rand->Value);
		out_rand = out_rand->Random;
	}
	printf("-1");
	return 0;
}