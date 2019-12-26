#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
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
			if(textline=="") continue;
			textline[textline.length()-1] = '\t';
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
		state():cost(0), dis(0), index(0), pre(nullptr){}
		state(int cost, int dis, state* pre, int index):cost(cost), dis(dis), pre(pre), index(index){}
		bool operator==(const state&); // 比较两个节点是相等的
		bool operator<(const state&); // 一个节点比另一个节点小
		int get_key(); // 计算hash属性
		int cost;
		int dis;
		int index; // 节点的编号
		state* pre;
};
bool state::operator==(const state& rhs){ 
	return this->cost == rhs.cost && this->dis == rhs.dis;
}
bool state::operator<(const state& rhs){ 
	return this->cost < rhs.cost && this->dis < rhs.dis;
}
int state::get_key(){
	// operator '<<' has lower precedence than '+'
	return (this->cost << 16) + this->dis;
}

int main(){
    vector<vector<int> > m1 = readMatrixFromTxt("m1.txt"); // 距离
	vector<vector<int> > m2 = readMatrixFromTxt("m2.txt"); // 代价
	const int Num_City = m1.size();
	int i = 0;
	vector<map<int,state*> > process(Num_City);
	state *init = new state();
	process[0][init->get_key()] = init; // 初始化状态

	queue<state *> todos;
	todos.push(init); // 初始化，把自己放到需要处理的列表中

	int p, d, c; // 处理的城市标号，距离，代价
	map<int, state*>::iterator p_it, p_temp;
	state *p_state;
	while(!todos.empty()){
		p_state = todos.front(); // 集合中的第一个点
		p = p_state->index;
		// std::cout << "del " << p << "\t";
		for(i = 0; i < Num_City; ++i){
			d = m1[p][i], c = m2[p][i]; // p 到 i 的距离和代价
			if(d == No_Way) continue; // 没有路的话，就不进行处理了
			if(p_state->cost + c > Max_Cost) continue; // 超过了最大的代价，剪枝
			// 判断节点是否有价值，有价值加入待处理集合中
			state *s = new state(p_state->cost + c, p_state->dis + d, p_state, i);
			if((p_temp = process[i].find(s->get_key())) != process[i].end()){ // 节点存在
				delete s; // 已经计算过了，不需要继续计算了
			}else{ // 没有找到
				for(p_temp = process[i].begin(); p_temp!=process[i].end(); ++p_temp){
					if(*(p_temp->second) < *s){ // 有完美更优解，不需要继续计算了
						delete s;
						break;
					}
				}
				if(p_temp==process[i].end()){ // 没有找到一个完美更优的
					process[i][s->get_key()] = s;
					todos.push(s); // 添加新的任务点
					// cout << "add " << i << "\t";
				}
			}
		}
		todos.pop(); // 从队列中删除
		// cout << endl;
	}
	int min_dis = Max_Int;
	int ans_cost = Max_Int;
	for(p_it=process[Num_City-1].begin(); p_it!=process[Num_City-1].end(); ++p_it){
		c = p_it->second->cost, d = p_it->second->dis;
		if(min_dis > d){
			min_dis = d, ans_cost = c;
			p_temp = p_it;
		}
	}
	stack<int> route;
	state* s = p_temp->second;
	while(s){
		route.push(s->index);
		s = s->pre;
	}
	cout << "最短距离为: " << min_dis << "\t对应的开销为: " << ans_cost << "\t 路径为:" << endl;
	while(true){
		cout << route.top()+1 << " ";
		route.pop();
		if(route.empty()) break;
		else cout << "->";
	}
	cout << endl;
    return 0;
}