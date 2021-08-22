// https://leetcode-cn.com/problems/web-crawler-multithreaded/
#include<bits/stdc++.h>
using namespace std;

// This is the HtmlParser's API interface.
// You should not implement it, or speculate about its implementation
class HtmlParser {
  public:
    vector<string> getUrls(string url);
};

class Solution {
private:
    std::mutex mu;
    std::condition_variable cv_req,cv_res;
    int requestCounter=0;
    int exited_flag=0;
public:
    void threadFunc(HtmlParser& htmlParser,string& host_name,queue<string>& requestQueue,queue<string>& resultQueue) {
        while(true){
            unique_lock<mutex> lk(mu);
            while(requestQueue.empty()&&exited_flag==0) 
                cv_req.wait(lk);
            if(exited_flag) return ;
            string url=requestQueue.front();
            requestQueue.pop();
            lk.unlock();
            vector<string> urls=htmlParser.getUrls(url);
            for(auto gurl:urls){
                int pos=gurl.find('/',7);
                string host=gurl.substr(7,pos-7);
                if(host_name==host){
                    lk.lock();
                    resultQueue.push(gurl);
                    lk.unlock();
                }
            }
            lk.lock();
            this->requestCounter--;
            lk.unlock();
            cv_res.notify_one();
        }
    }
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        queue<string> requestQueue;
        requestQueue.push(startUrl);
        queue<string> resultQueue;
        set<string> urlset;
        urlset.insert(startUrl);
        auto pos=startUrl.find('/',7);
        string hostname=startUrl.substr(7,pos-7);
        this->requestCounter=1;
        for(int i=1;i<=3;i++){
            std::thread th(&Solution::threadFunc,this,std::ref(htmlParser),std::ref(hostname),std::ref(requestQueue),std::ref(resultQueue));
            th.detach();
        }
        while(true){
            unique_lock<mutex> lk(mu);
            while(resultQueue.empty()&&this->requestCounter!=0){
                cv_res.wait(lk);
            }
            while(!resultQueue.empty()){
                string url=resultQueue.front();
                resultQueue.pop();
                if(urlset.find(url)!=urlset.end()) continue;
                requestQueue.push(url);
                urlset.insert(url);
                requestCounter++;
            }
            cv_req.notify_all();
            if(requestCounter==0) {
                exited_flag=1;
                break;
            } 
        }
        vector<string> res;
        for(auto resurl:urlset){
            res.push_back(resurl);
        }
        return res;
    }
};

// 作者：nojoker
// 链接：https://leetcode-cn.com/problems/web-crawler-multithreaded/solution/condition_variablemutex-by-nojoker/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。