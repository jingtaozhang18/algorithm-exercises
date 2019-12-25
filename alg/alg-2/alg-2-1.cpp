#include <iostream>
#include <vector>
#include <set>
#include <map>
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
		state():cost(0), dis(0), recalc(true){}
		state(int cost, int dis):cost(cost), dis(dis), recalc(true){}
		bool operator==(const state&); // 比较两个节点是相等的
		int get_key(); // 计算hash属性
		int cost;
		int dis;
		bool recalc;
};
bool state::operator==(const state& rhs){ 
	return this->cost == rhs.cost && this->dis == rhs.dis;
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

	set<int> todos;
	todos.insert(0); // 初始化，把自己放到需要处理的列表中

	int p, d, c; // 处理的城市标号，距离，代价
	set<int>::iterator it;
	map<int, state*>::iterator p_it, p_temp;
	state *p_state;
	while(!todos.empty()){
		it = todos.begin(); // 集合中的第一个点
		p = *it;
		std::cout << "del " << p << "\t";
		todos.erase(it); // 从集合中删除这个点

		p_it = process[p].begin();
		while(p_it != process[p].end()){
			p_state = p_it->second;
			if(p_state->recalc){
				for(i = 0; i < Num_City; ++i){
					d = m1[p][i], c = m2[p][i]; // p 到 i 的距离和代价
					if(d == No_Way) continue; // 没有路的话，就不进行处理了
					if(p_state->cost + c > Max_Cost) continue; // 超过了最大的代价，剪枝
					// TODO 若存在路径又长，代价又高的情况，则也应该剪枝
					// 判断节点是否已经存在
					state *s = new state(p_state->cost + c, p_state->dis + d);
					if((p_temp = process[i].find(s->get_key())) != process[i].end()){ // 节点存在
						// p_temp->second->recalc = true; // 已经计算过了，没有继续
						delete s;
					}else{ // 没有找到
						process[i][s->get_key()] = s;
						todos.insert(i); // 添加新的任务点
						cout << "add " << i << "\t";
					}
				}
				// 更改recalc为false;
				p_state->recalc = false;
			}
			++p_it;
		}
		cout << endl;
	}
    return 0;
}