#include <iostream>
#include <vector>
#include <set>
#include "string.h"
#include <fstream>

using namespace std;

static const int Max_Int = 0x7fffffff;
static const int No_Way = 9999;
static const int Max_Cost = 1500;

void split(const string& src, const string& delim, vector<int>& dest);
vector<vector<int> > readMatrixFromTxt(string file_name);

void split(const string& src, const string& delim, vector<int>& dest){
	string str = src;
	string::size_type start = 0, index;
	string substr;
 
	index = str.find_first_of(delim, start);	//在str中查找(起始：start) delim的任意字符的第一次出现的位置
	while(index != string::npos){
		substr = str.substr(start, index-start);
		dest.push_back(stoi(substr));
		start = str.find_first_not_of(delim, index);	//在str中查找(起始：index) 第一个不属于delim的字符出现的位置
		if(start == string::npos) return;
		index = str.find_first_of(delim, start);
	}
}

vector<vector<int> > readMatrixFromTxt(string file_name){
    ifstream infile(file_name, ios::in);
	vector<vector<int> > ans;
	string delim("\t");
	string textline;
	vector<int> aline_words;
	if(infile.good()){
		while(!infile.fail()){
			getline(infile, textline);
			aline_words.clear();
			split(textline, delim, aline_words);
			ans.push_back(aline_words);
		}
	}
	infile.close();
	return ans;
}

void print_v(vector<vector<int > >& m){
	for(int i=0;i<m.size();++i){
		for(int j=0;j<m[i].size();++j){
			if (i==j)
				cout << "  \t";
			else if (m[i][j] == 9999)
				cout << "!!" << "\t";
			else
				cout<< m[i][j]<<"\t";
		}
		cout<<endl;
	}
}
class state
{
	public:
		state():cost(0), dis(0), next(nullptr), recalc(true){}
		state(int cost, int dis):cost(cost), dis(dis), next(nullptr), recalc(true){}
		state(int cost, int dis, state* next):cost(cost), dis(dis), next(next), recalc(true){}
		bool operator==(const state& rhs); // 比较两个节点是相等的
		void del_dup(); // 删除以当前节点的下一个节点为头的链表中的重复节点。// 重复节点删除后面的节点
		void show(); // 展示链表中的内容（不包括该节点）
		int cost;
		int dis;
		bool recalc;
		state* next;
};
bool state::operator==(const state& rhs){ 
	return this->cost == rhs.cost && this->dis == rhs.dis;
}
void state::del_dup(){ 
	if (this == nullptr) return;
	state *cur_p = this->next; // 当前要处理的节点
	if (cur_p == nullptr) return;
	state *p, *father; // 向后遍历的节点,其父节点
	while(cur_p){
		p = cur_p->next;
		father = cur_p;
		while(p){
			if(*p==*cur_p){ // 遇到相等的删除
				// 删除之前判断状态是够需要刷新
				if (p->recalc) cur_p->recalc = true;
				father->next=p->next;
				delete p;
				p = father->next;
			}
			else // 不是相等的，继续向下处理
				p=p->next;
		}
		cur_p = cur_p->next;	
	}
}

void state::show(){
	if (this == nullptr) return;
	state *p = this->next; // 当前要处理的节点
	cout << p << ":" << endl;
	while(p){
		cout << '\t' << p->cost << '\t' << p->dis << endl;
	}
	cout << endl;

}


int main(){
    vector<vector<int> > m1 = readMatrixFromTxt("m1.txt"); // 距离
	vector<vector<int> > m2 = readMatrixFromTxt("m2.txt"); // 代价
	const int Num_City = m1.size();
	int i = 0;
	vector<state *> dp(Num_City);
	for(i = 0; i < Num_City; ++i){
		dp[i] = new state;
	}
	dp[0]->next = new state(); // 初始化状态

	set<int> todos;
	todos.insert(0); // 初始化，把自己放到需要处理的列表中

	int p, d, c; // 处理的城市标号，距离，代价
	set<int>::iterator it;
	while(!todos.empty()){
		it = todos.begin(); // 集合中的第一个点
		p = *it;
		cout << "del " << p << "\t";
		todos.erase(it); // 从集合中删除这个点
		// 状态集合进行去重
		dp[p]->del_dup(); // 线性去重的速度比较慢，后面会使用集合来进行处理
		state *p_state = dp[p]->next;
		while(p_state){
			if(p_state->recalc){
				for(i = 0; i < Num_City; ++i){
					d = m1[p][i], c = m2[p][i]; // p 到 i 的距离和代价
					if(d == No_Way) continue; // 没有路的话，就不进行处理了
					if(p_state->cost + c > Max_Cost) continue; // 超过了最大的代价，剪枝
					// 插入新的状态节点
					state *t = new state(p_state->cost + c, p_state->dis + d, dp[i]->next);
					dp[i]->next = t;
					todos.insert(i); // 添加新的任务点
					cout << "add " << i << "\t";
				}
			}
			else
				p_state->recalc = false;
			p_state = p_state->next;
		}
		cout << endl;
	}
	

	dp[Num_City-1]->show();
    return 0;
}